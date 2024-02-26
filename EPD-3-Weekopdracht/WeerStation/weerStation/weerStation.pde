import processing.serial.*;

Serial serielePoort;
final int BAUDRATE = 9600;
final int EINDTEKEN = 127;

void setup(){

   String portName = "COM3";
   serielePoort = new Serial(this, portName, BAUDRATE);
}

void draw() {
 if (serielePoort.available() > 0) {
  String gelezenWaarden = serielePoort.readStringUntil(EINDTEKEN);
  println(gelezenWaarden);
 }
}
