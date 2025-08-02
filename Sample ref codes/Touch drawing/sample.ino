#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "XPT2046_Touchscreen.h"
#include "Math.h"


#define TFT_CS 10
#define TFT_DC 9
#define TFT_MOSI 11
#define TFT_CLK 13
#define TFT_RST 8
#define TFT_MISO 12
#define TS_CS 7

float xCalM = 0.0, yCalM = 0.0;
float xCalC = 0.0, yCalC = 0.0;
int tftWidth, tftHeight;

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC/RST
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
XPT2046_Touchscreen ts(TS_CS);

void setup() {
  Serial.begin(9600);
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);
  tftWidth = tft.width();
  tftHeight = tft.height();
  ts.begin();
  ts.setRotation(1);
  calibrateTouchScreen();

//boolean istouched = ts.touched();
// TS_Point p = ts.getPoint();
// p.x xaxis
 //p.y yaxis
 //p.z pressure


}


void loop()
{
  TS_Point p = ts.getPoint();
  int x = p.x;
  int y = p.y;
  int16_t xCoord = round((x * xCalM) + xCalC);
  int16_t yCoord = round((y * yCalM)+ yCalC);
  if(xCoord < 0) xCoord = 0;
  if(xCoord >= tftWidth) xCoord = tftWidth - 1;
  if(yCoord < 0) yCoord = 0;
  if(yCoord >= tftHeight) yCoord = tftHeight - 1;
  tft.drawPixel(xCoord,yCoord,ILI9341_BLUE);
}

void calibrateTouchScreen(){
  TS_Point p;
  int16_t x1,y1,x2,y2;
  
  tft.fillScreen(ILI9341_BLACK);
  // wait for no touch
  while(ts.touched());
  tft.drawFastHLine(10,20,20,ILI9341_RED);
  tft.drawFastVLine(20,10,20,ILI9341_RED);
  while(!ts.touched());
  p = ts.getPoint();
  x1 = p.x;
  y1 = p.y;
  tft.drawFastHLine(10,20,20,ILI9341_BLACK);
  tft.drawFastVLine(20,10,20,ILI9341_BLACK);
  delay(500);
  while(ts.touched());
  tft.drawFastHLine(tftWidth - 30,tftHeight - 20,20,ILI9341_RED);
  tft.drawFastVLine(tftWidth - 20,tftHeight - 30,20,ILI9341_RED);
  while(!ts.touched());
  p = ts.getPoint();
  x2 = p.x;
  y2 = p.y;
  tft.drawFastHLine(tftWidth - 30,tftHeight - 20,20,ILI9341_BLACK);
  tft.drawFastVLine(tftWidth - 20,tftHeight - 30,20,ILI9341_BLACK);

  int16_t xDist = tftWidth - 40;
  int16_t yDist = tftHeight - 40;

  // translate in form pos = m x val + c
  // x
  xCalM = (float)xDist / (float)(x2 - x1);
  xCalC = 20.0 - ((float)x1 * xCalM);
  // y
  yCalM =  (float)yDist / (float)(y2 - y1);
  yCalC = 20.0 - ((float)y1 * yCalM);

  Serial.print("x1 = ");Serial.print(x1);
  Serial.print(", y1 = ");Serial.print(y1);
  Serial.print("x2 = ");Serial.print(x2);
  Serial.print(", y2 = ");Serial.println(y2);
  Serial.print("xCalM = ");Serial.print(xCalM);
  Serial.print(", xCalC = ");Serial.print(xCalC);
  Serial.print("yCalM = ");Serial.print(yCalM);
  Serial.print(", yCalC = ");Serial.println(yCalC);
  
}
