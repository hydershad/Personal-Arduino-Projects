byte ir[1500]{0};
int i = 0;
int x =0;
void setup() {
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(3, INPUT);
pinMode(2, OUTPUT);
Serial.begin(9600);
}

void loop() {
  delay(3000);
 for(i=0;i<4;i++){
  digitalWrite(4, HIGH);
  delay(1000);
    digitalWrite(4, LOW);
  delay(1000);
 }
  digitalWrite(4, HIGH);
  delay(1000);
    digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  for(i=0;i<1500;i++){
    ir[i] = not (digitalRead(3));
  for(x=0;x<150;x++){}
  }
   digitalWrite(5, LOW);
  delay(5000);
 digitalWrite(5, HIGH);
 while(1){
  for(i=0;i<1500;i++){
    digitalWrite(2, ir[i]);
 for(x=0;x<150;x++){}
  }  
  }
  
 }

