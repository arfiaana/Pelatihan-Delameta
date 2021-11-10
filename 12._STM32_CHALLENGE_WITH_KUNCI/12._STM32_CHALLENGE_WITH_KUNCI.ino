//INISIAL
int arfi_Red = PC13;
int arfi_Yellow = PC14;
int arfi_Green = PC15;

int arfi_tombol1 = PA1;
int arfi_tombol2 = PA2;
int arfi_tombol3 = PA3;

int kunci1=0;
int kunci2=0;
int kunci3=0;

void setup() {

  Serial.begin(9600);
  pinMode (arfi_tombol1,INPUT);
  pinMode (arfi_tombol2,INPUT);
  pinMode (arfi_tombol3,INPUT);
  pinMode (arfi_Red,OUTPUT);
  pinMode (arfi_Yellow,OUTPUT);
  pinMode (arfi_Green,OUTPUT);

}

void loop() {
  // BACA DATA 
   int bacaarfi_tombol1=digitalRead(arfi_tombol1);
   int bacaarfi_tombol2=digitalRead(arfi_tombol2);
   int bacaarfi_tombol3=digitalRead(arfi_tombol3);

  //PRINT TO SERIAL
  Serial.print( " arfi_tombol1 : " );
  Serial.print(bacaarfi_tombol1);
  Serial.print( " - arfi_tombol2 : " );
  Serial.print(bacaarfi_tombol2);
  
  Serial.print( " - arfi_tombol3 : " );
  Serial.print(bacaarfi_tombol3);
  Serial.println(); // untuk enter

  //LOGIKA
  if (bacaarfi_tombol1==1 and kunci1==0){
     digitalWrite(arfi_Red,HIGH);
     kunci1=1;
     delay(500);
  }
  else if (bacaarfi_tombol1==1 and kunci1==1) {
     digitalWrite(arfi_Red,LOW);
     kunci1=0;
     delay(500);
  }
  if (bacaarfi_tombol2==1 and kunci2==0){
     digitalWrite(arfi_Yellow,HIGH);
     kunci2=1;
     delay(500);
  }
  else if (bacaarfi_tombol2==1 and kunci2==1){
     digitalWrite(arfi_Yellow,LOW);
     kunci2=0;
     delay(500);
  }
  if (bacaarfi_tombol3==1 and kunci3==0){
     digitalWrite(arfi_Green,HIGH);
     kunci3=1;
     delay(500);
  }
  else if (bacaarfi_tombol3==1 and kunci3==1) {
     digitalWrite(arfi_Green,LOW);
     kunci3=0;
     delay(500);
  }
}
