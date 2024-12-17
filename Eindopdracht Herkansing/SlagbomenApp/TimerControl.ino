long previousMillis;

boolean TimerControl_Timer(int interval){
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval){
    previousMillis = currentMillis;
    return true;
  } else {
    return false;
  }
}