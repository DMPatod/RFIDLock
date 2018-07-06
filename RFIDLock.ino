#include <SoftwareSerial.h>

#define RDM_RX 2
#define RDM_TX 3
SoftwareSerial RDMSerial(RDM_RX,RDM_TX);

uint8_t TAG_ID[5];
uint8_t CHECKSUM;
uint8_t serialBuffer[30];

void setup()
{
	Serial.begin(9600);
	Serial.println("Begin Program");
	
	RDMSerial.begin(9600);
}

void loop()
{
	if ( RDMRead() )
	{
		Serial.println("Found RFID");
	}
	else
	{
		Serial.println("Nothing Found");
	}
}
