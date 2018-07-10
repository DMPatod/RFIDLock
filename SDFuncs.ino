boolean SDinit()
{
	if (!SD.begin(4))
	{
		return false;
	}
	return true;
}

boolean searchTAG(uint8_t *TAG)
{
	boolean foundState = false;	//To Return
	
	File listFile = SD.open(fileName,FILE_READ);
	int counter = -1;
	boolean section = false;	//False for TAG section and True for Name section
	
	uint8_t bufferTAG[10];
	uint8_t *readedTAG;
	char readedName[25];
	
	if (listFile)
	{
		while (listFile.available() > 0)
		{
			if (!section)
			{
				uint8_t readVal = listFile.read();
				if (readVal == 0x2A)	//0x2A => '*'
				{
					counter = 0;
				}
				else if (readVal == 0x23)	//0x23 => '#'
				{
					//Reset Counter AND change section
					counter = -1;
					section = true;
					
					readedTAG = decodeBuffer(bufferTAG);
					
					if ((TAG[0] == readedTAG[0]) && (TAG[1] == readedTAG[1]) && (TAG[2] == readedTAG[2]) && (TAG[3] == readedTAG[3]) && (TAG[4] == readedTAG[4]))
					{
						foundState = true;
					}
					
				}
				else if (counter >= 0)
				{
					bufferTAG[counter++] = readVal;
				}
			}
			else
			{
				byte readVal = listFile.read();
				
				if (readVal == 0x23)	//0x23 => '#'
				{
					counter = 0;
				}
				else if (readVal == 0x3B)	//0x38 => ';'
				{
					if (foundState)
					{
						listFile.close();
						return foundState;
					}
					else
					{
						counter = -1;
						section = false;
					}
				}
				else if (counter >= 0)
				{
					readedName[counter++] = readedTAG;
				}
			}
		}
		listFile.close();
		
		return foundState;
	}
	else
	{
		Serial.println("Unable to Read File");
		return foundState;
	}
}

uint8_t* decodeBuffer(char* buffer)
{
	static uint8_t tempTAG[5];
	
	for (int i = 0, y = 0; i < 10; i++)
	{
		uint8_t auxLeft = convertASCtoINT(buffer[i++]);
		uint8_t auxRight = convertASCtoINT(buffer[i]);
		
		tempTAG[y++] = (auxLeft << 4) | auxRight;
	}
	
	return tempTAG;
}