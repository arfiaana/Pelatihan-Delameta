#include<NewPing.h>

//INISIAL
int triger = 5;
int echo = 4;
int batas = 400;
int pinR = 6;
int pinY = 7;
int pinG =8;
int BUZZ = 3;


NewPing cm(triger,echo,batas);

void setup() {
  // BACA SENSOR
  Serial.begin(115200);
  pinMode (pinR,OUTPUT);
  pinMode (pinY,OUTPUT);
  pinMode (pinG,OUTPUT);
  pinMode (BUZZ,OUTPUT);

}

void loop() {
  //BACA DATA
  int bacaJarak=cm.ping_cm();

  //PRINT TO SERIAL
  Serial.print(" Data Jarak: ");
  Serial.print(bacaJarak);
  Serial.print(" cm ");
  Serial.println();
  delay(500);

  //LOGIKA 
  if(bacaJarak <=20 and bacaJarak!=0 )
  {
  Serial.println ( " BERHENTI ");
  digitalWrite(pinR,HIGH);
  digitalWrite(pinY,LOW);
  digitalWrite(pinG,LOW);
  digitalWrite (BUZZ,HIGH);
  delay(50);
  digitalWrite(BUZZ,LOW);
  delay(50);
  }

  else if(bacaJarak >=21 and bacaJarak <=71)
  {
    Serial.println ( " BAHAYA ");
    digitalWrite(pinR,LOW);
    digitalWrite(pinY,HIGH);
    digitalWrite(pinG,LOW);
    digitalWrite(BUZZ,HIGH);
    delay(300);
    digitalWrite(BUZZ,LOW);
    delay(300);
  }
  else if(bacaJarak >=71)
  {
    Serial.print( " AMAN " );
    digitalWrite(pinR,LOW);
    digitalWrite(pinY,LOW);
    digitalWrite(pinG,HIGH);
  }
}
 
