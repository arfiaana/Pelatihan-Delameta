int tomboll=2;
int tombolll=3;
int R=5;

void setup() {
  Serial.begin(9600);
  pinMode(tomboll,INPUT);
  pinMode(tombolll,INPUT);
  pinMode(R,OUTPUT);
  

}

void loop() {
 int bacatomboll=digitalRead(tomboll);
  Serial.println("kondisi tombol:" +String(bacatomboll));
  int bacatombolll=digitalRead(tombolll);
  Serial.println("kondisi tombol:" +String(bacatombolll));


  if(bacatomboll==1){
  digitalWrite(R,HIGH);
  }else{
   digitalWrite(R,LOW); 
 if(bacatombolll==1){
  digitalWrite(R,HIGH);
  }else{
   digitalWrite(R,LOW); 
  }
  }
}
