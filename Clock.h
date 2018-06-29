#ifndef _CLOCK_h
	#define _CLOCK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#ifndef TwoWire_h
	#include <Wire.h>
#endif

#define RTCaddress 0x68
#define Seconds_Register 0x00
#define Minutes_Register 0x01
#define Hour_Register 0x02
#define DayOfWeek_Register 0x03
#define Date_Register 0x04
#define Month_Register 0x05
#define Year_Register 0x06
#define Status_Register 0x0f

class Clock
{
 protected:
 
 private:

 public:
	Clock();
	void setTime(int hour, int minutes, int seconds, int date, int month, uint16_t year);
	
	void init();
};

#endif

