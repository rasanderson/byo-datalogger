#include <cmdArduino.h>

// Declare a variable that can be used to refer to the
// LED code on the WildLogger board. Likewise the delay
// time was hard-coded originally. Now use a variable.
int pinLed = 13;
int delayTime = 1000;

void setup(){
  cmd.begin(57600); // baud rate for command line
  Serial.println("Lab 1b (module 3.1.3): Command blink");

  pinMode(pinLed, OUTPUT); // originally 13 was hard-coded
  digitalWrite(pinLed, LOW); // off to start with

  cmd.add("blink", cmdBlink); // define name of function
}

void loop(){
  cmd.poll();

  // Get the LED to blink, but allow the delay time to vary
  digitalWrite(pinLed, HIGH);
  delay(delayTime);
  digitalWrite(pinLed, LOW);
  delay(delayTime);
}

void cmdBlink(int argCnt, char **args){
  pinLed = cmd.conv(args[1]);
  delayTime = cmd.conv(args[2]);
}
