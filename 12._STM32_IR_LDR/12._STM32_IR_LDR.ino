int pinLDR = PA0;
int pinIR = PA1;
int kunci = 0;

int Red = PA6;
int Yellow = PA7;
int Green = PB0;

void setup() {

  Serial.begin(9600);
  pinMode(pinIR,INPUT);
  pinMode(pinLDR,INPUT);
  pinMode(Red,OUTPUT);
  pinMode(Yellow,OUTPUT);
  pinMode(Green,OUTPUT);

}

void loop() {
  // BACA DATA
  int bacaLDR=analogRead (pinLDR);
      bacaLDR=map (bacaLDR,149,4095,0,255);
  int bacaIR=digitalRead(pinIR);

    //PRINT TO SERIAL 
    Serial.print( " NILAI : " );
    Serial.print(bacaLDR);
    Serial.println();
    delay(200);

    //LOGIKA
    analogWrite(Red,bacaLDR);

    if(bacaIR==0 and kunci==0) 
    {
      digitalWrite(Yellow,HIGH);
      delay(100);
      kunci=1;
    }
    else
    if(bacaIR==0 and kunci==1)
    {
      digitalWrite(Yellow,LOW);
      delay(300);
      kunci=0;
    }
}
