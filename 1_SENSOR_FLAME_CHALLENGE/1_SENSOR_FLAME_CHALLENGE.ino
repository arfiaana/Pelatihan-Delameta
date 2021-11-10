int pinFlame = A1;
int BUZZ = 5;

void setup() {
  Serial.begin(9600);
  pinMode (BUZZ,OUTPUT);

}

void loop() {
  //BACA DATA
    int bacaFlame=analogRead (pinFlame);
       bacaFlame=map (bacaFlame,0,1015,100,0);

    //PRINT TO SERIAL
    Serial.print("NILAI :");
    Serial.print(bacaFlame);
    Serial.println();
    delay(100);

    //LOGIKA
    if(bacaFlame==0){
      Serial.print("AMAN SAYY");
    }else{
      if(bacaFlame>=50 and bacaFlame <80){
        Serial.println("WARNING SILAHKAN PERIKSA");
        digitalWrite(BUZZ,HIGH);
        delay(500);
        digitalWrite(BUZZ,LOW);
        delay(500);
      }else{
        if(bacaFlame>=80){
          Serial.println(" WASPADA HARAP MENUNGGU");
          digitalWrite(BUZZ,HIGH);
          delay(100);
          digitalWrite(BUZZ,LOW);
          delay(100);
        }
        }
        
      }
    }
