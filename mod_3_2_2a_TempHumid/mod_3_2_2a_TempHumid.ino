#include <DHT.h>

// The temperature and humidity sensor will be plugged into
// pin A0 and is of type DHT11 (there is also a DHT22)
// The next line initialises the dht object.
DHT dht(A0, DHT11);

void setup() {
  // Initialise dht object and then serial port etc.
  dht.begin();
  Serial.begin(57600);
  Serial.println("Module 3.2.2a : Temperature & humidity");
}

void loop() {
  // Initialise a float variable called temperature and assign
  // it the value from the logger. Ditto humidity.
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Now print out temperature and humidity every 2 seconds
  Serial.print("Temperature=");
  Serial.print(temperature);
  Serial.print("  Humidity=");
  Serial.println(humidity);
  delay(2000);
}
