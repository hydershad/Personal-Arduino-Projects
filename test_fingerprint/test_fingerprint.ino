/*************************************************** 
  This is an example sketch for our optical Fingerprint sensor

  Designed specifically to work with the Adafruit BMP085 Breakout 
  ----> http://www.adafruit.com/products/751

  These displays use TTL Serial to communicate, 2 pins are required to 
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/



// On Leonardo/Micro or others with hardware serial, use those! #0 is green wire, #1 is white
// uncomment this line:
// #define mySerial Serial1

// For UNO and others without hardware serial, we must use software serial...
// pin #2 is IN from sensor (GREEN wire)
// pin #3 is OUT from arduino  (WHITE wire)
// comment these two lines if using hardware serial

#include <Adafruit_Fingerprint.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>
#define OLED_RESET 12

//pin setup
SoftwareSerial mySerial(8, 9);    //for fingerprint sensor serial
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);    //begin serial with fingerprint sensor
Adafruit_SSD1306 display(OLED_RESET);

int scan = 0;   //return value from f-sensor
int d1, d2, d3, d4 = 0;

void lights(void);
int getFingerprintID(void);

void setup(){

 
  pinMode(4, INPUT);    //touchpad inputs
  pinMode(5, INPUT);
  pinMode(6, INPUT);   
  pinMode(7, INPUT);
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32) 
  display.display();
  delay(2000);


  // set the data rate for the sensor serial port
  finger.begin(57600);
  
  display.clearDisplay();
  display.display();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  delay(500);
  if (finger.verifyPassword()) {    //detect fingerprint sensor
    display.println("Found fingerprint\nsensor!");
    display.display();
  } 
  else {
    display.println("Did not find fingerprint sensor :(");
    display.setCursor(0,1);
    display.println("Please reset system...");
    display.display();
    delay(10000);

  }
  delay(2000);
}

void loop(){             // run over and over again
  
  if(digitalRead(4)){     //if button held
    display.clearDisplay();
    display.setCursor(0,0);
    display.setTextSize(1);
    display.println("Scanning...");
    display.println("Put finger on sensor");
    display.println("> > > > > > > > > >");
    display.println("> > > > > > > > > >");
    display.display();
    display.clearDisplay();
    display.setCursor(0,0);
    delay(50);
    
    int j = 0;
    while((scan <1) && (j<100)){   //do 50 scans before resetting
      j = j+1;
      scan = getFingerprintID();
      delay(10);
    }
    display.display();
    
    if(scan <1){      //if scan failed reset
       display.clearDisplay();
       display.setCursor(0,0);
       display.setTextSize(1);
       display.println("Scan Failed!!!");
       display.println("Resetting...");
       display.display();
       delay(3000);
    }
 
    if(scan > 0){   //if scan found authorized user
      display.println("4 -> access");
      display.display();
      j = 0;
      d4 = 0;
      while((d4 ==0) && (j<50)){    //wait for user to hold 4 button down
        d4 = digitalRead(7);
        j = j +1;
        delay(200);
      }
      if(d4){                       //if button pressed start light control
      display.clearDisplay();
      display.setCursor(0,0);
      display.setTextSize(2);
      display.print("Accessing\nLights");
      display.display();
      delay(2000);
      lights();                 //call lighting control subroutine * * * * * * * * * * * * * * * * * * * 
    }
    else{                         //timeout error and reset if button not pressed
      display.clearDisplay();
      display.setCursor(0,0);
      display.setTextSize(2);
      display.println("Timeout\nError");
      display.println("-------");
      display.display();
      delay(3000);
    }
  }
  scan = 0;   //reset scan variable for next scan
 }
  else{                          //main screen flashes in loop if button 1 not pressed
     display.clearDisplay();
     display.setTextSize(3);
     display.setCursor(0,0);
     display.println("-------");
     display.setTextSize(1);
     display.println("     1 -> start");
     display.display();
     delay(750);
     display.clearDisplay();
     display.setTextSize(3);
     display.setCursor(0,0);
     display.println("SYS RDY");
     display.setTextSize(1);
     display.println("     1 -> start");
     display.display();
     delay(750);
  }
}


void lights(void){          //control lights function
  int found_lights = 0;     //check to see if reciever is turned on
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  int d1_stat = 0;      //temporary variables to hold status of button presses
  int d2_stat = 0;
  int d3_stat = 0;
  int d4_stat = 0;

     display.println("Control System Ready");
     display.println("Loading.....");
     display.display();
     delay(3000);
     
     display.clearDisplay();
     display.setCursor(0,0);
     display.println("1 -> Room Light");
     display.println("2 -> Upper Counter");
     display.println("3 -> Lower Counter");
     display.print("4 -> Stove Light");
     display.display();
     d1 = 0;
     d2 = 0;
     d3 = 0;
     d4 = 0;
     int d1_old, d2_old, d3_old, d4_old = 0;    //for button depress
      for(int k = 0;k<200;k = k+1){             //k is timeout variable so after 200 iterations it returns to main screeen

        d1_old = d1;
        d2_old = d2;
        d3_old = d3;
        d4_old = d4;
        d1 = digitalRead(4);
        d2 = digitalRead(5);
        d3 = digitalRead(6);
        d4 = digitalRead(7);
        
        if((d1 != d1_old)&& d1){    //check to makesure button pressed once
           d1_stat = !d1_stat;
           k = 0;
        }
        if((d2 != d2_old) && d2){
           d2_stat = !d2_stat;
           k = 0;
        }
        if((d3 != d3_old)&& d3){
           d3_stat = !d3_stat;
           k = 0;
        }
        if((d4 != d4_old)&& d4){
           d4_stat = !d4_stat;
           k = 0;
        }
           display.clearDisplay();
           display.setCursor(0,0);
           display.print(d1_stat);              //display status of lights
           display.println(" -> Room Light");
           display.print(d2_stat);
           display.println(" -> Upper Counter");
           display.print(d3_stat);
           display.println(" -> Lower Counter");
           display.print(d4_stat);
           display.print(" -> Stove Light");
           display.display();
         delay(50); 
       }

     display.clearDisplay();    //timeout screen
     display.setCursor(0,0);
     display.println("Exiting Light Control\n.....");
     display.display();
     delay(3000);
     return;                //return to main screen
}



//fingerprint functions

int getFingerprintID() {
  int p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      //display.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      //display.println("No finger detected");
      return -1;
    case FINGERPRINT_PACKETRECIEVEERR:
     // display.println("Communication error");
      return -1;
    case FINGERPRINT_IMAGEFAIL:
     // display.println("Imaging error");
      return -1;
    default:
      //display.println("Unknown error");
      return -1;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      //display.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
     // display.println("Image too messy");
      return -1;
    case FINGERPRINT_PACKETRECIEVEERR:
     // display.println("Communication error");
      return -1;
    case FINGERPRINT_FEATUREFAIL:
     // display.println("Could not find fingerprint features");
      return -1;
    case FINGERPRINT_INVALIDIMAGE:
     //display.println("Could not find fingerprint features");
      return -1;
    default:
     // display.println("Unknown error");
      return -1;
  }
  
  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    display.println("Scan successful");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
   // display.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    //display.println("Did not find a match");
    return -1;
  } else {
   // display.println("Unknown error");
    return -1;
  }   
  
  // found a match!
  display.print("Fingerprint ID #"); display.println(finger.fingerID); 
  display.print("Confidence level "); display.println(finger.confidence); 

  return finger.fingerID;
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  display.print("Found ID #"); display.println(finger.fingerID); 
  display.print("with confidence of "); display.println(finger.confidence);
  return finger.fingerID; 
}
