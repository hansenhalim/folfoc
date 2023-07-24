#include <Arduino.h>
#include <AFMotor.h>
#include <Wire.h>

// AF_Stepper Stepper1(48, 1);
// AF_Stepper Stepper2(48, 2);

void receiveEvent(int numBytes)
{
  if (numBytes >= 7)
  { // Make sure at least 7 bytes are received ("<motor_id>,<direction>,<steps>;")
    String command = "";
    while (Wire.available())
    {
      char c = Wire.read();
      command += c;
    }

    Serial.println(command);

    int motor_id, steps;
    String direction;

    sscanf(command.c_str(), "%d,%s,%d;", &motor_id, direction, &steps);

    // Perform action based on received command
    // if (motor_id == 1)
    // {
    //   // controlMotor(motor1Pin, direction, steps);
    //   Serial.print("motor_id: ");
    //   Serial.println(motor_id);
    //   Serial.print("direction: ");
    //   Serial.println(direction);
    //   Serial.print("steps: ");
    //   Serial.println(steps);
    // }
    // else if (motor_id == 2)
    // {
    //   // controlMotor(motor2Pin, direction, steps);
    //   Serial.print("motor_id: ");
    //   Serial.println(motor_id);
    //   Serial.print("direction: ");
    //   Serial.println(direction);
    //   Serial.print("steps: ");
    //   Serial.println(steps);
    // }

    Serial.print("motor_id: ");
    Serial.println(motor_id);
    Serial.print("direction: ");
    Serial.println(direction);
    Serial.print("steps: ");
    Serial.println(steps);
  }
}

void setup()
{
  Serial.begin(9600);

  String command = "";

  // Wire.begin(8); // Arduino A is the I2C slave with address 8
  // Wire.onReceive(receiveEvent);

  // Stepper1.setSpeed(50); // 50 rpm
  // Stepper2.setSpeed(50); // 50 rpm
}

void loop()
{
  // Stepper1.step(500, FORWARD, DOUBLE);
  // Stepper1.step(500, BACKWARD, DOUBLE);
  // Stepper2.step(500, FORWARD, DOUBLE);
  // Stepper2.step(500, BACKWARD, DOUBLE);
  // delay(5000);
}