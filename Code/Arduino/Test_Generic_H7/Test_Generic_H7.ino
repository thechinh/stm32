void setup() {
  // put your setup code here, to run once:
  pinMode(PB0, OUTPUT);
  pinMode(PB14, OUTPUT);
  pinMode(PE1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PB0, HIGH);
  digitalWrite(PB14, HIGH);
  digitalWrite(PE1, HIGH);
  delay(500);
  digitalWrite(PB0, LOW);
  digitalWrite(PB14, LOW);
  digitalWrite(PE1, LOW);
  delay(500);
}
