void setup() {
  // put your setup code here, to run once:
  pinMode(14, OUTPUT);
  pinMode(0, INPUT);
  pinMode(1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(0) == HIGH) {
    digitalWrite(14, HIGH);
  } else if(digitalRead(1) == HIGH) {
    digitalWrite(14, LOW);
  }
}