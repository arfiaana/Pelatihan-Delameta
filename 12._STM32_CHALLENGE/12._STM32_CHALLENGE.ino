//INISIAL
int arfi_Red = PC13;
int arfi_Yellow = PC14;
int arfi_Green = PC15;

int arfi_tombol1 = PA1;
int arfi_tombol2 = PA2;
int arfi_tombol3 = PA3;

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
  if (bacaarfi_tombol1==1){
     digitalWrite(arfi_Red,HIGH);
  }
  else {
     digitalWrite(arfi_Red,LOW);
  }
  if (bacaarfi_tombol2==1){
     digitalWrite(arfi_Yellow,HIGH);
  }
  else {
     digitalWrite(arfi_Yellow,LOW);
  }
  if (bacaarfi_tombol3==1){
     digitalWrite(arfi_Green,HIGH);
  }
  else {
     digitalWrite(arfi_Green,LOW);
  }
}
