const int slagboomStand_Openen = 1;
const int slagboomStand_Sluiten = 2;
const int buzzer_SNEL = 1;
const int buzzer_AFTELLEN = 2;
const int buzzer_STOP = 0;
const int STATE_slagboomDichtgaan_Entry = 1;
const int STATE_slagboomDichtgaan_Do = 2;
const int STATE_slagboomDichtgaan_Exit = 3;
const int STATE_slagboomDicht_Entry = 4;
const int STATE_slagboomDicht_Do = 5;
const int STATE_slagboomDicht_Exit = 6;
const int STATE_slagboomOpengaan_Entry = 7;
const int STATE_slagboomOpengaan_Do = 8;
const int STATE_slagboomOpengaan_Exit = 9;
const int STATE_slagboomOpen_Entry = 10;
const int STATE_slagboomOpen_Do = 11;
const int STATE_slagboomOpen_Exit = 12;
const int STATE_stoplichtCyclusNeutraal_Entry = 16;
const int STATE_stoplichtCyclusNeutraal_Do = 17;
const int STATE_stoplichtCyclusNeutraal_Exit = 18;
const int STATE_stoplichtCyclus_Entry = 19;
const int STATE_stoplichtCyclus_Do = 20;
const int STATE_stoplichtCyclus_Exit = 21;
int currentState;
boolean treinSensor = false;
boolean andereTreinSensor = false;
char ingedrukteKnopStoplicht;
char ingedrukteKnopTrein;
char ingedrukteKnopTreinAndereKant;
char ingedrukteKnopStoplichtWachtrij;




void setup() {
  //Alle setups van verschillende onderdelen
  buttonHardware_Setup();
  button_Setup();
  serialSetup();
  ledControl_setup();
  stoplichtControl_setup();
  buzzerControl_setup();
  main_setup();
  displayControl_setup();
  slagboomControl_setup(slagboomStand_Openen);
  currentState = STATE_stoplichtCyclusNeutraal_Entry;
}

void loop(){
  button_Loop();
  assignButtons(getKnopIngedruktArray());
  Serial.println(currentState);
  switch (currentState){
    case STATE_stoplichtCyclusNeutraal_Entry:
      stoplichtCyclusNeutraal_Entry();
      currentState = STATE_stoplichtCyclusNeutraal_Do;
      break;
    case STATE_stoplichtCyclusNeutraal_Do:
      stoplichtCyclusNeutraal_Do();
      break;
    case STATE_stoplichtCyclusNeutraal_Exit:
      stoplichtCyclusNeutraal_Exit();
      break;
    case STATE_stoplichtCyclus_Entry:
      stoplichtCyclus_Entry();
      currentState = STATE_stoplichtCyclus_Do;
      break;
    case STATE_stoplichtCyclus_Do:
      stoplichtCyclus_Do();
      break;
    case STATE_stoplichtCyclus_Exit:
      stoplichtCyclus_Exit();
      currentState = STATE_stoplichtCyclusNeutraal_Entry;
      break;
    case STATE_slagboomDichtgaan_Entry:
      slagboomDichtgaan_Entry();
      currentState = STATE_slagboomDichtgaan_Do;
      break;
    case STATE_slagboomDichtgaan_Do:
      slagboomDichtgaan_Do();
      break;
    case STATE_slagboomDichtgaan_Exit:
      slagboomDichtgaan_Exit();
      currentState = STATE_slagboomDicht_Entry;
      break;
    case STATE_slagboomDicht_Entry:
      slagboomDicht_Entry();
      currentState = STATE_slagboomDicht_Do;
      break;


    case STATE_slagboomDicht_Do:
      slagboomDicht_Do();
      break;
    case STATE_slagboomDicht_Exit:
      slagboomDicht_Exit();
      currentState = STATE_slagboomOpengaan_Entry;
      break;



    case STATE_slagboomOpengaan_Entry:
      slagboomOpengaan_Entry();
      currentState = STATE_slagboomOpengaan_Do;
      break;
    case STATE_slagboomOpengaan_Do:
      slagboomOpengaan_Do();
      break;
    case STATE_slagboomOpengaan_Exit:
      slagboomOpengaan_Exit();
      currentState = STATE_slagboomOpen_Entry;
      break;
    case STATE_slagboomOpen_Entry:
      slagboomOpen_Entry();
      currentState = STATE_slagboomOpen_Do;
      break;
    case STATE_slagboomOpen_Do:
      slagboomOpen_Do();
      break;
    case STATE_slagboomOpen_Exit:
      slagboomOpen_Exit();
      currentState = STATE_stoplichtCyclusNeutraal_Entry;
      break;
  }
  
}

void main_setup(){
  // Stoplichten_Op_Rood();
  // SlagboomControl_SlagboomBewegen(90);
}

// Slagboom Dichtgaan States
void slagboomDichtgaan_Entry(){
  currentState = STATE_slagboomDichtgaan_Entry;
}

void slagboomDichtgaan_Do(){
  buzzerControl_buzzerTikken(buzzer_SNEL);
  slagboomControl_slagboomBewegen();

}

void slagboomDichtgaan_Exit(){
  buzzerControl_buzzerTikken(buzzer_STOP);
}

// Slagboom Dicht States
void slagboomDicht_Entry(){}

void slagboomDicht_Do(){
    stoplichtControl_stoplichtOranjeKnipperen();    
    if (treinSensor == true && andereTreinSensor == true){
      currentState = STATE_slagboomDicht_Exit;
    }
}
void slagboomDicht_Exit(){
  stoplichtControl_stoplichtOranjeKnipperenStop();
}

// Slagboom Opengaan States
void slagboomOpengaan_Entry(){}
void slagboomOpengaan_Do(){
  buzzerControl_buzzerTikken(buzzer_SNEL);
  slagboomControl_slagboomBewegen();
  
}
void slagboomOpengaan_Exit(){}

// Slagboom Open States
void slagboomOpen_Entry(){}

void slagboomOpen_Do(){
  
  displayControl_aftellen();
  
}
void slagboomOpen_Exit(){
  displayControl_displayOff();
  buzzerControl_buzzerTikken(buzzer_STOP);
  treinSensor = false;
  andereTreinSensor = false;
  ingedrukteKnopTrein = NULL;
  ingedrukteKnopTreinAndereKant = NULL;
}

// Stoplicht Cyclus Neutraal States
void stoplichtCyclusNeutraal_Entry(){

}

void stoplichtCyclusNeutraal_Do(){
  if(ingedrukteKnopTrein == 'W' || ingedrukteKnopTrein == 'O'){
    currentState = STATE_stoplichtCyclusNeutraal_Exit;
    treinSensor = true;
    // ingedrukteKnop = getIngedrukteKnop();
  }
  else if (ingedrukteKnopStoplicht == 'N' || ingedrukteKnopStoplicht == 'Z'){
    currentState = STATE_stoplichtCyclusNeutraal_Exit;
    // ingedrukteKnop = getIngedrukteKnop();
  }
}

void stoplichtCyclusNeutraal_Exit(){
  if (treinSensor == true){
    currentState = STATE_slagboomDichtgaan_Entry;
  } else if (ingedrukteKnopStoplicht == 'N' || ingedrukteKnopStoplicht == 'Z'){
    currentState = STATE_stoplichtCyclus_Entry;
  }
}

void stoplichtCyclus_Entry(){}

void stoplichtCyclus_Do(){
    stoplichtControl_stoplichtCyclus(ingedrukteKnopStoplicht, ingedrukteKnopTrein);
}

void stoplichtCyclus_Exit(){
  if(ingedrukteKnopStoplicht == 'N'){
      setKnopNoordIngedrukt(false);
  } else if (ingedrukteKnopStoplicht == 'Z') {
    setKnopZuidIngedrukt(false);
  }
  ingedrukteKnopStoplicht = NULL;
  ingedrukteKnopStoplichtWachtrij = NULL;
  currentState = STATE_stoplichtCyclusNeutraal_Entry;
}

void assignButtons(boolean knopIngedrukt[]){
  if(knopIngedrukt[0] == true && ingedrukteKnopStoplicht == NULL){
    ingedrukteKnopStoplicht = 'N';
  } else if (knopIngedrukt[0] == true && ingedrukteKnopStoplicht != NULL){
    ingedrukteKnopStoplichtWachtrij = 'N';
  } else if (knopIngedrukt[1] == true && ingedrukteKnopTrein == NULL){
    ingedrukteKnopTrein = 'O';
    treinSensor = true;
    setKnopOostIngedrukt(false);
  } else if (knopIngedrukt[1] == true && ingedrukteKnopTrein != NULL && ingedrukteKnopTrein != 'O'){
    ingedrukteKnopTreinAndereKant = 'O';
    andereTreinSensor = true;
    setKnopOostIngedrukt(false);
  } else if (knopIngedrukt[2] == true && ingedrukteKnopStoplicht == NULL){
    ingedrukteKnopStoplicht = 'Z';
  } else if (knopIngedrukt[2] == true && ingedrukteKnopStoplicht != NULL){
    ingedrukteKnopStoplichtWachtrij = 'Z';
  } else if (knopIngedrukt[3] == true && ingedrukteKnopTrein == NULL){
    ingedrukteKnopTrein = 'W';
    treinSensor = true;
    setKnopWestIngedrukt(false);
  } else if (knopIngedrukt[3] == true && ingedrukteKnopTrein != NULL && ingedrukteKnopTrein != 'W'){
    ingedrukteKnopTrein = 'W';
    andereTreinSensor = true;
    setKnopWestIngedrukt(false);

  }
}









