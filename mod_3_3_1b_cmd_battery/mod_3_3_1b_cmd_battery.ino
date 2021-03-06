#include <cmdArduino.h>

// Get voltage on command


#define ADC_UNITS 1024 // The pin is 10-bit, i.e. 2^10 = 1024 divisions
#define ADC_REF_VOLTAGE 3.3 // The value the ADC works from
#define ADC_SCALE_FACTOR 2 // Use to convert back to original

int pinBatt = A6; // The pin for the battery

void setup() {
  pinMode(pinBatt, INPUT); // define mode of pin as input only

  cmd.begin(57600);
  Serial.println("Module 3.3: part 1b. Display battery volts on batt command");
  cmd.add("batt", cmdBatt);
}

void loop() {
  cmd.poll();
}

void cmdBatt(int argCnt, char **args){
  // Read the battery but note it will not be in volts so needs conversion
  int battAdc = analogRead(pinBatt);
  float mVPerUnit = ADC_REF_VOLTAGE / ADC_UNITS;
  float battVoltage = battAdc * mVPerUnit * ADC_SCALE_FACTOR;

  Serial.print("ADC value is ");
  Serial.print(battAdc);
  Serial.print(" battery voltage is ");
  Serial.println(battVoltage);
}
