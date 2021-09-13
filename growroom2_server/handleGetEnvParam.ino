

void handleGetEnvParam() {
  readDataFromSensorBoard();


  int val = 0;
  String message = "";
  val = getDataByIndex(DATA_INDEX_ROOM_AUTO);
  
  if (val > 0) {
    message += "{\"roomAuto\":\"on\"";
  } else {
    message += "{\"roomAuto\":\"off\"";
  }
  val = getDataByIndex(DATA_INDEX_LIGHT1);
  if (val > 0) {
    message += ",\"light1\":\"on\"";
  } else {
    message += ",\"light1\":\"off\"";
  }
  val = getDataByIndex(DATA_INDEX_LIGHT2);
  if (val > 0) {
    message += ",\"light2\":\"on\"";
  } else {
    message += ",\"light2\":\"off\"";
  }


  val = getDataByIndex(DATA_INDEX_LIGHT1_ON_TIME );
  message += ",\"light1On\":\"" + String(val/100) + ":" + String(val%100) + "\"";
  val = getDataByIndex(DATA_INDEX_LIGHT1_OFF_TIME );
  message += ",\"light1Off\":\"" + String(val/100) + ":" + String(val%100) + "\"";
  val = getDataByIndex(DATA_INDEX_LIGHT2_ON_TIME );
  message += ",\"light2On\":\"" + String(val/100) + ":" + String(val%100) + "\"";;
  val = getDataByIndex(DATA_INDEX_LIGHT2_OFF_TIME );
  message += ",\"light2Off\":\"" + String(val/100) + ":" + String(val%100) + "\"";;

  //      val = getDataByIndex(DATA_INDEX_FAN_STAUTS);
  //      if(val > 0) {
  //        message += ",\"fan'\":\"on\"";
  //      } else {
  //        message += ",\"fan'\":\"off\"";
  //      }

  val = getDataByIndex(DATA_INDEX_CO2);
  message += ",\"CO2\":\"" + String(val) + "\"";
  val = getDataByIndex(DATA_INDEX_CO2_AUTO_HIGH);
  message += ",\"CO2High\":\"" + String(val) + "\"";
  val = getDataByIndex(DATA_INDEX_CO2_AUTO_LOW);
  message += ",\"CO2Low\":\"" + String(val) + "\"";

  val = getDataByIndex(DATA_INDEX_TEMPERATUREF);
  message += ",\"temperatureF\":\"" + String(val / 100) + "." + String(val % 100) + "f\"";
  val = getDataByIndex(DATA_INDEX_TEMPERATUREC);
  message += ",\"temperatureC\":\"" + String(val / 100) + "." + String(val % 100) + " c\"";
  

  val = getDataByIndex(DATA_INDEX_HUMIDITY);
  message += ",\"humidity\":\"" + String(val/100) + "\"";

  val = getDataByIndex(DATA_INDEX_HUMIDITY_AUTO_HIGH);
  message += ",\"humidityHigh\":\"" + String(val/100) + "\"";
  val = getDataByIndex(DATA_INDEX_HUMIDITY_AUTO_LOW);
  message += ",\"humidityLow\":\"" + String(val/100) + "\"";

  val = getDataByIndex(DATA_INDEX_DWC1_PH);
  message += ",\"dwc1Ph\":\"" + String(val / 100) + "." + String(val % 100) + "\"";
  val = getDataByIndex(DATA_INDEX_DWC1_TEMPERATURE);
  message += ",\"dwc1Temp\":\"" + String(val / 100) + "." + String(val % 100) + " c\"";
  val = getDataByIndex(DATA_INDEX_DWC1_TDS);
  message += ",\"dwc1Tds\":\"" + String(val/100) + " PPM\"";
  
  val = getDataByIndex(DATA_INDEX_DWC1_TEMPERATURE_AUTO_STATUS);
  if (val > 0) {
    message += ",\"dwc1TempAuto\":\"on\"";
  } else {
    message += ",\"dwc1TempAuto\":\"off\"";
  }

  val = getDataByIndex(DATA_INDEX_DWC1_TEMPERATURE_AUTO_LOW);
  message += ",\"dwc1TempLow\":\"" + String(val / 100) + "." + String(val % 100) + " c\"";

  val = getDataByIndex(DATA_INDEX_DWC1_TEMPERATURE_AUTO_HIGH);
  message += ",\"dwc1TempHigh\":\"" + String(val / 100) + "." + String(val % 100) + " c\"";

  val = getDataByIndex(DATA_INDEX_DWC1_LEVEL);
  if (val > 0) {
    message += ",\"dwc1Level\":\"High\"";
  } else {
    message += ",\"dwc1Level\":\"Low\"";
  }

  val = getDataByIndex(DATA_INDEX_DWC2_PH);
  message += ",\"dwc2Ph\":\"" + String(val / 100) + "." + String(val % 100) + "\"";
  val = getDataByIndex(DATA_INDEX_DWC2_TEMPERATURE);
  message += ",\"dwc2Temp\":\"" + String(val / 100) + "." + String(val % 100) + " c\"";
  val = getDataByIndex(DATA_INDEX_DWC2_TDS);
  message += ",\"dwc2Tds\":\"" + String(val/100) + " PPM\"";


  
  val = getDataByIndex(DATA_INDEX_DWC2_TEMPERATURE_AUTO_STATUS);
  if (val > 0) {
    message += ",\"dwc2TempAuto\":\"on\"";
  } else {
    message += ",\"dwc2TempAuto\":\"off\"";
  }
  val = getDataByIndex(DATA_INDEX_DWC2_TEMPERATURE_AUTO_LOW);
  message += ",\"dwc2TempLow\":\"" + String(val / 100) + "." + String(val % 100) + " c\"";
  val = getDataByIndex(DATA_INDEX_DWC2_TEMPERATURE_AUTO_HIGH);
  message += ",\"dwc2TempHigh\":\"" + String(val / 100) + "." + String(val % 100) + " c\"";
  val = getDataByIndex(DATA_INDEX_DWC1_LEVEL);
  if (val > 0) {
    message += ",\"dwc2Level\":\"High\"";
  } else {
    message += ",\"dwc2Level\":\"Law\"";
  }

  Serial.println("Get Request: "+message);
  //      val = getDataByIndex(DATA_INDEX_DWC2_PPM_24HOUR + getCurrentHour());
  //      message += ",\"dwc2PPM\":\"" + String(val) + "\"";
  //
  //      message += ",\"\"dwc1Temp7Days\":" + getDataArrayByIndex(DATA_INDEX_DWC1_TEMPERATURE_7DAY, 7 ) ; //Requesting 7 data
  //      message += ",\"\"dwc1Temp24Hour\":" + getDataArrayByIndex(DATA_INDEX_DWC1_TEMPERATURE_24HOUR, 12 ); // 24
  //      message += ",\"\"dwc1PPM7Days\":" + getDataArrayByIndex(DATA_INDEX_DWC1_PPM_7DAY, 7 ) ;   //14
  //      message += ",\"\"dwc1PPM24Hour\":" + getDataArrayByIndex(DATA_INDEX_DWC2_PPM_24HOUR, 12 ) ;   //24
  //
  //      message += ",\"\"dwc2Temp7Days\":" + getDataArrayByIndex(DATA_INDEX_DWC2_TEMPERATURE_7DAY, 7 );   //14
  //      message += ",\"\"dwc2Temp24Hour\":" + getDataArrayByIndex(DATA_INDEX_DWC2_TEMPERATURE_24HOUR, 12 );   //14
  //      message += ",\"\"dwc2PPM7Days\":" + getDataArrayByIndex(DATA_INDEX_DWC2_PPM_7DAY, 7 );   //14
  //      message += ",\"\"dwc2PPM24Hour\":" + getDataArrayByIndex(DATA_INDEX_DWC2_PPM_24HOUR, 12 );   //14

  message += getHistory();
  message += "}";

//  Serial.println("Respond to get env param : "+message);

  server.send(200, "text/plain", message);
}
String getHistory(){
  String str;
  
  
  for(int tote = 0; tote<=1; tote++ ){
    str += ",\"dwc" + String(tote+1) + "PH7Day\":"; //Requesting 7 data
    str += "[";
    for(int i =0; i<7; i++) {
      int a = _7DayDWCPh[tote][i]/100;
      int b = _7DayDWCPh[tote][i]%100;
      str +=  "\"Day "+String(i+1)+"  pH "+String(a) + "."+(b<10 ? ("0"+String(b)) : String(b))+" ""\"";
      if(i<6)  str += + ", ";
    }
    str += "]";

   str += ",\"dwc" + String(tote+1) + "TDS7Day\":"; //Requesting 7 data
    str += "[";
    for(int i =0; i<7; i++) {
      str +=  "\"Day "+String(i+1)+"   "+String(_7DayDWCTDS[tote][i])+" "+" PPM\"";
      if(i<6)  str += + ", ";
    }
    str += "]";

   str += ",\"dwc" + String(tote+1) + "Temp24Hour\":"; //Requesting 7 data
    str += "[";
    for(int i =0; i<24; i++) {
      int temp = _24HourDWCTemperature[tote][i];
      str += "\""+String(i+1)+" "+(i<12 ? "AM":"PM")+"  "+String(temp/100)+"."+String(temp%100)+"'C \"";
      if(i<23)  str += + ", ";
    }
    str += "]";
  }
//Serial.println("history record = "+str);
  return str;
}
