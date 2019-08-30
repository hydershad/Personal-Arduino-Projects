/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 

void setup() 
{ 
   pinMode(13, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(2, OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
void loop() 
{ 
  
  for(pos = 0; pos <= 180; pos += 180) // goes from 0 degrees to 180 degrees 
  { 
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    delay(1000);
    myservo.write(pos);
  } 
    
    for(pos = 180; pos>=0; pos -= 180)     // goes from 180 degrees to 0 degrees 
  {                           
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    delay(1000);
    myservo.write(pos);
     delay(1000);
     digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    delay(5000);

    // tell servo to go to position in variable 'pos' 
                           // waits 15ms for the servo to reach the position 
  }
}
  