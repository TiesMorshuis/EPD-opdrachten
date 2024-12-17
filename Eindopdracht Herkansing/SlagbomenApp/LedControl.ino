const int ledArray [] {2, 3, 4, 5, 6, 7};

void ledControl_Setup(){
  for (int arrayIndex = 0; sizeof(ledArray); arrayIndex++){
    pinMode(ledArray[arrayIndex], OUTPUT);
  }
}

void ledControl_LedAan(int pinNummer){
  digitalWrite(pinNummer, HIGH);
}

void ledControl_LedUit(int pinNummer){
  digitalWrite(pinNummer, LOW);
}

void ledControl_alleLedAan(){
  for (int arrayIndex = 0; sizeof(ledArray); arrayIndex++){
    digitalWrite(ledArray[arrayIndex], HIGH);
  }
}

void ledControl_alleLedUit(){
  for (int arrayIndex = 0; sizeof(ledArray); arrayIndex++){
    digitalWrite(ledArray[arrayIndex], LOW);
  }
}

void ledControl_LedKnipperen(int pinNummer){
  if (TimerControl_Timer(800) == true){
      digitalWrite(pinNummer, LOW);
      if (TimerControl_Timer(800) == true){
        digitalWrite(pinNummer, HIGH);
      }
  }
}