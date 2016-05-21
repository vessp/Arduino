#include "Arduino.h"
#include "TempSensor.h"


TempSensor::TempSensor(int sensorPin)
{
	//Serial.begin(9600);
	_sensorPin = sensorPin;
	pinMode(_sensorPin, INPUT);
}

float TempSensor::getC()
{
	int reading = analogRead(_sensorPin); 
    
    float voltage = reading * 5.0; //change if not inputing 5V
    voltage /= 1024.0; 
   
    //Serial.print(voltage); Serial.println(" volts");
  
    float temperatureC = (voltage - 0.5) * 100 ;
    //Serial.print(temperatureC); Serial.println(" degrees C");
  
    return temperatureC*-1; //is returning -ve number
}