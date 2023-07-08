#include <Arduino.h>
#include <AFMotor.h>

AF_Stepper Stepper1(48, 1);
AF_Stepper Stepper2(48, 2);

void setup()
{
  Stepper1.setSpeed(50); // 50 rpm
  Stepper2.setSpeed(50); // 50 rpm
}

void loop()
{
  Stepper1.step(500, FORWARD, DOUBLE);
  Stepper1.step(500, BACKWARD, DOUBLE);
  Stepper2.step(500, FORWARD, DOUBLE);
  Stepper2.step(500, BACKWARD, DOUBLE);
  // delay(5000);
}