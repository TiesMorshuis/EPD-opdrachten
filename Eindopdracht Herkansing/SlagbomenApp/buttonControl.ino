const int knopNoord = A0;
const int knopZuid = A1;
const int knopWest = A2;
const int knopOost = A3;
const int nr_Of_Knoppen = 4;
const int knoppenLijst[] = {knopNoord, knopZuid, knopWest, knopOost};
char buttonPressed;
int buttonState;
int eerstIngedrukteKnop;

void buttonControl_Setup() {
  for (int index = 0; index < nr_Of_Knoppen; index++){
    pinMode(knoppenLijst[index], INPUT);
  }

}

void buttonControl_ButtonLoop(){
  //switch(buttonPressed)
}

void buttonControl_buttonPressed(){
  
}

// --- Setters --- //

void setEerstIngedrukteKnop(char ingedrukteKnop){
  switch(ingedrukteKnop){
    case 'N':
      eerstIngedrukteKnop = knopNoord;
      break;
    case 'Z':
      eerstIngedrukteKnop = knopZuid;
      break;
  } 
}

// --- Getters --- //

int getKnopNoord(){
  return knopNoord;
}

int getKnopOost(){
  return knopOost;
}

int getKnopZuid(){
  return knopZuid;
}

int getKnopWest(){
  return knopWest;
}

int getEerstIngedrukteKnop(){
  return eerstIngedrukteKnop;
}

char getButtonPressed(){
  return buttonPressed;
}