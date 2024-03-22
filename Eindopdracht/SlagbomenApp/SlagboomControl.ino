#include <Servo.h>
const int servoPin = 8;
Servo servo;

const int TIKKEN = 1;
const int UIT = 2;

int slagboomStand;
const int slagboomStand_Openen = 1;
const int slagboomStand_Dicht = 2;

long slagboomPreviousMillis;
int slagboomControlInterval = 1000;
int beginPositie = 90;
int eindPositie = 180;

void slagboomControl_Setup(){
  servo.attach(servoPin);
  slagboomStand = slagboomStand_Openen;
}

void slagboomControl_SlagboomBewegen(int slagboomStand){
  switch(slagboomStand){
    case slagboomStand_Openen:
      for (int positie = beginPositie; positie <= eindPositie; positie++){
        unsigned long currentMillis = millis();
        if (currentMillis - slagboomPreviousMillis < slagboomControlInterval){
          slagboomPreviousMillis = currentMillis;
        servo.write(positie);
        }
      }
      break;
    case slagboomStand_Dicht:
      for (int positie = eindPositie; positie >= beginPositie; positie--){
        unsigned long currentMillis = millis();
        if (currentMillis - slagboomPreviousMillis < slagboomControlInterval){
          slagboomPreviousMillis = currentMillis;
        servo.write(positie);
        }
      }
      break;
  }
}

//States
// ---Slagboom_Open_Entry State-----
void slagboom_Open_Entry(){
  //Treinsensor == false;
}

// ---Slagboom_Open_Do State-----
void slagboom_Open_Do(){
  //Set display, roodstoplicht(uit)
}

// ---Slagboom_Open_Exit State-----
void slagboom_Open_Exit(){
  //todo
}

// ---Slagboom_DichtGaan_Entry State-----
void slagboom_DichtGaan_Entry(){
  //todo
}

// ---Slagboom_DichtGaan_Do State-----
void slagboom_DichtGaan_Do(){
  buzzerControl_buzzerGeluidAfspelen(TIKKEN);
  slagboomControl_SlagboomBewegen(slagboomStand_Dicht);
}

// ---Slagboom_DichtGaan_Exit State-----
void slagboom_DichtGaan_Exit(){
  //todo
}

// ---Slagboom_Dicht_Entry State-----
void slagboom_Dicht_Entry(){
  buzzerControl_buzzerGeluidAfspelen(UIT);
  //starttimer, treinsensor = false
}

// ---Slagboom_Dicht_Do State-----
void slagboom_Dicht_Do(){
  ledControl_ledLatenKnipperen(getStoplichtNoordGeelPin());
  ledControl_ledLatenKnipperen(getStoplichtZuidGeelPin());
  //gettimer
}

// ---Slagboom_Dicht_Exit State-----
void slagboom_Dicht_Exit(){
  //todo
}

// ---Slagboom_OpenGaan_Entry State-----
void slagboom_OpenGaan_Entry(){
  //todo
}

// ---Slagboom_OpenGaan_Do State-----
void slagboom_OpenGaan_Do(){
  slagboomControl_SlagboomBewegen(slagboomStand_Openen);
}




































