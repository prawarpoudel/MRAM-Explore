#ifndef MY_HEADER_H
#define MY_HEADER_H


#include <mram.h>
#include <stdio.h>

//create an object here so that it has global scope throughout this file
//  -> CS signal is Android pin 10
mram myMram(9,3);
bool flushMemAndCheck()
{
  /*
    this function flushes the entire memory range and checks to see if reading and writing is correct
  */

  char myMessage[100];
  bool sendStatus = true;
 //first we will just go through the memory and write zeros to them
 //each of the chip is 32K bytes
 //fillBytes will write the same thing over the entire range of memory (length should be specified): 0x00
 myMram.fillBytes(0x00,0,32768);

 //now when I read out, all of then should be read as 00s
 for(unsigned short i=0;i<32768;i++)
 {
    if(myMram.readByte(i)==0)
    {}
     else
     {
      sprintf(myMessage,"MRAM: Error at location 0x%x: 0x%x should be 0",i);
      Serial.println(myMessage);
      sendStatus = false;
     }
 } 
 
 //fillBytes will write the same thing over the entire range of memory (length should be specified): 0xff
 myMram.fillBytes(0x00,255,32768);

 //now when I read out, all of then should be read as 00s
 for(unsigned short i=0;i<32768;i++)
 {
    if(myMram.readByte(i)==255)
    {}
     else
     {
      sprintf(myMessage,"MRAM: Error at location 0x%x: 0x%x should be 0xff",i);
      Serial.println(myMessage);
      sendStatus = false;
     }
 }
 return sendStatus;
}
#endif