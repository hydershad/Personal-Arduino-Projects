char uprelay[2]{11, 2}; //array for pins associated with up and down relays for each respective actuator
char downrelay[2]{10, 12};
boolean mov= false;
boolean minus = false;
char rx_byte = 0;
String rx_str = "";
int big;
int result;
int wait;
int actuator;
boolean start = false;
boolean fault=false;
boolean lock=true;

int pad1 = 0;
int pad2 = 0;
int pad3 = 0;
int pad4 = 0;
const int digits = 6; //number of digits in code *Note this line must be above the arrays so that they initialize*
int Code[digits]{2, 2, 4, 3, 1, 3}; // enter code of size = # of digits
int Key[digits]{};
int count = 0;   // counts up to number of digits in code
int success = 0; //counts down from digits

//--------------------------------------------------------------------------------------------------------------

void setup() {
Serial.begin(9600);
pinMode (8, INPUT); //pad4
pinMode (7, INPUT); //pad3
pinMode (6, INPUT); //pad2
pinMode (5, INPUT); //pad1
pinMode (4, INPUT); //button
pinMode (3, INPUT); //button
pinMode (2, OUTPUT); //signal
pinMode (12, OUTPUT); //signal
pinMode (13, OUTPUT); //Denied LED
pinMode (10, OUTPUT); // base signal for collector of transistor to activate 5V+ relay
pinMode (11, OUTPUT); // base signal for collector of transistor to activate 5V+ relay

//--------------------------------------------------------------------------------------------------------------

//start one time run lock
while(lock==true){
Serial.println("Enter passcode on board:");

for(count = 0; count < digits; count++){
while(pad1 == 0 & pad2==0 & pad3 == 0 & pad4 ==0){

pad1 =digitalRead(5);
pad2 =digitalRead(6);
pad3 =digitalRead(7);
pad4 =digitalRead(8);
}

if(pad1 == 1){
Key[count] = 1;  
}
if(pad2 == 1){
Key[count] = 2;
}
if(pad3 == 1){
Key[count] = 3;
}
if(pad4 == 1){  
Key[count] = 4;
}

digitalWrite(13, HIGH);
delay(20);
digitalWrite(13, LOW);
delay(20);

pad1 = 0;
pad2 = 0;
pad3 = 0;
pad4 = 0;
}

count = 0;
success = digits;
while(count < digits){
if(Key[count] == Code[count]){
  success--;
}
count++;
}
if (success == 0){
digitalWrite(13, HIGH);  
delay(20);
digitalWrite(13, LOW);
delay(100);

digitalWrite(13, HIGH);
delay(20);
digitalWrite(13, LOW);
delay(100);

digitalWrite(13, HIGH);
delay(20);
digitalWrite(13, LOW);

lock=false;
}
if(success != 0){

digitalWrite(13, HIGH);
delay(1000);
digitalWrite(13, LOW) ; 
}
}
}
//--------------------------------------------------------------------------------------------------------------
void loop() {
//start by selecting actuator

Serial.println("Enter actuator number to move:");

while(start==false){
  
if(Serial.available()==0){    //flashes board LED while waiting for input
 digitalWrite(13, HIGH);
 delay(100); 
  digitalWrite(13, LOW); 
delay(100);
}

if(Serial.available() > 0) {    // is a character available?
   
    rx_byte = Serial.read();       // get the character
    
      if (rx_byte != '/') {
      // a character of the string was received
     if ((rx_byte >= '0') && (rx_byte <= '9')){
      rx_str += rx_byte;
    }
    else{ //any non numeric character other than the backslash triggers fault warning
  fault=true;
    }
    }
    if(rx_byte == '/'){
     big= rx_str.length();
     if(big==1){                 //monitor string lentgh
      start=true;
      actuator=rx_str.toInt();      //convert ascii characters to number
       rx_str = ""; //reset string for next input section
}
if(big!=1){
fault=true;   //too large value for actuator
   }
   if(fault==true){             //detects faults such as non-numeric entries into serial command
    rx_str = ""; //reset string
  Serial.println("Error. Enter valid actuator number to start:");
  start=false;
  fault=false;
}
  }  
}
}//end of start section

//--------------------------------------------------------------------------------------------------------------

//begin movement entry section

Serial.println("Enter movements:");
 
 while((mov==false)&&(start==true)){

 if(Serial.available()==0){     //flashes board LED while waiting for input
 digitalWrite(13, HIGH);
 delay(100); 
  digitalWrite(13, LOW);
  delay(100); 
}
 
 if(Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();       // get the character
    
    if (rx_byte != '/') {
      // a character of the string was received
      
     if ((rx_byte >= '0') && (rx_byte <= '9')){
      rx_str += rx_byte;
    }
   else if(rx_byte == '-'){
     minus = true; 
    }
    else{//any non numeric character other than the backslash and minus/hyphen triggers fault warning
  fault=true;
    }
    }
    
    if(rx_byte == '/'){
     big= rx_str.length();
     if(big<5){                 //monitor string lentgh
      mov=true;
       result= rx_str.toInt();
       wait = result;
    }
    if(big>=5){
      fault=true;
    }
    if(fault==true){             //detects faults such as non-numeric entries into serial command
       rx_str = ""; //reset string
     Serial.println("Error. Enter valid movement range:");
  mov=false;
  fault=false;
  minus=false;
}
    }
 }
}//end of movement entry section

//--------------------------------------------------------------------------------------------------------------

//start process

while((mov==true)&&(start==true)){

if(minus==true){
  result= -1*result;
}
//display entries
Serial.print("Actuator #");
  Serial.print(actuator);
  Serial.print(",");
  Serial.println(result);
  
  digitalWrite(13, HIGH);  //signal light

if(minus==false){                              //based on minus boolean determines which relay should be activated between the two for each actuator
  digitalWrite(uprelay[actuator-1],HIGH);
   digitalWrite(downrelay[actuator-1],LOW);
}
 if(minus==true){
  digitalWrite(downrelay[actuator-1],HIGH);
   digitalWrite(uprelay[actuator-1],LOW);
} 
  delay(wait);//keep spe on for specified time
  
   digitalWrite(uprelay[actuator-1],LOW); //turn relays back to off
   digitalWrite(downrelay[actuator-1],LOW);
  
  mov=false;        //reset booleans and entry string
  start=false;
  minus = false;
  digitalWrite(13, LOW);
  rx_str = ""; 
}
}

