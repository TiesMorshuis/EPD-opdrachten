

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
  for (int i = 0; i < 200; i++) {
    servo.write(i);
    delay(15);  // dit mag natuurlijk niet, en dat gaan we in de lessen
    // dan ook oplossen!
  }
}
