const byte DS = 13; //Data Serial
const byte ST_CP = 12; // Storage Clock Pulse
const byte SH_CP = 11; // Shift Clock Pulse
byte font[] {
  B10110110, // 5
  B01100110, // 4
  B11110010, // 3
  B11011010, // 2
  B01100000, // 1
  B11111100  // 0
};

int displayStatus = 0;


long previousMillis;
unsigned long currentMillis;


void setup(){
  displayControl_setup();
}

void loop(){
  displayControl_aftellen();
}

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

void displayControl_aftellen(){

  switch (displayStatus){
    case 5:
        displayControl_setDisplay(5);
          if(timerControl_timer(1000) == true){
        displayStatus = 4;
          }
      break;
    case 4:
        displayControl_setDisplay(4);
          if(timerControl_timer(1000) == true){
        displayStatus = 3;
          }
      break;
    case 3:
        displayControl_setDisplay(3);
          if(timerControl_timer(1000) == true){
        displayStatus = 2;
          }
      break;
    case 2:
        displayControl_setDisplay(2);
          if(timerControl_timer(1000) == true){
        displayStatus = 1;
          }
      break;
    case 1:
        displayControl_setDisplay(1);
          if(timerControl_timer(1000) == true){
        displayStatus = 0;
          }
      break;
    case 0:
        displayControl_setDisplay(0);
          if(timerControl_timer(1000) == true){
        displayStatus = 5;
        
          }
      break;
  }
}





boolean timerControl_timer(int interval){
   currentMillis = millis();
  if(currentMillis - previousMillis > interval){
    previousMillis = currentMillis;
    return true;
  } else {
    return false;
  }
}
