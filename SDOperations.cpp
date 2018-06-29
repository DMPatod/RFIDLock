#include "SDOperations.h"

boolean SDOperations::init()
{
	if (!SD.begin(4))
	{
		return false;
	}
	return true;
}

boolean SDOperations::searchTAG(char *TAG)
{
	boolean foundState = false;
	
	File listFile = SD.open(fileName,FILE_READ);
	int counter = -1;
	boolean section = false;	//False for TAG section and True for Name section

	uint8_t bufferTAG[10];
	
	if (listFile)
	{
		while (listFile.available() > 0)
		{
			if (!section)
			{
				uint8_t readVal = listFile.read();
				if (readVal == 0x2A)
				{
					counter = 0;
				}
				else if (readVal == 0x23)
				{
					counter = -1;
					section = true;
					
					decode(bufferTAG);
					
					
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
				
				if (readVal == 0x23)
				{
					counter = 0;
				}
				else if (readVal == 0x38)
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
					readedName[counter++] = readVal;
				}
			}
		}
		listFile.close();
		
		return foundState;
	}
	else
	{
		return false;
	}
}

void SDOperations::decode(uint8_t *bufferPointer)
{
	for (int i = 0, y = 0; i < 10; i++)
	{
		uint8_t auxLeft = convertASCtoINT(bufferPointer[i++]);
		uint8_t auxRight = convertASCtoINT(bufferPointer[i]);
		
		readedTAG[y++] = (auxLeft << 4) | auxRight;
	}
}

int SDOperations::convertASCtoINT(uint8_t value)
{
	if (value - 48 > 9) {
		value -= 55;
	}
	else {
		value -= 48;
	}
	return value;
}