#include <Servo.h>
const int servoPin = 8;
Servo servo;

int slagboomStand;
const int slagboomStand_Openen = 1;
const int slagboomStand_Sluiten = 2;

int slagboomControl_Interval = 100;

int beginPositie;
int huidigePositie;
int eindPositie;


void SlagboomControl_Setup() {
  servo.attach(servoPin);
  slagboomStand = slagboomStand_Openen;
}

void SlagboomControl_SlagboomBewegen(int slagboomStand) {
  boolean timer = TimerControl_Timer(slagboomControl_Interval);
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