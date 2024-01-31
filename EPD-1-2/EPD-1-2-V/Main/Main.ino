void setup(){
  CONTROLLED_SETUP(CONTROLLED_GET_PINARRAY(), CONTROLLED_GET_PINARRAY_SIZE());
  SERIALSETUP();
}
void loop(){ 
  //CONTROLLED_HEEN_EN_WEER(CONTROLLED_GET_PINARRAY(), CONTROLLED_GET_PINARRAY_SIZE(), CONTROLLED_TIJD_BEREKENEN(5));
  //CONTROLLED_SAMENVOEGEN(CONTROLLED_GET_PINARRAY(), CONTROLLED_GET_PINARRAY_SIZE(), CONTROLLED_TIJD_BEREKENEN(2));
  /*if (Serial.available() > 0) {
    char karakter = Serial.read();
    Serial.print("Ontvangen karakter: ");
    Serial.println(karakter);
  }*/
  lampjeBranden();
}




