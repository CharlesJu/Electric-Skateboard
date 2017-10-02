#include "Servo.h"
Servo esc;
int throttlePin = 0;
 
void setup()
{
  esc.attach(9);
}
 
void loop()
{
  
    esc.write(50);
  
}
