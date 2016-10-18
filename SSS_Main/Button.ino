void buttonAction() {
  if (isShooting == true) {
    sendShootingSound();
    sendSonic();
    sendPulse();
    bullet--;
  } else {
    stopPulse();
    stopSonic();
  }
}

void readButtonVal() {
  isShooting = false;
  int buttonState = digitalRead(buttonPin);
  if (lastButtonState == HIGH && buttonState == LOW) {
    int now = millis();
    if ( (now - lastDebounceTime) > debounceDelay ) {
      onPress();
    }
    lastDebounceTime = now;
  }
  lastButtonState = buttonState;
}

void onPress() {
  if (bullet > 0) {
    isShooting = true;
//    count = count + 1;
  }
}

