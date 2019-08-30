/*
* Arduino Wireless Communication Tutorial
* Transciever Code
* www.HowToMechatronics.com
* Modified by Hyder Shad
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CNS, CE

char pong[1]{0};
bool output = 0;
bool flag = 0;
bool radioNumber = 0;     //CHANGE FOR EACH PROGRAMMED RADIO ON THE NETWORK
byte addresses[][6] = {"1Node","2Node"};              // Radio pipe addresses for the 2 nodes to communicate.
void setup() {
pong[0] = 0;
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT); 
  
  Serial.begin(9600);
  radio.begin();
if(radioNumber){
    radio.openWritingPipe(addresses[1]);        // Both radios listen on the same pipes by default, but opposite addresses
    radio.openReadingPipe(1,addresses[0]);      // Open a reading pipe on address 0, pipe 1
    radio.startListening();
  }
  else{
    radio.openWritingPipe(addresses[0]);
    radio.openReadingPipe(1,addresses[1]);
    radio.startListening();
  }
  radio.setPALevel(RF24_PA_MIN);
}

void loop() {
  while(radio.available()) {
    radio.read(&pong, sizeof(pong));
      output = 1;
  }
  if(output ==1){
    Serial.println(pong[0]);
    if(pong[0] == '1'){
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
    }
       if(pong[0] == '2'){
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
    }
       if(pong[0] == '3'){
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
    }
       if(pong[0] == '4'){
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
    }
        if(pong[0] == '5'){
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
    }
       if(pong[0] == '6'){
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
    }
       if(pong[0] == '7'){
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
    }
       if(pong[0] == '8'){
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
    }
        if(pong[0] == '9'){
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
    }
    pong[0] = 0;
    output = 0;
  }
}
