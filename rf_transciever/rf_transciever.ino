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

RF24 radio(9, 10); // CNS, CE
char rx_str[500] = {0};
char rx_byte = 0;
char text[500] = {0};
int i = 0;
int j = 0;
bool output = 0;
bool flag = 0;
bool radioNumber = 1;   //CHANGE FOR EACH PROGRAMMED RADIO ON THE NETWORK
byte addresses[][6] = {"1Node","2Node"};              // Radio pipe addresses for the 2 nodes to communicate.
void setup() {

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
  }
  radio.setPALevel(RF24_PA_MIN);
}

void loop() {
  delay(5000);
 while((Serial.available()) &&( flag==0)){
     rx_byte = Serial.read();
     if(rx_byte == '/'){
      flag = 1;
     }
     else{
      rx_str[i] = rx_byte;
     }
  i++;
  }
if (flag == 1){
    radio.stopListening();
    radio.write(&rx_str, sizeof(rx_str));
    Serial.print("-->");
    Serial.println(rx_str);
    for(i=0;i<500;i++){
      rx_str[i] = 0;
    }
    flag=0;
    i=0;
    radio.startListening();
}
  while(radio.available()) {
    radio.read(&text, sizeof(text));
      output = 1;
  }
  if(output ==1){
    Serial.println(text);
      for(j=0;j<500;j++){
      text[j] = 0;
    }
    output = 0;
    j = 0;
  }
}
