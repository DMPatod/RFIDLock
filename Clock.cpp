#include "Clock.h"

Clock::Clock()
{
}

static void Clock::init()
{
	Wire.begin();
}

static void Clock::setTime(int hour, int minutes, int seconds, int date, int month, uint16_t year)
{
	year -= 2000;

	Wire.beginTransmission(RTCaddress);
	Wire.write(Year_Register);
	Wire.write( DECtoBCD(year) );
	Wire.endTransmission();

	delay(70); // TESTAR SEM DEPOIS

	Wire.beginTransmission(RTCaddress);
	Wire.write(Month_Register);
	Wire.write( DECtoBCD(month) );
	Wire.endTransmission();

	delay(70); // TESTAR SEM DEPOIS

	Wire.beginTransmission(RTCaddress);
	Wire.write(Date_Register);
	Wire.write( DECtoBCD(date) );
	Wire.endTransmission();

	delay(70); // TESTAR SEM DEPOIS

	Wire.beginTransmission(RTCaddress);
	Wire.write(Hour_Register);
	Wire.write( DECtoBCD(hour) );
	Wire.endTransmission();

	delay(70); // TESTAR SEM DEPOIS

	Wire.beginTransmission(RTCaddress);
	Wire.write(Minutes_Register);
	Wire.write( DECtoBCD(minutes) );
	Wire.endTransmission();

	delay(70); // TESTAR SEM DEPOIS

	Wire.beginTransmission(RTCaddress);
	Wire.write(Seconds_Register);
	Wire.write( DECtoBCD(seconds) );
	Wire.endTransmission();

	delay(70); // TESTAR SEM DEPOIS
}

static Time Clock::readTime()
{
	int secondsBCD, minutesBCD, hourBCD, dateBCD, monthBCD, yearBCD;

	Wire.beginTransmission(RTCaddress);
	Wire.write(Year_Register);
	Wire.write(Month_Register);
	Wire.write(DayOfWeek_Register);
	Wire.write(Date_Register);
	Wire.write(Hour_Register);
	Wire.write(Minutes_Register);
	Wire.write(Seconds_Register);
	Wire.endTransmission();

	delay(70);

	Wire.beginTransmission(RTCaddress);
	Wire.write(0x00);
	Wire.endTransmission(RTCaddress);

	Wire.requestFrom(RTCaddress, MSGSIZE);

	if (MSGSIZE <= Wire.available())
	{
		secondsBCD = Wire.read();
		minutesBCD = Wire.read();
		hourBCD = Wire.read();
		Wire.read();
		dateBCD = Wire.read();
		monthBCD = Wire.read();
		yearBCD = Wire.read();
	}
	
	Time object;
	object.setSeconds(BCDtoDEC(secondsBCD));
	object.setMinutes(BCDtoDEC(minutesBCD));
	object.setHour(BCDtoDEC(hourBCD));
	object.setDate(BCDtoDEC(dateBCD));
	object.setMonth(BCDtoDEC(monthBCD));
	object.setYear(BCDtoDEC(yearBCD) + 2000);
	
	return object;
}

static int Clock::DECtoBCD(int value)
{
	return ((value/10) << 4) + (value%10);
}

static int Clock::BCDtoDEC(int value)
{
	return value - 6 * (value >> 4);
}