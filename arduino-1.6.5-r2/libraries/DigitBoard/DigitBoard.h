#ifndef DigitBoard_h
#define DigitBoard_h

#include "Arduino.h"

class DigitBoard
{
  public:
    DigitBoard();
    void displayNum(int num);
  private:
  
	void lightNum(int num);
	void del();
	
	int IB = sizeof(int);
	
	/*
	  Pin Map:
	  Top Row
	  1,a,f,2,4,b
	  Bottom Row
	  e,d,dp,c,g,3
	 */
		
	//int d1 = ?
	//int d2 = ?
	int d3 = 2;
	int d4 = 3;
	int sa = 4;
	int sb = 5;
	int sc = 6;
	int sd = 7;
	int se = 8;
	int sf = 9;
	int sg = 10;

	int SEGS[7] = {sa, sb, sc, sd, se, sf, sg};

	int ZERO[6] = {sa, sb, sc, sd, se, sf};
	int ONE[2] = {se, sf};
	int TWO[5] = {sa, sb, sg, se, sd};
	int THREE[5] = {sa, sb, sg, sc, sd};
	int FOUR[4] = {sf, sg, sb, sc};
	int FIVE[5] = {sa, sf, sg, sc, sd};
	int SIX[6] = {sa, sf, sg, sc, sd, se};
	int SEVEN[3] = {sa, sb, sc};
	int EIGHT[7] = {sa, sb, sc, sd, se, sf, sg};
	int NINE[6] = {sa, sb, sc, sd, sf, sg};
	int DASH[1] = {sg};
	
};

#endif