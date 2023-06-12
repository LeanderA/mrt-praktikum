int delaytime;
int maxPhase;
int minPhase;
int maxDelay;
int minDelay;
int countPhase;
bool lampState;

void setup() {
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(6, INPUT);
  pinMode(9, INPUT);
  
  pinMode(3, OUTPUT);

  lampState = true;
  
  delaytime = 5000;
  maxPhase = 160; // maximaler Winkel in Grad
  minPhase = 5; // minimaler Winkel in Grad
  countPhase = 0;

  maxDelay = 10000 / 180 * maxPhase;
  minDelay = 10000 / 180 * minPhase;

  attachInterrupt(digitalPinToInterrupt(9), phaseCut, RISING);
}

void loop() {
  if(digitalRead(0) == HIGH) delaytime += 10;
  if(digitalRead(1) == HIGH) delaytime -= 10;
  
  if(delaytime > maxDelay) delaytime = maxDelay;
  if(delaytime < minDelay) delaytime = minDelay;

  delayMicroseconds(10000);
}

void phaseCut() {
  if (lampState == true){
    delayMicroseconds(delaytime);
    digitalWrite(3, HIGH);
    delayMicroseconds(10);
    digitalWrite(3, LOW);
  }
  else{
    digitalWrite(3, HIGH);
    delayMicroseconds(10);
    digitalWrite(3, LOW);
  }

  countPhase ++;
  if (countPhase >= 50){
    countPhase = 0;
    lampState = !lampState;
  }
}