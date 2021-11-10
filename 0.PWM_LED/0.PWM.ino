

void setup() {
 for(float i=5; i<=7; i++) {
  pinMode(i,OUTPUT);
 }

}

void loop() {
for(float i=0; i<=255; i++){
  analogWrite(5,i);
  delay(200);
}
for(float i=255; i<=0; i--){
  analogWrite(5,i);
  delay(200);
}


}
