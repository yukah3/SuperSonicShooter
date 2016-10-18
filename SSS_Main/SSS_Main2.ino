#include <Wire.h>
int g;
/********************
MAIN CODE

- SEND EMS PULSE
- SEND SUPER SONIC
- RECEIVE SUPER SONIC
- READ PIEZO
- LOAD BULLET
- LIGHT UP LED
**********************/


String plus = " + ";
String com = " , ";

// BULLET
int MAX_BULLET = 10;
int bullet = MAX_BULLET;
int isChargeOK = false;

//EMS
const int EMS_PIN = 10;

// PIEZO
const int PIEZO_PIN = A3; // Piezo output
float piezoConverted = 0;
int piezoCount = 0;
int prevPiezoCount = 0;
int piezoStaticCount = 0;
boolean isCartridgeFull = false;
int piezoShakeDifference = 20;
int piezoRequireNum = 16;

// SOINIC RECEIVE
const int SONIC_RECEIVE_PIN = A6;
int sonicVal = 0;
int sonicReceiveCounter = 0;
boolean isAttacked = false;
volatile int sonicState = 0;

// SONIC SEND
const int SONIC_SEND_PIN = 3;

// BUTTON
const int buttonPin = 2;
int lastButtonState = LOW;
long lastDebounceTime = 0;
long debounceDelay = 3;
int count;
boolean isButtonOn;

// LED PIN
const int LED_START_PIN = 4;
const int LED_END_PIN = 8;

// I2C
byte x = 0;
boolean isShooting = false;

void setup() {
  Serial.begin(9600);
  
  setupLEDs();
  setupEMS();
  setupSendSonic();
  Wire.begin();
}

void loop() {
  checkChargability();
  
  if(isShooting == false && isAttacked == false && isChargeOK == true){
    readPiezo();
    loadBullet();
  }
  
  receiveSonic();
  
  switchLEDs();
  
  if(isAttacked){
    sendAttackedSound();
    sendShock();
  }else{
    stopPulse();
    readButtonVal();
    buttonAction();
  }
//  Serial.print(bullet);
//  Serial.print(",");
//  Serial.println(isChargeOK);
//  Serial.print(",");
  Serial.println(piezoConverted);
}

// for sending data via serial for the sound effect
void sendSerialData(){
  Wire.beginTransmission(8);
  if (isAttacked) {
    Wire.write(2);
  }
  if (isShooting == true) {
    Wire.write(1);
  }
  Wire.endTransmission();
}

void sendAttackedSound(){
  Wire.beginTransmission(8);
  Wire.write(2);
  Wire.endTransmission();
}

void sendShootingSound(){
  Wire.beginTransmission(8);
  Wire.write(1);
  Wire.endTransmission();
}



