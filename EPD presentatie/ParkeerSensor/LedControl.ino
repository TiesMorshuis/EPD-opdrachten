

void ledControl_Setup() {
  pinMode(rodePin, OUTPUT);
  pinMode(gelePin, OUTPUT);
  pinMode(groenePin, OUTPUT);
}

void ledControl_LedAanzetten(int ledNummer){
  digitalWrite(ledNummer, HIGH);
}

void ledControl_LedUitzetten(int ledNummer){
  digitalWrite(ledNummer, LOW);
}

