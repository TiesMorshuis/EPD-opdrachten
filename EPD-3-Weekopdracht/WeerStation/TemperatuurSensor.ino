const int TEMPERATUURSENSOR_PIN = A0;

void temperatuurSensor_Setup(){
  pinMode(TEMPERATUURSENSOR_PIN, INPUT);
}

float temperatuurSensor_getTemperatuur() {
  const float vout0 = 400;  // sensor output voltage in mV at 0°C
  const float tc = 19.53;   // mV for °C temperature constant
  float vout_avg = 0;
  const int AANTAL_METINGEN = 1000;
  for (int i = 0; i < AANTAL_METINGEN; i++) {
    float vout = analogRead(TEMPERATUURSENSOR_PIN) * (4976.30 / 1023);
    vout_avg = vout_avg + vout;
  }
  float vout = vout_avg / AANTAL_METINGEN;
  return (vout - vout0) / tc;
}