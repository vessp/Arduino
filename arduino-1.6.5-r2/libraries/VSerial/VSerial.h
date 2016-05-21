#ifndef VSerial_h
#define VSerial_h

#include "Arduino.h"


class VSerial
{
  public:
    VSerial();
	void setup();
	void trace(String s);
	void checkSerial(String target, void (*callback)(void));
  private:
};

#endif