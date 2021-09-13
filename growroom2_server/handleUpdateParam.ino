
void handleUpdateEnvParam() {
  Serial.print("update param is called, msg : \n");
  if (server.method() != HTTP_POST) {
    Serial.println("Method not a POST request.");
    server.send(405, "text/plain", "Method Not Allowed");
  } else {
    String message = "Received update request, updting data array : \n";
    for (uint8_t i = 0; i < server.args(); i++) {
      
      String paramName = server.argName(i);
      String paramVal = server.arg(i);

Serial.print("Params : "+String(paramName) + " "+String(paramVal));
      if(isNumeric(paramName) && isNumeric(paramVal)) {
        
        int index = paramName.toInt();
        int val1 = paramVal.toInt()/100;
        int val2 = paramVal.toInt()%100;
        setDataByIndex(index, paramVal.toInt());

Serial.println(" val1 : "+String(val1) + " , val2 : "+String(val2));

        Wire.beginTransmission(I2C_SLAVE); // transmit to device #9 (0x2c)
        Wire.write(index);
        Wire.write(val1);
        Wire.write(val2);    
        Wire.endTransmission();
        
        Serial.print("Set index "+paramName+" to "+String(paramVal));
        Serial.println(getDataByIndex(index));

        if(index<0||index>31) continue;
        setDataByIndex(index,paramVal.toInt());

        message += "Index " + paramName + " set to "+String(getDataByIndex(index)+"\n");
      } else if(paramName == "t") {
        int hour = paramVal.toInt()/100;
        int minute = paramVal.toInt()%100;
        time1.setNow(hour, minute);
        
        Wire.beginTransmission(I2C_SLAVE); // transmit to device #9 (0x2c)
        Wire.write(hour);    
        Wire.write(minute);    
        Wire.endTransmission();
        Serial.print("Set time to "+String(hour)+":"+String(minute));
      } else if(paramName == "ymd") {
        int year = paramVal.toInt()/10000;
        int month = (paramVal.toInt()-year*10000)/100%12;
        int day = paramVal.toInt()-year*10000-month*100;
        
        time1.setYearMonthDay(year, month, day);
        Serial.print("Set mmddyy to "+String(month)+"/"+String(day)+"/"+String(year));
        Wire.beginTransmission(I2C_SLAVE); // transmit to device #9 (0x2c)
        Wire.write(year/100);
        Wire.write(year%100);
        Wire.write(month);
        Wire.write(day); 
        Wire.endTransmission();
      }
    } 
//    sendDataToSensorBoard();
    
    server.send(200, "text/plain", message);
  }
}
bool isNumeric(String str) {
  if(str.length() == 0) return false;
  for(int i =0, len = str.length(); i < len ; i ++ ){
    if( !isDigit(str.charAt(i)) ) {
      Serial.println(" Not digit : ["+str+"]");
      return false;
    }
  }
  
  return true;
}
