
//----------------------------------------------------------
//wifi setup and library, network name and pass
#include <WiFi.h>
const char * hostDomain = "example.com";
const int hostPort = 80;

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };   //mac address
byte ip[] = { 192, 168, 0, 13 };                      // Lan IP
byte gateway[] = { 192, 168, 0, 1 };                   // gateway IP

const char* ssid = "hsG7";
const char* password = "g7netw0rk";
//----------------------------------------------------------
WiFiServer server(80);
  int x = 5;
  int y = 5;
  int j = 0;
  int beep = 0;
  int button = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
delay(1000);
//----------------------------------------------------------
//wifi scan for network and connect to 
 WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
    
  }
 
  Serial.print("Connected to the WiFi network: ");
  Serial.println(WiFi.SSID());
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
//----------------------------------------------------------
pinMode(21, INPUT);
pinMode(22, OUTPUT);
delay(100);
   ledcAttachPin(2, 1); // assign RGB led pins to channels
 ledcSetup(1, 12000, 8); // 12 kHz PWM, 8-bit resolution
}

void loop() { 
  
  // put your main code here, to run repeatedly:
button  = digitalRead(21);
if(button && (beep == 500)){
  for(j=0;j<5;j=j+1){
  digitalWrite(22, HIGH);
  delay(100);
  digitalWrite(22, LOW);
  delay(100);
}
  beep = 0;
}
if(beep<500){beep = beep + 1;}

ledcWrite(1, x);
if(x == 255 || x ==0){
 y=-y;
}
x=x+y;
delay(25);
}
