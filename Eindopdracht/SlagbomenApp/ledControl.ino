const int numberOfLeds = 6;                   // Om de leds samen met de array te initialiseren
const int ledArray[] = { 2, 3, 4, 5, 6, 7 };  // om samen met het aantal leds de leds te initialiseren
int ledStand = 1;                             //defaultwaarde voor het laten knipperen
const int ledControlInterval = 200;           //Interval voor de knipperende ledjes

void ledControl_Setup() {
  for (int index = 0; index < ledControl_getLedArrayLength(); index++) {
    pinMode(ledArray[index], OUTPUT);
  }
}

void ledControl_ledAan(int pinNummer) {
  digitalWrite(pinNummer, HIGH);
}

void ledControl_ledUit(int pinNummer) {
  digitalWrite(pinNummer, LOW);
}

void ledControl_ledLatenKnipperen(int pinNummer) {
  if (timerControl_isTimerAfgegaan(ledControlInterval) == true) {
    switch (ledStand) {
      case '1':
        digitalWrite(pinNummer, LOW);
        ledStand = 2;
        break;
      case '2':
        digitalWrite(pinNummer, HIGH);
        ledStand = 1;
        break;
    }
  }
}

int ledControl_getLedArrayLength() {
  int lengte = sizeof(ledArray);
  return lengte;
}