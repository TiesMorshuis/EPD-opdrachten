void knipperen_geen_for() {
  digitalWrite(led_pin, HIGH);
  delay(1000);
  digitalWrite(led_pin, LOW);
  delay(1000);
  digitalwrite(led_pin, HIGH);
  delay(500);
  digitalwrite(led_pin, LOW);
  delay(500);
  digitalwrite(led_pin, HIGH);
  delay(500);
  digitalwrite(led_pin, LOW);
  delay(500);
}

void knipperen_met_for(int tijd, int j) {
  for (int i = 0; i < j, i++ ){
    digitalwrite(led_pin, HIGH);
    delay(tijd)
    digitalwrite(led_pin, LOW);
    delay(tijd)
  }
}