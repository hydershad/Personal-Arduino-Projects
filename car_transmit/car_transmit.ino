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
char ping[1]{0};
char rx_byte = 0;
bool output = 0;
bool flag = 0;
bool radioNumber = 1;     //CHANGE FOR EACH PROGRAMMED RADIO ON THE NETWORK
byte addresses[][6] = {"1Node","2Node"};              // Radio pipe addresses for the 2 nodes to communicate.
void setup() {
  Serial.begin(9600);
  radio.begin();
if(radioNumber){
    radio.openWritingPipe(addresses[1]);        // Both radios listen on the same pipes by default, but opposite addresses
    radio.openReadingPipe(1,addresses[0]);      // Open a reading pipe on address 0, pipe 1
     radio.stopListening();
  }
  else{
    radio.openWritingPipe(addresses[0]);
    radio.openReadingPipe(1,addresses[1]);
     radio.stopListening();
  }
  radio.setPALevel(RF24_PA_MIN);
}

void loop() {
while((Serial.available()) &&( flag==0)){
     rx_byte = Serial.read();
     if(rx_byte == '/'){
      flag = 1;
     }
     else{
      ping[0] = rx_byte;
     }
  }
if (flag == 1){
 radio.write(&ping, sizeof(ping));
 Serial.println(ping[0]);
 ping[0] = 0;
 flag = 0;
 delay(100);
}
}
