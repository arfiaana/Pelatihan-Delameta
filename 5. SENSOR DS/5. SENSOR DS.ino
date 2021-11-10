#include<OneWire.h>
#include<DallasTemperature.h>

int sensorsuhu =2;
OneWire oneWire(sensorsuhu);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  Sensors.begin ();

}

void loop() {
  // put your main code here, to run repeatedly:

}
