int delaytime;
int maxPhase;
int minPhase;
int maxDelay;
int minDelay;

void setup() {
  Serial.begin(9600);

  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(6, INPUT);

  pinMode(3, OUTPUT);
  
  delaytime = 5000;
  maxPhase = 160; // maximaler Winkel in Grad
  minPhase = 5; // minimaler Winkel in Grad

  maxDelay = 10000 / 180 * maxPhase;
  minDelay = 10000 / 180 * minPhase;
}


void loop() {
  if(digitalRead(0) == HIGH) delaytime += 10;
  if(digitalRead(1) == HIGH) delaytime -= 10;
  
  if(delaytime > maxDelay) delaytime = maxDelay;
  if(delaytime < minDelay) delaytime = minDelay;

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

  Serial.println(delaytime);
}