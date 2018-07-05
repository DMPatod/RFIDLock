#ifndef __TIME_H__
#define __TIME_H__

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Time
{
public:
	Time();
	Time(int hour, int minutes, int seconds, int date, int month, uint16_t year);
	~Time();
	
	int getSeconds();
	int getMinutes();
	int getHour();
	int getDate();
	int getMonth();
	int getYear();
	
	void setSeconds(int value);
	void setMinutes(int value);
	void setHour(int value);
	void setDate(int value);
	void setMonth(int value);
	void setYear(uint16_t value);
	
private:
	int seconds = 0;
	int minutes = 0;
	int hour = 0;
	int date = 0;
	int month = 0;
	int year = 0;
};

#endif //__TIME_H__