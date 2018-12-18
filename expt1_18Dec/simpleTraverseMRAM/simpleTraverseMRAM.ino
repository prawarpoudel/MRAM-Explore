/****************************************************************************
This program writes the entire memory range of FRAM and MRAM connected to the 
Arduino.

MRAM is connected at CS:9, Hold:3
FRAM is connected at CS:10, Hold:2

Developed by: Prawar Poudel (pp0030@uah.edu)
Date: 12/14/3018
****************************************************************************/
#include "myheader.h"

void setup() 
{
  char myMessage[100];
  Serial.begin(115200);     //initiate serial communication @ 115200 bps
  
  if (flushMemAndCheck())
  {
    sprintf(myMessage,"flush and check Successful !!");
    Serial.println(myMessage);
  }else
  {
    sprintf(myMessage,"flush and check NOT  Successful !!");
    Serial.println(myMessage);
  }
}

void loop() 
{
  // put your main code here, to run repeatedly:

}
