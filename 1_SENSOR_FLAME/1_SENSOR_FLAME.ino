int pinFlame = A1;
int pinR = 3;

void setup() {
  Serial.begin(9600);
  pinMode (pinR,OUTPUT);

}

void loop() {
  //BACA DATA
    int bacaFlame=analogRead (pinFlame);
      // bacaFlame=map (bacaFlame,32,427,0,255);

    //PRINT TO SERIAL
    Serial.print("NILAI :");
    Serial.print(bacaFlame);
    Serial.println();

    //LOGIKA
 
    }
