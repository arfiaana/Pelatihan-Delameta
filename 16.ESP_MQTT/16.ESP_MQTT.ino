#include <WiFiEsp.h>
#include <WiFiEspClient.h>
#include <WiFiEspUdp.h>
#include <SoftwareSerial.h>
#include <PubSubClient.h>



char ssid[]        = "delameta";            // your network SSID (name)
char pass[]        = "bilano1407";        // your network password
int status = WL_IDLE_STATUS; // the Wifi radio's status
unsigned long lastSend;

// Initialize the Ethernet client object
WiFiEspClient espClient;
PubSubClient client(espClient);

SoftwareSerial Serialx(2,3); // RX, TX   //ESP8266 RX,TX connected to these pins
int R = 4;
int Y = 5;
int G = 6;
int LDR = A0;
int flame =A1;
void setup() {
// initialize serial for debugging
Serial.begin(115200);
// initialize serial for ESP module
Serialx.begin(9600);
// initialize ESP module
WiFi.init(&Serialx);
pinMode(R,OUTPUT);
pinMode(Y,OUTPUT);
pinMode(G,OUTPUT);
pinMode(LDR,INPUT);
pinMode(flame,INPUT);

// check for the presence of the shield
if (WiFi.status() == WL_NO_SHIELD) {
Serial.println("WiFi shield not present");
// don't continue
while (true);
}

// attempt to connect to WiFi network
while ( status != WL_CONNECTED) {
Serial.print("Attempting to connect to WPA SSID: ");
Serial.println(ssid);
// Connect to WPA/WPA2 network
status = WiFi.begin(ssid, pass);
lastSend = 0;
}

// you're connected now, so print out the data
Serial.println("You're connected to the network");

//connect to MQTT server
client.setServer("192.168.1.67", 1883);
client.setCallback(callback);
}

//print any message received for subscribed topic
void callback(char* topic, byte* payload, unsigned int length) {
Serial.print("Pesan diterima [");
  Serial.print(topic);
  Serial.println("] ");
  //==============================================================
  if (strcmp(topic, "arfiana/lampu1") == 0) //Membandingkan 2 buah String
  { 
    for (int i=0;i<length;i++) {
    char receivedChar = (char)payload[i];
    if (receivedChar == '1'){
       //Jalankan Perintah1
       Serial.println("JALANKAN PERINTAH 1");
       digitalWrite(R,HIGH);
    }
    if (receivedChar == '0'){
       //Jalankan Perintah0
       Serial.println("JALANKAN PERINTAH 0");
       digitalWrite(R,LOW);
    }
  }
  }
  //==============================================================
  //==============================================================
  if (strcmp(topic, "arfiana/lampu2") == 0) //Membandingkan 2 buah String
  { 
    for (int i=0;i<length;i++) {
    char receivedChar = (char)payload[i];
    if (receivedChar == '1'){
       //Jalankan Perintah1
       Serial.println("JALANKAN PERINTAH 1");
       digitalWrite(Y,HIGH);
    }
    if (receivedChar == '0'){
       //Jalankan Perintah0
       Serial.println("JALANKAN PERINTAH 0");
       digitalWrite(Y,LOW);
    }
  }
  }
  //==============================================================
  //==============================================================
  if (strcmp(topic, "arfiana/lampu3") == 0) //Membandingkan 2 buah String
  { 
    for (int i=0;i<length;i++) {
    char receivedChar = (char)payload[i];
    if (receivedChar == '1'){
       //Jalankan Perintah1
       Serial.println("JALANKAN PERINTAH 1");
       digitalWrite(G,HIGH);
    }
    if (receivedChar == '0'){
       //Jalankan Perintah0
       Serial.println("JALANKAN PERINTAH 0");
       digitalWrite(G,LOW);
    }
  }
  }
  //==============================================================
  
  
}

void pushdata(){
  //Ambil Data / Baca Sensor
  int bacaLDR=analogRead(LDR);
  int bacaflame=analogRead(flame);
  //char msgBuffer[20];
  //int datax=bacaLDR;
  
  //POST TO SERIAL
  Serial.print("LDR :");Serial.print(bacaLDR);
  Serial.println();
  Serial.print("Flame :");Serial.print(bacaflame);
  Serial.println();
  
  //POST TO MQTT
  //client.publish("arfiana/datax", dtostrf(datax, 6, 2, msgBuffer)); //Convert to String
  client.publish("arfianaLDR", String(bacaLDR).c_str());
  client.publish("arfianaflame", String(bacaflame).c_str()); 
}

void loop() {
// put your main code here, to run repeatedly:
if (!client.connected()) {
reconnect();
}
if ( millis() - lastSend > 500 ) { // Update and send only after 1 seconds
    pushdata();
    lastSend = millis();
 }
client.loop();
}

void reconnect() {
// Loop until we're reconnected
while (!client.connected()) {
Serial.print("Attempting MQTT connection...");
// Attempt to connect, just a name to identify the client
if (client.connect("arfiana")) {
Serial.println("connected");

//client.publish("outpic","Hello World");
client.subscribe("arfiana/lampu1",0);
client.subscribe("arfiana/lampu2",0);
client.subscribe("arfiana/lampu3",0);

} else {
  Serial.print("failed, rc=");
  Serial.print(client.state());
  Serial.println(" try again in 5 seconds");
  // Wait 5 seconds before retrying
  delay(5000);
}
}
}
