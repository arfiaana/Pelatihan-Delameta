int pinLDR = PA6; 
int pinIR = PA7;
int kunci = 0;

int Red = PA0;
int Yellow = PA1;
int Green= PA2;


void setup() {
  
  Serial.begin(9600);
  pinMode(pinLDR,INPUT);
  pinMode(pinIR,INPUT);
  pinMode(Red,OUTPUT);
  pinMode(Yellow,OUTPUT);
  pinMode(Green,OUTPUT);
  
}

void loop() {
  // BACA DATA
    int bacaLDR=analogRead(pinLDR);
        bacaLDR=map (bacaLDR,149,4095,0,255);
    int bacaIR=digitalRead(pinIR);
 

  //PRINT TO SERIAL 
    Serial.print( " NILAI LDR : " );
    Serial.print(bacaLDR);
    Serial.println();
    delay(200);

  //LOGIKA
  if (bacaIR==0 and kunci==0)
  {
    kunci=1;
    delay(200);
  }
  else if(bacaIR==0 and kunci==1)
  {
    digitalWrite(Red,LOW);
    digitalWrite(Yellow,LOW);
    digitalWrite(Green,LOW);
    kunci=0;
    delay(200);
  }
  
if(bacaLDR<=60 and kunci==1)
    {
      digitalWrite(Red,LOW);
      digitalWrite(Yellow,LOW);
      digitalWrite(Green,HIGH);
    }
    else if(bacaLDR>=60 and bacaLDR<=200 and kunci==1)
    {
      digitalWrite(Red,LOW);
      digitalWrite(Yellow,HIGH);
      digitalWrite(Green,LOW);
    }
    else if(bacaLDR>=200 and kunci==1)
    {
      digitalWrite(Red,HIGH);
      digitalWrite(Yellow,LOW);
      digitalWrite(Green,LOW);
    }
}
  
