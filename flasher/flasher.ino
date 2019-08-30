void setup() {
  // initialize digital pin 13 as an output.
    pinMode(6, OUTPUT);
    pinMode(9, OUTPUT);

}

int x = 20;
int y = 180;
int fadex = 7;
int fadey = 7;
int d = 35;
int i = 0;
int j = 0;
void loop() {
for(i = 0; i<300;i++){  
  if (x <= 10 || x >= 245) {
    fadex = -fadex;
  }
  if (y <= 10 || y >= 245) {
    fadey = -fadey;
  }
x = x +fadex;
y = y +fadey;

analogWrite(6, x);
analogWrite(9, y);
delay(20);
}
for(j=0;j<5;j++){
for(i = 0; i<5; i++){
digitalWrite(6, HIGH);
delay(d);
digitalWrite(6, LOW);
delay(d);
}
digitalWrite(9, HIGH);
delay(300);
digitalWrite(9, LOW);
}
}
