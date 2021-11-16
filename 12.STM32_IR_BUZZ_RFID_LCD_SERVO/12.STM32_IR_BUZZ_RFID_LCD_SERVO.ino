#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

String uidString;

int buzzer = PA0;
int sensorIR = PA1;
int kunci1 = 0;
int outServo = PA2;
Servo myservo;


#define SS_PIN PB1
#define RST_PIN PB0
MFRC522 mfrc522(SS_PIN, RST_PIN);  // create MFRC522 instance
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(outServo);
  lcd.begin();
  pinMode (buzzer,OUTPUT);
  pinMode (sensorIR,INPUT);
  SPI.begin();
  mfrc522.PCD_Init();
  bunyibuzzeroke();
  Serial.println( " TEMPELKAN KARTU " );
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("   TEMPELKAN ");
  lcd.setCursor(0,1); lcd.print("     KARTU     ");
  myservo.write(90); 
  delay(1000); 
  
}

void loop() 
{
  // BACA SENSOR
  int bacaIR=digitalRead(sensorIR);
  if(mfrc522.PICC_IsNewCardPresent() and kunci1==0)
  {
      readRFID();
      Serial.print( " Tag UID : " );
      Serial.println(uidString);
        if(uidString=="138-55-90-26")
        {
          kunci1=1;
          Serial.println("    BERHASIL    ");
          bunyibuzzeroke();
          lcd.clear();
          lcd.setCursor(0,0); lcd.print("    BERHASIL    ");
          delay(500);
          lcd.clear();
          Serial.print(" SILAHKAN MASUK ");
          Serial.println(); 
          lcd.setCursor(0,0); lcd.print(" SILAHKAN MASUK ");
           delay(500);
           myservo.write(180); //0-180
             delay(1000); //Jeda waktu perulagan seama 500 mili detik
        }
        else if(uidString!="138-55-90-26")
        {
   
          lcd.setCursor(0,0); lcd.print(" ");
          Serial.println(" KARTU TIDAK TERDAFTAR ");
          bunyibuzzersalah();
          lcd.clear();
          lcd.setCursor(0,0); lcd.print("   KARTU TIDAK   ");
          lcd.setCursor(0,1); lcd.print("   TERDAFTAR    ");
          delay(1000);
          lcd.clear();
          Serial.println("   TEMPELKAN KARTU    ");
          lcd.clear();
          lcd.setCursor(0,0); lcd.print("   TEMPELKAN ");
          lcd.setCursor(0,1); lcd.print("     KARTU     ");
          
        }
       
  }
  
  if(bacaIR==0 && kunci1==1)
  {
     bunyibuzzeroke();
     kunci1=0;
    Serial.print( " PALANG DITUTUP " );
    Serial.println(); 
    lcd.setCursor(0,0); lcd.print(" PALANG DITUTUP ");
    myservo.write(90); 
    delay(1000);   
    Serial.println("   TEMPELKAN KARTU    ");
    lcd.clear();
    lcd.setCursor(0,0); lcd.print("   TEMPELKAN ");
    lcd.setCursor(0,1); lcd.print("     KARTU     ");
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
    delay(50);
    digitalWrite(buzzer,LOW);
    delay(50);
    digitalWrite(buzzer,HIGH);
    delay(50);
    digitalWrite(buzzer,LOW);
    delay(50);
  }

void bunyibuzzersalah()
{
  digitalWrite(buzzer,HIGH);
  delay(500);
  digitalWrite(buzzer,LOW);
}
