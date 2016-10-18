void receiveSonic(){
  sonicVal = analogRead(SONIC_RECEIVE_PIN);
  if(sonicVal >= 590){
    isAttacked = true;
  }else{
    isAttacked = false;
  }
}
