/*
* RDM6300.cpp
* Author: DM
*/

#include "RDM6300.h"

// default constructor
RDM6300::RDM6300(SerialStream &port)
{
	mSerial = port;
} //RDM6300

boolean RDM6300::read(uint8_t *ValuePointer)
{
	int counter = -1;
	while (mSerial.available() > 0) {
		uint8_t readVal = mSerial.read();

		if (readVal == 0x02) {
			// Data Start
			counter = 0;
		}
		else if (readVal == 0x03) {
			// End Data
			return decodeRFID(ValuePointer);
		}
		else if (counter >= 0) {
			// Data Reading
			serialBuffer[counter++] = readVal;
		}
	}
	return false;
}

boolean RDM6300::decodeRFID(uint8_t *ValuePointer)
{
	for (int i = 0, y = 0; i < 12; i++)
	{
		uint8_t auxLeft = convertASCtoINT(serialBuffer[i++]);
		uint8_t auxRight = convertASCtoINT(serialBuffer[i]);
		
		if (y <= 5)
		{
			ValuePointer[y++] = (auxLeft << 4) | auxRight;
		}
		else
		{
			CHECKSUM = (auxLeft << 4) | auxRight;
		}
	}
	uint8_t TEMPSUM = 0;
	for (int i = 0; i < 5; i++)
	{
		TEMPSUM ^= ValuePointer[i];
	}
	if (TEMPSUM == CHECKSUM)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int RDM6300::convertASCtoINT(uint8_t value)
{
	if (value - 48 > 9) {
		value -= 55;
	}
	else {
		value -= 48;
	}
	return value;
}

// default destructor
RDM6300::~RDM6300()
{
} //~RDM6300