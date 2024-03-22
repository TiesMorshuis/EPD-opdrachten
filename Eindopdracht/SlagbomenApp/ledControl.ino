const int numberOfLeds = 6;
const int ledArray[] = {2, 3, 4, 5, 6, 7};
long previousMillis;

void ledControl_Setup(){
  for (int index = 0; index < ledArray.length, index++){
    pinMode(ledArray[index], OUTPUT);
  }
}

void ledControl_ledAan(int pinNummer){
  digitalwrite(pinNummer, HIGH);
}

void ledControl_ledUit(int pinNummer){
  digitalWrite(pinNummer, LOW);
}

void ledControl_ledLatenKnipperen(int pinNummer){
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > 200) {
    previousMillis = currentMillis;

  }
}