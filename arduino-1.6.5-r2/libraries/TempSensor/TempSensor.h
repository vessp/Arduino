#ifndef TempSensor_h
#define TempSensor_h

#include "Arduino.h"

/*
	Looking at flat side of sensor:
	-left pin is voltage
	-middle pin is reading output
	-right pin is ground

*/

class TempSensor
{
  public:
    TempSensor(int sensorPin);
	float getC();
  private:
	int _sensorPin;
	
};

#endif