const int led_pin = 13


void setup() {
  pinMode(led_pin, OUTPUT);
}
void loop() {
  knipperen()
}

void knipperen(){
  digitalWrite(led_pin, HIGH);
  delay(1000);
  digitalWrite(led_pin, LOW);
  delay(1000);
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
}
