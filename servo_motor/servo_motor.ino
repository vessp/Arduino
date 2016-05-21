#include <DigitBoard.h>
#include <TempSensor.h>
#include <VButton.h>
#include <VSerial.h>
#include <Servo.h>
#include <IRremote.h>

Servo servo;
DigitBoard digitBoard;
TempSensor tempSensor(A0);
VButton button(12);
VSerial verial;

IRrecv irrecv(11);
decode_results results;


int servoPin = 13;
int touchPos = 140;
int restPos = 75;

int loopCounter = 0;
int dispTemp = -1;

//-------CALLBACKS----------------------------
void setup()
{
  verial.setup();
  
  servo.attach(servoPin);
  jump(restPos);
  servo.detach();

  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
  if(button.wasPressed())
  {
    doPush();
  }

  if (irrecv.decode(&results))
  {
    doPush();
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }

  if(loopCounter++ > 100)
  {
    loopCounter = 0;
    dispTemp = tempSensor.getC();
  }
  digitBoard.displayNum(dispTemp);
}

void serialEvent()
{
  verial.checkSerial("push", doPush);
}

//-------COMMANDS----------------------------
void doPush()
{
    servo.attach(servoPin);
    walk(restPos, touchPos);
    jump(restPos);
    servo.detach();
}

void jump(int p)
{
  servo.write(p);
  delay(1000);
}

void walk(int s, int e)
{
  for(int pos = s; pos < e; pos += 1)  
  {                                
    servo.write(pos);              
    delay(15);                      
  }
}
