/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 6514
  by Scott Fitzgerald
 */
int i =0;
int j =0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11,OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {

for(j=0;j<10;j++){
  for(i=2;i<8;i++){
    digitalWrite(i, HIGH);
    delay(50);
    digitalWrite(i,LOW);
  }
}
 for(j=0;j<2;j++){ 
    for(i=0;i<3;i++){
    digitalWrite(2, HIGH);
    digitalWrite(5, HIGH);
    delay(65);
    
    digitalWrite(2, LOW);
    digitalWrite(5, LOW);
    delay(65);
    }
    for(i=0;i<3;i++){
    digitalWrite(8, HIGH);
    delay(65);
    digitalWrite(8, LOW);
    delay(65);
    }
 }
for(j=0;j<2;j++){
for(i=0;i<3;i++){
   digitalWrite(4, HIGH);
    digitalWrite(7, HIGH);
    delay(65);
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
    delay(65);
}
 for(i=0;i<3;i++){
    digitalWrite(8, HIGH);
    delay(65);
    digitalWrite(8, LOW);
    delay(65);
    }
}

for(j=0;j<2;j++){
for(i=0;i<3;i++){
    digitalWrite(3, HIGH);
    digitalWrite(6, HIGH);
    delay(65);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    delay(65);
}
 for(i=0;i<3;i++){
    digitalWrite(8, HIGH);
    delay(65);
    digitalWrite(8, LOW);
    delay(65);
    }
}

for(j=0;j<5;j++){
digitalWrite(9, HIGH);
delay(250);
digitalWrite(9, LOW);
delay(250);
}
}


