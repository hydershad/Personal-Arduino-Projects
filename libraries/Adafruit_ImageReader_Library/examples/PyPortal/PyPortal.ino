// Adafruit_ImageReader test for PyPortal. Demonstrates loading images
// from SD card to screen, to RAM, and how to query image file dimensions.
// OPEN THE ARDUINO SERIAL MONITOR WINDOW TO START PROGRAM.
// Requires three BMP files in root directory of SD card:
// purple.bmp, parrot.bmp and wales.bmp.

#include <SD.h>
#include <Adafruit_GFX.h>         // Core graphics library
#include <Adafruit_ILI9341.h>     // Hardware-specific library
#include <Adafruit_ImageReader.h> // Image-reading functions

#define TFT_D0        34 // Data bit 0 pin (MUST be on PORT byte boundary)
#define TFT_WR        26 // Write-strobe pin (CCL-inverted timer output)
#define TFT_DC        10 // Data/command pin
#define TFT_CS        11 // Chip-select pin
#define TFT_RST       24 // Reset pin
#define TFT_RD         9 // Read-strobe pin
#define TFT_BACKLIGHT 25
#define SD_CS         32

Adafruit_ILI9341     tft(tft8, TFT_D0, TFT_WR, TFT_DC, TFT_CS, TFT_RST, TFT_RD);
Adafruit_ImageReader reader;     // Class w/image-reading functions
Adafruit_Image       img;        // An image loaded into RAM
int32_t              width  = 0, // BMP image dimensions
                     height = 0;

void setup(void) {

  ImageReturnCode stat; // Status from image-reading functions

  Serial.begin(9600);
  while(!Serial);       // Wait for Serial Monitor before continuing

  // Turn on backlight (required on PyPortal)
  pinMode(TFT_BACKLIGHT, OUTPUT);
  digitalWrite(TFT_BACKLIGHT, HIGH);

  tft.begin();          // Initialize screen

  Serial.print(F("Initializing SD card..."));
  if(!SD.begin(SD_CS)) {
    Serial.println(F("failed!"));
    for(;;); // Loop here forever
  }
  Serial.println(F("OK!"));

  // Fill screen blue. Not a required step, this just shows that we're
  // successfully communicating with the screen.
  tft.fillScreen(ILI9341_BLUE);

  // Load full-screen BMP file 'purple.bmp' at position (0,0) (top left).
  // Notice the 'reader' object performs this, with 'tft' as an argument.
  Serial.print(F("Loading purple.bmp to screen..."));
  stat = reader.drawBMP("/purple.bmp", tft, 0, 0);
  // (Absolute path isn't necessary on most devices, but something
  // with the ESP32 SD library seems to require it.)
  reader.printStatus(stat);   // How'd we do?

  // Query the dimensions of image 'parrot.bmp' WITHOUT loading to screen:
  Serial.print(F("Querying parrot.bmp image size..."));
  stat = reader.bmpDimensions("/parrot.bmp", &width, &height);
  reader.printStatus(stat);   // How'd we do?
  if(stat == IMAGE_SUCCESS) { // If it worked, print image size...
    Serial.print(F("Image dimensions: "));
    Serial.print(width);
    Serial.write('x');
    Serial.println(height);
  }

  // Load small BMP 'wales.bmp' into a GFX canvas in RAM. This should
  // fail gracefully on AVR and other small devices, meaning the image
  // will not load, but this won't make the program stop or crash, it
  // just continues on without it.
  Serial.print(F("Loading wales.bmp to canvas..."));
  stat = reader.loadBMP("/wales.bmp", img);
  reader.printStatus(stat); // How'd we do?

  delay(2000); // Pause 2 seconds before moving on to loop()
}

void loop() {
  for(int r=0; r<4; r++) { // For each of 4 rotations...
    tft.setRotation(r);    // Set rotation
    tft.fillScreen(0);     // and clear screen

    // Load 4 copies of the 'parrot.bmp' image to the screen, some
    // partially off screen edges to demonstrate clipping. Globals
    // 'width' and 'height' were set by bmpDimensions() call in setup().
    for(int i=0; i<4; i++) {
      reader.drawBMP("/parrot.bmp", tft,
        (tft.width()  * i / 3) - (width  / 2),
        (tft.height() * i / 3) - (height / 2));
    }

    delay(1000); // Pause 1 sec.

    // Draw 50 Welsh dragon flags in random positions. This has no effect
    // on memory-constrained boards like the Arduino Uno, where the image
    // failed to load due to insufficient RAM, but it's NOT fatal.
    for(int i=0; i<50; i++) {
      // Rather than reader.drawBMP() (which works from SD card),
      // a different function is used for RAM-resident images:
      img.draw(tft,                                    // Pass in tft object
        (int16_t)random(-img.width() , tft.width()) ,  // Horiz pos.
        (int16_t)random(-img.height(), tft.height())); // Vert pos
      // Reiterating a prior point: img.draw() does nothing and returns
      // if the image failed to load. It's unfortunate but not disastrous.
    }

    delay(2000); // Pause 2 sec.
  }
}
