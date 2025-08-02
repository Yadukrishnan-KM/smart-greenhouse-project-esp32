// Wire Slave Sensor Transmiter
// by Yadukrishnan K M

// It is an I2C sensor transmiter using ATTiny85
// Sends 3 data(temperature, moisture, light) as an I2C slave device
// The sending data ranges between 0 and 1023 (output of ADC)
// input contain 3 analog sensor and connected to the analog pins

// Created on 16 June 2021

// This example code is in the private domain.


#include <TinyWire.h>

//variables for saving data
int16_t ph ;
int16_t moisture;
int16_t light;

void setup() 
{
  analogReference(INTERNAL2V56);
  TinyWire.begin(1);                // join i2c bus with address #1
  TinyWire.onRequest(requestEvent); // register event
}

void loop() 
{
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()

void requestEvent() 
{
  ph = analogRead(A0);
  moisture = analogRead(A3);
  light = analogRead(A2);
  byte myArray1[2];
  byte myArray2[2];
  byte myArray3[2];
  myArray1[0] = (ph >> 8) & 0xFF;
  myArray1[1] = ph & 0xFF;
  TinyWire.send(myArray1, 2);
  myArray2[0] = (moisture >> 8) & 0xFF;
  myArray2[1] = moisture & 0xFF;
  TinyWire.send(myArray2, 2);
  myArray3[0] = (light >> 8) & 0xFF;
  myArray3[1] = light & 0xFF;
  TinyWire.send(myArray3, 2);
}
