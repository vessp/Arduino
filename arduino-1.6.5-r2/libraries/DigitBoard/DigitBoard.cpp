#include "Arduino.h"
#include "DigitBoard.h"


DigitBoard::DigitBoard()
{
	pinMode(d3, OUTPUT);
	pinMode(d4, OUTPUT);

	for(int i=0; i<(sizeof(SEGS)/sizeof(int)); i++)
	{
		pinMode(SEGS[i], OUTPUT);
	}
}

void DigitBoard::displayNum(int num)
{
  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);

  digitalWrite(d4, HIGH);
  lightNum(num % 10);
  del();
  digitalWrite(d4, LOW);

  digitalWrite(d3, HIGH);
  lightNum(num >= 10 ? num / 10 : -1);
  del();
  digitalWrite(d3, LOW);
}

void DigitBoard::del()
{
  delay(4);
}

void DigitBoard::lightNum(int num)
{
  for(int i=0; i<(sizeof(SEGS)/IB); i++)
  {
    digitalWrite(SEGS[i], LOW);
  }

  int *segLights;
  int len;
  switch(num)
  {
    case 0:
      segLights = ZERO; len = sizeof(ZERO)/IB; break;
    case 1:
      segLights = ONE; len = sizeof(ONE)/IB; break;
    case 2:
      segLights = TWO; len = sizeof(TWO)/IB; break;
    case 3:
      segLights = THREE; len = sizeof(THREE)/IB; break;
    case 4:
      segLights = FOUR; len = sizeof(FOUR)/IB; break;
    case 5:
      segLights = FIVE; len = sizeof(FIVE)/IB; break;
    case 6:
      segLights = SIX; len = sizeof(SIX)/IB; break;
    case 7:
      segLights = SEVEN; len = sizeof(SEVEN)/IB; break;
    case 8:
      segLights = EIGHT; len = sizeof(EIGHT)/IB; break;
    case 9:
      segLights = NINE; len = sizeof(NINE)/IB; break;
    default:
      segLights = DASH; len = sizeof(DASH)/IB; break;   
  }
  
  for(int i=0; i<len; i++)
  {
    digitalWrite(segLights[i], HIGH);
  }
}