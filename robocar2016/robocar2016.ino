int left;
int right;
int front;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
    pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT); 
 
Serial.begin (9600);
}

// the loop function runs over and over again forever
void loop() {
 
left = analogRead (A0);
right = analogRead (A1);
front = analogRead (A5);
while(500<front){
  digitalWrite(4, LOW);
    digitalWrite(6, LOW);
        digitalWrite(5, LOW);
    digitalWrite(7, LOW);

front = analogRead (A5);
}
if(right<400){
  if(left>400){
    digitalWrite(4, LOW);
    digitalWrite(6, HIGH);
     digitalWrite(5, LOW);
    digitalWrite(7, LOW);
  }
}
if(right>400){
  if(left<400){
    digitalWrite(4, HIGH);
    digitalWrite(6, LOW);
        digitalWrite(5, LOW);
    digitalWrite(7, LOW);
  }
}
if(right>400){
  if(left>400){
      digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
        digitalWrite(5, LOW);
    digitalWrite(7, LOW);
  }
}

delay(30);
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
        digitalWrite(5, LOW);
    digitalWrite(7, LOW);
delay(30);
}

