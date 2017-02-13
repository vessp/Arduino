#include <Servo.h> 
#include <IRremote.h>
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards

int POS_1 = 90;
int POS_2 = 0;

int curPos = POS_1;    // variable to store the servo position 

String serialString = "";
boolean hasSerialCommand = false;

int PIN_POWER = 10;
int PIN_SERVO = 9;
int PIN_IR_RECV = 11;
//int PIN_IR_SEND = 3; //this always has to be 3?

int PIN_MOTOR_ENABLE = 6;
int PIN_MOTOR_1 = 4;
int PIN_MOTOR_2 = 5;

IRrecv irrecv(PIN_IR_RECV);
decode_results irSignal;
IRsend irsend;

unsigned int SIGNAL_POWER_ON[19] = {
  2500, 2700, 800, 900, 750, 900, 800, 1900, 800, 1900, 800, 1900, 800, 1900, 800, 900, 750, 900, 800
};

unsigned int SIGNAL_POWER_OFF[19] = {
  2550, 2650, 800, 900, 750, 1950, 750, 950, 750, 900, 750, 1950, 750, 950, 700, 1950, 800, 1900, 800
};

unsigned int SIGNAL_AC_ON[100] = {
  //450, 1700, 450, 1700, 450, 1700, 450, 650, 400, 650, 450, 1700, 450, 600, 450, 650, 450, 600, 450, 650, 450, 600, 450, 1700, 450, 1700, 450, 600, 450, 1700, 450, 650, 450, 600, 450, 650, 450, 600, 450, 650, 400, 650, 450, 1700, 450, 1700, 450, 1700, 450, 1700, 450, 1700, 450, 1700, 450, 1650, 450, 1700, 450, 650, 450, 600, 450, 650, 450, 600, 450, 650, 400, 650, 450, 600, 450, 650, 450, 600, 450, 1700, 450, 1700, 450, 650, 400, 650, 450, 650, 400, 650, 450, 600, 450, 650, 450, 600, 450, 650, 450, 600, 450, 650 
  //450, 650, 450, 600, 450, 650, 400, 650, 450, 650, 400, 650, 450, 600, 450, 650, 450, 600, 450, 1700, 450, 1700, 450, 650, 400, 650, 450, 650, 400, 650, 450, 600, 450, 650, 450, 600, 450, 650, 400, 650, 450, 650, 400, 650, 450, 600, 450, 650, 450, 1700, 450, 1700, 400, 650, 450, 650, 400, 650, 450, 650, 400, 650, 450, 600, 450, 650, 450, 600, 450, 1700, 450, 650, 400, 650, 450, 650, 400, 650, 450, 600, 450, 1700, 450, 650, 400
  4300, 4400, 500, 1700, 450, 1650, 500, 1650, 500, 1650, 450, 600, 500, 600, 450, 1700, 450, 650, 450, 600, 450, 650, 400, 600, 500, 600, 450, 1700, 450, 1700, 450, 600, 500, 1650, 500, 550, 500, 600, 450, 650, 450, 600, 450, 600, 500, 600, 450, 1700, 450, 1700, 450, 1700, 450, 1700, 450, 1650, 500, 1700, 450, 1650, 450, 1750, 450, 600, 450, 600, 450, 650, 450, 600, 450, 650, 450, 600, 450, 600, 450, 650, 450, 650, 400, 1700, 450, 600, 500, 600, 450, 650, 450, 1700, 400, 650, 450, 600, 450, 650, 450, 600, 450, 650
  //23826, 4300, 4400, 500, 1650, 500, 1650, 500, 1650, 450, 1700, 450, 600, 500, 600, 450, 1700, 450, 600, 500, 550, 500, 550, 500, 600, 500, 600, 450, 1700, 450, 1700, 450, 650, 450, 1650, 500, 550, 500, 600, 450, 600, 500, 600, 450, 600, 500, 600, 450, 1700, 450, 1700, 450, 1700, 450, 1650, 500, 1700, 450, 1650, 500, 1650, 500, 1700, 450, 600, 450, 600, 450, 650, 450, 600, 450, 650, 450, 600, 450, 650, 450, 600, 450, 600, 450, 1700, 450, 650, 450, 600, 450, 650, 450, 1650, 500, 600, 450, 600, 450, 650, 450, 600, 500, 600, 14286, 62556, 65436, 55656, 65436, 48050, 65436, 9700, 9550, 9800, 9800, 150, 34204, 250, 65436, 100, 65436, 100, 65436, 100, 65436, 100, 65436, 100, 65436, 100, 65436, 100, 65436, 100, 65436, 100, 65436, 100, 65436, 100, 65436, 100, 65436, 100, 65436, 100, 65436, 100, 65436, 39012, 64476, 27526, 52526, 18684, 12840, 51340, 41512, 51876, 25690, 38440, 18484, 52926, 38240, 18684, 63890, 12840, 41212, 39076, 38540, 13140, 18484, 240, 11404, 41412, 38876, 41712, 11740, 51190, 52526, 18684, 39726, 34594, 200, 100, 25500, 100, 38300, 100, 65436, 300, 65436, 2550, 50, 100, 50076, 100, 21916, 38430, 53416, 21484, 4574, 24504, 23516, 40466, 31574, 63494, 26454, 53412, 41262, 19108, 20622, 51516, 26904, 39076, 39676, 18684, 38080, 36108, 19184, 52826, 38812, 10916, 48158, 27354, 64476, 2600, 19184, 52826, 65436, 9800, 9800, 10390, 28100, 33480, 21984, 37394, 33680, 22184, 330
};

unsigned int SIGNAL_AC_OFF[100] = {
  450, 1700, 450, 600, 450, 1700, 450, 650, 400, 650, 450, 650, 400, 650, 450, 600, 450, 650, 450, 1700, 450, 1700, 450, 1700, 400, 1750, 400, 1700, 450, 1700, 450, 1700, 450, 1700, 450, 650, 450, 600, 450, 650, 400, 650, 450, 600, 450, 650, 450, 600, 450, 650, 450, 600, 450, 1700, 450, 1700, 450, 650, 400, 650, 450, 600, 450, 650, 450, 600, 450, 650, 450, 600, 450, 650, 400, 650, 450, 650, 400, 650, 450, 600, 450, 1700, 450, 1700, 450, 1700, 450, 650, 400, 650, 450, 650, 400, 650, 450, 600, 450, 650, 400, 650
};



void setup() 
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  //irrecv.blink13(true);
  
  pinMode(PIN_SERVO, OUTPUT);
  pinMode(PIN_POWER, OUTPUT);
  //pinMode(PIN_IR_SEND, OUTPUT); //done automatically?
  
  digitalWrite(PIN_POWER, HIGH); //start on
  //digitalWrite(PIN_POWER, LOW); //start off

  pinMode(PIN_MOTOR_ENABLE, OUTPUT);
  pinMode(PIN_MOTOR_1, OUTPUT);
  pinMode(PIN_MOTOR_2, OUTPUT);
  analogWrite(PIN_MOTOR_ENABLE, 0);  
  //digitalWrite(PIN_MOTOR_ENABLE, HIGH);
 // digitalWrite(PIN_MOTOR_1, HIGH);
  //digitalWrite(PIN_MOTOR_2, HIGH);
  
  //digitalWrite(PIN_SERVO, HIGH);

  //digitalWrite(PIN_TRANS, HIGH);
  
  //myservo.attach(PIN_SERVO);
  //myservo.write(curPos);
  //Serial.println(curPos);
  //myservo.detach();
  
  //digitalWrite(PIN_TRANS, LOW);
  Serial.println("--Started--");
} 

// Storage for the recorded code
int codeType = -1; // The type of code
unsigned long codeValue; // The code value if not raw
unsigned int rawCodes[RAWBUF]; // The durations if raw (RAWBUF == 101)
int rawLen; // The length of the code
int toggle = 0; // The RC5/6 toggle state

// Stores the code for later playback
// Most of this code is just logging
void storeCode(decode_results *results) {
  codeType = results->decode_type;
  rawLen = results->rawlen;
  //int count = results->rawlen;
  volatile unsigned int* rawBuf = results->rawbuf;
  
  Serial.println("-----------------");
  Serial.println("Received IR:: codeType: " + ((String)UNKNOWN) + ", rawLen: " + ((String)rawLen) + ", bits: " + ((String)results->bits));
  //if (codeType == UNKNOWN)
  //{
    Serial.println(sizeof(rawBuf) / sizeof(int));
    for (int i = 0; i < 500; i++) {
      Serial.print(results->rawbuf[i]);
      Serial.print(", ");
    }
    Serial.println("");
  
    // To store raw codes:
    // Drop first value (gap), start at 0 or 1?
    // Convert from ticks to microseconds
    // Tweak marks shorter, and spaces longer to cancel out IR receiver distortion
    Serial.print("  ");
    for (int i = 0; i < rawLen; i++) {
      if (i % 2) {
        rawCodes[i - 1] = results->rawbuf[i]*USECPERTICK - MARK_EXCESS; // Mark
      } 
      else {
        rawCodes[i - 1] = results->rawbuf[i]*USECPERTICK + MARK_EXCESS; // Space
      }
      Serial.print(rawCodes[i - 1], DEC);
      if(i != rawLen-1)
        Serial.print(", ");
    }
    Serial.println("");
  //}
  //else
  //{
  //  Serial.println("unhandled codeType");
  //}
}

void loop()
{
  Serial.println("write1");
  //analogWrite(PIN_MOTOR_ENABLE, 0);
  digitalWrite(PIN_MOTOR_ENABLE, LOW);
  digitalWrite(PIN_MOTOR_1, HIGH);
  digitalWrite(PIN_MOTOR_2, LOW);
  //analogWrite(PIN_MOTOR_ENABLE, 255);
  digitalWrite(PIN_MOTOR_ENABLE, HIGH);
  delay(2000);
  Serial.println("write2");
  //analogWrite(PIN_MOTOR_ENABLE, 0);
  digitalWrite(PIN_MOTOR_ENABLE, LOW);
  digitalWrite(PIN_MOTOR_1, LOW);
  digitalWrite(PIN_MOTOR_2, HIGH);
  //analogWrite(PIN_MOTOR_ENABLE, 255);
  digitalWrite(PIN_MOTOR_ENABLE, HIGH);
  delay(2000);
  /*
  serialEvent();
  if (hasSerialCommand) {
    onCommand(serialString);
    serialString = "";
    hasSerialCommand = false;
  }

  if (irrecv.decode(&irSignal)) {
    //Serial.print("IR recv: (" + (String)irSignal.decode_type + ") "); //NEC, SONY, RC5, RC6, UNKNOWN
    //Serial.println(irSignal.value, HEX);
    storeCode(&irSignal);
    irrecv.resume(); // Receive the next value
  }
  */
  delay(100);
}

void onCommand(String cmdString) {
  Serial.println(">" + cmdString);

  if(cmdString == "on") {
    digitalWrite(PIN_POWER, HIGH);
    Serial.println("<POWER ON");
  }
  else if(cmdString == "off") {
    digitalWrite(PIN_POWER, LOW);
    Serial.println("<POWER OFF");
  }
  else if(cmdString == "push") {
    Serial.println("PUSH!");
    digitalWrite(PIN_MOTOR_ENABLE, HIGH);
    digitalWrite(PIN_MOTOR_1, HIGH);
    digitalWrite(PIN_MOTOR_2, LOW);
    delay(1000);
    digitalWrite(PIN_MOTOR_ENABLE, LOW);
    digitalWrite(PIN_MOTOR_1, LOW);
    digitalWrite(PIN_MOTOR_2, LOW);
  }
  else if(cmdString.startsWith("ir ")) {
    String irCmd = cmdString.substring(3);
    irCmd.trim();

    if(irCmd == "on") {
      for (int i = 0; i < 3; i++) {
        irsend.sendRaw(SIGNAL_POWER_ON, sizeof(SIGNAL_POWER_ON)/sizeof(int), 38);
        delay(40);
      }
      irrecv.enableIRIn();
      Serial.println("IR send: ON!!");
    }
    else if(irCmd == "off") {
      for (int i = 0; i < 3; i++) {
        irsend.sendRaw(SIGNAL_POWER_OFF, sizeof(SIGNAL_POWER_OFF)/sizeof(int), 38);
        delay(40);
      }
      irrecv.enableIRIn();
      Serial.println("IR send: OFF!!");
    }
    else if(irCmd == "ac on") {
      for (int i = 0; i < 3; i++) {
        irsend.sendRaw(SIGNAL_AC_ON, sizeof(SIGNAL_AC_ON)/sizeof(int), 38);
        delay(40);
      }
      irrecv.enableIRIn();
      Serial.println("IR send: AC ON!!");
    }
    else if(irCmd == "ac off") {
      for (int i = 0; i < 3; i++) {
        irsend.sendRaw(SIGNAL_AC_OFF, sizeof(SIGNAL_AC_OFF)/sizeof(int), 38);
        delay(40);
      }
      irrecv.enableIRIn();
      Serial.println("IR send: AC OFF!!");
    }
    else if(irCmd == "recorded") {
      for (int i = 0; i < 3; i++) {
        irsend.sendRaw(rawCodes, rawLen, 38);
        delay(40);
      }
      irrecv.enableIRIn();
      Serial.println("IR send: recorded");
    }
    else {
      //assume raw hex
      int hex = strToHex(irCmd);
      Serial.println(hex, HEX);
      //irsend.sendSony(0xa90, 12); //8F0C8B3A
    }
  }

  //digitalWrite(PIN_TRANS, HIGH);
  /*
  myservo.attach(PIN_SERVO);
  if(curPos == POS_1)
    rotateTo(POS_2);
  else 
    rotateTo(POS_1);
  myservo.detach();
  */
  
  //digitalWrite(PIN_TRANS, LOW);
  //Serial.println("--");
}

int strToHex(String s) {
  char charBuf[50];
  s.toCharArray(charBuf, 50);
  int hex = strtoul(charBuf, NULL, 16);
  return hex;
}

void rotateTo(int toPos) {
  if(curPos == toPos)
    return;

  int dp = (curPos < toPos) ? 1 : -1;
  curPos += dp;
  myservo.write(curPos);
  Serial.println(curPos);
  delay(7);
  rotateTo(toPos);
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();// get the new byte:
    if (inChar == '\n') {
      hasSerialCommand = true;
    }
    else {
      serialString += inChar;
    }
  }
}
