
void setup() {
   
pinMode(13,OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);
pinMode(8, OUTPUT);
pinMode(7, OUTPUT);
pinMode(6, OUTPUT);

Serial.begin(9600);

}  

String input = "";
  char inchar = 0;
  int i = 0;
  bool x = false; 
  bool alty, altr, altg = false;
  bool flashing, flashy, flashr, flashg = false;
  bool state[13]= {};
  int dly = 100; //delay timing
  
void loop() {


 while(Serial.available()){
  if(!x){
    input = "";
    x = true;
  }
  inchar = (char)Serial.read();
  input += inchar;
 }


if(x){

 if(input == "100"){ dly = 100;}
 if(input == "500"){ dly = 500;}
 if(input == "1000"){ dly = 1000;}
 if(input == "50"){ dly = 50;}
 if(input == "150"){ dly = 150;}
 if(input == "200"){ dly = 200;}
 if(input == "250"){ dly = 250;}
 if(input == "300"){ dly = 300;}
 

 if(input == "on"){
    alty = false;
altg = false;
altr = false;
flashy = false;
flashr = false;
flashg = false;
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
for(i=0;i<14;i++){
  state[i] = true;
  }
}
 if(input == "off"){
  alty = false;
altg = false;
altr = false;
flashy = false;
flashr = false;
flashg = false;
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
for(i=0;i<14;i++){
  state[i] = false;
  }
}
   if(input == "ty"){
    alty = false;
    flashy = false;
    toggle(8);
    toggle(9);
    toggle(10);
 }
   if(input == "tr"){
    altr = false;
    flashr = false;
    toggle(11);
    toggle(12);
 }
   if(input == "tg"){
    altg = false;
    flashg = false;
     toggle(6);
     toggle(7);
 }

if(input == "alty"){
  flashy = false;
  if(!alty){
   state[8] = false;
   state[9] = true;
   state[10] = false;
  }
   alty = !alty;
}
if(input == "altr"){
  flashr = false;
  if(!altr){
   state[12] = false;
   state[11] = true;
  }
   altr = !altr;
}
if(input == "altg"){
  flashg = false;
  if(!altg){
   state[6] = false;
   state[7] = true;
  }
   altg = !altg;
}

if(input == "flashy"){
  alty = false;
   flashy = !flashy;
}

if(input == "flashr"){
  altr = false;
   flashr = !flashr;
}
if(input == "flashg"){
  altg = false;
   flashg = !flashg;
}

Serial.println("Request: " + input);
input = "";
 x = false;

}

if(alty){
  toggle(8);
    toggle(10);
  toggle(9);

}
if(altr){
  toggle(11);
  toggle(12);
}
if(altg){
  toggle(6);
  toggle(7);
}

if(flashy){
  if(flashing){
    on(8);
    on(9);
    on(10);
  }
  else{
    off(8);
    off(9);
    off(10);
  }
}
if(flashr){
  if(flashing){
    on(11);
    on(12);
  }
  else{
    off(11);
    off(12);
  }
}
if(flashg){
  if(flashing){
    on(6);
    on(7);
  }
  else{
    off(6);
    off(7);
  }
}

 flashing = !flashing;
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


