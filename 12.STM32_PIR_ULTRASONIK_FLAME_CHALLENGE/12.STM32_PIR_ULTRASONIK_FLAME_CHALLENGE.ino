#include<NewPing.h>

//INISIAL
int pinPIR = PA1;
int pinFlame = PA0;
int kunci = 0;

int triger = PA3;
int echo = PA2;
int batas = 400;
NewPing cm(triger,echo,batas);

int Red = PA6;
int Yellow = PA7;
int Green = PB0;


void setup() {
  
  Serial.begin(9600);
  pinMode(pinPIR,INPUT);
  pinMode(pinFlame,INPUT);
  pinMode(Red,OUTPUT);
  pinMode(Yellow,OUTPUT);
  pinMode(Green,OUTPUT);
  

}

void loop() {
//BACA DATA
  int bacaFlame=analogRead(pinFlame);
      
  int bacaPIR=digitalRead(bacaPIR);
  int bacaJarak=cm.ping_cm();

//PRINT TO SERIAL
Serial.print( " PIR : " );
Serial.print(bacaPIR);
Serial.println();
Serial.print( " Jarak : " );
Serial.print(bacaJarak);
Serial.println();
Serial.print( " Flame : " );
Serial.print(bacaFlame);
Serial.println();
delay(200);

//LOGIKA 
if(bacaFlame<=500 and kunci==0)
  {
    kunci=1;
    delay(100);
  }
else if(bacaFlame<=500 and kunci==1)
  {
    digitalWrite(Red,LOW);
    digitalWrite(Yellow,LOW);
    digitalWrite(Green,LOW);
    kunci=0;
    delay(100);
  }
else if(bacaJarak>=200 and kunci==1)
  {
    flipflop();
  }
else if(bacaJarak<=200 and bacaJarak>=19 and kunci==1)
  {
    lampusedang();
  }
else if(bacaJarak<=10 and kunci==1)
  {
   lampudekat();
  }
}

void flipflop(){
  digitalWrite(Red,HIGH);
  delay(50);
  digitalWrite(Red,LOW);
  digitalWrite(Yellow,HIGH);
  delay(50);
  digitalWrite(Yellow,LOW);
  digitalWrite(Green,HIGH);
  delay(50);
  digitalWrite(Green,LOW);
}

void lampusedang(){
  digitalWrite(Red,HIGH);
  digitalWrite(Yellow,HIGH);
  digitalWrite(Green,HIGH);
  delay(1000);
  digitalWrite(Red,LOW);
  digitalWrite(Yellow,LOW);
  digitalWrite(Green,LOW);
  delay(1000);
}

void lampudekat(){
  digitalWrite(Red,HIGH);
  digitalWrite(Yellow,HIGH);
  digitalWrite(Green,HIGH);
  delay(100);
  digitalWrite(Red,LOW);
  digitalWrite(Yellow,LOW);
  digitalWrite(Green,LOW);
  delay(100);
}
  
