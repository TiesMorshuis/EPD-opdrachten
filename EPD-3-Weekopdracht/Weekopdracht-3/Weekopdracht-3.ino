const byte DS = 8;      // Data Serial
const byte ST_CP = 9;   // Storage Clock Pulse
const byte SH_CP = 10;  // Shift Clock Puls
const byte N = B11101100;
const byte E = B11111100;
const byte S = B11011010;
const byte W = B01111100;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  shiftRegisterSetup();
  shiftRegisterOff();
}

void loop(){
  float temperatuur = getTemperatuurInGradenCelcius();
  byte windrichting = getWindrichting();
  shiftRegisterSet(windrichting);
  Serial.println(temperatuur);
  
  



}
float getTemperatuurInGradenCelcius() {
  const float vout0 = 400;  // sensor output voltage in mV at 0°C
  const float tc = 19.53;   // mV for °C temperature constant
  float vout_avg = 0;
  const int AANTAL_METINGEN = 1000;
  for (int i = 0; i < AANTAL_METINGEN; i++) {
    float vout = analogRead(A0) * (4976.30 / 1023);
    vout_avg = vout_avg + vout;
  }
  float vout = vout_avg / AANTAL_METINGEN;
  return (vout - vout0) / tc;
}

byte getWindrichting(){
  byte windrichting;
  int sensorGetal = analogRead(A1);
  int nieuwSensorGetal = map(sensorGetal, 0, 1023, 0, 359);
  
  if (nieuwSensorGetal >= 0 && nieuwSensorGetal < 90){
    windrichting = N;
  } else if (nieuwSensorGetal >= 90 && nieuwSensorGetal < 180){
    windrichting = E;
  } else if (nieuwSensorGetal >= 180 && nieuwSensorGetal < 270){
    windrichting = S;
  } else if (nieuwSensorGetal >= 270 && nieuwSensorGetal < 360){
    windrichting = W;
  }
  return windrichting;
}



void shiftRegisterSetup(){
  pinMode(DS, OUTPUT);
  pinMode(ST_CP, OUTPUT);
  pinMode(SH_CP, OUTPUT);
  digitalWrite(DS, LOW);
  digitalWrite(ST_CP, LOW);
  digitalWrite(SH_CP, LOW);
}
 
void shiftRegisterSet(byte patroon) {
  for(int index = 0; index < 8; index++) {
    if (bitRead(patroon, index)) {
      digitalWrite(DS, HIGH);
    } else {
      digitalWrite(DS, LOW);
    }
    digitalWrite(SH_CP, HIGH);
    digitalWrite(SH_CP, LOW);
  }
  digitalWrite(ST_CP, HIGH);
  digitalWrite(ST_CP, LOW);
}
 
void shiftRegisterOff(){
  for(int index=0; index < 8; index++){
    digitalWrite(DS, LOW);
    digitalWrite(SH_CP, HIGH);
    digitalWrite(SH_CP, LOW);
  }
  digitalWrite(ST_CP, HIGH);
  digitalWrite(ST_CP, LOW);
}
