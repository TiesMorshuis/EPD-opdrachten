// Module ButtonHardware
// Configuratie en uitlezen van de fysieke knop
const int BUTTON_PIN = 10;
// --- Setup -------------------
void buttonHardware_Setup() {
  pinMode(BUTTON_PIN, INPUT);
}
// --- Events -----------
boolean buttonHardware_Down() {
  // Pull up resistor used.
  return (digitalRead(BUTTON_PIN) == LOW);
  // if pull down resistor is used, compare to HIGH
}
boolean buttonHardware_Up() {
  return !buttonHardware_Down();
}