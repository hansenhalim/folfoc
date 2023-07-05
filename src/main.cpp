#include <Arduino.h>
#include <AFMotor.h>

AF_Stepper motor(48, 2);

void setup()
{
  motor.setSpeed(100); // 100 rpm
}

void loop()
{
  motor.step(500, FORWARD, SINGLE);
  motor.step(500, BACKWARD, SINGLE);
  delay(5000);
}