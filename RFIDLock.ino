#include <SoftwareSerial.h>

#include "Time.h"
#include "Clock.h"
#include "SDOperations.h"
#include "RDM6300.h"

#define RDM_RX 2
#define RDM_TX 3
SoftwareSerial RDMSerial(RDM_RX,RDM_TX);
uint8_t TAG_ID[5];

RDM6300 mRDM(RDMSerial);

void setup()
{
	
}

void loop()
{
}
