#include <Wire.h>
#include "DFRobot_RainfallSensor.h"

DFRobot_RainfallSensor_I2C rain(&Wire);

void setup() {
  Serial.begin(9600);
  Wire.begin();

  Serial.println("Initializing rainfall sensor...");

  if (!rain.begin()) {
    Serial.println("Rainfall sensor init failed");
    while (1);
  }

  Serial.println("Rainfall sensor ready");
  Serial.print("Firmware version: ");
  Serial.println(rain.getFirmwareVersion());
}

void loop() {
  float totalRainMM = rain.getRainfall();

  Serial.print("Total Rainfall: ");
  Serial.print(totalRainMM, 4);
  Serial.println(" mm");

  delay(2000);
}
