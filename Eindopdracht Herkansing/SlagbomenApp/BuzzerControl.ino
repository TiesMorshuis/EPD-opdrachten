int buzzerPin = 9;
int buzzerFrequentie, buzzerDuratie, buzzerInterval;

void buzzerControl_setup(){
  pinMode(buzzerPin, OUTPUT);
}

void buzzerControl_buzzerTikken(int patroon){
  switch (patroon){
    case '1':
        buzzerInterval = 1;//todo
        buzzerDuratie = 1;//todo
        buzzerFrequentie = 1;//todo
        if (timerControl_timer(buzzerInterval) == true){
          tone(buzzerPin, buzzerFrequentie, buzzerDuratie);
        }
        break;
    case '2':
        buzzerInterval = 1;//todo
        buzzerDuratie = 1;//todo
        buzzerFrequentie = 1;//todo
        if (timerControl_timer(buzzerInterval) == true){
          tone(buzzerPin, buzzerFrequentie, buzzerDuratie);
        }
        break;
    case '0':
      digitalWrite(buzzerPin, LOW);
      break;
  }
}