#include <Servo.h>
const int servoPin = 8;
Servo servo;

int slagboomStand;


int slagboomControl_Interval = 100;

int beginPositie;
int huidigePositie;
int eindPositie;


void slagboomControl_setup(int slagboomStand_Openen) {
  servo.attach(servoPin);
  slagboomStand = slagboomStand_Openen;
}

void slagboomControl_slagboomBewegen(int slagboomStand) {
  boolean timer = timerControl_timer(slagboomControl_Interval);
  switch (slagboomStand) {
    case slagboomStand_Openen:
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
    case slagboomStand_Sluiten:
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