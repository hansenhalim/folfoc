#include <Arduino.h>
#include <AFMotor.h>
#include <Wire.h>

#define MOTOR_A 0
#define MOTOR_B 1

#define I2C_ADDR 8 // The I2C address of client

AF_Stepper Stepper1(48, 1);
AF_Stepper Stepper2(48, 2);

void receiveEvent(int numBytes)
{
  if (numBytes >= 7)
  {
    // Make sure at least 7 bytes are received ("<motor_id>,<dir>,<steps>;")
    String command = "";

    while (Wire.available())
      command += Wire.read();

    uint8_t motor_id;
    uint8_t dir;
    uint16_t steps;

    sscanf(command.c_str(), "%u,%u,%u;", &motor_id, &dir, &steps);

    // Perform action based on received command
    switch (motor_id)
    {
    case MOTOR_A:
      Stepper1.step(steps, dir, DOUBLE);
      break;

    case MOTOR_B:
      Stepper2.step(steps, dir, DOUBLE);
      break;
    }
  }
}

void setup()
{
  Serial.begin(9600);

  Stepper1.setSpeed(50); // 50 rpm
  Stepper2.setSpeed(50); // 50 rpm

  Wire.begin(I2C_ADDR);
  Wire.onReceive(receiveEvent);
}

void loop()
{
}