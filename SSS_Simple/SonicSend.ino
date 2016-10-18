void setupSendSonic(){
  pinMode(buttonPin, INPUT);
  pinMode(SONIC_SEND_PIN, OUTPUT);
}

void sendSonic(){
  tone(SONIC_SEND_PIN,40000);
  delay(100);
  noTone(SONIC_SEND_PIN);
}

void stopSonic(){
  noTone(SONIC_SEND_PIN);
}
