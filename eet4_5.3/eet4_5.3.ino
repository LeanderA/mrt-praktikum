int delaytime;
int maxPhase;
int minPhase;
int maxDelay;
int minDelay;

void setup() {
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(6, INPUT);
  pinMode(9, INPUT);
  
  pinMode(3, OUTPUT);
  
  delaytime = 5000;
  maxPhase = 160; // maximaler Winkel in Grad
  minPhase = 5; // minimaler Winkel in Grad

  maxDelay = 10000 / 180 * maxPhase;
  minDelay = 10000 / 180 * minPhase;

  attachInterrupt(digitalPinToInterrupt(9), phaseCut, RISING);
}

void loop() {
  if(digitalRead(0) == HIGH) delaytime += 10;
  if(digitalRead(1) == HIGH) delaytime -= 10;
  
  if(delaytime > maxDelay) delaytime = maxDelay;
  if(delaytime < minDelay) delaytime = minDelay;

  delay(10);
}

void phaseCut() {
  delayMicroseconds(delaytime);
  digitalWrite(3, HIGH);
  delayMicroseconds(10);
  digitalWrite(3, LOW);
}