void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  Serial.print("Hello Sketch v");
  Serial.println("1.0");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello world");
  delay(1000);
}
