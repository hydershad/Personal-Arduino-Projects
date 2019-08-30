int brightness = 0;
int x = 255;
int fadeAmount = 5;

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
   pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
   pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);
   pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
   pinMode(3, OUTPUT);
    pinMode(2, OUTPUT);
}

void loop() {
  
 analogWrite(2, brightness);
analogWrite(3, x);
analogWrite(4, brightness);
analogWrite(5, x);
analogWrite(6, brightness);
analogWrite(7, x);
analogWrite(8, brightness);
analogWrite(9, x);
analogWrite(10, brightness);
analogWrite(11, x);
analogWrite(12, brightness);
analogWrite(13, x);





  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;
  x = x - fadeAmount;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness == 0 || brightness == 150) {
    fadeAmount = -fadeAmount ; 
  }     
  if (x == 0 || x == 150) {
    fadeAmount = fadeAmount ; 
  }
  // wait for 30 milliseconds to see the dimming effect    
  delay(30);
 
//  
// digitalWrite(2,LOW);
//  digitalWrite(3,HIGH);
//  digitalWrite(4,LOW);
//  digitalWrite(5,HIGH);
//  digitalWrite(6,LOW);
//  digitalWrite(7,HIGH);
//  digitalWrite(8,LOW);
//  digitalWrite(9,HIGH);
//  digitalWrite(10,LOW);
//  digitalWrite(11,HIGH);
//  digitalWrite(12,LOW);
//  digitalWrite(13,HIGH);
//  
//  delay(101);
//  
//  digitalWrite(2,HIGH);
//  digitalWrite(3,LOW);
//  digitalWrite(4,HIGH);
//  digitalWrite(5,LOW);
//     digitalWrite(6,HIGH);
//  digitalWrite(7,LOW);
//  digitalWrite(8,HIGH);
//  digitalWrite(9,LOW);
//  digitalWrite(10,HIGH);
//  digitalWrite(11,LOW);
//  digitalWrite(12,HIGH);
//  digitalWrite(13,LOW);
//  
//  
//  delay(101);
//  
//   digitalWrite(2,LOW);
//  digitalWrite(3,HIGH);
//  digitalWrite(4,LOW);
//  digitalWrite(5,HIGH);
//  digitalWrite(6,LOW);
//  digitalWrite(7,HIGH);
//  digitalWrite(8,LOW);
//  digitalWrite(9,HIGH);
//  digitalWrite(10,LOW);
//  digitalWrite(11,HIGH);
//  digitalWrite(12,LOW);
//  digitalWrite(13,HIGH);
//  
//  delay(101);
//  
//  digitalWrite(2,HIGH);
//  digitalWrite(3,LOW);
//  digitalWrite(4,HIGH);
//  digitalWrite(5,LOW);
//     digitalWrite(6,HIGH);
//  digitalWrite(7,LOW);
//  digitalWrite(8,HIGH);
//  digitalWrite(9,LOW);
//  digitalWrite(10,HIGH);
//  digitalWrite(11,LOW);
//  digitalWrite(12,HIGH);
//  digitalWrite(13,LOW);
//  
//  delay(101);
//  
//  digitalWrite(2,LOW);
//  digitalWrite(3,HIGH);
//  digitalWrite(4,LOW);
//  digitalWrite(5,HIGH);
//  digitalWrite(6,LOW);
//  digitalWrite(7,HIGH);
//  digitalWrite(8,LOW);
//  digitalWrite(9,HIGH);
//  digitalWrite(10,LOW);
//  digitalWrite(11,HIGH);
//  digitalWrite(12,LOW);
//  digitalWrite(13,HIGH);
//  
//  delay(101);
//  
//  digitalWrite(2,HIGH);
//  digitalWrite(3,LOW);
//  digitalWrite(4,HIGH);
//  digitalWrite(5,LOW);
//     digitalWrite(6,HIGH);
//  digitalWrite(7,LOW);
//  digitalWrite(8,HIGH);
//  digitalWrite(9,LOW);
//  digitalWrite(10,HIGH);
//  digitalWrite(11,LOW);
//  digitalWrite(12,HIGH);
//  digitalWrite(13,LOW);
//  
//   delay(101);
//  
//   digitalWrite(2,LOW);
//  digitalWrite(3,HIGH);
//  digitalWrite(4,LOW);
//  digitalWrite(5,HIGH);
//  digitalWrite(6,LOW);
//  digitalWrite(7,HIGH);
//  digitalWrite(8,LOW);
//  digitalWrite(9,HIGH);
//  digitalWrite(10,LOW);
//  digitalWrite(11,HIGH);
//  digitalWrite(12,LOW);
//  digitalWrite(13,HIGH);
//  
//  delay(101);
//  
//  digitalWrite(2,HIGH);
//  digitalWrite(3,LOW);
//  digitalWrite(4,HIGH);
//  digitalWrite(5,LOW);
//     digitalWrite(6,HIGH);
//  digitalWrite(7,LOW);
//  digitalWrite(8,HIGH);
//  digitalWrite(9,LOW);
//  digitalWrite(10,HIGH);
//  digitalWrite(11,LOW);
//  digitalWrite(12,HIGH);
//  digitalWrite(13,LOW);
//  
//  
//  delay(101);
//  
//   digitalWrite(2,LOW);
//  digitalWrite(3,HIGH);
//  digitalWrite(4,LOW);
//  digitalWrite(5,HIGH);
//  digitalWrite(6,LOW);
//  digitalWrite(7,HIGH);
//  digitalWrite(8,LOW);
//  digitalWrite(9,HIGH);
//  digitalWrite(10,LOW);
//  digitalWrite(11,HIGH);
//  digitalWrite(12,LOW);
//  digitalWrite(13,HIGH);
//  
//  delay(101);
//  
//  digitalWrite(2,HIGH);
//  digitalWrite(3,LOW);
//  digitalWrite(4,HIGH);
//  digitalWrite(5,LOW);
//     digitalWrite(6,HIGH);
//  digitalWrite(7,LOW);
//  digitalWrite(8,HIGH);
//  digitalWrite(9,LOW);
//  digitalWrite(10,HIGH);
//  digitalWrite(11,LOW);
//  digitalWrite(12,HIGH);
//  digitalWrite(13,LOW);
//  
//  delay(101);
//  
//  digitalWrite(2,LOW);
//  digitalWrite(3,HIGH);
//  digitalWrite(4,LOW);
//  digitalWrite(5,HIGH);
//  digitalWrite(6,LOW);
//  digitalWrite(7,HIGH);
//  digitalWrite(8,LOW);
//  digitalWrite(9,HIGH);
//  digitalWrite(10,LOW);
//  digitalWrite(11,HIGH);
//  digitalWrite(12,LOW);
//  digitalWrite(13,HIGH);
//  
//  delay(101);
//  
//  digitalWrite(2,HIGH);
//  digitalWrite(3,LOW);
//  digitalWrite(4,HIGH);
//  digitalWrite(5,LOW);
//     digitalWrite(6,HIGH);
//  digitalWrite(7,LOW);
//  digitalWrite(8,HIGH);
//  digitalWrite(9,LOW);
//  digitalWrite(10,HIGH);
//  digitalWrite(11,LOW);
//  digitalWrite(12,HIGH);
//  digitalWrite(13,LOW);
//  
////  
//  delay(101);
////  
//
//
////  
//  digitalWrite(2,LOW);
//  digitalWrite(3,LOW);
//  digitalWrite(4,LOW);
//  digitalWrite(5,LOW);
//     digitalWrite(6,LOW);
//  digitalWrite(7,LOW);
//  digitalWrite(8,LOW);
//  digitalWrite(9,LOW);
//  digitalWrite(10,LOW);
//  digitalWrite(11,LOW);
//  digitalWrite(12,LOW);
//  digitalWrite(13,LOW);
//
}
