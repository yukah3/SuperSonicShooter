void setupLEDs(){
  for (int i = LED_START_PIN; i <= LED_END_PIN; i++) {      //  iを変えて4回繰り返し
    pinMode(i, OUTPUT);             //　ポートの設定（入力か出力か？）
  }
}

void switchLEDs() {
  // all 5 ON
  if (bullet == MAX_BULLET) {
    for (int i = LED_START_PIN; i <= LED_END_PIN; i++) {
      digitalWrite(i, HIGH);
    }
  }
  
  // 4 ON
  if (bullet >= MAX_BULLET / 4 * 3 && bullet < MAX_BULLET) {
    for (int i = LED_START_PIN + 1; i <= LED_END_PIN; i++) {
      digitalWrite(i, HIGH);
    }
    digitalWrite(LED_START_PIN, LOW);
  }
  
  // 3 ON
  if (bullet >= MAX_BULLET / 4 * 2 && bullet < MAX_BULLET / 4 * 3) {
    for (int i = LED_START_PIN + 2; i <= LED_END_PIN; i++) {
      digitalWrite(i, HIGH);
    }
    for(int i = LED_START_PIN; i <= LED_START_PIN + 1; i++){
      digitalWrite(i, LOW);
    }
  }
  
  // 2 ON
  if (bullet >= MAX_BULLET / 4 && bullet < MAX_BULLET / 4 * 2) {
    for (int i = LED_START_PIN + 3; i <= LED_END_PIN; i++) {
      digitalWrite(i, HIGH);
    }
    for(int i = LED_START_PIN; i <= LED_START_PIN + 2; i++){
      digitalWrite(i, LOW);
    }
  }
  
  // 1 ON
  if (bullet > 0 && bullet < MAX_BULLET / 4) {
    
    digitalWrite(LED_END_PIN, HIGH);
    
    for(int i = LED_START_PIN; i <= LED_START_PIN + 3; i++){
      digitalWrite(i, LOW);
    }
  }
  
  // ALL OFF
  if (bullet == 0) {
    for(int i = LED_START_PIN; i <= LED_END_PIN; i++){
      digitalWrite(i, LOW);
    }
  }
}
