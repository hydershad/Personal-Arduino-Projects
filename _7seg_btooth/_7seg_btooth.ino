
void setup() {
   
pinMode(5, OUTPUT);
pinMode(4, OUTPUT);
pinMode(3, OUTPUT);
pinMode(2, OUTPUT);

Serial.begin(9600);
}  

String input = "";
  char inchar = 0;
  int i = 0;
  bool x = false; 
  bool start = true;
  bool low, mid, up, dot = false;
  bool state[13]= {};
  int dly = 100; //delay timing
  
void loop() {

 while(Serial.available()){

  if(start){
  Serial.println("Starting 7 segment bluetooth communications test...");
Serial.println("Enter '?' for command list");
Serial.println("");
start = false;
  }
  if(!x){
    input = "";
    x = true;
  }
  inchar = (char)Serial.read();
  input += inchar;
 }

if(x){

if(input == "?"){
  Serial.println("Commands list---\n");
  Serial.println("on :: all connected segments on\n");
    Serial.println("off :: all connected segments off\n");
  Serial.println("t(up/mid/low/dot) :: toggle selected segments on and off\n");
    Serial.println("alt(up/mid/low/dot) :: selected segments flash on and off with delay timing\n");
  Serial.println("50/100/150/200/250/300/500/1000 :: select delay timing in ms\n");
}

  

 if(input == "100"){ dly = 100;}
 if(input == "500"){ dly = 500;}
 if(input == "1000"){ dly = 1000;}
 if(input == "50"){ dly = 50;}
 if(input == "150"){ dly = 150;}
 if(input == "200"){ dly = 200;}
 if(input == "250"){ dly = 250;}
 if(input == "300"){ dly = 300;}
 

 if(input == "on"){

mid = false;
low = false;
up = false;
dot = false;

  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);

for(i=0;i<14;i++){
  state[i] = true;
  }
}
 if(input == "off"){
mid = false;
low = false;
up = false;
dot = false;
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);

for(i=0;i<14;i++){
  state[i] = false;
  }
}
  if(input == "tup"){
up = false;

    toggle(5);
  }
   if(input == "tlow"){
    low = false;
    toggle(3);
  }
   if(input == "tmid"){
    mid = false;
    toggle(4);
  }
   if(input == "tdot"){
    dot = false;
    toggle(2);
  }
    if(input == "altup"){
    up = !up;
  }
      if(input == "altlow"){
    low = !low;
  }
      if(input == "altmid"){
    mid = !mid;
  }
      if(input == "altdot"){
    dot = !dot;
  }
  x = false;
  Serial.println("Command: " + input);
  input = "";
}

if(mid){
  toggle(4);
}
if(up){
  toggle(5);
}
if(low){
  toggle(3);
}
if(dot){
  toggle(2);
}
  delay(dly);
}


void toggle(int j){
 
  if(state[j] == false){
    digitalWrite(j, HIGH);
}
else{
  digitalWrite(j, LOW);
}
state[j] = !state[j];
}

void on(int j){
  state[j] = true;
  digitalWrite(j, HIGH);
}

void off(int j){
   state[j] = false;
  digitalWrite(j, LOW);
}


