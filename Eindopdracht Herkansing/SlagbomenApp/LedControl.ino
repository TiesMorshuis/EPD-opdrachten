const int ledArray [] {2, 3, 4, 5, 6, 7};

void ledControl_setup(){
  for (int arrayIndex = 0; sizeof(ledArray); arrayIndex++){
    pinMode(ledArray[arrayIndex], OUTPUT);
  }
}

void ledControl_ledAan(int pinNummer){
  digitalWrite(pinNummer, HIGH);
}

void ledControl_ledUit(int pinNummer){
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