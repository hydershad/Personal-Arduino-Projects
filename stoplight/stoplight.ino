/*
#include <NeoSWSerial.h>

NeoSWSerial ble( 2, 4 );
//NeoSWSerial sim( 3, 5 );


char c = 0;
void setup(){
Serial.begin(9600);
ble.begin(19200);
delay(100);
//ble.listen();
//sim.begin(19200);
//delay(100);
//  
}


void loop(){

while(ble.available()){
  c = ble.read();
  Serial.write(c);
}

while(Serial.available()){
  c = Serial.read();
  int i = ble.write(c);
}
  
}
606405CFCE38
A81B6AB3F219
*/


#include <NeoSWSerial.h>
NeoSWSerial bleSerial(2, 4); // RX, TX

char c = 0;
void setup() { 
Serial.begin(57600); 
   bleSerial.begin(19200);
   delay(250);

  

}
void loop(){
while (bleSerial.available()) {
c = bleSerial.read();
  Serial.write(c);
}

while (Serial.available()) {
c = Serial.read();
  bleSerial.write(c);
}
}




/*
#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 5); // RX, TX
char c = 0;

  //A81B6AB3F219
  //D8A98BB46D83
  //MUST SEND AT+START TO BOTH MODULES TO BEGIN BLE CONNECTIONS
void setup() { 
Serial.begin(57600); 
mySerial.begin(57600); 

//delay(3000);
//mySerial.write("AT+CGPSCOLD");
//mySerial.write(0x0D);
//
//delay(5000);
//      mySerial.write("ATD2149911799;");
//      mySerial.write(0x0D);
pinMode(11, OUTPUT);
// pinMode(10, OUTPUT);

}
void loop(){
 digitalWrite(11, HIGH);
 digitalWrite(10, HIGH);

 delay(250);
 digitalWrite(11,LOW);
 digitalWrite(10,LOW);

 delay(250);
//  
//while (mySerial.available()) {
//  c = mySerial.read();
//  Serial.write(c);
//}
//
//while (Serial.available()) {
//mySerial.write(Serial.read());}
}

*/

/*
VCC -> 3.3 V / 5 V (better)
GND -> GND
SCL -> A5
SDA -> A4
XDA ->
XCL ->
ADO -> 
INT ->
*/

/*

#include "Wire.h" // This library allows you to communicate with I2C devices.
#include <Adafruit_NeoPixel.h>
#define PIN 6
#define STRIPSIZE 12
uint32_t c = 0; //pixel color
uint16_t onpix, sequence, r, g, b = 0;
int delta = 5;
const int MPU_ADDR = 0x68; // I2C address of the MPU-6050. If AD0 pin is set to HIGH, the I2C address will be 0x69.
  Adafruit_NeoPixel strip = Adafruit_NeoPixel(STRIPSIZE, PIN, NEO_GRB + NEO_KHZ800);

int16_t accelerometer_x, accelerometer_y, accelerometer_z; // variables for accelerometer raw data
int16_t gyro_x, gyro_y, gyro_z; // variables for gyro raw data
int16_t temperature; // variables for temperature data

char tmp_str[7]; // temporary variable used in convert function

char* convert_int16_to_str(int16_t i) { // converts int16 to string. Moreover, resulting strings will have the same length in the debug monitor.
  sprintf(tmp_str, "%6d", i);
  return tmp_str;
}

void setup() {
  strip.begin();
  strip.setBrightness(50);  // Lower brightness and save eyeballs!
  strip.show(); // Initialize all pixels to 'off'
  //Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MPU_ADDR); // Begins a transmission to the I2C slave (GY-521 board)
  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0); // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  onpix = 0;
  r = 30;
  b = 0;
  g = 0;
  sequence = 1;


  for(int j = 0; j<strip.numPixels();j++){
    strip.setPixelColor(j, strip.Color(63,63,63));
    strip.show();
    delay(50);
  }
  delay(1000);
    for(int j = strip.numPixels()-1; j>=0;j--){
    strip.setPixelColor(j, strip.Color(0,0,0));
    strip.show();
    delay(50);
  }
}
void loop() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H) [MPU-6000 and MPU-6050 Register Map and Descriptions Revision 4.2, p.40]
  Wire.endTransmission(false); // the parameter indicates that the Arduino will send a restart. As a result, the connection is kept active.
  Wire.requestFrom(MPU_ADDR, 7*2, true); // request a total of 7*2=14 registers
  
  // "Wire.read()<<8 | Wire.read();" means two registers are read and stored in the same variable
  accelerometer_x = Wire.read()<<8 | Wire.read(); // reading registers: 0x3B (ACCEL_XOUT_H) and 0x3C (ACCEL_XOUT_L)
  accelerometer_y = Wire.read()<<8 | Wire.read(); // reading registers: 0x3D (ACCEL_YOUT_H) and 0x3E (ACCEL_YOUT_L)
  accelerometer_z = Wire.read()<<8 | Wire.read(); // reading registers: 0x3F (ACCEL_ZOUT_H) and 0x40 (ACCEL_ZOUT_L)
  temperature = Wire.read()<<8 | Wire.read(); // reading registers: 0x41 (TEMP_OUT_H) and 0x42 (TEMP_OUT_L)
  gyro_x = Wire.read()<<8 | Wire.read(); // reading registers: 0x43 (GYRO_XOUT_H) and 0x44 (GYRO_XOUT_L)
  gyro_y = Wire.read()<<8 | Wire.read(); // reading registers: 0x45 (GYRO_YOUT_H) and 0x46 (GYRO_YOUT_L)
  gyro_z = Wire.read()<<8 | Wire.read(); // reading registers: 0x47 (GYRO_ZOUT_H) and 0x48 (GYRO_ZOUT_L)

if(gyro_z<(-1300)){

    switch(sequence){
    case 1:
      if(r<60){
        if(b>0){b=b-delta;}
        r=r+delta;
      }
      else sequence++;
    break;
    case 2: 
      if(g<60){
        if(r>0){r=r-delta;}
        g=g+delta;
        }
      else sequence++;
    break;
    case 3: 
      if(b<60){
        if(g>0){g=g-delta;}
        b=b+delta;}
      else sequence=1;
    break;
    default:
    break;
  }
  
}
if(gyro_z>(1300)){

  switch(sequence){
    case 1: 
      if(b<60){
        if(r>0){r=r-delta;}
        b=b+delta;}
      else sequence =3;
    break;
    case 2: 
      if(r<60){
        r=r+delta; 
        if(g>0){g=g-delta;}
        }
      else sequence= sequence -1;
    break;
    case 3: 
      if(g<60){
        g=g+delta;
        if(b>0){b=b-delta;}
      }
      
      else sequence= sequence -1;
    break;
    default:
    break;
  }
  
}

 c = (strip.Color(r,g,b));
 
 if(gyro_x >1500){
      if(onpix<strip.numPixels()){
      onpix = onpix+1;
    }
 }
 if(gyro_x <(-1500)){
      if(onpix>0){
      onpix = onpix-1;
      }
 }
 for(int i = 0; i<onpix; i++){
      strip.setPixelColor(i, c);
 }
 for(int i = onpix; i<strip.numPixels(); i++){
    strip.setPixelColor(i, strip.Color(0,0,0));
 }
  
  // print out data
  Serial.print("aX = "); Serial.print(convert_int16_to_str(accelerometer_x));
  Serial.print(" | aY = "); Serial.print(convert_int16_to_str(accelerometer_y));
  Serial.print(" | aZ = "); Serial.print(convert_int16_to_str(accelerometer_z));
  // the following equation was taken from the documentation [MPU-6000/MPU-6050 Register Map and Description, p.30]
  Serial.print(" | tmp = "); Serial.print(temperature/340.00+36.53);
 Serial.print(" | gX = "); Serial.print(convert_int16_to_str(gyro_x));
 Serial.print(" | gY = "); Serial.print(convert_int16_to_str(gyro_y));
 Serial.print(" | gZ = "); Serial.print(convert_int16_to_str(gyro_z));
 Serial.println();
  
  // delay
  strip.show();
  delay(50);
}
*/
