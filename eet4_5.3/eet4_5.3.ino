int delaytime;

void setup() {
  Serial.begin(9600);
  pinMode(6, INPUT);
  pinMode(3, OUTPUT);
  delaytime = 7000;
}

void loop() {
  while(digitalRead(6) == LOW) {
    delayMicroseconds(1);
  }

  delayMicroseconds(delaytime);

  digitalWrite(3, HIGH);
  delayMicroseconds(10);
  digitalWrite(3, LOW);

  while(digitalRead(6) == HIGH) {
    delayMicroseconds(1);
  }
}