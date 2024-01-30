int tijd_berekenen(int hz){
  int periode = 1000/hz;
  int tijd = periode/2;
  return tijd;
}

void heen_en_weer(int StartPin, int Aantal_Lampjes, int Tijd){
  for (int LED = StartPin; LED <= ((StartPin + Aantal_Lampjes) - 1); LED++){
    LEDCONTROL_ON(LED);
    delay(Tijd);
    LEDCONTROL_OFF(LED);
  }
  //for (int lampje = startpin; lampje <= ((startpin + aantal_lampjes) - 1); lampje++){
  //  ledUit(lampje);
  //}
  
  for (int LED = ((StartPin + Aantal_Lampjes) - 1); LED >= StartPin; LED--){
    LEDCONTROL_ON(LED);
    delay(Tijd);
    LEDCONTROL_OFF(LED);
  }

}