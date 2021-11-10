int pinFlame = A1;
int pinLDR = A0;
int pinPIR=2;
int pinR=3;
int pinY=4;
int pinG=5;
int BUZZ = 6;


void setup() {
  Serial.begin(9600);
  pinMode (pinPIR,INPUT);
  pinMode (pinR,OUTPUT);
  pinMode (pinY,OUTPUT);
  pinMode (pinG,OUTPUT);
  pinMode (BUZZ,OUTPUT);

}

void loop() {
  //BACA DATA
    int bacaFlame=analogRead (pinFlame);
    int bacaLDR=analogRead (pinLDR);
    int bacaPIR=digitalRead (pinPIR);

    //PRINT TO SERIAL
    Serial.print(" LDR    :");
    Serial.print(bacaLDR);
    Serial.println();
    Serial.print(" Flame :");
    Serial.print(bacaFlame);
    Serial.println();
    Serial.print(" PIR    :");
    Serial.print(bacaPIR);
    Serial.println();

//MAPPING
bacaLDR=map (bacaLDR,37,827,0,255);
bacaFlame=map (bacaFlame,32,427,100,0);

    //LOGIKA
    analogWrite(pinR,bacaLDR);
    if(bacaFlame<30){
     Serial.println("AMAN BANGET SAYY");
     digitalWrite(pinG,HIGH);
     digitalWrite(pinY,LOW);
    }
  else if(bacaFlame>30 and bacaFlame<80){
    Serial.println(" WARNING SILAHKAN PERIKSA ");
    digitalWrite(pinY,HIGH);
    digitalWrite(pinG,LOW);
    digitalWrite(BUZZ,HIGH);
    delay(500);
    digitalWrite(BUZZ,LOW);
    delay(500);
  }
    else if (bacaFlame>=80){
      Serial.println( " WASPADA HARAP MENGUNGSI " );
      digitalWrite(pinY,HIGH);
      digitalWrite(pinG,HIGH);
      digitalWrite(BUZZ,HIGH);
      delay(100);
      digitalWrite(BUZZ,LOW);
      delay(100);
    }    
    }
        
        
 
