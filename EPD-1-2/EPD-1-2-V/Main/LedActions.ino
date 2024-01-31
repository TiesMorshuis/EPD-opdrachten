int CONTROLLED_TIJD_BEREKENEN(int hz) {
  int periode = 1000 / hz;
  int tijd = periode / 2;
  return tijd;
}

void CONTROLLED_HEEN_EN_WEER(int CONTROLLED_PINARRAY[], int CONTROLLED_PINARRAY_SIZE, int Tijd) {
  for (int index = 0; index < CONTROLLED_PINARRAY_SIZE; index++) {
    CONTROLLED_OFF(index);
  }
  for (int index = 0; index < CONTROLLED_PINARRAY_SIZE; index++) {
    CONTROLLED_ON(index);
    delay(Tijd);
  }
}

void CONTROLLED_SAMENVOEGEN(int CONTROLLED_PINARRAY[], int CONTROLLED_PINARRAY_SIZE, int Tijd) {
  for (int index = 0; index < CONTROLLED_PINARRAY_SIZE; index++) {
    CONTROLLED_OFF(index);
  }
  int indexLinks = 0;
  int indexRechts = 7;
  for (int AantalKeerBranden = 0; AantalKeerBranden <= 4; AantalKeerBranden++) {
    CONTROLLED_ON(CONTROLLED_PINARRAY[indexLinks]);
    CONTROLLED_ON(CONTROLLED_PINARRAY[indexRechts]);
    delay(Tijd);
    indexLinks = indexLinks + 1;
    indexRechts = indexRechts - 1;
  }
}

