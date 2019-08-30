//#include <Adafruit_NeoPixel.h>
//#define PIN 11
//#define STRIPSIZE 12
int pad1 = 0;
int pad2 = 0;
int pad3 = 0;
int pad4 = 0;
const int digits = 6; //number of digits in code *Note this line must be above the arrays so that they initialize*
int Code[digits]{2, 2, 4, 3, 1, 3}; // enter code of size = # of digits
int Key[digits]{};
int count = 0;   // counts up to number of digits in code
int success = 0; //counts down from digits

uint16_t act1 = 0;
uint16_t act2 = 0;
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(STRIPSIZE, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
//  Serial.begin(9600);
  // put your setup code here, to run once:
pinMode (8, INPUT); //pad4
pinMode (7, INPUT);//pad3
pinMode (6, INPUT);//pad2
pinMode (5, INPUT); //pad1
pinMode (4, INPUT); //button
pinMode (3, INPUT); //button
pinMode (2, OUTPUT); //signal
pinMode (12, OUTPUT);//signal
pinMode (13, OUTPUT); //Denied LED
pinMode (10, OUTPUT); // base signal for collector of transistor to activate 5V+ relay
pinMode (11, OUTPUT); // base signal for collector of transistor to activate 5V+ relay

 // strip.begin();
 // strip.setBrightness(50);  // Lower brightness and save eyeballs!
 // strip.show(); // Initialize all pixels to 'off'
  }

void loop(){

for(count = 0; count < digits; count++){
while(pad1 == 0 & pad2==0 & pad3 == 0 & pad4 ==0){

pad1 =digitalRead(5);
pad2 =digitalRead(6);
pad3 =digitalRead(7);
pad4 =digitalRead(8);

}

if(pad1 == 1){
Key[count] = 1;  
}
if(pad2 == 1){
Key[count] = 2;
}
if(pad3 == 1){
Key[count] = 3;
}
if(pad4 == 1){  
Key[count] = 4;
}

digitalWrite(13, HIGH);
delay(5);
digitalWrite(13, LOW);
delay(300);

pad1 = 0;
pad2 = 0;
pad3 = 0;
pad4 = 0;
}

count = 0;
success = digits;
while(count < digits){
if(Key[count] == Code[count]){
  success--;
}
count++;
}
if (success == 0){
digitalWrite(13, HIGH);  
delay(20);
digitalWrite(13, LOW);
delay(100);

digitalWrite(13, HIGH);
delay(20);
digitalWrite(13, LOW);
delay(100);

digitalWrite(13, HIGH);
delay(20);
digitalWrite(13, LOW);

while(1){
  
while(analogRead(A0)<= 100){
  
while(digitalRead(3)== HIGH){
 digitalWrite(10, HIGH);
 digitalWrite(11, LOW);
 if(act1 !=0){
  act1--;
 }
 delay(10);
}

while(digitalRead(4)== HIGH){
 digitalWrite(10, LOW);
 digitalWrite(11, HIGH);
  
if(act1 <1051){
  act1++;
}
delay(10);
}
digitalWrite(10, LOW); //relay off
digitalWrite(11, LOW);
delay(10);
//Serial.println(act1);
}

while(analogRead(A0)> 100){
  
while(digitalRead(3)== HIGH){
 digitalWrite(12, HIGH);
 digitalWrite(2, LOW);
  if(act2 !=0){
  act2--;
 }
 delay(10);
}
while(digitalRead(4)== HIGH){
 digitalWrite(12, LOW);
 digitalWrite(2, HIGH);
if(act2 <1051){
  act2++;
}
delay(10);
}
digitalWrite(12, LOW); //relay off
digitalWrite(2, LOW);
delay(10);
//Serial.println(act2);
}
}
}

if(success != 0){

digitalWrite(13, HIGH);
delay(1000);
digitalWrite(13, LOW) ; 
}
}

