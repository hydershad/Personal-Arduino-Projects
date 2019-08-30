#include <Servo.h> 
 
Servo myservo;  
int pos = 10;    
void setup() 
{ 
   pinMode(13, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(2, OUTPUT);
  myservo.attach(9);
} 
void loop() 
{ 
  
  for(pos = 0; pos <= 175; pos += 180) 
  { 
    digitalWrite(2, LOW);
    digitalWrite(13, HIGH);
    delay(1000);
    myservo.write(pos);
    delay(1000);
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    delay(5000);
  } 
    
    for(pos = 175; pos>=0; pos -= 180) 
  { 
    digitalWrite(12, LOW);
    digitalWrite(2, LOW);
    digitalWrite(13, HIGH);
    delay(1000);
    myservo.write(pos);
     delay(1000);
     digitalWrite(13, LOW);
    digitalWrite(2, HIGH);
    delay(5000);
  }
}
  
