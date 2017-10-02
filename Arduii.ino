#include <VirtualWire.h>
#include <VirtualWire_Config.h>

int joy = 0;
bool but;
int counter;
float power = 0;
float vel = 0;
void setup() {
  // put your setup code here, to run once:
  //Setup Serial monitor
  Serial.begin(9600);
  Serial.println("setup");

 
  //Set Pinmode
  pinMode(4, INPUT);
  pinMode(13, OUTPUT);

  //Reset Variables
  counter = 0;
  power = 0;
  vel = 0;
  but = false;
  
}

void loop() {
  joy = analogRead(0) - 500;
  but = digitalRead(4);
  
  
  Serial.println(-power/380);

  //Accel. Profile
  if(but){
    if(power < joy && (!(-15 < joy && joy < 15) || power != 0) ){
      if(joy > 15 && power < 0){
        power += 5;
      } else {
        power += 2;
      }
    } else if(power > joy && (!(-15 < joy && joy < 15) || power != 0)) {
      if(joy < -15 && power > 0){
        power -= 5;
      } else {
        power -= 2;
      }
    }
  } else {
    if(power < 0){
      power += 2;
    } else if (power > 0){
      power -= 2;
    }
  }

  setMotor(-power / 380);

}

void setMotor(double v){
    v = (v + 1) * 63.5 + 127;
    analogWrite(3, (int)v);
  
}

