// Module Button
// --- States -----------

const int BUTTON_STATE_RELEASED = 1;
const int BUTTON_STATE_CHECK_PRESSED = 2;
const int BUTTON_STATE_PRESSED = 3;
const int BUTTON_STATE_CHECK_RELEASED = 4;
int states[4] {BUTTON_STATE_RELEASED, BUTTON_STATE_RELEASED, BUTTON_STATE_RELEASED, BUTTON_STATE_RELEASED};
boolean knopIngedrukt[] {false, false, false, false};
// Current state
int button_State;
// Timer variables
const int BUTTON_INTERVAL = 20;  // 10msec, test your own button
unsigned long button_Previous;
// --- Setup -------------------
void button_Setup() {
  Serial.begin(9600);  // to print "CLICK"
  // Start state
  button_Released_Entry();

}
// --- Loop --------------------
void button_Loop() {
  for(int index = 0; index < 4; index++){
    Serial.println(knopIngedrukt[index]);
  switch (states[index]) {
    case BUTTON_STATE_RELEASED:
      button_Released_Do();
      if (buttonHardware_Down(index) == true) {
        button_Released_Exit();
        states[index] = BUTTON_STATE_CHECK_PRESSED;
        button_Check_Pressed_Entry();
      }
      break;
    case BUTTON_STATE_CHECK_PRESSED:
      button_Check_Pressed_Do();
      if (buttonHardware_Up(index) == true) {
        button_Check_Pressed_Exit();
        states[index] = BUTTON_STATE_RELEASED;
        button_Released_Entry();
      } else if ((buttonHardware_Down(index) == true)
                 && (millis() - BUTTON_INTERVAL >= button_Previous)) {
        button_Check_Pressed_Exit();
        states[index] = BUTTON_STATE_PRESSED;
        button_Pressed_Entry();
      }
      break;
    case BUTTON_STATE_PRESSED:
      button_Pressed_Do();
      if (buttonHardware_Up(index) == true) {
        button_Pressed_Exit();
        states[index] = BUTTON_STATE_CHECK_RELEASED;
        button_Check_Released_Entry();
      }
      break;
    case BUTTON_STATE_CHECK_RELEASED:
      button_Check_Released_Do();
      if (buttonHardware_Down(index) == true) {
        button_Check_Released_Exit();
        states[index] = BUTTON_STATE_PRESSED;
        button_Pressed_Entry();
      } else if ((buttonHardware_Up(index) == true)
                 && (millis() - BUTTON_INTERVAL >= button_Previous)) {
        button_Check_Released_Exit();
        states[index] = BUTTON_STATE_RELEASED;
        knopIngedrukt[index] = true;
        // on this transation the CLICK occurs!
        Serial.println("CLICK");
        button_Released_Entry();
      }
      break;
  }}
}
// --- BUTTON_STATE_RELEASED -----------
void button_Released_Entry() {
  // <nothing>
}
void button_Released_Do() {
  // <nothing>
}
void button_Released_Exit() {
  // <nothing>
}
// --- BUTTON_STATE_CHECK_PRESSED -----------
void button_Check_Pressed_Entry() {
  button_Previous = millis();
}
void button_Check_Pressed_Do() {
  // <nothing>
}
void button_Check_Pressed_Exit() {
  // <nothing>
}
// --- BUTTON_STATE_PRESSED -----------
void button_Pressed_Entry() {
  // <nothing>
}
void button_Pressed_Do() {
  // <nothing>
}
void button_Pressed_Exit() {
  // <nothing>
}
// --- BUTTON_STATE_CHECK_RELEASED -----------
void button_Check_Released_Entry() {
  button_Previous = millis();
}
void button_Check_Released_Do() {
  // <nothing>
}
void button_Check_Released_Exit() {
  // <nothing>
}

// --- Getters ------------
// boolean getKnopNoordIngedrukt(){
//   return(knopNoordIngedrukt);
// }

// boolean getKnopOostIngedrukt(){
//   return(knopOostIngedrukt);
// }

// boolean getKnopZuidIngedrukt(){
//   return(knopZuidIngedrukt);
// }

// boolean getKnopWestIngedrukt(){
//   return(knopWestIngedrukt);
// }

int getStates(){
  return(states);
}
// --- Setters -------------
// void setKnopNoordIngedrukt(boolean waarde){
//   knopNoordIngedrukt = waarde;
// }

// void setKnopOostIngedrukt(boolean waarde){
//   knopOostIngedrukt = waarde;
// }

// void setKnopZuidIngedrukt(boolean waarde){
//   knopZuidIngedrukt = waarde;
// }

// void setKnopWestIngedrukt(boolean waarde){
//   knopWestIngedrukt = waarde;
// }