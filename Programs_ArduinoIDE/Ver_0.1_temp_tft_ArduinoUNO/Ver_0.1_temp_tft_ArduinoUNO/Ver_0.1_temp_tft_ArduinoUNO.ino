/***************************************************
  This is our GFX example for the Adafruit ILI9341 Breakout and Shield
  ----> http://www.adafruit.com/products/1651

  Check out the links above for our tutorials and wiring diagrams
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional)
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/


#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include <OneWire.h>
#include <DallasTemperature.h>

#define TFT_DC 9
#define TFT_CS 10
#define ONE_WIRE_BUS A4
#define buttonPin A5

OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);  // Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC  
                                                          // If using the breakout, change pins as desired
                                                          //Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);
int buttonValue = 0;
int buttonThreshold = 50;
int cx =0;
int cy =0;
int cutin=34;
int cutout=24;
int fan=0;
void setup() 
{
 Serial.begin(9600);
 tft.begin();
 sensors.begin();
 tft.setRotation(1);
 Serial.println("Xiotas_Agro_Starting....");
 Serial.println("Auto_Temp_Controller");
 Serial.println("Version_0.1");
  
 tft.fillScreen(ILI9341_WHITE);         
 cx = tft.width() ,
 cy = tft.height();
 tft.fillRoundRect(10, 10, (cx-20), (cy-20),20, tft.color565(20, 40, 60));
 tft.setCursor(85, 15);
 tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(2);
 tft.println("Hello World!");
 tft.setTextColor(ILI9341_YELLOW); tft.setTextSize(2);
 tft.setCursor(110, 33);
 tft.println("Ver. 0.1");
 tft.setCursor(125, 55);
 tft.setTextColor(ILI9341_BLUE);    tft.setTextSize(2);
 tft.println("Beta");
 tft.println();
 tft.setTextColor(ILI9341_RED);
 tft.setTextSize(5);
 tft.setCursor(70, 100);
 tft.println("XIOTAS");
 tft.setTextColor(ILI9341_GREEN);
 tft.setCursor(100, 150);
 tft.println("Agro");
 delay(2500);
}
void loop ()
{
   
 sensors.requestTemperatures();
 float temp = (sensors.getTempCByIndex(0));
 Serial.println(temp);
 //tft.fillRoundRect(10, 10, (cx-20), (cy-20),20, tft.color565(95, 90, 100));
 //tft.drawRoundRect(cx-i2, cy-i2, i, i, i/8, tft.color565(i, 0, 0));  
 //tft.drawFastHLine(0, y, w, color1);
 tft.fillScreen(ILI9341_WHITE);
 tft.setTextColor(ILI9341_RED, ILI9341_BLACK);
 tft.setTextSize(3);
 tft.setCursor(7, 5); 
 tft.print("   XIOTAS Agro   ");
 tft.setTextColor(ILI9341_RED, ILI9341_BLACK);
 tft.setTextSize(3);
 tft.setCursor(7, 210); 
 tft.print("Back");
 tft.setTextColor(ILI9341_RED, ILI9341_BLACK);
 tft.setTextSize(3);
 tft.setCursor(240, 210); 
 tft.print("Menu");
 tft.setTextColor(ILI9341_BLACK, ILI9341_GREEN);
 tft.setTextSize(3);
 tft.setCursor(65, 50); 
 tft.print("Temperature");
 //tft.fillRect(100, 85, 120, 30, ILI9341_WHITE);
 tft.setCursor(100, 85);    
 tft.println(String(sensors.getTempCByIndex(0),1)+" "+"C");
 tft.drawCircle(180, 90, 3, ILI9341_BLACK);
 tft.setCursor(7, 140); tft.setTextSize(2);
 tft.setTextColor(ILI9341_BLACK);
 tft.print("Set Temp.");
 tft.setCursor(7, 160); tft.setTextSize(2);
 tft.print("ON = " + String(cutin) +", OFF = " + String(cutout));
 if( temp>cutin)
 {fan=1;
 digitalWrite(2,HIGH);
 }
 else if(temp<cutout)
 {fan=0;
 digitalWrite(2,LOW);
 }
 if(fan==1)
 { tft.setCursor(7, 183); tft.setTextSize(2);
  tft.print("Status = ");
  tft.setTextColor(ILI9341_GREEN, ILI9341_YELLOW);
  tft.print("ON");
 }
 else if(fan==0)
 { tft.setCursor(7, 183); tft.setTextSize(2);
  tft.print("Status = ");
  tft.setTextColor(ILI9341_RED, ILI9341_YELLOW);
  tft.print("OFF");
 }
 //tft.print(sensors.getTempFByIndex(0),1);
 //Serial.println(sensors.getTempCByIndex(0),1);
 //Serial.println(sensors.getTempFByIndex(0),1);
delay(2000);
 buttonValue = analogRead(buttonPin);
 if(abs(buttonValue - 505) < buttonThreshold)digitalWrite(2,LOW) ; 
 else if(abs(buttonValue - 329) < buttonThreshold)digitalWrite(2,HIGH) ; 
 else if(abs(buttonValue - 145) < buttonThreshold) digitalWrite(2,LOW); 
 else if( abs(buttonValue - 0) < buttonThreshold)digitalWrite(2,LOW);
 else if(abs(buttonValue - 741) < buttonThreshold) digitalWrite(2,HIGH);
  
}
