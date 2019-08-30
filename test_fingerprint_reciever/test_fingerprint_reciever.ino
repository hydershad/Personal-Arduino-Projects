#include <nRF24L01.h>
#include <RF24.h>
#include <SPI.h>
RF24 radio(9, 10); // CNS, CE
int j = 0;
bool output = 0;
char text[2] = {0};
char rx[2] = {0};
bool radioNumber = 1;   //CHANGE FOR EACH PROGRAMMED RADIO ON THE NETWORK
byte addresses[][6] = {"1Node","2Node"};              // Radio pipe addresses for the 2 nodes to communicate.

void setup() {
  // put your setup code here, to run once:
//radio setup *************
Serial.begin(9600);
Serial.println("Ready");
radio.begin();
if(radioNumber){
    radio.openWritingPipe(addresses[1]);        // Both radios listen on the same pipes by default, but opposite addresses
    radio.openReadingPipe(1,addresses[0]);      // Open a reading pipe on address 0, pipe 1
    radio.startListening();
  }
  else{
    radio.openWritingPipe(addresses[0]);
    radio.openReadingPipe(1,addresses[1]);
  }
  radio.setPALevel(RF24_PA_MAX);
//radio setup *************

}

void loop() {
   while(radio.available()) {
    radio.read(&text, sizeof(text));
      output = 1;
  }
  if(output ==1){
    Serial.print(text[0]);
    Serial.println(text[1]);
    if(text[0] == 'R' && text[1]=='?'){
      Serial.println("connected");
      radio.stopListening();    //check to see if other radio is connected
      rx[0] = 'Y';
      rx[1] = '!';
  radio.write(&rx, sizeof(rx));
  radio.startListening();    //check to see if other radio is connected
    }
      for(j=0;j<2;j++){
      text[j] = 0;
    }
    output = 0;
  }
delay(500);
Serial.println("waiting");
}
