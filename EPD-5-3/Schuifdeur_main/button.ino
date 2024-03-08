// Module Button
// --- States -----------
const int BUTTON_STATE_RELEASED = 1;
const int BUTTON_STATE_CHECK_PRESSED = 2;
const int BUTTON_STATE_PRESSED = 3;
const int BUTTON_STATE_CHECK_RELEASED = 4;
// Current state
int button_State;
// Timer variables
const int BUTTON_INTERVAL = 20;  // 10msec, test your own button
unsigned long button_Previous;
// --- Setup -------------------
void button_Setup() {
  Serial.begin(9600);  // to print "CLICK"
  // Start state
  button_State = BUTTON_STATE_RELEASED;
  button_Released_Entry();

}
// --- Loop --------------------
void button_Loop() {
  switch (button_State) {
    case BUTTON_STATE_RELEASED:
      button_Released_Do();
      if (buttonHardware_Down() == true) {
        button_Released_Exit();
        button_State = BUTTON_STATE_CHECK_PRESSED;
        button_Check_Pressed_Entry();
      }
      break;
    case BUTTON_STATE_CHECK_PRESSED:
      button_Check_Pressed_Do();
      if (buttonHardware_Up() == true) {
        button_Check_Pressed_Exit();
        button_State = BUTTON_STATE_RELEASED;
        button_Released_Entry();
      } else if ((buttonHardware_Down() == true)
                 && (millis() - BUTTON_INTERVAL >= button_Previous)) {
        button_Check_Pressed_Exit();
        button_State = BUTTON_STATE_PRESSED;
        button_Pressed_Entry();
      }
      break;
    case BUTTON_STATE_PRESSED:
      button_Pressed_Do();
      if (buttonHardware_Up() == true) {
        button_Pressed_Exit();
        button_State = BUTTON_STATE_CHECK_RELEASED;
        button_Check_Released_Entry();
      }
      break;
    case BUTTON_STATE_CHECK_RELEASED:
      button_Check_Released_Do();
      if (buttonHardware_Down() == true) {
        button_Check_Released_Exit();
        button_State = BUTTON_STATE_PRESSED;
        button_Pressed_Entry();
      } else if ((buttonHardware_Up() == true)
                 && (millis() - BUTTON_INTERVAL >= button_Previous)) {
        button_Check_Released_Exit();
        button_State = BUTTON_STATE_RELEASED;
        // on this transation the CLICK occurs!
        Serial.println("CLICK");
        button_Released_Entry();
      }
      break;
  }
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