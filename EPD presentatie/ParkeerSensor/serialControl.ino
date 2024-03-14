char versnellingGelezen;

void serialControl_Setup() {
  Serial.begin(9600);
}

void serialControl_AfstandPrinten(float distance) {
  if (distance < 100) {
    Serial.print("Distance: ");
    Serial.println(distance);
  }
}

char serialControl_leesVersnelling() {
  if (Serial.available() > 0) {
    versnellingGelezen = Serial.read();
    Serial.print(versnellingGelezen);
  }
  return versnellingGelezen;
}