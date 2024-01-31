void lampjeBranden (){
  if (Serial.available() < 0){
    char pin = Serial.read();
    Serial.println(pin);
    if (pin == 6) {
      CONTROLLED_ON(pin);
      Serial.println(pin);
    }
  }
}