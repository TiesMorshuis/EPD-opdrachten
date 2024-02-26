const int WINDRICTHINGSENSOR_PIN = A1;

void windrichtingSensor_Setup() {
  pinMode(WINDRICTHINGSENSOR_PIN, INPUT);
}

char windrichtingSensor_getWindrichting(){
  char windrichting = 'X';
  int sensorWaarde = analogRead(WINDRICTHINGSENSOR_PIN);
  int nieuwSensorWaarde = map(sensorWaarde, 0, 1023, 0, 359);
    if (nieuwSensorWaarde >= 315 || nieuwSensorWaarde < 45){
    windrichting = 'N';
  } else if (nieuwSensorWaarde >= 45 && nieuwSensorWaarde < 135){
    windrichting = 'O';
  } else if (nieuwSensorWaarde >= 135 && nieuwSensorWaarde < 225){
    windrichting = 'Z';
  } else if (nieuwSensorWaarde >= 225 && nieuwSensorWaarde < 315){
    windrichting = 'W';
  }

  return windrichting;
}

