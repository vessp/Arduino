#include "Arduino.h"
#include "VButton.h"


VButton::VButton(int buttonPin)
{
	_buttonPin = buttonPin;
	pinMode(_buttonPin, INPUT);
}

boolean VButton::wasPressed()
{
	boolean cur =  digitalRead(_buttonPin);
	if(_lastButtonState != cur)
	{
		delay(5);
		cur = digitalRead(_buttonPin);
	}
	boolean newPress = cur == HIGH && cur != _lastButtonState;
	_lastButtonState = cur;
	return newPress;
}