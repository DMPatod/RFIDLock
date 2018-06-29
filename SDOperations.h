// SDOperations.h

#ifndef _SDOPERATIONS_h
	#define _SDOPERATIONS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#ifndef __SD_H__
	#include <SD.h>
#endif

#ifndef _SPI_H_INCLUDED
	#include <SPI.h>
#endif

class SDOperations
{
 protected:


 public:
	SDOperations();
	static boolean init();
	static boolean searchTAG(char *TAG); 
private:
	String fileName = "IDList.txt";
	uint8_t readedTAG[5];
	byte readedName[25];
	
	void decode(uint8_t *bufferPointer);
	int convertASCtoINT(uint8_t value);
};

#endif

