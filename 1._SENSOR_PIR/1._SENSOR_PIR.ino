int pinPIR=2;
int pinBUZZER=5;


void setup() {
  Serial.begin(9600);
  pinMode(pinPIR,INPUT);
  pinMode(pinBUZZER,OUTPUT);

}

void loop() {
  //BACA SESNOR
  int bacaPIR=digitalRead(pinPIR);

  //PRINT TO SERIAL
  Serial.print("PIR");
  Serial.print(bacaPIR);
  Serial.println();//UNTUK ENTER

  //LOGIKA
  if(bacaPIR=1){
    Serial.println("AWAS ADA MALING!!!");
    digitalWrite(pinBUZZER,HIGH);
    delay(100);
    digitalWrite(pinBUZZER,LOW);
    delay(100);
  }else{
    Serial.println("AMAN BOSS QU");
    digitalWrite(pinBUZZER,LOW);
  }
  

}
