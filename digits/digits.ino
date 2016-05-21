/*
  Top Row
  1,a,f,2,3,b
  Bottom Row
  e,d,dp,c,g,4
 */
int IB = sizeof(int);

int d3 = 3;
int d4 = 2;
int sa = 4;
int sb = 5;
int sc = 6;
int sd = 7;
int se = 8;
int sf = 9;
int sg = 10;

int SEGS[] = {sa, sb, sc, sd, se, sf, sg};

int ZERO[6] = {sa, sb, sc, sd, se, sf};
int ONE[2] = {se, sf};
int TWO[5] = {sa, sb, sg, se, sd};
int THREE[] = {sa, sb, sg, sc, sd};
int FOUR[] = {sf, sg, sb, sc};
int FIVE[] = {sa, sf, sg, sc, sd};
int SIX[] = {sa, sf, sg, sc, sd, se};
int SEVEN[] = {sa, sb, sc};
int EIGHT[] = {sa, sb, sc, sd, se, sf, sg};
int NINE[] = {sa, sb, sc, sd, sf, sg};

void setup()
{
  Serial.begin(9600);
  
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);

  for(int i=0; i<(sizeof(SEGS)/sizeof(int)); i++)
  {
     pinMode(SEGS[i], OUTPUT);
  }

  

}

void loop()
{
  displayNum(13);
}

void del()
{
  delay(4);
}

void displayNum(int num)
{
  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);

  digitalWrite(d4, HIGH);
  lightNum(num % 10);
  del();
  digitalWrite(d4, LOW);

  digitalWrite(d3, HIGH);
  lightNum(num / 10);
  del();
  digitalWrite(d3, LOW);
}

void selectDigit(int x)
{
  //digitalWrite(d1, LOW);
 // digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);
  
  switch(x)
  {
    //case 1: digitalWrite(d1, HIGH); break;
    //case 2: digitalWrite(d2, HIGH); break;
    case 3: digitalWrite(d3, HIGH); break;
    default: digitalWrite(d4, HIGH); break;
  }
  
}

void lightNum(int num)
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
      return;       
  }
  
  for(int i=0; i<len; i++)
  {
    digitalWrite(segLights[i], HIGH);
  }
}

