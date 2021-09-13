void initData() {
  for(int curBuffer = 0; curBuffer< dataBufferArraySize; curBuffer++) {
    for(int currentData = 0; currentData< I2C_TRANSMISSION_SIZE; currentData++) {
      data[curBuffer][currentData] = -1;
    }
  }
}

String getDataArrayByIndex(int dataIndex, int totalDataRequested) {
  String message;
  message += "[";

  for (int current = 0; current < totalDataRequested; current ++) {
    int val =
      ((data[ dataIndex / I2C_TRANSMISSION_SIZE ][ dataIndex % I2C_TRANSMISSION_SIZE]) << 8 ) &
      (data[ dataIndex / I2C_TRANSMISSION_SIZE ][ dataIndex % I2C_TRANSMISSION_SIZE + 1]);
    if (val > 9) {
      message += "0";
    }
    message += String(val);

    if (current < totalDataRequested - 1) {
      message += ",";
    }
  }
  message += "]";
  return message;
}

int getDataByIndex(int dataIndex ) {
  int a = (dataIndex*2)/I2C_TRANSMISSION_SIZE;
  int b = (dataIndex*2)%I2C_TRANSMISSION_SIZE;
//  String val;
  int val = 
        (int)data[a][b] * 100 +
        (int)data[a][b+1];
  
  return val;
}
void setDataByIndex(int dataIndex, int val) {
  
  data[(dataIndex*2)/I2C_TRANSMISSION_SIZE][(dataIndex*2)%I2C_TRANSMISSION_SIZE] = val/100;
  data[(dataIndex*2)/I2C_TRANSMISSION_SIZE][(dataIndex*2)%I2C_TRANSMISSION_SIZE+1] = val%100;
}


void readDataFromSensorBoard() {

  Serial.println(" --- Read data from sensor board --- ");

  
  for (int arrIndex = 0; arrIndex < dataBufferArraySize; arrIndex++) {
    bufferIndex = arrIndex;
    Wire.beginTransmission(I2C_SLAVE); // transmit to device #9 (0x2c)
    Wire.write(bufferIndex);    // set index
    Wire.endTransmission();
    
    delay(100);
    
    Serial.println("Read buffer "+String(bufferIndex)+" : ");
    Wire.requestFrom(I2C_SLAVE, I2C_TRANSMISSION_SIZE);
    
    for (int index = 0; index < I2C_TRANSMISSION_SIZE; index++) {

      data[bufferIndex][index]  =Wire.read();
      Serial.print((int)data[bufferIndex][index]);
      if(index%2 == 1)Serial.print(" ");
    }

    delay(100);
  }
//  Serial.println("After update: ");
//  printData();
//  
//  Serial.println(" --- End --- ");
  Serial.println();
}
void printData() {
  Serial.println("Printing data : ")  ;
  for(int j = 0; j<2; j++)
    for(int i =0; i< I2C_TRANSMISSION_SIZE; i++){
      Serial.print(data[j][i]);
      if(i%2==1)Serial.print(" ");
      if(i%8==7)Serial.println();
    }
  Serial.println()  ;
}


/* Forward server's update request to Mega */
void sendDataToSensorBoard() {
  for(int currentBuffer =0; currentBuffer< dataBufferArraySize; currentBuffer++) {
    // 1. Update buffer index 
      Wire.beginTransmission(I2C_SLAVE); // transmit to device #9 (0x2c)
      Wire.write(currentBuffer);  // forward request to MEGA
      Wire.endTransmission();
      delay(20);
      
      Serial.println(" --- Sending buffer "+String(currentBuffer)+" to Sensor board : " );
      Wire.beginTransmission(I2C_SLAVE); // transmit to device #8 
  
      for(int i =0; i<32; i++) {
          Wire.write(data[bufferIndex][i]);
          Serial.print(data[bufferIndex][i]);
          if(i%2 == 1)
            Serial.print(" ");
      }
      Wire.endTransmission();
      Serial.println(" ---  End --- ");
      
      
  }
  Serial.println();
}
