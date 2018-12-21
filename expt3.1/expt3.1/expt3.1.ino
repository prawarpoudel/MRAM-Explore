#include "myheader.h"

const unsigned long int stressLoop = 1000000;
uint8_t readLoop = 200;
char *myVal;
const unsigned int myAddress = 10;
char myStressData;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  myVal = new char[readLoop];
  
  myStressData = 0xff;
  stress(stressLoop,myStressData,myAddress);
  readData(myVal,readLoop,myAddress);

  myStressData = 0x00;
  stress(stressLoop,myStressData,myAddress);
  readData(myVal,readLoop,myAddress);

  myStressData = 0x55;
  stress(stressLoop,myStressData,myAddress);
  readData(myVal,readLoop,myAddress);
  
  myStressData = 0xaa;
  stress(stressLoop,myStressData,myAddress);
  readData(myVal,readLoop,myAddress);
  delete[] myVal;
}

void loop() {
  // put your main code here, to run repeatedly:

}
