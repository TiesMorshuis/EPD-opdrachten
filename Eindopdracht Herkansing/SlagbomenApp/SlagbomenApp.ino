void setup() {
  //Alle setups van verschillende onderdelen
  stoplichtControl_Setup();
  ledControl_Setup();
  buzzerControl_Setup();
  main_Setup();
  displayControl_setup();
  pinMode(5, OUTPUT);
}

void main_Setup(){
  main_Setup_Entry();
  main_Setup_Do();
  main_Setup_Exit();
}
void loop() {
  digitalWrite(5, HIGH);
}

void main_Setup_Entry(){
  // Stoplichten_Op_Rood();
  // SlagboomControl_SlagboomBewegen(90);
  // treinSensor = false;
  // andereTreinSensor = false;
}

void main_Setup_Do(){}
void main_Setup_Exit(){}

void Slagboom_Dichtgaan_Entry(){}
void Slagboom_Dichtgaan_Do(){}
void Slagboom_Dichtgaan_Exit(){}

void Slagboom_Dicht_Entry(){}
void Slagboom_Dicht_Do(){}
void Slagboom_Dicht_Exit(){}

void Slagboom_Opengaan_Entry(){}
void Slagboom_Opengaan_Do(){}
void Slagboom_Opengaan_Exit(){}

void Slagboom_Open_Entry(){}
void Slagboom_Open_Do(){}
void Slagboom_Open_Exit(){}


