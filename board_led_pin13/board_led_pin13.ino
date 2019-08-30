//wheel lock unit code
//pin 6 = buzzer
//pin 2 = arduino->ble TX
//pin 3 = Arduino->ble RX
//pin 5 = indicator LED
//pin 7 = Relay control pin (transistor base terminal)
//#define board

#ifndef board
#include <SoftwareSerial.h>
SoftwareSerial bleSerial(3, 2); // RX, TX

void setup() {

Serial.begin(57600); 
bleSerial.begin(19200);
  
}
char c =0;
void loop(){
  while (bleSerial.available()) {
c = bleSerial.read();
  Serial.write(c);
}

while (Serial.available()) {
c = Serial.read();
  bleSerial.write(c);
}
}



#endif

#ifdef board

#include <SoftwareSerial.h>
SoftwareSerial bleSerial(2, 4); // RX, TX

char c = 0;
void setup() { 
Serial.begin(57600); 
//mySerial.begin(19200);
bleSerial.begin(19200);

//mySerial.end();
//leSerial.begin(115200);

}
void loop(){
while (bleSerial.available()) {
c = bleSerial.read();
  Serial.write(c);
}

while (Serial.available()) {
c = Serial.read();
  bleSerial.write(c);
}
}
#endif
