#include <SPI.h>
#include <MFRC522.h>

String uidString;

int buzzer = 2;
int sensorIR = 3;
int kunci1 = 0;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);  // create MFRC522 instance

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (buzzer,OUTPUT);
  pinMode (sensorIR,INPUT);
  SPI.begin();
  mfrc522.PCD_Init();
  bunyibuzzeroke();
  Serial.println( " TEMPELKAN KARTU " );
}

void loop() 
{
  // put your main code here, to run repeatedly:
  int bacaIR=digitalRead(sensorIR);
  if(mfrc522.PICC_IsNewCardPresent() and kunci1==0)
  {
      readRFID();
      Serial.print( " Tag UID : " );
      Serial.println(uidString);
        if(uidString=="138-55-90-26"){
          kunci1=1;
        Serial.println( " BERHASIL " );
        bunyibuzzeroke();
        }
        else
        {
          Serial.println( " GAGAL " );
          bunyibuzzersalah();
          kunci1=0;
        }
  }
  
  if(bacaIR==0 && kunci1==1)
  {
  bunyibuzzeroke();
  kunci1=0;
  Serial.print( " SILAHKAN MASUK ");
  Serial.println(); 
  delay(1000);
  Serial.print( " PALANG DITUTUP " );
  Serial.println(); 
  delay(1000); 
  Serial.println( " TEMPELKAN KARTU ");
  
  }
  
}

void readRFID()
  {
    mfrc522.PICC_ReadCardSerial();
    //SOUND THE BUZZER WHEN A CARD IS READ
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
  digitalWrite(buzzer,LOW);
}
