

#include <Servo.h>
const int SERVOPIN = 9;
Servo servo;
void setup() {
  servo.attach(SERVOPIN);
  buttonHardware_Setup();
  button_Setup();
  serialInput_Setup();
}
void loop() {
  button_Loop();
  // Serial.println(getKnopNoordIngedrukt());
  // Serial.println(getKnopOostIngedrukt());
  // Serial.println(getKnopZuidIngedrukt());
  // Serial.println(getKnopWestIngedrukt());
}
