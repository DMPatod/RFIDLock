boolean RDMRead()
{
	int counter = -1;
	if (RDMSerial.available() > 0)
	{
		while(RDMSerial.available() > 0)
		{
			uint8_t readVal = RDMSerial.read();
			
			if (readVal == 0x02) {
				// Data Start
				counter = 0;
			}
			else if (readVal == 0x03) {
				// End Data
				return decodeRFID();
			}
			else if (counter >= 0) {
				// Data Reading
				serialBuffer[counter++] = readVal;
			}
		}
	}
	else
	{
		return false;
	}
}

boolean decodeRFID()
{
	for (int i = 0, y = 0; i < 12; i++)
	{
		uint8_t auxLeft = convertASCtoINT(serialBuffer[i++]);
		uint8_t auxRight = convertASCtoINT(serialBuffer[i]);
		
		if (y < 5)
		{
			TAG_ID[y++] = (auxLeft << 4) | auxRight;
		}
		else
		{
			CHECKSUM = (auxLeft << 4) | auxRight;
		}
	}
	uint8_t TEMPSUM = 0;
	for (int i = 0; i < 5; i++)
	{
		TEMPSUM ^= TAG_ID[i];
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