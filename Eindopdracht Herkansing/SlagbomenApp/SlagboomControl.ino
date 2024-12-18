#include <Servo.h>
const int servoPin = 8;
Servo servo;

int slagboomStand;
const int STATE_slagboomStand_openen = 1;
const int STATE_slagboomStand_dichtgaan = 2;

int slagboomControl_Interval = 100;

int beginPositie;
int huidigePositie;
int eindPositie;


void slagboomControl_setup(int STATE_slagboomStand_openen) {
  servo.attach(servoPin);
  slagboomStand = STATE_slagboomStand_openen;
}

void slagboomControl_slagboomBewegen(int slagboomStand) {
  boolean timer = timerControl_timer(slagboomControl_Interval);
  switch (slagboomStand) {
    case STATE_slagboomStand_openen:
      beginPositie = 90;
      huidigePositie = beginPositie;
      eindPositie = 180;
      if (timer = true) {
        huidigePositie += 1;
        servo.write(huidigePositie);
      }
      if (huidigePositie == eindPositie) {
        break;
      }
    case STATE_slagboomStand_dichtgaan:
      beginPositie = 180;
      huidigePositie = beginPositie;
      eindPositie = 90;
      if (timer = true) {
        huidigePositie -= 1;
        servo.write(huidigePositie);
      }
      if (huidigePositie == eindPositie) {
        break;
      }
  }
}