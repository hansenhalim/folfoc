#include <Arduino.h>
#include <AFMotor.h>
#include <Wire.h>

#define MOTOR_A 0
#define MOTOR_B 1

#define I2C_ADDR 8      // I2C address of client
#define MOTOR_SPEED 500 // in rpm

AF_Stepper Stepper1(48, 1);
AF_Stepper Stepper2(48, 2);

uint16_t steps[2];
uint8_t dir[2];

void receiveEvent(int numBytes)
{
  if (numBytes >= 7)
  {
    // Make sure at least 7 bytes are received ("<motor_id>,<cmnd_dir>,<cmnd_steps>;")
    String command = "";

    while (Wire.available())
    {
      char c = Wire.read();
      command += c;
    }

    unsigned int motor_id;
    unsigned int cmnd_dir;
    unsigned int cmnd_steps;

    sscanf(command.c_str(), "%u,%u,%u;", &motor_id, &cmnd_dir, &cmnd_steps);

    steps[motor_id] = cmnd_steps;
    dir[motor_id] = cmnd_dir;
  }
}

void setup()
{
  Stepper1.setSpeed(MOTOR_SPEED);
  Stepper2.setSpeed(MOTOR_SPEED);

  Stepper1.release();
  Stepper2.release();

  Wire.begin(I2C_ADDR);
  Wire.onReceive(receiveEvent);
}

void loop()
{
  if (steps[MOTOR_A] > 0)
  {
    Stepper1.step(steps[MOTOR_A], dir[MOTOR_A], MICROSTEP);
    steps[MOTOR_A] = 0;
  }
  if (steps[MOTOR_B] > 0)
  {
    Stepper2.step(steps[MOTOR_B], dir[MOTOR_B], MICROSTEP);
    steps[MOTOR_B] = 0;
  }
}