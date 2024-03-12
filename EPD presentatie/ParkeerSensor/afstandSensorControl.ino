const int echoPin = 8;
const int trigPin = 9;
float duration, distance;

void afstandSensorControl_Setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float afstandSensorControl_AfstandBerekenen() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;
  return distance;
}