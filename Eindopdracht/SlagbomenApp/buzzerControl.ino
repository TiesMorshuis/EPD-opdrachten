long buzzerPreviousMillis = 0;
int buzzerInterval = 100;
int buzzerFrequentie = 400;
int buzzerDuratie = 50;
int buzzerPin = 9;

void buzzerControl_Setup(){
  pinMode(buzzerPin, OUTPUT);
}

void buzzerControl_buzzerGeluidAfspelen(int patroon){
  switch(patroon){
    case 1:
      unsigned long currentMillis = millis();
        if (currentMillis - buzzerPreviousMillis < buzzerInterval){
          buzzerPreviousMillis = currentMillis;
          tone(buzzerPin, buzzerFrequentie, buzzerDuratie);
        }
      break;
    case 2:
      digitalWrite(buzzerPin, LOW);
  }
}

