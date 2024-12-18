const int groenLichtTijd = 6000;
const int oranjeLichtTijd = 3000;
int Z = 1;
int N = 2;
const int noordGroen = 7;
const int noordOranje = 6;
const int noordRood = 5;
const int zuidGroen = 4;
const int zuidOranje = 3;
const int zuidRood = 2;
int ledState = LOW;
const int STATE_stoplichtGroen = 1;
const int STATE_stoplichtOranje = 2;
const int STATE_stoplichtRood = 3;
int stoplichtState = STATE_stoplichtRood;

void stoplichtControl_setup(){
  stoplichtControl_stoplichtenOpRood();
}

void stoplichtControl_stoplichtenOpRood(){
  ledControl_ledAan(zuidRood);
  ledControl_ledAan(noordRood);
}

void stoplichtControl_stoplichtCyclus(char stoplichtChar){
  switch (stoplichtState){
    case STATE_stoplichtRood:
      if (stoplichtChar == 'N'){
        ledControl_ledUit(noordRood);
        ledControl_ledAan(noordGroen);
        stoplichtState = STATE_stoplichtGroen;
      }
      else if (stoplichtChar == 'Z'){
        ledControl_ledUit(zuidRood);
        ledControl_ledAan(zuidGroen);
        stoplichtState = STATE_stoplichtGroen;
      }
      case STATE_stoplichtGroen:
        if (timerControl_timer(groenLichtTijd) == true){
          if (stoplichtChar == 'N'){
             ledControl_ledUit(noordGroen);
             ledControl_ledAan(noordOranje);
             stoplichtState = STATE_stoplichtOranje;
          } else if (stoplichtChar == 'Z'){
            ledControl_ledUit(zuidGroen);
            ledControl_ledAan(zuidOranje);
            stoplichtState = STATE_stoplichtOranje;
          }
        }
      case STATE_stoplichtOranje:
        if (timerControl_timer(oranjeLichtTijd) == true){
          if (stoplichtChar == 'N'){
            ledControl_ledUit(noordOranje);
            ledControl_ledAan(noordRood);
            stoplichtState = STATE_stoplichtRood;
            currentState = STATE_stoplichtCyclus_Exit;
          } else if (stoplichtChar == 'Z'){
            ledControl_ledUit(zuidOranje);
            ledControl_ledAan(zuidRood);
            stoplichtState = STATE_stoplichtRood;
            currentState = STATE_stoplichtCyclus_Exit;
          }
        }
  }
}

// void stoplichtControl_stoplichtCyclusNeutraal(char ingedrukteKnop){
//   stoplichtControl_stoplichtenOpRood();
//   stoplichtControl_stoplichtCyclus(ingedrukteKnop);
// }

void stoplichtControl_stoplichtNaarOranje(char stoplichtChar){
  switch (stoplichtChar){
    case 'Z':
      ledControl_ledUit(4);
      ledControl_ledAan(3);
      if(timerControl_timer(oranjeLichtTijd == true)){
        ledControl_ledUit(3);
        ledControl_ledAan(2);
      }
      case 'N':
      ledControl_ledUit(7);
      ledControl_ledAan(6);
      if(timerControl_timer(oranjeLichtTijd == true)){
        ledControl_ledUit(6);
        ledControl_ledAan(5);
      }
  }
}

void stoplichtControl_stoplichtOranjeKnipperen(int status){
  if(status == 1){
  if(timerControl_timer(1000) == true){
    if (ledState == LOW){
      ledControl_ledAan(noordOranje);
      ledControl_ledAan(zuidOranje);
      ledState = HIGH;
    }
    else if (ledState == HIGH){
      ledControl_ledUit(noordOranje);
      ledControl_ledUit(zuidOranje);
      ledState = LOW;
    }
  }
  }
  else {
    ledControl_ledUit(noordOranje);
    ledControl_ledUit(zuidOranje);
  }
}
