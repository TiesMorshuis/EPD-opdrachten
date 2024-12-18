// Module ButtonHardware
// Configuratie en uitlezen van de fysieke knop

int BUTTON_PIN_Array[4] = {A0, A1, A2, A3};
// --- Setup -------------------
void buttonHardware_Setup() {
  for (int i = 0; i < 4; i++){
  pinMode(BUTTON_PIN_Array[i], INPUT);
  }
}
// --- Events -----------
boolean buttonHardware_Down(int index) {
  // Pull up resistor used.
  return (digitalRead(BUTTON_PIN_Array[index]) == LOW);
  // if pull down resistor is used, compare to HIGH
}
boolean buttonHardware_Up(int index) {
  return !buttonHardware_Down(index);
}