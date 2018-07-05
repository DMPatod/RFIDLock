#include "Time.h"

Time::Time()
{
}

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

void Time::setSeconds(int value)
{
	if (value < 0 || value >= 60)
	{
		// NAO DEIXO
		return;
	}
	this->seconds = value;
}

int Time::getMinutes()
{
	return this->minutes;
}

void Time::setMinutes(int value)
{
	if (value < 0 || value >= 60)
	{
		// NAO DEIXO
		return;
	}
	this->minutes = value;
}

int Time::getHour()
{
	return this->hour;
}

void Time::setHour(int value)
{
	if (value < 0 || value >= 24)
	{
		// NAO DEIXO
		return;
	}
	this->hour = value;
}

int Time::getDate()
{
	return this->date;
}

void Time::setDate(int value)
{
	if (value < 0)
	{
		// NAO DEIXO
		return;
	}
	this->date = value;
}

int Time::getMonth()
{
	return this->month;
}

void Time::setMonth(int value)
{
	if (value < 0)
	{
		// NAO DEIXO
		return;
	}
	this->month = value;
}

int Time::getYear()
{
	return this->year;
}

void Time::setYear(uint16_t value)
{
	if (value < 0)
	{
		// NAO DEIXO
		return;
	}
	this->year = value;
}