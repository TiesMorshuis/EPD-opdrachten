#include <Servo.h>
const int servoPin = 8;
Servo servo;



long previousMillis;





void setup(){
  // slagboomControl_setup();
  Serial.begin(9600);
}

void loop(){
  Serial.print("State");
}



boolean timerControl_timer(int interval){
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval){
    previousMillis = currentMillis;
    return true;
  } else {
    return false;
  }
}
