#include <VL53L1X.h>
#include <Wire.h>
VL53L1X sensor;
VL53L1X sensor2;

void setup()
{

  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);

  delay(500);
  Wire.begin();


  Serial.begin (9600);

  pinMode(4, INPUT);
  delay(150);
  sensor.init(true);

  delay(100);
  sensor.setAddress(0x28);

  pinMode(5, INPUT);
    delay(150);
  sensor2.init(true);

  delay(100);
  sensor2.setAddress(0x31);

  sensor.setDistanceMode(VL53L1X::Long);
  sensor.setMeasurementTimingBudget(50000);
  sensor.startContinuous(50);
  sensor2.setDistanceMode(VL53L1X::Long);
  sensor2.setMeasurementTimingBudget(50000);
  sensor2.startContinuous(50);
  sensor.setTimeout(100);
  sensor2.setTimeout(100);
  delay(150);

  byte count = 0;


  for (byte i = 1; i < 120; i++)
  {

    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
    {


      count++;
      delay (1);  // maybe unneeded?
    } // end of good response
  } // end of for loop
  


}

void loop()
{

  Serial.print("a");
  Serial.print(sensor.read());
  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
  Serial.println();
  Serial.print("b");
   Serial.print(sensor2.read());
  if (sensor2.timeoutOccurred()) { Serial.print(" TIMEOUT"); }

  Serial.println();
  delay(100);

}
