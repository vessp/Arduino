void setup()
{
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  int i=0;
  
  oneFullCW();
  
  delay(2000);
}

void oneFullCW()
{
  for(int i=0;i<512;i++){
    clockwiserotate();
    Serial.println(i);
  }
}

void clockwiserotate()
{
  step1();
  step2();
  step3();
  step4();
  step5();
  step6();
  step7();
  step8();
}

void counterclockwiserotate()
{
  step1();
  step7();
  step6();
  step5();
  step4();
  step3();
  step2();
  step1();
}

void step1()
{
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(1);
}

void step2()
{
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(1);
}

void step3()
{
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(1);
}

void step4()
{
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(1);
}

void step5()
{
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(1);
}

void step6()
{
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  delay(1);
}

void step7()
{
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(1);
}

void step8()
{
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(1);
}
