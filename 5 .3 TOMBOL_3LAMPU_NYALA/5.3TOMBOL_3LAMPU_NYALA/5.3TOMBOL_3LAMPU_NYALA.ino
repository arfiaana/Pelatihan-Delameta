int tombol1=2;
int tombol2=3;

int kunci1=0;
int kunci2=0;

int R=5;
int Y=6;
int G=7;

void setup() {
  Serial.begin(9600);
  pinMode(tombol1,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
}

void loop() {
   int bacaTombol1=digitalRead(tombol1);
   int bacaTombol2=digitalRead(tombol2);
   Serial.println("Tombol 1:" + String(bacaTombol1) + 
   "Tombol 2:" + String(bacaTombol2) + 
   " | " + String (kunci1));  
   
    if (bacaTombol1==1 and kunci1==0){ 
      delay(500);
      Serial.println("LED ON");
      digitalWrite(R,HIGH);
      kunci1=1; 
    }else if (bacaTombol1==1 && kunci1==1){ 
      delay(500);
      Serial.println("LED OFF");
      digitalWrite(R,LOW);
      kunci1=0; 
    }  

    if (bacaTombol2==1 and kunci2==0){ 
      delay(500);
      Serial.println("LED 2 ON");
      digitalWrite(Y,HIGH);
      kunci2=1; 
    }else if (bacaTombol2==1 && kunci2==1){ 
      delay(500);
      Serial.println("LED 2 OFF");
      digitalWrite(Y,LOW);
      kunci2=0; 
    }  
    
}
