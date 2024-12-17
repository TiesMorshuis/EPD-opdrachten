const int groenlichtTijd = 6000;
const int oranjelichtTijd = 3000;
int Z = 1;
int N = 2;
const int noordGroen = 7;
const int noordOranje = 6;
const int noordRood = 5;
const int zuidGroen = 4;
const int zuidOranje = 3;
const int zuidRood = 2;

void stoplichtControl_Setup(){
  stoplichtControl_StoplichtenOpRood();
}

void stoplichtControl_StoplichtenOpRood(){
  ledControl_alleLedUit();
  ledControl_LedAan(zuidRood);
  ledControl_LedAan(noordRood);
}

void stoplichtControl_StoplichtCyclus(char stoplichtChar){
  switch (stoplichtChar){
    case 'Z':
    // if (ingedrukteKnop = 'O' or ingedrukteKnop = 'W'){
    //   stoplichtControl_StoplichtNaarOranje(stoplichtChar);
    //   break;
    // }
      ledControl_LedAan(4);
      if (TimerControl_Timer(groenlichtTijd) == true){
        ledControl_LedUit(4);
        ledControl_LedAan(3);
        if (TimerControl_Timer(oranjelichtTijd) == true){
          ledControl_LedUit(3);
          ledControl_LedAan(2);
        }
      }
    case 'N':
    // if (ingedrukteKnop = 'O' or ingedrukteKnop = 'W'){
    //   stoplichtControl_StoplichtNaarOranje(stoplichtChar);
    //   break;
    // }
      ledControl_LedAan(7);
      if (TimerControl_Timer(groenlichtTijd) == true){
        ledControl_LedUit(7);
        ledControl_LedAan(6);
        if (TimerControl_Timer(oranjelichtTijd) == true){
          ledControl_LedUit(6);
          ledControl_LedAan(5);
        }
  }
}
}

void stoplichtControl_StoplichtCyclusNeutraal(char ingedrukteKnop){
  stoplichtControl_StoplichtenOpRood();
  stoplichtControl_StoplichtCyclus(ingedrukteKnop);
}

void stoplichtControl_StoplichtNaarOranje(char stoplichtChar){
  switch (stoplichtChar){
    case 'Z':
      ledControl_LedUit(4);
      ledControl_LedAan(3);
      if(TimerControl_Timer(oranjelichtTijd == true)){
        ledControl_LedUit(3);
        ledControl_LedAan(2);
      }
      case 'N':
      ledControl_LedUit(7);
      ledControl_LedAan(6);
      if(TimerControl_Timer(oranjelichtTijd == true)){
        ledControl_LedUit(6);
        ledControl_LedAan(5);
      }
  }
}

