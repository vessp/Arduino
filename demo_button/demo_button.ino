int switchPin = 8;
int ledPin = 11;

boolean lastButState = LOW;
int ledLevel = 0; //0-255


void setup() {
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);

}

boolean debounce(boolean last)
{
  boolean cur =  digitalRead(switchPin);
  if(last != cur)
  {
    delay(5);
    cur = digitalRead(switchPin);
  }
  return cur;
}

void loop()
{
  boolean curButState = debounce(lastButState);
  
  if(curButState == HIGH && curButState != lastButState)
  {
    ledLevel += 100;
  }
  lastButState = curButState;

  if(ledLevel > 255)
    ledLevel = 0;

analogWrite(ledPin, ledLevel);
}
