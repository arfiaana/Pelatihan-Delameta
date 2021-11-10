#include<OneWire.h>
#include<DallasTemperature.h>

//INISIALISASI
int sensorSuhu =2;
int BUZZ = 3;
OneWire oneWire(sensorSuhu);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  sensors.begin ();
  pinMode (BUZZ,OUTPUT);

}

void loop() {
  // BACA PROGRAM
  sensors.requestTemperatures();
  float bacaSuhu = sensors.getTempCByIndex(0);

  //PRINT SERIAL
  Serial.print(" SUHU ");
  Serial.print(bacaSuhu);
  Serial.print(" C ");
  Serial.println();

  if(bacaSuhu>=30){
  digitalWrite(BUZZ,HIGH);
  delay(100);
  digitalWrite(BUZZ,LOW);
  delay(100);
}
  else{
}
}
