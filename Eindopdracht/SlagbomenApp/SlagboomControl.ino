#include <Servo.h>
const int servoPin = 8;
Servo servo;

void slagboomControl_Setup(){
  servo.attach(servoPin);
}
