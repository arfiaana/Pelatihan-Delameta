
#include <LiquidCrystal_I2C.h>
//Inisialisasi pembuatan variable
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 lcd.begin();
}
void loop() {
 //Program yang akan dijalankan berulang-ulang
float suhu=random(27.1,35.10);
 
 lcd.clear(); //Untuk Menghapus karakter pada LCD
 lcd.setCursor(0,0); lcd.print("SUHU");
 lcd.setCursor(4,0); lcd.print(":");
 lcd.setCursor(5,0); lcd.print(suhu);
 lcd.setCursor(10,0); lcd.print("c");
 delay(1000); //Jeda waktu perulagan seama 1000 mili detik

 
}
