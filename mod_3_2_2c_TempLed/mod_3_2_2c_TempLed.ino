// Should print a warning and turn on LED if temperature goes above threshold
//#include <cmdArduino.h>
#include <DHT.h>

DHT dht(A0, DHT11);

int threshold = 25;
int pinLed = 4;

void setup() {
  pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed, LOW);

  dht.begin();
  Serial.begin(57600);
  Serial.println("Module 3.2.2c: Temperature warning system");
}

void loop() {
  float temperature = dht.readTemperature();

  if (temperature > threshold){
    digitalWrite(pinLed, HIGH);
    Serial.println("Warning, temperature exceeded threshold");
  } else {
    digitalWrite(pinLed, LOW);
  }
  Serial.print("Current temperature is ");
  Serial.print(temperature);
  Serial.println();
  delay(1000);
}
