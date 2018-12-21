#ifndef MY_HEADER_H
#define MY_HEADER_H


#include <mram.h>
#include <stdio.h>

//create an object here so that it has global scope throughout this file
//  -> CS signal is Android pin 10
mram myMram(9,3);
void stress(const unsigned long int& stressLoop,const char stressData,uint16_t address)
{
	for(unsigned long int i=0;i<stressLoop;i++)
	{
		myMram.writeByteEffecient(address,stressData);
	}
}

void readData(char* myArray,const int numToRead,const char myAddress)
{
	//no error handling considering that the array passed is good
	for(unsigned int i=0;i<numToRead;i++)
	{
		myArray[i] = myMram.readByteEffecient(myAddress);
		Serial.print(myArray[i]);
	}
}
#endif