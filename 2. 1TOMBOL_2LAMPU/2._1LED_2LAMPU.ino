int tomboll=2;
int R=5;
int Y=6;

void setup() {
  Serial.begin(9600);
  pinMode(tomboll,INPUT);
  pinMode(R,OUTPUT);
  pinMode (Y,OUTPUT);
  

}

void loop() {
 int bacatomboll=digitalRead(tomboll);
  Serial.println("kondisi tombol:" +String(bacatomboll));


  if(bacatomboll==1){
  digitalWrite(R,HIGH);
  }else{
   digitalWrite(R,LOW); 
  if(bacatomboll==1){
  digitalWrite(Y,HIGH);
  }else{
   digitalWrite(Y,LOW); 
 
  }
  }
}
