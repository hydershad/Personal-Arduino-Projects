#include <Adafruit_GFX.h>
#include <gfxfont.h>

#include <Adafruit_NeoPixel.h>

int button1 = 0;         // variable for reading the pushbutton status
int button2 = 0;         // variable for reading the pushbutton status
int button3 = 0;         // variable for reading the pushbutton status
int button4 = 0; 

void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT);
   pinMode(9, INPUT); 
   pinMode(10, INPUT); 
   pinMode(11, INPUT);
   pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   button1 = digitalRead(8);
  button2 = digitalRead(9);
  button3 = digitalRead(10);
  button4 = digitalRead(11);
  
if(button1==HIGH & button2==LOW & button3==LOW & button4==LOW){
digitalWrite(13, HIGH);
delay(200);
digitalWrite(13, LOW);
delay(200);
}
if(button1==LOW & button2==HIGH & button3==LOW & button4==LOW){
digitalWrite(13, HIGH);
delay(100);
digitalWrite(13, LOW);
delay(100);
}
if(button1==LOW & button2==LOW & button3==HIGH & button4==LOW){
digitalWrite(13, HIGH);
delay(50);
digitalWrite(13, LOW);
delay(50);
}
if(button1==LOW & button2==LOW & button3==LOW & button4==HIGH){
digitalWrite(13, HIGH);
delay(25);
digitalWrite(13, LOW);
delay(25);

}
}


