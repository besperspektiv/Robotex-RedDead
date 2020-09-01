void Sensors_Read (){
  distance_front = readMedian(10);
  distance_right = sensor_right.getDist();
  distance_left = sensor_left.getDist();
  distance_right = distance_right / 10;
  distance_left = distance_left / 10;
}
