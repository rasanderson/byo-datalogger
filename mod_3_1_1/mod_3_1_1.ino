#include <cmdArduino.h>

void setup()
{
  // put your setup code here, to run once:
  cmd.begin(57600);
  // hello is the name we want to use
  // cmdHello is the function defined below
  cmd.add("hello", cmdHello);
}

void loop() {
  // put your main code here, to run repeatedly:
  // cmd.poll checks the serial monitor every time something is typed
  // to see if it matches anything in the command list (hello in this example)
  // In the serial console make sure Carriage return is set.
  // It will display CMD: command not recognised initially
  cmd.poll();
}

void cmdHello(int argCnt, char **args)
{
  Serial.println("Hello little Command Line");
}
