const byte DS = 8;      // Data Serial
const byte ST_CP = 9;   // Storage Clock Pulse
const byte SH_CP = 10;  // Shift Clock Puls

void display_Setup(){
  pinMode(DS, OUTPUT);
  pinMode(ST_CP, OUTPUT);
  pinMode(SH_CP, OUTPUT);
  digitalWrite(DS, LOW);
  digitalWrite(ST_CP, LOW);
  digitalWrite(SH_CP, LOW);
  display_Off();
}

void display_Off(){
  for(int index=0; index < 8; index++){
    digitalWrite(DS, LOW);
    digitalWrite(SH_CP, HIGH);
    digitalWrite(SH_CP, LOW);
  }
  digitalWrite(ST_CP, HIGH);
  digitalWrite(ST_CP, LOW);
}

void display_Set(char windrichting){
  byte patroon = display_getPatroon(windrichting);
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

byte display_getPatroon(char windrichting){
  byte patroon;
  if (windrichting == "X"){
    patroon = B01101110;
  } else if (windrichting == "N"){
    patroon = B11101100;
  } else if (windrichting == "O"){
    patroon = B11111100;
  } else if (windrichting == "Z"){
    patroon = B11011010;
  } else if (windrichting == "W"){
    patroon = B01111100;
  }
  return patroon;
}