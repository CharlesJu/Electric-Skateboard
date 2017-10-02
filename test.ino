int counter;

void setup() {
  // put your setup code here, to run once:
counter = 0;
Serial.begin(9600);
}

void loop() {
  swag();
}

void setMotor(double v){
  
    v = (v + 1) * 63.5 + 127;
    analogWrite(10, v);
}

void swag(){
  analogWrite(10, 0);
  delay(1000);
  analogWrite(10, 127);
  delay(1000);
  analogWrite(10, 0);
  delay(1000);
  analogWrite(10, 127);
  delay(1000);
}

