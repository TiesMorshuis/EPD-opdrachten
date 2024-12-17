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
int ledState = LOW;

void stoplichtControl_setup(){
  stoplichtControl_stoplichtenOpRood();
}

void stoplichtControl_stoplichtenOpRood(){
  ledControl_alleLedUit();
  ledControl_ledAan(zuidRood);
  ledControl_ledAan(noordRood);
}

void stoplichtControl_stoplichtCyclus(char stoplichtChar){
  switch (stoplichtChar){
    case 'Z':
    // if (ingedrukteKnop = 'O' or ingedrukteKnop = 'W'){
    //   stoplichtControl_StoplichtNaarOranje(stoplichtChar);
    //   break;
    // }
      ledControl_ledAan(4);
      if (timerControl_timer(groenlichtTijd) == true){
        ledControl_ledUit(4);
        ledControl_ledAan(3);
        if (timerControl_timer(oranjelichtTijd) == true){
          ledControl_ledUit(3);
          ledControl_ledAan(2);
        }
      }
    case 'N':
    // if (ingedrukteKnop = 'O' or ingedrukteKnop = 'W'){
    //   stoplichtControl_StoplichtNaarOranje(stoplichtChar);
    //   break;
    // }
      ledControl_ledAan(7);
      if (timerControl_timer(groenlichtTijd) == true){
        ledControl_ledUit(7);
        ledControl_ledAan(6);
        if (timerControl_timer(oranjelichtTijd) == true){
          ledControl_ledUit(6);
          ledControl_ledAan(5);
        }
  }
}
}

void stoplichtControl_stoplichtCyclusNeutraal(char ingedrukteKnop){
  stoplichtControl_stoplichtenOpRood();
  stoplichtControl_stoplichtCyclus(ingedrukteKnop);
}

void stoplichtControl_stoplichtNaarOranje(char stoplichtChar){
  switch (stoplichtChar){
    case 'Z':
      ledControl_ledUit(4);
      ledControl_ledAan(3);
      if(timerControl_timer(oranjelichtTijd == true)){
        ledControl_ledUit(3);
        ledControl_ledAan(2);
      }
      case 'N':
      ledControl_ledUit(7);
      ledControl_ledAan(6);
      if(timerControl_timer(oranjelichtTijd == true)){
        ledControl_ledUit(6);
        ledControl_ledAan(5);
      }
  }
}

void stoplichtControl_stoplichtOranjeKnipperen(int status){
  if(status == 1){
  if(timerControl_timer(1000) == true){
    if (ledState == LOW){
      digitalWrite(noordOranje, HIGH);
      digitalWrite(zuidOranje, HIGH);
      ledState = HIGH;
    }
    else if (ledState == HIGH){
      digitalWrite(noordOranje, LOW);
      digitalWrite(zuidOranje, LOW);
      ledState = LOW;
    }
  }
  }
  else {
    digitalWrite(noordOranje, LOW);
    digitalWrite(zuidOranje, LOW);
  }
}
