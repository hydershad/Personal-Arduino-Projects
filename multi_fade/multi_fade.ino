/*
 Fade
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 
 This example code is in the public domain.
 */

          // the pin that the LED is attached to
int brightness = 0;
int x = 255;
int fadeAmount = 5;

// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(4, OUTPUT);
} 

// the loop routine runs over and over again forever:
void loop()  { 
  // set the brightness of pin 9:
  analogWrite(5, brightness);
analogWrite(6, x);
analogWrite(10, brightness);
analogWrite(11, x);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;
  x = x - fadeAmount;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  if (x == 0 || x == 255) {
    fadeAmount = fadeAmount ; 
  }
  // wait for 30 milliseconds to see the dimming effect    
  delay(10);
digitalWrite(4, HIGH);  
}

