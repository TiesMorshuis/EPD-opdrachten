const int rodePin = 4;
const int gelePin = 5;
const int groenePin = 6;



void setup() {
  ledControl_Setup();
  buzzerControl_Setup();
  afstandSensorControl_Setup();
  serialControl_Setup();
}

void loop() {
  float distance = afstandSensorControl_AfstandBerekenen();
  serialControl_AfstandPrinten(distance);
  if (distance <= 10) {
    ledControl_LedUitzetten(groenePin);
    ledControl_LedUitzetten(gelePin);
    ledControl_LedAanzetten(rodePin);
    if (distance < 3) {
      buzzerControl_BuzzerGeluidAfspelen(0);
    } else if (distance < 6) {
      buzzerControl_BuzzerGeluidAfspelen(100);
    } else if (distance <= 10) {
      buzzerControl_BuzzerGeluidAfspelen(250);
    }
  } else if (distance > 10 && distance < 20) {
    ledControl_LedUitzetten(rodePin);
    ledControl_LedUitzetten(groenePin);
    ledControl_LedAanzetten(gelePin);
    buzzerControl_BuzzerGeluidAfspelen(500);
  } else if (distance >= 20) {
    ledControl_LedUitzetten(rodePin);
    ledControl_LedUitzetten(gelePin);
    ledControl_LedAanzetten(groenePin);
  }
}
