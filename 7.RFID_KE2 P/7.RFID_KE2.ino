#include <SPI.h>
#include <MFRC522.h>

String uidString;

int buzzer = 3;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);  // create MFRC522 instance

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (buzzer,OUTPUT);
  SPI.begin();
  mfrc522.PCD_Init();
  bunyibuzzeroke();
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if(mfrc522.PICC_IsNewCardPresent())
  {
  readRFID();
  Serial.print( " Tag UID : " );
  Serial.println(uidString);
  }
}

void readRFID()
  {
    mfrc522.PICC_ReadCardSerial();
    //SOUND THE BUZZER WHEN A CARD IS READ
    bunyibuzzeroke();
    //PEMBATAS BISA DIRUBAH SESUAI KEINGINAN, DISINI YANG DIGUNAKAN "-"
    uidString = String(mfrc522.uid.uidByte[0]) + "-" +
    String(mfrc522.uid.uidByte[1]) + "-" +
    String(mfrc522.uid.uidByte[2]) + "-" +
    String(mfrc522.uid.uidByte[3]);
 
  }
  
void bunyibuzzeroke()
  {
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    delay(100);
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    delay(100);
  }

void bunyibuzzersalah()
{
  digitalWrite(buzzer,HIGH);
  delay(1000);
}
