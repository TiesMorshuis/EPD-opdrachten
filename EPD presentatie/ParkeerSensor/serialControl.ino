void serialControl_Setup() {
  Serial.begin(9600);
}

void serialControl_AfstandPrinten(float distance) {
  Serial.print("Distance: ");
  Serial.println(distance);
}