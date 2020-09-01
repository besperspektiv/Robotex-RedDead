void Move_Forvard() {                       //moving forvard
  analogWrite(AA_PWM_Motor, SpeedAA);
  digitalWrite(AA_1_Motor, LOW);
  digitalWrite(AA_2_Motor, HIGH);

  analogWrite(BB_PWM_Motor, SpeedBB);
  digitalWrite(BB_1_Motor, LOW);
  digitalWrite(BB_2_Motor, HIGH);
}
void Move_Backvard() {                       //moving backvard
  analogWrite(AA_PWM_Motor, SpeedBB);
  digitalWrite(AA_1_Motor, HIGH);
  digitalWrite(AA_2_Motor, LOW);

  analogWrite(BB_PWM_Motor, SpeedAA);
  digitalWrite(BB_1_Motor, HIGH);
  digitalWrite(BB_2_Motor, LOW);
}
void Stop_Moving() {                       //Stop moving
  SpeedBB = 255;
  SpeedAA = 255;
  Serial.print(" Stop ");
  analogWrite(AA_PWM_Motor, SpeedAA);
  digitalWrite(AA_1_Motor, HIGH);
  digitalWrite(AA_2_Motor, HIGH);
  analogWrite(BB_PWM_Motor, SpeedBB);
  digitalWrite(BB_1_Motor, HIGH);
  digitalWrite(BB_2_Motor, HIGH);
}
void Rotate_Right() {                       //Rotating right
  //analogWrite(AA_PWM_Motor, 125);
  digitalWrite(AA_1_Motor, LOW);
  digitalWrite(AA_2_Motor, HIGH);

  //analogWrite(BB_PWM_Motor, 125);
  digitalWrite(BB_1_Motor, HIGH);
  digitalWrite(BB_2_Motor, LOW);
}
void Rotate_Left() {                       //Rotating left
  //analogWrite(AA_PWM_Motor, 125);
  digitalWrite(AA_1_Motor, HIGH);
  digitalWrite(AA_2_Motor, LOW);

  //analogWrite(BB_PWM_Motor, 125);
  digitalWrite(BB_1_Motor, LOW);
  digitalWrite(BB_2_Motor, HIGH);
}
