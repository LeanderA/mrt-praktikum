int count;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(6, INPUT);
  pinMode(3, OUTPUT);
  count = 0;
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(3, LOW);
  while(digitalRead(6) == LOW) {
    delayMicroseconds(1);
  }
  digitalWrite(3, HIGH);
  count++;
  Serial.println(count);
  while(digitalRead(6) == HIGH) {
    delayMicroseconds(1);
  }
}