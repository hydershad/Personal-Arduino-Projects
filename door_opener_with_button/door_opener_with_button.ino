
#include <Servo.h> 
const int buttonPin = 2; 
Servo myservo;  
int pos = 10;
int buttonState = 0; 
void setup() 
{ 
  pinMode(buttonPin, INPUT);
   pinMode(13, OUTPUT);
   pinMode(12, OUTPUT);
  myservo.attach(9);
} 
void loop() 
{ 
  buttonState = digitalRead(buttonPin);
   if (buttonState == LOW) {
  buttonState = digitalRead(buttonPin);
     for(pos = 0; pos <= 175; pos += 180) // goes from 0 degrees to 180 degrees 
  {
    digitalWrite(13, HIGH);
    delay(1000);
    myservo.write(pos);
    delay(1000);
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    delay(5000);
  }
   }
  else { 
    buttonState = digitalRead(buttonPin);
    for(pos = 175; pos>=0; pos -= 180)     // goes from 180 degrees to 0 degrees 
  { 
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    
    myservo.write(pos);
     
  }
}
}
