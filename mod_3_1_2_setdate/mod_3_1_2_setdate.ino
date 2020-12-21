// This module shows how to use arguments etc. in the functions
#include <cmdArduino.h>

void setup(){
  cmd.begin(57600);
  Serial.println("Module 3.1.2 Setting and accessing parameters");
  Serial.println("Command line argument list");
  Serial.println("Command line argument setdate assumes year month day");
  cmd.add("list", cmdList);
  cmd.add("setdate", cmdSetDate);
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

void cmdSetDate(int argCnt, char **args){
  int year = cmd.conv(args[1]);
  int month = cmd.conv(args[2]);
  int day = cmd.conv(args[3]);
  int yearlen = strlen(args[1]);
  
  if(yearlen != 4){
    Serial.println("Please enter year first in 4 digits e.g. 2020");
    //Serial.println(yearlen);
  } else {
  Serial.print(year);
  Serial.print("/");
  Serial.print(month);
  Serial.print("/");
  Serial.println(day);
  }
}
