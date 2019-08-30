
  int valRIGHT = 0;
  int valLEFT = 0;
void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  valRIGHT = analogRead(A0);
  Serial.print("valRIGHT-----");
  Serial.print(valRIGHT);
  Serial.println();
  valLEFT = analogRead(A1);
  Serial.print("valLEFT------");
  Serial.print(valLEFT);
  Serial.println();
  delay(500);

}
