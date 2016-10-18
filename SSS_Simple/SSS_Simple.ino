String com = " , ";
boolean isShooting = false;

//EMS
const int EMS_PIN = 2;

// SOINIC RECEIVE
const int SONIC_RECEIVE_PIN = A0;
int sonicVal = 0;
boolean isAttacked = false;

// SONIC SEND
const int SONIC_SEND_PIN = 13;

// BUTTON
int buttonState;
const int buttonPin = 12;

void setup() {
  Serial.begin(9600);

  setupEMS();
  setupSendSonic();
}

void loop() {
  
  buttonState = digitalRead(buttonPin);
  sonicVal = analogRead(SONIC_RECEIVE_PIN);
  
  if(sonicVal > 500){
    isAttacked = true;
    sendShock();
  }else{
    isAttacked = false;
  }
  
  if(buttonState == LOW){
      isShooting = true;
      sendSonic();
      sendPulse();
  }else{
      isShooting = false;
      stopPulse();
      stopSonic();
  }
  
  Serial.println(sonicVal);
//  Serial.println(buttonState);
//Serial.println(isShooting);
//Serial.println(isAttacked);
}
