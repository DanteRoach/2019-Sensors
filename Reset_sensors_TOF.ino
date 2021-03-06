/* Mentor Code.
  Author: Dafydd Rhys-Jones
  Team:   2557 The SOTABots
  Last updated: 20190224
  ##
  Description:
  Sample code to show a quick way to create arrays on pins and values, easy to call.

*/

//adds libraries
#include <VL53L1X.h>
#include <Wire.h>

//defines time of flight sensors
VL53L1X TOF1;
VL53L1X TOF2;

int IR_sensorPin[8] = {A0, A1, A2, A3, A4, A5, A6, A7}; // Analog Pins for distance sensors.
int IR_lineFollowerPin[6] = {A8, A9, A10, A11, A12, A13};  // Analog Pins for line following sensors.

// variable to store the value coming from the sensors.
double  IR_sensorValue[8];
double  IR_lineValue[6];
bool    lineBool;
bool    sensorBool;

// Delay
int delay_ms = 500;

// Declare your variables.
String  sensor;
int     location;
int     measurement;

// Declare your thresholds.
int sensorMin = -1;
int lineMin = 1000;


void setup() {

  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);

  Wire.begin();

  // Configure pins as Inputs.
  for (int i = 0; i < 8; i++) {
    pinMode(IR_sensorPin[i], INPUT);
  }
  for (int i = 0; i < 6; i++) {
    pinMode(IR_lineFollowerPin[i], INPUT);
  }
  // Set Booleans to False
  lineBool = false;
  sensorBool = false;

  Serial.begin (9600);

  pinMode(4, INPUT);
  TOF1.init(true);
  delay(200);
  TOF1.setAddress(0x28);

  pinMode(5, INPUT);
  TOF2.init(true);

  delay(200);
  TOF2.setAddress(0x31);

  TOF1.setDistanceMode(VL53L1X::Long);
  TOF1.setMeasurementTimingBudget(50000);
  TOF1.startContinuous(50);
  TOF2.setDistanceMode(VL53L1X::Long);
  TOF2.setMeasurementTimingBudget(50000);
  TOF2.startContinuous(50);\
  TOF1.setTimeout(100);
  TOF2.setTimeout(100);
  delay(150);

  byte count = 0;
  for (byte i = 1; i < 120; i++)
  {
    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
    {
      count++;
    }
  }
}

void loop() {
  Serial.print("TOFL");
  //Serial.print("Tof_1\t:\t");
  Serial.println(TOF1.read());
  //  Serial.print("ToF_2\t:\t");
  Serial.print("TOFR");
    Serial.println(TOF2.read());
  //Serial.println();
  for (int i = 0; i < 8; i++) {
    IR_sensorValue[i] = analogRead(IR_sensorPin[i]);
  };
  for (int i = 0; i < 6; i++) {
    IR_lineValue[i] = analogRead(IR_lineFollowerPin[i]);
  };
  for ( int a = 0; a < 8; a = a + 1 ) {
    sensor = "IR";
    location = a;
    measurement = IR_sensorValue[a];
    if (measurement < sensorMin) {
      sensorBool = true;
    } else {
      sensorBool = false;
    }
    //    Serial.print(sensor);
    //    Serial.print(location);
    //    Serial.print("\t:\t");
    //    Serial.println(sensorBool);
  };
  for ( int a = 0; a < 6; a = a + 1 ) {
    sensor = "Line";
    location = a;
    measurement = IR_lineValue[a];
    if (measurement < lineMin) {
      lineBool = true;
    } else {
      lineBool = false;
    }
   // Serial.print(sensor);
    //Serial.print(location);
   // Serial.print("\t:\t");
   // Serial.println(measurement);
  }
 // Serial.println("\n\n\n\n");
  delay(delay_ms);
  if (TOF1.read() == 0 || TOF2.read() == 0) {

    pinMode(4, INPUT);
    TOF1.init(true);
    delay(200);
    TOF1.setAddress(0x28);
    pinMode(5, INPUT);
    TOF2.init(true);

    TOF1.setDistanceMode(VL53L1X::Long);
    TOF1.setMeasurementTimingBudget(50000);
    TOF1.startContinuous(50);
    TOF2.setDistanceMode(VL53L1X::Long);
    TOF2.setMeasurementTimingBudget(50000);
    TOF2.startContinuous(50);
    TOF1.setTimeout(100);
  TOF2.setTimeout(100);
  delay(150);

  }
}
