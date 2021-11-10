int tomboll=2;
int tombolll=3;
int tombollll=4;
int R=5;
int Y=6;
int G=7;

void setup() {
  Serial.begin(9600);
  pinMode(tomboll,INPUT);
  pinMode(tombolll,INPUT);
   pinMode(tombollll,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
 

}

void loop() {
  int bacatomboll=digitalRead(tomboll);
  Serial.println("kondisi tombol:" +String(bacatomboll));
  int bacatombolll=digitalRead(tombolll);
  Serial.println("kondisi tombol:" +String(bacatombolll));
  int bacatombollll=digitalRead(tombollll);
  Serial.println("kondisi tombol:" +String(bacatombollll));

  if(bacatomboll==1){
  digitalWrite(R,HIGH);
  }else{
  if(bacatomboll==0)
   digitalWrite(R,LOW); 
  }
   if(bacatombolll==1){
  digitalWrite(Y,HIGH);
  }else{
    if(bacatombolll==0)
   digitalWrite(Y,LOW);
  }
   if(bacatombollll==1){
  digitalWrite(G,HIGH);
  }else{
    if(bacatombollll==0)
   digitalWrite(G,LOW);
  }

}
