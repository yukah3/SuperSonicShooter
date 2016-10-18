void setupEMS(){
  pinMode(EMS_PIN, OUTPUT);
}

void sendPulse(){
  digitalWrite(EMS_PIN, HIGH);
  delay(1);
  digitalWrite(EMS_PIN, LOW);
  delay(140);
  digitalWrite(EMS_PIN, HIGH);
  delay(1);
  digitalWrite(EMS_PIN, LOW);
  delay(140);
}

void stopPulse(){
  digitalWrite(EMS_PIN, LOW);
}

void sendShock(){
  digitalWrite(EMS_PIN, HIGH);
  delay(10);
  digitalWrite(EMS_PIN, LOW);
  delay(50);
  digitalWrite(EMS_PIN, HIGH);
  delay(10);
  digitalWrite(EMS_PIN, LOW);
  delay(50);
  digitalWrite(EMS_PIN, HIGH);
  delay(10);
  digitalWrite(EMS_PIN, LOW);
  delay(50);
  digitalWrite(EMS_PIN, HIGH);
  delay(10);
  digitalWrite(EMS_PIN, LOW);
  delay(50);
  digitalWrite(EMS_PIN, HIGH);
  delay(10);
  digitalWrite(EMS_PIN, LOW);
  delay(50);
  digitalWrite(EMS_PIN, HIGH);
  delay(10);
  digitalWrite(EMS_PIN, LOW);
  delay(50);
}
