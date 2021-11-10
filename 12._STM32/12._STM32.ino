void setup() {
  pinMode (PB13, OUTPUT);
  pinMode (PB14, OUTPUT);
  pinMode (PB15, OUTPUT);

}

void loop() {
  digitalWrite(PB13,HIGH);
  delay(1000);
  digitalWrite(PB13,LOW);
  delay(1000);
  digitalWrite(PB14,HIGH);
  delay(1000);
  digitalWrite(PB14,LOW);
  delay(1000);
  digitalWrite(PB15,HIGH);
  delay(1000);
  digitalWrite(PB15,LOW);
  delay(1000);
  

}
