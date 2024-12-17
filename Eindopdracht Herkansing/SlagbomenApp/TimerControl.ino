long previousMillis;

boolean timerControl_timer(int interval){
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval){
    previousMillis = currentMillis;
    return true;
  } else {
    return false;
  }
}