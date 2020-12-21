// This module shows how to use arguments etc. in the functions
#include <cmdArduino.h>

void setup(){
  cmd.begin(57600);
  Serial.println("Module 3.1.2 Setting and accessing parameters");
  Serial.println("Command line argument list");
  cmd.add("list", cmdList);
}

void loop(){
  cmd.poll();
}

void cmdList(int argCnt, char **args){
  int i;
  i = 0;
  for(i=0; i<argCnt; i++){
    Serial.print("Arg ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(args[i]);
  }
}
