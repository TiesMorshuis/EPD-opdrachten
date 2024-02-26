const int LICHTSENSOR_PIN = A2;

void lichtSensor_Setup(){
  pinMode(LICHTSENSOR_PIN, INPUT);
}

int lichtSensor_getLichtSterkte(){
  int sensorWaarde = analogRead(LICHTSENSOR_PIN);
  int lichtSterkte = map(sensorWaarde, 0, 1023, 0, 126);
  return lichtSterkte;
}