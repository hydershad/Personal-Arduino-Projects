byte x = 0;
byte i = 0;
byte j = 0;
byte modes[5]{0,1,1,1,0}; 
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
if(modes[0] == 1){
  for(j=0;j<2;j++){ //mode repeat
  for(i=2; i<14; i++){
digitalWrite(i, HIGH);
delay(40);
digitalWrite(i, LOW);
  }
    for(i=13; i>1; i--){
digitalWrite(i, HIGH);
delay(40);
digitalWrite(i, LOW);
  }
  }
}

if(modes[1] ==1){
 for(j=0;j<18;j++){       //mode repeat
  
 digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  
  delay(100);
  
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
     digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  
  
  delay(100);
 }
 for(i=2;i<14;i++){ 
  digitalWrite(i,LOW);
 }
}
if(modes[2] == 1){
for(j=0;j<6;j++){         //mode repeat
for(i=0;i<3;i++){
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
   digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  delay(60);
  digitalWrite(2, LOW);
digitalWrite(3, LOW);
   digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
delay(60);
}
for(i=0;i<3;i++){ 
 
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  delay(60);

  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
   digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
delay(60);
}
}
}
if(modes[3] == 1){
for(j=0;j<6;j++){           //mode repeat 
 for(i=0;i<3;i++){
   digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  delay(60);
   digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
delay(60);
 }
  
for(i=0;i<3;i++){
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  delay(60);
     digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
   digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
delay(60);
}
}
}
if(modes[4] == 1){
 for(j=0;j<6;j++){        //mode repeat
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  
delay(60);
//  
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
     digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
    delay(60);
 }
}
}
