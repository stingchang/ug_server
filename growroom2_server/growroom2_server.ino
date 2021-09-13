#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include <Wire.h>
#include "Pin.h"
#include "TimeHelper.h"

#ifndef STASSID
#define STASSID "****"
#define STAPSK  "******"
#endif

const char *ssid = STASSID;
const char *password = STAPSK;

const long offSetMilliSeconds = - 8 * 60 * 60 * 1000; // Pacifit time is -8

ESP8266WebServer server(8081);

String SENSOR_VALUES = "";
boolean WIFI_CONNECTED = false;

const int I2C_TRANSMISSION_SIZE = 32;  // 32 Byte is I2C transfer buffer size so we can only transfer 32 bytes at a time.
const int16_t I2C_SLAVE = 0x08;
/*
  Setup
    . connect to wifi
    . connect to sensors board

  Loop
    . read data from sensors board
    . output to serial port
    . receive request
      . App request environment values
      . App request update values
    . send request
      . Send environment values to App(Secheduled/Reply)

*/

#define dataBufferArraySize 2
int data[dataBufferArraySize][I2C_TRANSMISSION_SIZE];
int bufferIndex = 0;

TimeHelper time1(0,0);
void setup(void) {
  Wire.begin(SDA_PIN, SCL_PIN);
  Serial.begin(9600);
  
  Serial.println("Master Wire ESP8266 init");
  if (tryConnectWifi()) {
    trySetUpServer();
  }

  initData();
  readDataFromSensorBoard();
}

boolean tryConnectWifi() {
  Wire.begin(SDA_PIN, SCL_PIN); /* join i2c bus with SDA=D1 and SCL=D2 of NodeMCU */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // Wait for connection

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  return true;
}

boolean trySetUpServer() {

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  serverStartRouting();
  Serial.println("HTTP server started");
}
// http://107.184.148.167:8081
void serverStartRouting() {
  server.on("/", handleRoot);
  server.on("/test.svg", drawGraph);
  server.on("/homepagejs.js", handleGetHomePageJs);
  server.on("/getparam", handleGetEnvParam);
  server.on("/updateparam", handleUpdateEnvParam);
  


  server.onNotFound(handleNotFound);
  server.begin();
}

int _7DayDWCPh[2][7];
int _7DayDWCTDS[2][7];
int _24HourDWCTemperature[2][24];
void loop(void) {
  static int lastUpdateHour = - 1;
  static int lastUpdateDay = - 1;
  int hour = time1.getHour();
  int day = time1.getDay();
  
  if( (hour != lastUpdateHour) && time1.getMinute() > 0 )  {
    
    _24HourDWCTemperature[0][hour] = getDataByIndex(DATA_INDEX_DWC1_TEMPERATURE);
    _24HourDWCTemperature[1][hour] = getDataByIndex(DATA_INDEX_DWC2_TEMPERATURE);
    lastUpdateHour = hour;
  }
  if(  millis() - lastUpdateDay >= 1 * time1._DAY  ) {
    
//    Serial.println("Update Daily record at hour = "+String(time1.getHour()));
    
    _7DayDWCPh[0][day] = getDataByIndex(DATA_INDEX_DWC1_PH);
    _7DayDWCPh[1][day] = 0;
    _7DayDWCTDS[0][day] = getDataByIndex(DATA_INDEX_DWC1_TDS);
    _7DayDWCTDS[1][day] = getDataByIndex(DATA_INDEX_DWC2_TDS);
    lastUpdateDay = day;

    time1.updateDay();

    lastUpdateDay = millis();
  }


  server.handleClient();
  MDNS.update();
  
}
