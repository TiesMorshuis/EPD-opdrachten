#include <Servo.h>
const int servoPin = 8;
Servo servo;

const int TIKKEN = 1;
const int UIT = 2;

int slagboomStand;
const int slagboomStand_Open = 1;
const int slagboomStand_Dicht = 2;

int slagboomControl_Interval = 100;

int beginPositie = 90;
int huidigePositie = beginPositie;
int eindPositie = 180;

void slagboomControl_Setup() {
  servo.attach(servoPin);
  slagboomStand = slagboomStand_Open;
}

void slagboomControl_SlagboomBewegen(int slagboomStand) {
  boolean timer = timerControl_isTimerAfgegaan(slagboomControl_Interval);
  switch (slagboomStand) {
    case slagboomStand_Open:
      eindPositie = 90;
      beginPositie = 180;
      do {
        if (timer == true) {
          huidigePositie += 1;
          servo.write(huidigePositie);
        }
      } while (huidigePositie != eindPositie);
      break;
    case slagboomStand_Dicht:
      eindPositie = 180;
      beginPositie = 90;
      do {
        if (timer == true) {
          huidigePositie -= 1;
          servo.write(huidigePositie);
        }
      } while (huidigePositie != eindPositie);
      break;
  }
}


boolean slagboomControl_isSlagboomOpen() {
  switch (slagboomStand) {
    case slagboomStand_Open:
      return true;
    case slagboomStand_Dicht:
      return false;
  }
  //todo
}


//States
// --- Slagboom_Open_Entry State --- //
void slagboom_Open_Entry() {
  setEerstIngedrukteKnop(NULL);
  //Treinsensor == false;
}

// --- Slagboom_Open_Do State --- //
void slagboom_Open_Do() {
  //Set display, roodstoplicht(uit)
}

// --- Slagboom_Open_Exit State --- //
void slagboom_Open_Exit() {
  //todo
}

// --- Slagboom_DichtGaan_Entry State --- //
void slagboom_DichtGaan_Entry() {
  treinActions_setIsTreinAanwezig(true);
  slagboom_DichtGaan_Do();
  //todo
}

// --- Slagboom_DichtGaan_Do State --- //
void slagboom_DichtGaan_Do() {
  stoplichtControl_treinAanwezig();
  buzzerControl_buzzerGeluidAfspelen(TIKKEN);
  slagboomControl_SlagboomBewegen(slagboomStand_Dicht);
}

// --- Slagboom_DichtGaan_Exit State --- //
void slagboom_DichtGaan_Exit() {
  //todo
}

// --- Slagboom_Dicht_Entry State --- //
void slagboom_Dicht_Entry() {
  buzzerControl_buzzerGeluidAfspelen(UIT);
  //starttimer, treinsensor = false
}

// --- Slagboom_Dicht_Do State --- //
void slagboom_Dicht_Do() {
  stoplichtControl_treinAanwezig();
  //gettimer
}

// --- Slagboom_Dicht_Exit State ---- //
void slagboom_Dicht_Exit() {
  //todo
}

// --- Slagboom_OpenGaan_Entry State --- //
void slagboom_OpenGaan_Entry() {
  //todo
}

// --- Slagboom_OpenGaan_Do State --- //
void slagboom_OpenGaan_Do() {
  slagboomControl_SlagboomBewegen(slagboomStand_Open);
}
