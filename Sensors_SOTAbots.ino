#include <VL53L1X.h>
#include <Wire.h>

VL53L1X sensorTOF1;
VL53L1X sensorTOF2;

#define sensor1 A0
#define sensor2 A1
#define sensor3 A2
#define sensor4 A3
#define sensor5 A4
#define sensor6 A5
#define sensor7 A6
#define sensor8 A7
#define sensor9 A8
#define sensor10 A9
#define sensor11 A10
#define sensor12 A11
#define sensor13 A12
#define sensor14 A13
void setup() {
  
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);

  delay(500);
  Wire.begin();

  Serial.begin (9600);

  pinMode(4, INPUT);
  delay(150);
  Serial.println("00");
  sensorTOF1.init(true);

  Serial.println("01");
  delay(100);
  sensorTOF1.setAddress(0x28);
  Serial.println("02");

  pinMode(5, INPUT);
    delay(150);
  sensorTOF2.init(true);
  Serial.println("03");
  delay(100);
  sensorTOF2.setAddress(0x31);
  Serial.println("04");

  sensorTOF1.setDistanceMode(VL53L1X::Long);
  sensorTOF1.setMeasurementTimingBudget(50000);
  sensorTOF1.startContinuous(50);
  sensorTOF2.setDistanceMode(VL53L1X::Long);
  sensorTOF2.setMeasurementTimingBudget(50000);
  sensorTOF2.startContinuous(50);
  sensorTOF1.setTimeout(100);
  sensorTOF2.setTimeout(100);
  delay(150);
  Serial.println("addresses set");

  Serial.println ("I2C scanner. Scanning ...");
  byte count = 0;


  for (byte i = 1; i < 120; i++)
  {

    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
    {
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      count++;
      delay (1);
    }
  }
  Serial.println ("Done.");
  Serial.print ("Found ");
  Serial.print (count, DEC);
  Serial.println (" device(s).");
  
}

void loop() {
  
  float volts1 = analogRead(sensor1)*0.0048828125;
  float volts2 = analogRead(sensor2)*0.0048828125;
  float volts3 = analogRead(sensor3)*0.0048828125;
  float volts4 = analogRead(sensor4)*0.0048828125;
  float volts5 = analogRead(sensor5)*0.0048828125;
  float volts6 = analogRead(sensor6)*0.0048828125;
  float volts7 = analogRead(sensor7)*0.0048828125;
  float volts8 = analogRead(sensor8)*0.0048828125;
  float volts9 = analogRead(sensor9)*0.0048828125;
  float volts10 = analogRead(sensor10)*0.0048828125;
  float volts11 = analogRead(sensor11)*0.0048828125;
  float volts12 = analogRead(sensor12)*0.0048828125;
  float volts13 = analogRead(sensor13)*0.0048828125;
  float volts14 = analogRead(sensor14)*0.0048828125;
  
  int distance1 = 13*pow(volts1, -1);
  int distance2 = 13*pow(volts2, -1);
  int distance3 = 13*pow(volts3, -1);
  int distance4 = 13*pow(volts4, -1);
  int distance5 = 13*pow(volts5, -1);
  int distance6 = 13*pow(volts6, -1);
  int distance7 = 13*pow(volts7, -1);
  int distance8 = 13*pow(volts8, -1);
  int distance9 = 13*pow(volts9, -1);
  int distance10 = 13*pow(volts10, -1);
  int distance11 = 13*pow(volts11, -1);
  int distance12 = 13*pow(volts12, -1);
  int distance13 = 13*pow(volts13, -1);
  int distance14 = 13*pow(volts14, -1);
  
  delay(100);

  Serial.print("TOF1&2");
  Serial.print(sensorTOF1.read());
  Serial.print(",");
  Serial.print(sensorTOF2.read());
  
  Serial.print(" IRD7-14: ");
  Serial.print(distance7);
  Serial.print(",");
  Serial.print(distance8);
  Serial.print(",");
  Serial.print(distance9);
  Serial.print(",");
  Serial.print(distance10);
  Serial.print(",");
  Serial.print(distance11);
  Serial.print(",");
  Serial.print(distance12);
  Serial.print(",");
  Serial.print(distance13);
  Serial.print(",");
  Serial.print(distance14);
  
  Serial.print(" V1-14: ");
  Serial.print(volts1);
  Serial.print(",");
  Serial.print(volts2);
  Serial.print(",");
  Serial.print(volts3);
  Serial.print(",");
  Serial.print(volts4);
  Serial.print(",");
  Serial.print(volts5);
  Serial.print(",");
  Serial.print(volts6);
  Serial.print(",");
  Serial.print(volts7);
  Serial.print(",");
  Serial.print(volts8);
  Serial.print(",");
  Serial.print(volts9);
  Serial.print(",");
  Serial.print(volts10);
  Serial.print(volts11);
  Serial.print(",");
  Serial.print(volts12);
  Serial.print(",");
  Serial.print(volts13);
  Serial.print(",");
  Serial.println(volts14);
}
