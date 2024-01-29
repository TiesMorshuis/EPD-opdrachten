const int led_pin = 13


  void
  setup() {
  pinMode(led_pin, OUTPUT);
}
void loop() {
  //knipperen_geen_for()
  knipperen_met_for(1000, 1)
  knipperen_met_for(500, 2)
}