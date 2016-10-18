#include <Wire.h>

#include <SD.h>                      // need to include the SD library
#define SD_ChipSelectPin 4  //using digital pin 4 on arduino nano 328, can use other pins
#include <TMRpcm.h>           //  also need to include this library...
#include <SPI.h>

TMRpcm tmrpcm;   // create an object for use in this sketch

boolean isSoundPlayed = false;
int recv_data = 0;

void setup() {
  pinMode(13, OUTPUT);
  
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  
  Serial.begin(9600);           // start serial for output

  tmrpcm.speakerPin = 9;
  
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");
    return;   // don't do anything more if not
  }
  tmrpcm.play("alert.wav");
}

void loop() {
}

void receiveEvent(int howMany) {
  recv_data = Wire.read();
  Serial.println(recv_data);         // print the integer
  
  switch(recv_data){
    case 0:
//      tmrpcm.play("alert.wav");
      break;
    case 1:
      tmrpcm.play("bullet.wav");
      break;
    case 2:
      tmrpcm.play("laser.wav");
      break;
    case 3:
      tmrpcm.play("charge.wav");
      break;
    case 4:
      tmrpcm.pause();
      break;
    case 5:
      tmrpcm.stopPlayback();
      break;
    case 6:
      tmrpcm.volume(1);
      break;
    case 7:
      tmrpcm.volume(0);
      break;
    default: break;
    }
}
