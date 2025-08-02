#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 RTC;

void setup () {
    Serial.begin(9600);
    Wire.begin();
    RTC.begin();
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(F(__DATE__),F( __TIME__)));
    //RTC.adjust(DateTime(2021, 7, 11, 9, 45, 0));
  }
}
void loop () {
    DateTime now = RTC.now(); 
    int Year = now.year();
    int Month = now.month();
    int Day = now.day();
    int Hour = now.hour();
    int Minute = now.minute();
    int Second = now.second();
    Serial.println(String(Year) + ":" + String(Month) + ":" + String(Day) + ":" + String(Hour)+":"+String(Minute)+":"+String(Second)+":");
    Serial.println(Minute);
    //Serial.print(now.year(), DEC);
   // Serial.print('/');
    //Serial.print(now.month(), DEC);
    //Serial.print('/');
    //Serial.print(now.day(), DEC);
   // Serial.print(' ');
    //Serial.print(now.hour(), DEC);
    //Serial.print(':');
    //Serial.print(now.minute(), DEC);
    //Serial.print(':');
    //Serial.print(now.second(), DEC);
    //Serial.println(); 
    //delay(1000);
}
