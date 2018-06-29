#ifndef __RDM6300_H__
#define __RDM6300_H__

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
typedef Stream SerialStream;
#else
#include <WProgram.h>
typedef Print SerialStream;
#endif

class RDM6300
{
	public:
	RDM6300(SerialStream &port);
	~RDM6300();
	
	boolean read(uint8_t *ValuePointer);
	protected:
	
	private:
	boolean decodeRFID(uint8_t *ValuePointer);
	int convertASCtoINT(uint8_t value);
	
	SerialStream &mSerial;
	
	uint8_t serialBuffer[30];
	uint8_t CHECKSUM;
};

#endif //__RDM6300_H__