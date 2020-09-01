void Serial_Print(){
//  Serial.print(" Left = ");
//  Serial.print(distance_left);
//  Serial.print(" Rigt = ");
//  Serial.print(distance_right);
//  Serial.print(" Front = ");
//  Serial.print(distance_front);
//  Serial.print(" SpeedAA = ");
//  Serial.print(SpeedAA);
//  Serial.print(" SpeedBB = ");
//  Serial.print(SpeedBB);
//  Serial.print(" Setpoint = ");
//  Serial.print(Right_sensor_PID.setpoint);
//  Serial.print(" Output = ");
//  Serial.print(Right_sensor_PID.getResultTimer());
//  Serial.print(" SpeedAA = ");
//  Serial.print(SpeedAA);
//  Serial.print(" SpeedBB = ");
//  Serial.print(SpeedBB);
//
//  //MPU6050
//  Serial.print    ("y\t");
//  Serial.print    (ypr[0] * 180 / M_PI); Serial.print(" ");
//  Serial.print    (ypr[1] * 180 / M_PI); Serial.print(" ");
//  Serial.println  (ypr[2] * 180 / M_PI);
//  
  if(true){
//    mySerial.print(" Left = ");
//    mySerial.print(distance_left);
//    mySerial.print(" Rigt = ");
//    mySerial.print(distance_right);
//    mySerial.print(" Front = ");
//    mySerial.print(distance_front);
//    mySerial.print(" SpeedAA = ");
//    mySerial.print(SpeedAA);
//    mySerial.print(" SpeedBB = ");
//    mySerial.print(SpeedBB);
//    mySerial.print(" Setpoint = ");
//    mySerial.print(Right_sensor_PID.setpoint);
//    mySerial.print(" Output = ");
//    mySerial.print(Right_sensor_PID.getResultTimer());
//    mySerial.print(" SpeedAA = ");
//    mySerial.print(SpeedAA);
//    mySerial.print(" SpeedBB = ");
//    mySerial.print(SpeedBB);

    //MPU6050
    y = ypr[0] * 180 / M_PI;
    Serial.print    ("y\t");
    Serial.print    (y); Serial.print(" ");
//    mySerial.print    (ypr[1] * 180 / M_PI); Serial.print(" ");
//    mySerial.println  (ypr[2] * 180 / M_PI);
  }
  mySerial.println();
  Serial.println();
}
