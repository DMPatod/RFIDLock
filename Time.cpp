#include "Time.h"

Time::Time(int hour, int minutes, int seconds, int date, int month, uint16_t year)
{
	this->hour = hour;
	this->minutes = minutes;
	this->seconds = seconds;
	this->date = date;
	this->month = month;
	this->year = year;
} //Time

Time::~Time()
{
}

int Time::getSeconds()
{
	return this->seconds;
}

int Time::getMinutes()
{
	return this->minutes;
}

int Time::getHour()
{
	return this->hour;
}

int Time::getDate()
{
	return this->date;
}

int Time::getMonth()
{
	return this->month;
}

int Time::getYear()
{
	return this->year;
}
