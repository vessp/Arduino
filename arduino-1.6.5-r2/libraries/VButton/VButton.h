#ifndef VButton_h
#define VButton_h

#include "Arduino.h"


class VButton
{
  public:
    VButton(int buttonPin);
	boolean wasPressed();
  private:
	int _buttonPin;
	int _lastButtonState = LOW;
};

#endif