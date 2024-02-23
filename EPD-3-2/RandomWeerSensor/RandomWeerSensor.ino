byte temperatuur;
byte lichtsterkte;
char windrichting;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  temperatuur = genereerRandomGetal(0, 31);
  lichtsterkte = genereerRandomGetal(0, 126);
  windrichting = genereerWindrichting(windrichting);
  //Serial.println(temperatuur);
  //Serial.println(lichtsterkte);
  //Serial.println(windrichting);
}

byte genereerRandomGetal(int min, int max){
  byte getal = random(min, max);
  return getal;
}

char genereerWindrichting(char windrichting){
  int getal = random(1, 5);
  if (getal == 1){
    windrichting = "N";
  } else if (getal == 2){
    windrichting = "E";
  } else if (getal == 3){
    windrichting = "S";
  } else if (getal == 4){
    windrichting = "W";
  }
  Serial.println(windrichting);
  return windrichting;
}
