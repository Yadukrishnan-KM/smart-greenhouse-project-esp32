// Wire Master Reader
// by YAdukrishnan K M

// Demonstrates use of the Wire library
// Reads data from an I2C/TWI slave device
// Refer to the "Wire Slave Sender" example for use with this

// Created 16 June 2021

// This example code is in the public domain.


#include <Wire.h>
int16_t  ph;
int16_t  light;
int16_t  moisture;
 
byte a,b;
 
void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop()
{
  Wire.requestFrom(1, 6);    // request 6 bytes from slave device #1

  while (Wire.available()) 
  { 
    a = Wire.read();
    b = Wire.read();
    ph = a;
    ph = ph << 8 | b;
    Serial.print( "ph"); 
    Serial.print( ph);  
    a = Wire.read();
    b = Wire.read();
    light = a;
    light = light << 8 | b;
    Serial.print( "; light"); 
    Serial.print( light); 
    a = Wire.read();
    b = Wire.read();
    moisture = a;
    moisture = moisture << 8 | b;
    Serial.print( "; moisture"); 
    Serial.println( moisture);        
  }

  delay(500);
}
