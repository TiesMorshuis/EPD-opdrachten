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
      if(slagboomControl_isSlagboomOpen() == true && getEerstIngedrukteKnop() == NULL){
        setEerstIngedrukteKnop(ingedrukteKnop);
      }
      //case Noord
      break;
    case 'O':
      //case Oost
      if (treinActions_getIsTreinAanwezig() == false){
        treinActions_setIsTreinAanwezig(true);

      } else {
        treinActions_setIsTreinAanwezig(false);
        slagboom_DichtGaan_Entry();
        
      }
      break;
    case 'Z':
      //case Zuid;
        if(slagboomControl_isSlagboomOpen() == true && getEerstIngedrukteKnop() == NULL){
          setEerstIngedrukteKnop(ingedrukteKnop);
        }
      break;
    case 'W':
      //case West;
      if (treinActions_getIsTreinAanwezig() == false){
        treinActions_setIsTreinAanwezig(true);
      } else {
        treinActions_setIsTreinAanwezig(false);
        slagboom_DichtGaan_Entry();
      }
      break;
  }
  
}
