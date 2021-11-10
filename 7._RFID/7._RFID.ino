#include <SPI.h>
#include <MFRC522.h>
//Inisialisasi pembuatan variable
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 
void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); 
 SPI.begin(); 
 mfrc522.PCD_Init();
}
void loop() {
 //Program yang akan dijalankan berulang-ulang
 if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
 // Select one of the cards
 if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
 
 //Show UID on serial monitor
 Serial.print("UID tag :");
 String content= "";
 byte letter;
 for (byte i = 0; i < mfrc522.uid.size; i++) 
 {
 Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
 Serial.print(mfrc522.uid.uidByte[i], HEX);
 content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
 content.concat(String(mfrc522.uid.uidByte[i], HEX));
 }
 Serial.println();
 Serial.print("Message : ");
 content.toUpperCase();
 
 if (content == "04516732885B80") 
 {
 Serial.println(" Selamat datang !!!");
 delay(2000);
  }else if(content== "65B07B28"){
  Serial.println ( " SILAKAN MASUK ");
  delay(2000);
 }
 else{
 Serial.println(" Kartu Belum Terdaftar!");
 }
 Serial.println(" Tempelkan Kartu!");
 delay(500); //Jeda waktu perulagan seama 500 mili detik
}
