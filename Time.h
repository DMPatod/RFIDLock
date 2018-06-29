#ifndef __TIME_H__
#define __TIME_H__

class Time
{
public:
	Time(int hour, int minutes, int seconds, int date, int month, uint16_t year);
	~Time();
	
	int getSeconds();
	int getMinutes();
	int getHour();
	int getDate();
	int getMonth();
	int getYear();
	
private:
	int seconds = 0;
	int minutes = 0;
	int hour = 0;
	int date = 0;
	int month = 0;
	int year = 0;
};

#endif //__TIME_H__
