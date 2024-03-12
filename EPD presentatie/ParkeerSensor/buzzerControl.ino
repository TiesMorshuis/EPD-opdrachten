const int buzzerPin = 3;

void buzzerControl_Setup(){
    pinMode(buzzerPin, OUTPUT);
}

void buzzerControl_BuzzerGeluidAfspelen(int interval){
  tone(buzzerPin, 400, 50);
  delay(interval);
}