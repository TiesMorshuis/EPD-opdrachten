void setup() {
  displayControl_Setup();
  slagboomControl_Setup();
  buzzerControl_Setup();
  ledControl_Setup();
  buttonControl_Setup();
}

//treinstatus aanpassen moet als EXIT!
void loop() {
  char ingedrukteKnop = getButtonPressed();
  stoplichtLoop();
  switch(ingedrukteKnop){
    case 'N':
      if(slagboomControl_isSlagboomOpen() == true){
        setEerstIngedrukteKnop(ingedrukteKnop);
      }
      //case Noord
      break;
    case 'O':
      //case Oost
      if (treinActions_getIsTreinVoorbij() == false){
        treinActions_setIsTreinVoorbij(true);

      } else {
        treinActions_setIsTreinVoorbij(false);
        slagboom_DichtGaan_Entry();
        slagboom_DichtGaan_Do();
      }
      break;
    case 'Z':
      //case Zuid;
      break;
    case 'W':
      //case West;
      if (treinActions_getIsTreinVoorbij() == false){
        treinActions_setIsTreinVoorbij(true);
      } else {
        treinActions_setIsTreinVoorbij(false);
      }
      break;
  }
  
}
