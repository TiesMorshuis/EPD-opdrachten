const byte DS = 13; //Data Serial
const byte ST_CP = 12; // Storage Clock Pulse
const byte SH_CP = 11; // Shift Clock Pulse
int getal = 2;
boolean x = true;
void setup() {

  pinMode(DS, OUTPUT);
  pinMode(ST_CP, OUTPUT);
  pinMode(SH_CP, OUTPUT);
  digitalWrite(DS, LOW);
  digitalWrite(ST_CP, LOW);
  digitalWrite(SH_CP, LOW);
  pinMode(5, OUTPUT);
}

void loop() {
  // displayControl_displayOff();
  digitalWrite(5, HIGH);
}

// void displayControl_displayOff(){
//   for (int index = 0; index < 8; index++){
//     digitalWrite(DS, LOW);
//     digitalWrite(SH_CP, HIGH);
//     digitalWrite(SH_CP, LOW);
//   }
//   digitalWrite(ST_CP, HIGH);
//   digitalWrite(ST_CP, LOW);
// }

byte displayControl_getPatroon(int getal){
  byte patroon;
  switch(getal){
    case 0: 
      patroon = B11111100;
      break;
    case 1:
      patroon = B01100000;
      break;
    case 2:
      patroon = B11011010;
      break;
    case 3:
      patroon = B11110010;
      break;
    case 4:
      patroon = B01100110;
      break;
    case 5:
      patroon = B10110110;
      break;
  }
  return patroon;
}
void displayControl_setDisplay(int getal){
  byte patroon = displayControl_getPatroon(getal);
  for (int index = 0; index < 8; index++){
    if (bitRead(patroon, index)){
      digitalWrite(DS, HIGH);
    } else {
      digitalWrite(DS, LOW);
    }
    digitalWrite(SH_CP, HIGH);
    digitalWrite(SH_CP, LOW);
  }
  digitalWrite(ST_CP, HIGH);
  digitalWrite(ST_CP, LOW);
}

void displayControl_Aftellen(){
  for (int index = 0; index < 6; index++){
    if (TimerControl_Timer(1000) == true){
      displayControl_setDisplay(index);
    }
  }
}

long previousMillis;

boolean TimerControl_Timer(int interval){
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval){
    previousMillis = currentMillis;
    return true;
  } else {
    return false;
  }
}