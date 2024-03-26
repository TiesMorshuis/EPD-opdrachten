const int stoplichtZuidRoodPin = 2;
const int stoplichtZuidGeelPin = 3;
const int stoplichtZuidGroenPin = 4;
const int stoplichtNoordRoodPin = 5;
const int stoplichtNoordGeelPin = 6;
const int stoplichtNoordGroenPin = 7;
boolean eerstKnopVerwerkt = false;


void stoplichtSetup(){
  //todo
}

void stoplichtLoop(){
  //todo
  //get eerst ingedrukte knop en geef die prioriteit als trein voorbij is.
  if (slagboomControl_isSlagboomOpen() == false){
    stoplichtControl_treinAanwezig();
  }
  
}

// --- Actions --- //
void stoplichtControl_treinAanwezig(){
  ledControl_ledUit(stoplichtNoordGroenPin);
  ledControl_ledUit(stoplichtZuidGroenPin);
  ledControl_ledUit(stoplichtNoordGeelPin);
  ledControl_ledUit(stoplichtZuidGeelPin);
  ledControl_ledAan(stoplichtNoordRoodPin);
  ledControl_ledAan(stoplichtZuidRoodPin);
  ledControl_ledLatenKnipperen(stoplichtNoordGeelPin);
  ledControl_ledLatenKnipperen(stoplichtZuidGeelPin);
  }

void stoplichtControl_StoplichtCycle(char eerstIngedrukteKnop){

    if (eerstKnopVerwerkt == false){
      
  }
}

void stoplichtControl_StoplichtPatroon(char eerstIngedrukteKnop){
  //
}

// --- Getters --- //

int getStoplichtZuidRoodPin(){
  return stoplichtZuidRoodPin;
}

int getStoplichtZuidGeelPin(){
  return stoplichtZuidGeelPin;
}

int getStoplichtZuidGroenPin(){
  return stoplichtZuidGroenPin;
}

int getStoplichtNoordRoodPin(){
  return stoplichtNoordRoodPin;
}

int getStoplichtNoordGeelPin(){
  return stoplichtNoordGeelPin;
}

int getStoplichtNoordGroenPin(){
  return stoplichtNoordGroenPin;
}

// ---Setters -----//
void setEersteKnopVerwerkt(boolean status){
  eerstKnopVerwerkt = status;
}

//-----------------------Zuid-----------------------//
// --- Stoplicht_Zuid_Rood State --- //
void Stoplicht_Zuid_Rood_Entry(){
  ledControl_ledAan(stoplichtZuidRoodPin);
}

void Stoplicht_Zuid_Rood_Do(){
  //TODO
}

void Stoplicht_Zuid_Rood_Exit(){
  ledControl_ledUit(stoplichtZuidRoodPin);
}

// --- Stoplicht_Zuid_Geel State --- //
void Stoplicht_Zuid_Geel_Entry(){
  ledControl_ledAan(stoplichtZuidGeelPin);
  //StartTimer
}

void Stoplicht_Zuid_Geel_Do(){
  //GetTimer
}

void Stoplicht_Zuid_Geel_Exit(){
  ledControl_ledUit(stoplichtZuidGeelPin);
}

// --- Stoplicht_Zuid_Groen State --- //
void Stoplicht_Zuid_Groen_Entry(){
  ledControl_ledAan(stoplichtZuidGroenPin);
}

void Stoplicht_Zuid_Groen_Do(){
  //TODO
}

void Stoplicht_Zuid_Groen_Exit(){
  ledControl_ledUit(stoplichtZuidGroenPin);
}


// -----------------------Noord-----------------------//
// --- Stoplicht_Noord_Rood State --- //
void Stoplicht_Noord_Rood_Entry(){
  ledControl_ledAan(stoplichtNoordRoodPin);
}

void Stoplicht_Noord_Rood_Do(){
  //TODO
}

void Stoplicht_Noord_Rood_Exit(){
  ledControl_ledUit(stoplichtNoordRoodPin);
}

// --- Stoplicht_Noord_Geel State --- //
void Stoplicht_Noord_Geel_Entry(){
  ledControl_ledAan(stoplichtNoordGeelPin);
  //StartTimer
}

void Stoplicht_Noord_Geel_Do(){
  //GetTimer
}

void Stoplicht_Noord_Geel_Exit(){
  ledControl_ledUit(stoplichtNoordGeelPin);
}

// --- Stoplicht_Noord_Groen State --- // 
void Stoplicht_Noord_Groen_Entry(){
  ledControl_ledAan(stoplichtNoordGroenPin);
}

void Stoplicht_Noord_Groen_Do(){
  //TODO
}

void Stoplicht_Noord_Groen_Exit(){
  ledControl_ledUit(stoplichtNoordGroenPin);
}