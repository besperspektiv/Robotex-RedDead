int readMedian (int samples) {
  // массив для хранения данных
  int raw[samples];
  // считываем вход и помещаем величину в ячейки массива
  for (int i = 0; i < samples; i++) {
    float volts = analogRead(sensor_front_Pin) * 0.0048828125; // value from sensor * (5/1024)
    int distance_Front = 29 * pow(volts, -1); // worked out from datasheet graph
    raw[i] = distance_Front;
  }
  // сортируем массив по возрастанию значений в ячейках
  int distance_Front = 0; // временная переменная

  for (int i = 0; i < samples; i++) {
    for (int j = 0; j < samples - 1; j++) {
      if (raw[j] > raw[j + 1]) {
        distance_Front = raw[j];
        raw[j] = raw[j + 1];
        raw[j + 1] = distance_Front;
      }
    }
  }
  return raw[samples / 2];
}
