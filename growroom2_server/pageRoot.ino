
void handleRoot() {

  Serial.println("Start handleRoot");

  char temp[700];
  int sec = millis() / 1000;
  int hr = time1.getHour();
  int minute = time1.getMinute();

  int y = time1.getYear();
  int m = time1.getMonth();
  int d = time1.getDay();

  snprintf(temp, 700,
"<html>\
<head>\
<title>ESP8266 Demo</title>\
<link rel='stylesheet' href='/homepagecss.css'></style>\
</head>\
<body>\
<h1>Hello from ESP8266!</h1>\
<p>Data from Sensors:</p>\
<p>Time: %02d/%02d/%02d %02d:%02d:%02d</p>\
<img src='/test.svg' />\
<div id='content'>test</div>\
<script src='/homepagejs.js'></script>\
</body>\
</html>"
           ,
           m,d,y,hr, minute % 60, sec % 60
          );
  server.send(200, "text/html", temp);
  Serial.println("End heandleRoot");
}
