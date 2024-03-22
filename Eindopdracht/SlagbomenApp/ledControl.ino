const int numberOfLeds = 6;
const int ledArray[] = {2, 3, 4, 5, 6, 7};

void ledControl_Setup(){
  for (int index = 0; index < ledArray.length, index++){
    pinMode(ledArray[index], OUTPUT);
  }
}