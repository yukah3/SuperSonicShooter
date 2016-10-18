void checkChargability(){
  if(bullet == 0){
    isChargeOK = true;
  }else if(bullet == MAX_BULLET){
    isChargeOK = false;
  }
}

void readPiezo() {
  // Read Piezo ADC value in, and convert it to a voltage
  int piezoADC = analogRead(PIEZO_PIN);
  float piezoV = piezoADC / 1023.0 * 5.0;
  
  piezoConverted = piezoV * 10;
  
  if (piezoConverted > piezoRequireNum) {
    piezoCount++;
  }
}

void loadBullet(){
  // bullet load restriction
  if(bullet >= MAX_BULLET){
    isCartridgeFull = true;
  }else{
    isCartridgeFull = false;
  }
  
  // add bullet to the cartridge
  if(isCartridgeFull == false && piezoCount >= prevPiezoCount + piezoShakeDifference){
    if(bullet > MAX_BULLET / 5 * 4){
      int bulletRemain = MAX_BULLET - bullet;
      bullet += bulletRemain;
    }
    else{
      bullet += MAX_BULLET / 5;
      prevPiezoCount = piezoCount;
    }
    
  }
  
  if (isCartridgeFull == true || isShooting || isAttacked){
    piezoCount = 0;
    prevPiezoCount = 0;
  }
  
}
