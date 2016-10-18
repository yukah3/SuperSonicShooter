void setupSendSonic(){
   // test button setup
  pinMode(buttonPin, INPUT);
  pinMode(SONIC_SEND_PIN, OUTPUT);
}

void sendSonic(){
  tone(SONIC_SEND_PIN,40000);
}

void stopSonic(){
  noTone(SONIC_SEND_PIN);
}
