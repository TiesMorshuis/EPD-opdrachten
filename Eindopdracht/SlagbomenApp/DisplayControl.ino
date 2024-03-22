const byte DS = 13; //Data Serial
const byte ST_CP = 12; // Storage Clock Pulse
const byte SH_CP = 11; // Shift Clock Pulse

void displayControl_setup(){
  pinMode(DS, OUTPUT);
  pinMode(ST_CP, OUTPUT);
  pinMode(SH_CP, OUTPUT);
  digitalWrite(DS, LOW);
  digitalWrite(ST_CP, LOW);
  digitalWrite(SH_CP, LOW);
  displayControl_displayOff();
}

void displayControl_displayOff(){
  for (int index = 0; index < 8; index++){
    digitalWrite(DS, LOW);
    digitalWrite(SH_CP, HIGH);
    digitalWrite(SH_CP, LOW);
  }
  digitalWrite(ST_CP, HIGH);
  digitalWrite(ST_CP, LOW);
}

byte displayControl_getPatroon(int getal){
  byte patroon;
  switch(getal){
    case 1;
      patroon = B01100000;
    break;
    case 2;
      patroon = B
  }
}