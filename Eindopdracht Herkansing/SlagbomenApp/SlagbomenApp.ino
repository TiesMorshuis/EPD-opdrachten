const int slagboomStand_Openen = 1;
const int slagboomStand_Sluiten = 2;
const int buzzer_SNEL = 1;
const int buzzer_AFTELLEN = 2;
const int buzzer_STOP = 0;
const int stoplichtKnipperen_START = 1;
const int stoplichtKnipperen_STOP = 0;
boolean treinSensor = false;
boolean andereTreinSensor = false;
char ingedrukteKnop;
char stoplichtVoorrangKnop;

void setup() {
  //Alle setups van verschillende onderdelen
  stoplichtControl_setup();
  ledControl_setup();
  buzzerControl_setup();
  main_setup();
  displayControl_setup();
  slagboomControl_setup(slagboomStand_Openen);
  pinMode(5, OUTPUT);
}

void main_setup(){
  main_setup_Entry();
  main_setup_Do();
  main_setup_Exit();
}
void loop() {
  switch (ingedrukteKnop) {
    case 'N':
    case 'O':
      slagboomDichtgaan_Entry();
      slagboomDichtgaan_Do();
    case 'Z':
    case 'W':
  }
}

void main_setup_Entry(){
  // Stoplichten_Op_Rood();
  // SlagboomControl_SlagboomBewegen(90);
  // treinSensor = false;
  // andereTreinSensor = false;
}

void main_setup_Do(){}
void main_setup_Exit(){}

// Slagboom Dichtgaan States
void slagboomDichtgaan_Entry(){}

void slagboomDichtgaan_Do(){
  slagboomControl_slagboomBewegen(slagboomStand_Sluiten);
  stoplichtControl_stoplichtOranjeKnipperen(stoplichtKnipperen_START);
  buzzerControl_buzzerTikken(buzzer_SNEL);
}

void SlagboomDichtgaan_Exit(){
  buzzerControl_buzzerTikken(buzzer_STOP);
}

// Slagboom Dicht States
void slagboomDicht_Entry(){}
void slagboomDicht_Do(){}
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


