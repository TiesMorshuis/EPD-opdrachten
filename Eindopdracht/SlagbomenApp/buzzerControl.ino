int buzzerPin = 9;
long buzzerPreviousMillis;
int buzzerInterval = 100;
int buzzerFrequentie = 400;
int buzzerDuratie = 50;


void buzzerControl_Setup() {
  pinMode(buzzerPin, OUTPUT);
}

void buzzerControl_buzzerGeluidAfspelen(int patroon) {
  switch (patroon) {
    case 1:
      if (timerControl_isTimerAfgegaan(buzzerInterval) == true) {
        tone(buzzerPin, buzzerFrequentie, buzzerDuratie);
      }
      break;
    case 2:
      digitalWrite(buzzerPin, LOW);
  }
}
