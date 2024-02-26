

void setup() {
  lichtSensor_Setup();
  temperatuurSensor_Setup();
  windrichtingSensor_Setup();
  weerControle_Setup();
  display_Setup();
}

void loop() {
  float temperatuur = temperatuurSensor_getTemperatuur();
  char windrichting = windrichtingSensor_getWindrichting();
  int lichtSterkte = lichtSensor_getLichtSterkte();
  
  display_Set(windrichting);

  weerControle_verstuur(windrichting, lichtSterkte, temperatuur);
}
