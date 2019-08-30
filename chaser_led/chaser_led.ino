

// the setup function runs once when you press reset or power the board
void setup() {

    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
   pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(4, HIGH);
  delay(77);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(77);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(77);
  digitalWrite(6, LOW);
  
  digitalWrite(7, HIGH);
  delay(77);
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  delay(77);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  delay(77);
  digitalWrite(5, LOW);
                                                               
}

