/*
WiFi Web Server LED Blink
Hyder Shad
 Modified example code from ESp-32s library for EE364E project testing
 ///////////////
 created for arduino 25 Nov 2012
 by Tom Igoe

ported for sparkfun esp32 
31.01.2017 by Jan Hendrik Berlin
 
 */

#include <WiFi.h>
const char* ssid     = "hsG7";
const char* password = "g7netw0rk";

WiFiServer server(80);

void setup()
{
    Serial.begin(115200);    //default serial bd rate for esp32s board, may not work well for secondary unit
    pinMode(2, OUTPUT);      // set to the on board blue LED pin
    pinMode(4, OUTPUT);

    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());  //print out local IP address for connection
    
    server.begin();
}

int value = 0;

void loop(){
 WiFiClient client = server.available();    // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");          // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/L\">here</a> to <strong>lock</strong> the car (LED).<br>");
            client.print("Click <a href=\"/U\">here</a> to <strong>unlock</strong> the car (LED).<br>");
   
            
 // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {               // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /U" or "GET /U":
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(2, HIGH);               // GET /L turns the LED on, "locking car"
          digitalWrite(4, HIGH);
        }
        if (currentLine.endsWith("GET /U")) {
          digitalWrite(2, LOW);                // GET /U turns the LED off, "unlocking car"
          digitalWrite(4, LOW);
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
