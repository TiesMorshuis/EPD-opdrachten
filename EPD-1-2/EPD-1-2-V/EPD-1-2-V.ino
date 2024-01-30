 void setup() {
  const int LEDCONTROL_PINARRAY = LEDCONTROL_GET_PINARRAY();
  const int LEDCONTROL_NUMBEROFLEDS = LEDCONTROL_GET_NUMBEROFLEDS();
  LEDCONTROL_SETUP(LEDCONTROL_NUMBEROFLEDS);
  const int hz = 3;
}

void loop() {
  // put your main code here, to run repeatedly:
  int tijd = tijd_berekenen(3);
  heen_en_weer(LEDCONTROL_PINARRAY[0], LEDCONTROL_NUMBEROFLEDS, tijd);
}
