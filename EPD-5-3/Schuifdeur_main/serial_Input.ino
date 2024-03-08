void serialInput_Setup() {
  Serial.begin(9600);
}
// --- Events -----------
boolean serialInput_Received() {
  int value = Serial.read();
  if (value > -1) {
    return true;
  } else {
    return false;
  }
}