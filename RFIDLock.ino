#include <SoftwareSerial.h>
#include <SD.h>
#include <SPI.h>

//////////////////////////////////////////////////////////////////////////
#define RDM_RX 2
#define RDM_TX 3
SoftwareSerial RDMSerial(RDM_RX,RDM_TX);

uint8_t TAG_ID[5];
uint8_t CHECKSUM;
uint8_t serialBuffer[30];
//////////////////////////////////////////////////////////////////////////
String fileName = "IDList.txt";
//////////////////////////////////////////////////////////////////////////

void setup()
{
	Serial.begin(9600);
	Serial.println("Begin Program");
	
	RDMSerial.begin(9600);
	
	if ( !SDinit() )
	{
		Serial.println("Fail to initialize SDCard");
		Serial.println("Ending Program");
		while(1){}
	}
}

void loop()
{
	if ( RDMRead() )
	{	
		if (searchTAG(TAG_ID))
		{
			Serial.println("ACHOUU");
		}
		else
		{
			Serial.println("NAO ACHOU :(");
		}
	}
	else
	{
		Serial.println("Nothing Found");
	}
}
