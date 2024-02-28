#include <Servo.h>
Servo motor; 

const int HZ = 50;
const float DUTY_CYCLE_RED = 0.9;
const int PIN_RED = 8;

const int PERIODE_DUUR = 1000 / HZ;
const int HIGH_TIME_RED = PERIODE_DUUR * DUTY_CYCLE_RED;
const int LOW_TIME_RED = PERIODE_DUUR - HIGH_TIME_RED;

bool stateRed = false;
bool intervalRed = LOW_TIME_RED;
unsigned long previousTimeRed = 0;

void setup() {
  pinMode(PIN_RED, OUTPUT);
  motor.attach(9);
}

void loop() {
    for (int hoek = 0; hoek < 180; hoek++){
  motor.write(hoek);
  delay(10);
    }
  /*unsigned long currentTime = millis();
  if(currentTime >= (previousTimeRed + intervalRed)) {
    if(stateRed == true){
      stateRed = false;
      intervalRed = LOW_TIME_RED;
      digitalWrite(PIN_RED, LOW);
    } else {
      stateRed = true;
      intervalRed = HIGH_TIME_RED;
      digitalWrite(PIN_RED, HIGH);
    }
    previousTimeRed = currentTime;
  }*/
}

