const int groenLichtTijd = 6000;
const int oranjeLichtTijd = 3000;
const int ontruimingstijd = 5000;
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

void stoplichtControl_stoplichtOranjeKnipperenStop(){
  ledControl_ledUit(noordOranje);
  ledControl_ledUit(zuidOranje);
}

void stoplichtControl_stoplichtCyclus(char stoplichtChar, char ingedrukteKnopTrein){
  switch (stoplichtState){
    case STATE_stoplichtRood:
      if(timerControl_timer(ontruimingstijd) == true || ingedrukteKnopTrein == 'O' || ingedrukteKnopTrein == 'W'){
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
      }
      break;
      case STATE_stoplichtGroen:
        if (timerControl_timer(groenLichtTijd) == true || ingedrukteKnopTrein == 'O' || ingedrukteKnopTrein == 'W'){
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
      break;
      case STATE_stoplichtOranje:
        if (timerControl_timer(oranjeLichtTijd) == true){
          if (stoplichtChar == 'N'){
            ledControl_ledUit(noordOranje);
            ledControl_ledAan(noordRood);
            stoplichtState = STATE_stoplichtRood;
            currentState = STATE_stoplichtCyclus_Exit;
            Serial.println("noord");
          } else if (stoplichtChar == 'Z'){
            ledControl_ledUit(zuidOranje);
            ledControl_ledAan(zuidRood);
            Serial.println("zuid");
            stoplichtState = STATE_stoplichtRood;
            currentState = STATE_stoplichtCyclus_Exit;
          }
        }
      break;
  }
}

void stoplichtControl_stoplichtOranjeKnipperen(){ 
    if(timerControl_timer(500) == true){
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
