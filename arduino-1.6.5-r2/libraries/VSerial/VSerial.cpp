#include "Arduino.h"
#include "VSerial.h"


VSerial::VSerial()
{
	
}

void VSerial::setup()
{
	Serial.begin(9600);
}

void VSerial::trace(String s)
{
	Serial.println(s);
}

void VSerial::checkSerial(String target, void (*callback)(void))
{
	Serial.print("I received: ");
	if (Serial.available() > 0)
	{
		String msg = Serial.readString();
		trace(msg);
		if(msg == target)
			callback();
	}
}