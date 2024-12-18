#include <Servo.h>
const int servoPin = 8;
Servo servo;

int slagboomState;
const int STATE_slagboomStand_Omhoog = 1;
const int STATE_slagboomStand_Omlaag = 2;

int slagboomInterval = 100;

int beginPositie;
int huidigePositie;
int eindPositie;


void slagboomControl_setup(int STATE_slagboomStand_openen) {
  servo.attach(servoPin);
  beginPositie = 90;
  eindPositie = 180;
  huidigePositie = beginPositie;
  slagboomState = STATE_slagboomStand_openen;
}

void slagboomControl_slagboomBewegen() {
  stoplichtControl_stoplichtOranjeKnipperen();
  switch (slagboomState){
    case STATE_slagboomStand_Omhoog:
      eindPositie = 180;
      if(timerControl_timer(slagboomInterval) == true){
         huidigePositie += 1;
         servo.write(huidigePositie);
      }
      if (huidigePositie == eindPositie){
        slagboomState = STATE_slagboomStand_Omlaag;
        currentState = STATE_slagboomDichtgaan_Exit;
      }
      break;
    case STATE_slagboomStand_Omlaag:
      eindPositie = 90;
      if(timerControl_timer(slagboomInterval) == true){
         huidigePositie -= 1;
         servo.write(huidigePositie);
      }
      if (huidigePositie == eindPositie){
        slagboomState = STATE_slagboomStand_Omhoog;
        currentState = STATE_slagboomOpengaan_Exit;
      }
    break;
  }
}