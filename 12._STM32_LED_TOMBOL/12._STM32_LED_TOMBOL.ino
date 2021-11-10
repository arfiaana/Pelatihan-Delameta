//INISIAL
int Red = PC13;
int Yellow = PC14;
int Green = PC15;

int tombol1 = PA1;
int tombol2 = PA2;
int tombol3 = PA3;

void setup() {
  Serial.begin(9600);
  pinMode (tombol1, INPUT);
  pinMode (tombol2, INPUT);
  pinMode (tombol3, INPUT);
  pinMode (Red, OUTPUT);
  pinMode (Green, OUTPUT);
  pinMode (Yellow, OUTPUT);

}

void loop() {
  //BACA DATA
  int bacatombol1=digitalRead(tombol1);
  int bacatombol2=digitalRead(tombol2);
  int bacatombol3=digitalRead(tombol3);

  //PRINT TO SERIAL
  Serial.print( " tombol1 : " );
  Serial.print(bacatombol1);
  Serial.print( " - tombol2 : " );
  Serial.print(bacatombol2);
  Serial.print( " - tombol3 : " );
  Serial.print(bacatombol3); 
  Serial.println(); // UNTUK ENTER
    
  //LOGIKA TOMBOL 1
  if (bacatombol1==1){
  digitalWrite(Red,HIGH);
  }
  else {
  digitalWrite(Red,LOW);
  }
  
  //LOGIKA TOMBOL 2
  if (bacatombol2==1){
  digitalWrite(Yellow,HIGH);
  }
  else {
  digitalWrite(Yellow,LOW);
  }
  
  //LOGIKA TOMBOL 3
  if (bacatombol3==1){
  digitalWrite(Green,HIGH);
  }
  else {
  digitalWrite(Green,LOW);
  }
}
