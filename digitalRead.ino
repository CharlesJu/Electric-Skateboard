int incomingByte = 0;
void setup() {
  //2400 baud for the 434 model
  Serial.begin(2400);
}
void loop() {
  // read in values, debug to computer
  if (Serial.available() > 0) {
    Serial.println(Serial.read());
  }
  incomingByte = 0;
}
