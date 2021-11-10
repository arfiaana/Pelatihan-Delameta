int tombol1=3;
int SensorIR=2;

int R=5;
int Y=6;
int G=7;

void setup() {
  Serial.begin(9600);
  pinMode(tombol1,INPUT);
  pinMode(SensorIR,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode (G,OUTPUT);

}

void loop() {
  //BACA DATA
 int bacatomboll=digitalRead(tombol1);
 int bacaIR=digitalRead(SensorIR);

 //PRINT SERIAL
  Serial.print("tombol 1:");
 Serial.print(bacatomboll);
 Serial.print(" | Sensor IR:");
 Serial.print(bacaIR);
 Serial.println();//UNTUK ENTER

 //LOGIKA
 if(bacaIR==0){
  digitalWrite(R,HIGH);
 }else{
  digitalWrite(R,LOW);
 }
}
