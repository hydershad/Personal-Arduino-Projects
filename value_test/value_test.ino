int index;
int thumb;
int middle;
int ring;
int pinky;
int i = 0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
   
 pinMode(2, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  //pinMode(4, OUTPUT);
  pinMode(5, OUTPUT); 
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
Serial.begin (9600);
}

// the loop function runs over and over again forever
void loop() {
//thumb = analogRead (A1);
//Serial.print ("thumb"); 
//Serial.println (thumb);
//
index = analogRead (A3);
//Serial.print ("index"); 
//Serial.println (index);
//
middle = analogRead (A2);
//Serial.print ("middle"); 
//Serial.println (middle);
//
ring = analogRead (A0);
//Serial.print ("ring"); 
//Serial.println (ring);
//
pinky = analogRead (A4);
//Serial.print ("pinky"); 
//Serial.println (pinky);

if(index >=25){
  if(middle <= 22){
  if(ring <= 34){
if(pinky >= 29){



  digitalWrite(3, HIGH);
 digitalWrite(6, LOW);
 digitalWrite(7, HIGH);
 //digitalWrite(4, LOW);
 delay(100);
  digitalWrite(3, LOW);
 digitalWrite(6, HIGH);
 digitalWrite(7, LOW);
 //digitalWrite(4, HIGH);
 delay(100);

  digitalWrite(3, HIGH);
 digitalWrite(6, LOW);
 digitalWrite(7, HIGH);
 //digitalWrite(4, LOW);
 delay(100);
  digitalWrite(3, LOW);
 digitalWrite(6, HIGH);
 digitalWrite(7, LOW);
 //digitalWrite(4, HIGH);
 delay(100);


 digitalWrite(6, LOW);
    digitalWrite(8, HIGH);
 digitalWrite(9, LOW);
 digitalWrite(5, HIGH);
 digitalWrite(2, LOW);
 delay(75);
  digitalWrite(8, LOW);
 digitalWrite(9, HIGH);
 digitalWrite(5, LOW);
 digitalWrite(2, HIGH);
 delay(75);
  digitalWrite(9, LOW);
   digitalWrite(2, LOW);
  
    digitalWrite(8, HIGH);
 digitalWrite(9, LOW);
 digitalWrite(5, HIGH);
 digitalWrite(2, LOW);
 delay(75);
  digitalWrite(8, LOW);
 digitalWrite(9, HIGH);
 digitalWrite(5, LOW);
 digitalWrite(2, HIGH);
 delay(75);
  digitalWrite(9, LOW);
   digitalWrite(2, LOW);   
    }
  }
  }
 }
else{
      
     
     
digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);              // wait for a second
  digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
            
digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);              // wait for a second
  digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
            
//  digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(50);              // wait for a second
//  digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
     
  digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);              // wait for a second
  digitalWrite(5, LOW);    // turn the LED off by making the voltage LOW
//  digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(50);              // wait for a second
//  digitalWrite(6, LOW);    // turn the LED off by making the voltage LOW
   digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);              // wait for a second
  digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
 digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);              // wait for a second
  digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
 digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);              // wait for a second
  digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
  
 
}
}
