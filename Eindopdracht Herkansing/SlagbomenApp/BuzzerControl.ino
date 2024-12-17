int buzzerPin = 9;
int buzzerFrequentie, buzzerDuratie, buzzerInterval;

void buzzerControl_Setup(){
  pinMode(buzzerPin, OUTPUT);
}

void buzzerControl_buzzerTikken(char patroon){
  switch (patroon){
    case 'snel':
        buzzerInterval = 1;//todo
        buzzerDuratie = 1;//todo
        buzzerFrequentie = 1;//todo
        if (TimerControl_Timer(buzzerInterval) == true){
          tone(buzzerPin, buzzerFrequentie, buzzerDuratie);
        }
        break;
    case 'aftellen':
        buzzerInterval = 1;//todo
        buzzerDuratie = 1;//todo
        buzzerFrequentie = 1;//todo
        if (TimerControl_Timer(buzzerInterval) == true){
          tone(buzzerPin, buzzerFrequentie, buzzerDuratie);
        }
        break;
    case 'stop':
      digitalWrite(buzzerPin, LOW);
      break;
  }
}