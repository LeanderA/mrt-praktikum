int delaytime;
int maxPhase;
int minPhase;
int maxDelay;
int minDelay;
int countPhase;
bool lampState;

void setup() {
  // Input-Pins initialisieren
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(6, INPUT);
  pinMode(9, INPUT);
  
  
  pinMode(3, OUTPUT); // Triac-Steuer-Pin initialisieren

  lampState = true; // Lampe anfangs eingeschaltet haben
  
  delaytime = 5000; // die delay-Zeit zum Anfang, wenn noch kein Taster gedrückt wurde
  maxPhase = 160; // maximaler Winkel in Grad
  minPhase = 5; // minimaler Winkel in Grad

  countPhase = 0; // speichert Anzal der Halbschwingungen seit dem letzten Blinken

  // minimales und maximales Delay aus der Phase berechnen
  maxDelay = 10000 / 180 * maxPhase;
  minDelay = 10000 / 180 * minPhase;

  // das Interrupt auf Pin 9 aktivieren und der Funktion phaseCut zuweisen
  attachInterrupt(digitalPinToInterrupt(9), phaseCut, RISING);
}

// Hauptschleife
void loop() {
  // Taster auslesen und evtl delay verkleinern oder vergrößern
  if(digitalRead(0) == HIGH) delaytime += 10;
  if(digitalRead(1) == HIGH) delaytime -= 10;
  
  // Limit überprüfen und Zeit anpassen wenn zu groß oder zu klein
  if(delaytime > maxDelay) delaytime = maxDelay;
  if(delaytime < minDelay) delaytime = minDelay;

  // warten bevor erneuter Tasterabfrage
  delayMicroseconds(10000);
}

// Interrupt-Methode
void phaseCut() {
  // Falls Lampe an ist, das delay abwarten und danach Impuls auf Triac geben
  if (lampState == true){
    delayMicroseconds(delaytime);
    digitalWrite(3, HIGH);
    delayMicroseconds(10);
    digitalWrite(3, LOW);
  }
  // Falls Lampe aus ist, direkt Impuls geben
  else{
    digitalWrite(3, HIGH);
    delayMicroseconds(10);
    digitalWrite(3, LOW);
  }

  // Zähler erhöhen
  countPhase ++;
  
  // Falls Zähler 50 Halbschwingungen erreicht hat,
  // Lampe ein- bzw. ausschalten um sie einmal pro Sekunde blinken zu lassen.
  if (countPhase >= 50){
    countPhase = 0;
    lampState = !lampState;
  }
}