long previousMillis;
long previousMillis2;

boolean timerControl_timer(int interval){
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval){
    previousMillis = currentMillis;
    return true;
  } else {
    return false;
  }
}

boolean timerControl_timer2(int interval){
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis2 > interval){
    previousMillis2 = currentMillis;
    return true;
  } else {
    return false;
  }
}

