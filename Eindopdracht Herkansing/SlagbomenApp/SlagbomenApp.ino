const int slagboomStand_Openen = 1;
const int slagboomStand_Sluiten = 2;
const int buzzer_SNEL = 1;
const int buzzer_AFTELLEN = 2;
const int buzzer_STOP = 0;
const int stoplichtKnipperen_START = 1;
const int stoplichtKnipperen_STOP = 0;
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
const int STATE_mainSetup_Entry = 13;
const int STATE_mainSetup_Do = 14;
const int STATE_mainSetup_Exit = 15;
const int STATE_stoplichtCyclusNeutraal_Entry = 16;
const int STATE_stoplichtCyclusNeutraal_Do = 17;
const int STATE_stoplichtCyclusNeutraal_Exit = 18;
const int STATE_stoplichtCyclus_Entry = 19;
const int STATE_stoplichtCyclus_Do = 20;
const int STATE_stoplichtCyclus_Exit = 21;
int currentState = STATE_stoplichtCyclus_Entry;
boolean treinSensor = false;
boolean andereTreinSensor = false;
char ingedrukteKnop = 'W';
char stoplichtVoorrangKnop;




void setup() {
  //Alle setups van verschillende onderdelen
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
  switch (currentState){
    case STATE_stoplichtCyclusNeutraal_Entry:
      Serial.println(currentState);
      stoplichtCyclusNeutraal_Entry();
      currentState = STATE_stoplichtCyclusNeutraal_Do;
    case STATE_stoplichtCyclusNeutraal_Do:
      Serial.println(currentState);
      stoplichtCyclusNeutraal_Do();
    case STATE_stoplichtCyclusNeutraal_Exit:
      Serial.println(currentState);
      stoplichtCyclusNeutraal_Exit();
    
    case STATE_stoplichtCyclus_Entry:
    Serial.println(currentState);
      stoplichtCyclus_Entry();
      currentState = STATE_stoplichtCyclus_Do;
    case STATE_stoplichtCyclus_Do:
    Serial.println(currentState);
      stoplichtCyclus_Do();
    case STATE_stoplichtCyclus_Exit:
    Serial.println(currentState);
      stoplichtCyclus_Exit();
      currentState = STATE_stoplichtCyclusNeutraal_Entry;
    
    case STATE_slagboomDichtgaan_Entry:
      Serial.println(currentState);
      slagboomDichtgaan_Entry();
      currentState = STATE_slagboomDichtgaan_Do;
    case STATE_slagboomDichtgaan_Do:
    Serial.println(currentState);
      slagboomDichtgaan_Do();
    case STATE_slagboomDichtgaan_Exit:
    Serial.println(currentState);
      slagboomDichtgaan_Exit();
      currentState = STATE_slagboomDicht_Entry;
    
    case STATE_slagboomDicht_Entry:
    Serial.println(currentState);
      slagboomDicht_Entry();
      currentState = STATE_slagboomDicht_Do;
    case STATE_slagboomDicht_Do:
    Serial.println(currentState);
      slagboomDicht_Do();
      currentState = STATE_slagboomDicht_Do;
    case STATE_slagboomDicht_Exit:
    Serial.println(currentState);
      slagboomDicht_Exit();
      currentState = STATE_slagboomOpengaan_Entry;

    case STATE_slagboomOpengaan_Entry:
    Serial.println(currentState);
      slagboomOpengaan_Entry();
      currentState = STATE_slagboomOpengaan_Do;
    case STATE_slagboomOpengaan_Do:
    Serial.println(currentState);
      slagboomOpengaan_Do();
    case STATE_slagboomOpengaan_Exit:
    Serial.println(currentState);
      slagboomOpengaan_Exit();
      currentState = STATE_slagboomOpen_Entry;
    
    case STATE_slagboomOpen_Entry:
    Serial.println(currentState);
      slagboomOpen_Entry();
      currentState = STATE_slagboomOpen_Do;
    case STATE_slagboomOpen_Do:
    Serial.println(currentState);
      slagboomOpen_Do();
    case STATE_slagboomOpen_Exit:
    Serial.println(currentState);
      slagboomOpen_Exit();
      currentState = STATE_stoplichtCyclusNeutraal_Entry;
  }
  
}

void main_setup(){
  // Stoplichten_Op_Rood();
  // SlagboomControl_SlagboomBewegen(90);
}

// Slagboom Dichtgaan States
void slagboomDichtgaan_Entry(){}

void slagboomDichtgaan_Do(){
  slagboomControl_slagboomBewegen(slagboomStand_Sluiten);
  stoplichtControl_stoplichtOranjeKnipperen(stoplichtKnipperen_START);
  buzzerControl_buzzerTikken(buzzer_SNEL);
  currentState = STATE_slagboomDichtgaan_Exit;
}

void slagboomDichtgaan_Exit(){
  buzzerControl_buzzerTikken(buzzer_STOP);
}

// Slagboom Dicht States
void slagboomDicht_Entry(){}

void slagboomDicht_Do(
  // stoplichtControl_stoplichtOranjeKnipperen(stoplichtKnipperen_START);
  
){currentState = STATE_slagboomDicht_Do;}
void slagboomDicht_Exit(){}

// Slagboom Opengaan States
void slagboomOpengaan_Entry(){}
void slagboomOpengaan_Do(){
  buzzerControl_buzzerTikken(buzzer_SNEL);
  slagboomControl_slagboomBewegen(slagboomStand_Openen);
}
void slagboomOpengaan_Exit(){}

// Slagboom Open States
void slagboomOpen_Entry(){}

void slagboomOpen_Do(){
  displayControl_aftellen();
  stoplichtControl_stoplichtOranjeKnipperen(stoplichtKnipperen_STOP);
  buzzerControl_buzzerTikken(buzzer_AFTELLEN);
}
void slagboomOpen_Exit(){
  buzzerControl_buzzerTikken(buzzer_STOP);
}

// Stoplicht Cyclus Neutraal States
void stoplichtCyclusNeutraal_Entry(){}

void stoplichtCyclusNeutraal_Do(){
  if(ingedrukteKnop == 'W' || ingedrukteKnop == 'O'){
    currentState = STATE_stoplichtCyclusNeutraal_Exit;
    treinSensor = true;
    // ingedrukteKnop = getIngedrukteKnop();
  }
  else if (ingedrukteKnop == 'N' || ingedrukteKnop == 'Z'){
    currentState = STATE_stoplichtCyclusNeutraal_Exit;
    // ingedrukteKnop = getIngedrukteKnop();
  }
}

void stoplichtCyclusNeutraal_Exit(){
  if (ingedrukteKnop == 'N' || ingedrukteKnop == 'Z'){
    currentState = STATE_stoplichtCyclus_Entry;
  }
  else if (treinSensor == true){
    currentState = STATE_slagboomDichtgaan_Entry;
  }
}

void stoplichtCyclus_Entry(){}

void stoplichtCyclus_Do(){
  if (ingedrukteKnop == 'O' || ingedrukteKnop == 'W'){
    treinSensor = true;
  }
  while (treinSensor == false){
    stoplichtControl_stoplichtCyclus(ingedrukteKnop);
    Serial.println(21);
  }
}

void stoplichtCyclus_Exit(){}

