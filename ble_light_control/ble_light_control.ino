
#include <avr/sleep.h>

void setup() {
  pinMode(2, INPUT);
Serial.begin(9600);

attachInterrupt(0, wake, HIGH);
int i =0;
int j =0;

pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT); 
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10,OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void sleepNow()  {       // here we put the arduino to sleep

set_sleep_mode(SLEEP_MODE_STANDBY);
sleep_enable();
 attachInterrupt(0, wake, HIGH); // use interrupt 0 (pin 2) and run function
                                       // wakeUpNow when pin 2 gets LOW

 sleep_mode(); //GOES TO SLEEP HERE
 sleep_disable();         // first thing after waking from sleep:
                             // disable sleep...
detachInterrupt(0);      // disables interrupt 0 on pin 2 so the 
                             // wakeUpNow code will not be executed 
                             // during normal running time.
 
}

void wake(){
//do stuff
}
