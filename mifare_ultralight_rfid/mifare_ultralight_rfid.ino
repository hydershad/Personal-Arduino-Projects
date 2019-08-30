
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9           // Configurable, see typical pin layout above
#define SS_PIN          10          // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance
char c[20] = {0};
char card_uno[] = "04 08 7A 04 03 3F 87";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //can change to higher baud rate  // Initialize serial communications with the PC
  SPI.begin();               // Init SPI bus
  mfrc522.PCD_Init();        // Init MFRC522 card
  Serial.println(F("Read personal data on a MIFARE PICC "));
  mfrc522.PCD_SetAntennaGain(mfrc522.RxGain_max);
}

void loop() {
  // put your main code here, to run repeatedly:
   MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;
    while ( ! mfrc522.PICC_IsNewCardPresent()) {
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
     return;
   }
//     Serial.print(F("Card UID:"));    //Dump UID
//    for (byte i = 0; i < mfrc522.uid.size; i++) {
//    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
//    Serial.print(mfrc522.uid.uidByte[i], HEX);
//  }
//  Serial.print(F(" PICC type: "));   // Dump PICC type
//  MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
//  Serial.println(mfrc522.PICC_GetTypeName(piccType));
//
 mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}
