void Police(int o) {
  if (o == 1) {
    Serial.print(" Police ");
    if (millis() - timing > 100) {
      digitalWrite(R, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(G, LOW);
    }
    if (millis() - timing > 200) {
      digitalWrite(R, LOW);
      digitalWrite(B, HIGH);
      timing = millis();
    }
  } else {
    digitalWrite(R, LOW);
    digitalWrite(B, LOW);
    digitalWrite(G, LOW);
  }
}
