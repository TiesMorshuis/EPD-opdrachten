const int rodePin = 6;
const int groenePin = 5;

const int trigPin = 9;
const int echoPin = 8;
float duration, distance;

void setup() {
  pinMode(rodePin, OUTPUT);
  pinMode(groenePin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);


  // put your setup code here, to run once:
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;
  if (distance >= 20){
    digitalWrite(rodePin, LOW);
    digitalWrite(groenePin, HIGH);
  } else if (distance < 20){
    digitalWrite(groenePin, LOW);
    digitalWrite(rodePin, HIGH);
  }

  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
  
}
