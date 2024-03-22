const int stoplichtZuidRoodPin = 2;
const int stoplichtZuidGeelPin = 3;
const int stoplichtZuidGroenPin = 4;
const int stoplichtNoordRoodPin = 5;
const int stoplichtNoordGeelPin = 6;
const int stoplichtNoordGroenPin = 7;


void stoplichtSetup(){
  //todo
}

void stoplichtLoop(){
  //todo
}



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

// -----------------------Zuid-----------------------//
// ---Stoplicht_Zuid_Rood State-----
void Stoplicht_Zuid_Rood_Entry(){
  ledControl_ledAan(stoplichtZuidRoodPin);
}

void Stoplicht_Zuid_Rood_Do(){
  //TODO
}

void Stoplicht_Zuid_Rood_Exit(){
  ledControl_ledUit(stoplichtZuidRoodPin);
}

// ---Stoplicht_Zuid_Geel State-----
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

// ---Stoplicht_Zuid_Groen State-----
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
// ---Stoplicht_Noord_Rood State-----
void Stoplicht_Noord_Rood_Entry(){
  ledControl_ledAan(stoplichtNoordRoodPin);
}

void Stoplicht_Noord_Rood_Do(){
  //TODO
}

void Stoplicht_Noord_Rood_Exit(){
  ledControl_ledUit(stoplichtNoordRoodPin);
}

// ---Stoplicht_Noord_Geel State-----
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

// ---Stoplicht_Noord_Groen State-----
void Stoplicht_Noord_Groen_Entry(){
  ledControl_ledAan(stoplichtNoordGroenPin);
}

void Stoplicht_Noord_Groen_Do(){
  //TODO
}

void Stoplicht_Noord_Groen_Exit(){
  ledControl_ledUit(stoplichtNoordGroenPin);
}