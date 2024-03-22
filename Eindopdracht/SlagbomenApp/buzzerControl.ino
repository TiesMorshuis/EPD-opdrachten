const int buzzerPin = 9;
long previousMillis;
void buzzerControl_Setup(){
  pinMode(buzzerPin, OUTPUT);
}

void buzzerControl_buzzerGeluidAfspelen(String patroon){
  switch(patroon){
    case 'TIKKEN';
      unsigned long currentMillis = millis();
        if (currentMillis - previousMillis < 100){
          previousMillis = currentMillis;
          tone(buzzerPin 400, 50);
        }
      break;
    case 'UIT';
      digitalWrite(buzzerPin, LOW);
  }
}

