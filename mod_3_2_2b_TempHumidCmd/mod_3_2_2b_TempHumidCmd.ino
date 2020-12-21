// Issue commands for temp or humidity
#include <cmdArduino.h>
#include <DHT.h>

// The temperature and humidity sensor will be plugged into
// pin A0 and is of type DHT11 (there is also a DHT22)
// The next line initialises the dht object.
DHT dht(A0, DHT11);

void setup() {
  // Initialise dht object and baud rate for serial monitor.
  dht.begin();
  cmd.begin(57600);
  
  // Print startup info
  Serial.println("Module 3.2.2b : Temperature & humidity");
  Serial.println("Use temp or humidity to get info");

  // The commands
  cmd.add("temp", cmdTemperature);
  cmd.add("humidity", cmdHumidity);
}

void loop() {
  cmd.poll();
}

void cmdTemperature(int argCnt, char **args){
  // Initialise a float variable called temperature and assign
  // it the value from the logger, then print nicely.
  float temperature = dht.readTemperature();
  Serial.print("Temperature=");
  Serial.print(temperature);
  Serial.println(" degrees Celsius");
}

void cmdHumidity(int argCnt, char **args){
  // Ditto humidity
  float humidity = dht.readHumidity();
  Serial.print("Humidity=");
  Serial.print(humidity);
  Serial.println(" % relative humidity");
}
