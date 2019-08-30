#include <Servo.h> 
Servo serv1;
Servo serv2;
Servo serv3;
Servo serv4;
Servo serv5;
int index; 
void setup () { 
Serial.begin (9600); 
serv1.attach (9);
serv2.attach (10);
serv3.attach (11);
serv4.attach (5);
serv5.attach (6);
// We attack the servant to pin 9 
} 
void loop () { 
index = analogRead (A0); 
Serial.print ("original value"); 
Serial.println (index); 
index = map (index, 50, 10, 10, 170); 
serv1.write (index); 
Serial.print ("scaled value:"); 
Serial.println (index); 
// We print the original value of the sensor and then modified by the map command 
 
index = analogRead (A1); 
Serial.print ("original value"); 
Serial.println (index); 
index = map (index, 45, 10, 10, 170); 
serv2.write (index); 
Serial.print ("scaled value:"); 
Serial.println (index); 
// We print the original value of the sensor and then modified by the map command 

index = analogRead (A2); 
Serial.print ("original value"); 
Serial.println (index);  
index = map (index, 50, 10, 10, 170); 
serv3.write (index); 
Serial.print ("scaled value:"); 
Serial.println (index); 
// We print the original value of the sensor and then modified by the map command 

index = analogRead (A3); 
Serial.print ("original value"); 
Serial.println (index); 
index = map (index, 50, 10, 10, 170); 
serv4.write (index); 
Serial.print ("scaled value:"); 
Serial.println (index); 
// We print the original value of the sensor and then modified by the map command 

index = analogRead (A4); 
Serial.print ("original value"); 
Serial.println (index);  
index = map (index, 50, 10, 10, 170); 
serv5.write (index); 
Serial.print ("scaled value:"); 
Serial.println (index); 
// We print the original value of the sensor and then modified by the map command 
delay(50);
}
