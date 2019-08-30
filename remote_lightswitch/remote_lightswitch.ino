void setup() {


Serial.begin(9600);
}

void loop() {
  String input = "";
  char inchar = 0;
  int i = 0;
  bool x = false; 
while(1){
 while(Serial.available()){
  if(!x){
    input = "";
    x = true;
  }
  inchar = (char)Serial.read();
  input += inchar;
 }

   if(x){
Serial.println(input);
 x = false;
 }
 if(input == "green"){
  digitalWrite(4, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(13, LOW);
 }
  else if(input == "yellow"){
  digitalWrite(4, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(13, LOW);
 }
  else if(input == "board"){
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  digitalWrite(13, HIGH);
 }
 else{
 for(i = 0; i<10; i++){
  digitalWrite(13, HIGH);
  delay(150);
  digitalWrite(13, LOW);
  delay(40);
 }
 }
 delay(2000);
}
}

