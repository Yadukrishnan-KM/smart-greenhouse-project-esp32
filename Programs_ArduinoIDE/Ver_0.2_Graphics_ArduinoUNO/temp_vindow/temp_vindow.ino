#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "XPT2046_Touchscreen.h"
#include "Fonts/FreeSerif9pt7b.h"
#include "Fonts/Org_01.h"
#include "Fonts/FreeSerif12pt7b.h"


#define TFT_CS 10
#define TFT_DC 9
#define phs_CS 7
//#define TFT_MOSI 11
//#define TFT_CLK 13
//#define TFT_RST 8
//#define TFT_MISO 12
//Global ariables
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
XPT2046_Touchscreen phs(phs_CS);
int tfth,tftw;

float pre_phs1d, pre_phs2d, pre_phs3d,pre_phs4d, pre_phs5d, pre_phs6d, pre_phs7d, pre_phs;
boolean phs1dcount = LOW; boolean phs2dcount = LOW; boolean phs3dcount = LOW; boolean phs4dcount = LOW; boolean phs5dcount = LOW; boolean phs6dcount = LOW; boolean phs7dcount = LOW;
boolean phscreen_count = LOW; //for working only 1 time the home page at initial

void setup() 
{
 Serial.begin(9600);
 tft.begin();
 tft.setRotation(1);
 tftw = tft.width();
 tfth = tft.height();
 Serial.println (tftw);
 Serial.println (tfth);
 phs.begin();
 phs.setRotation(1);



}
void loop()
{
  phPage(2.5,0,3.5,0,5.5,6.6,8,6.3);
}


                                     /******** phpage case3  *********/

void phPage(float phs1d,float phs2d,float phs3d,float phs4d,float phs5d,float phs6d,float phs7d,float phs)
{
  int pre_phs1d, pre_phs2d, pre_phs3d,pre_phs4d, pre_phs5d, pre_phs6d, pre_phs7d, pre_phs;

  
  if (phscreen_count == LOW)
  {
    tft.fillRect(0, 0, tftw, tfth, ILI9341_WHITE);
    backButtton(); 
    tft.setFont(&FreeSerif12pt7b); tft.setTextSize(1); 
    tft.setTextColor(ILI9341_BLACK);
    tft.setCursor(180, 220);
    tft.print("pH"); 
    offlineBox (5,5);
    offlineBox (110,5);
    offlineBox (215,5);
    offlineBox (5,68);
    offlineBox (110,68);
    offlineBox (5,131);
    offlineBox (110,131);
    phscreen_count = HIGH;
  }
  else 
  { 
    if (pre_phs != phs)
    {
      tft.setFont(&Org_01); tft.setTextSize(3);
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(220, 155);
      tft.print(pre_phs);//tft.print("*C"); 
      tft.setTextColor(ILI9341_RED);
      tft.setCursor(220, 155);
      tft.print(phs);//tft.print("*C"); 
      pre_phs = phs;
    }
    /****  sensor 1   *****/
  if (phs1d == 0 && (pre_phs1d != phs1d))
  {
    offlineBox (5,5);
    pre_phs1d = phs1d;
    phs1dcount= LOW;  
  }
  if (phs1d != 0 && (pre_phs1d != phs1d))
  {
    if (phs1dcount == LOW)
    {
      tft.fillRect(5, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(45,27);
      tft.print("pH"); 
      phs1dcount = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(40,47); 
    tft.print(pre_phs1d); //tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(40,47); 
    tft.print(phs1d);// tft.print("*C");
    pre_phs1d = phs1d;
  }
    /********  sensor2 *****/
if (phs2d == 0 && (pre_phs2d != phs2d))
  {
    offlineBox (110,5);
    pre_phs2d = phs2d;
    phs2dcount= LOW;  
  }
  if (phs2d != 0 && (pre_phs2d != phs2d))
  {
    if (phs2dcount == LOW)
    {
      tft.fillRect(110, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(150,27);
      tft.print("pH"); 
      phs2dcount = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(145,47); 
    tft.print(pre_phs2d); //tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(145,47); 
    tft.print(phs2d);// tft.print("*C");
    pre_phs2d = phs2d;
  }
    /********  sensor3 *****/
if (phs3d == 0 && (pre_phs3d != phs3d))
  {
    offlineBox (215,5);
    pre_phs3d = phs3d;
    phs3dcount= LOW;  
  }
  if (phs3d != 0 && (pre_phs3d != phs3d))
  {
    if (phs3dcount == LOW)
    {
      tft.fillRect(215, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(255,27);
      tft.print("pH"); 
      phs3dcount = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(250,47); 
    tft.print(pre_phs3d); //tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(250,47); 
    tft.print(phs3d); //tft.print("*C");
    pre_phs3d = phs3d;
  }
    /********  sensor4 *****/
if (phs4d == 0 && (pre_phs4d != phs4d))
  {
    offlineBox (5,68);
    pre_phs4d = phs4d;
    phs4dcount= LOW;  
  }
  if (phs4d != 0 && (pre_phs4d != phs4d))
  {
    if (phs4dcount == LOW)
    {
      tft.fillRect(5, 68, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(45,90);
      tft.print("pH"); 
      phs4dcount = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(40,110); 
    tft.print(pre_phs4d); //tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(40,110); 
    tft.print(phs4d); //tft.print("*C");
    pre_phs4d = phs4d;
  }
    /********  sensor5 *****/
if (phs5d == 0 && (pre_phs5d != phs5d))
  {
    offlineBox (110,68);
    pre_phs5d = phs5d;
    phs5dcount= LOW;  
  }
  if (phs5d != 0 && (pre_phs5d != phs5d))
  {
    if (phs5dcount == LOW)
    {
      tft.fillRect(110, 68, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(150,90);
      tft.print("pH"); 
      phs5dcount = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(145,110); 
    tft.print(pre_phs5d);// tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(145,110); 
    tft.print(phs5d); //tft.print("*C");
    pre_phs5d = phs5d;
  }
      /********  sensor6 *****/
if (phs6d == 0 && (pre_phs6d != phs6d))
  {
    offlineBox (5,131);
    pre_phs6d = phs6d;
    phs6dcount= LOW;  
  }
  if (phs6d != 0 && (pre_phs6d != phs6d))
  {
    if (phs6dcount == LOW)
    {
      tft.fillRect(5, 131, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(45,153);
      tft.print("pH"); 
      phs6dcount = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(40,173); 
    tft.print(pre_phs6d); //tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(40,173); 
    tft.print(phs6d); //tft.print("*C");
    pre_phs6d = phs6d;
  }
      /********  sensor7 *****/
if (phs7d == 0 && (pre_phs7d != phs7d))
  {
    offlineBox (110,131);
    pre_phs7d = phs7d;
    phs7dcount= LOW;  
  }
  if (phs7d != 0 && (pre_phs7d != phs7d))
  {
    if (phs7dcount == LOW)
    {
      tft.fillRect(110, 131, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(150,153);
      tft.print("pH"); 
      phs7dcount = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(145,173); 
    tft.print(pre_phs7d);// tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(145,173); 
    tft.print(phs7d); //tft.print("*C");
    pre_phs7d = phs7d;
  }
   int newphs = map(phs, 3, 9, 30, 150);
   Gauge (newphs,218, 150, 90);
  }
}









void backButtton()
{
  tft.fillCircle(27,213,21,tft.color565(8, 160, 223)); //back button circle
  tft.fillTriangle(8,213,42,223,42,203,tft.color565(255, 194, 14)); //back button triangle
 // tft.setFont(&FreeSerif12pt7b); tft.setTextSize(1); //for home symbol H
  //tft.setTextColor( tft.color565(255, 194, 14));
  //tft.setCursor(20, 220);
  //tft.print("H");
}
void offlineBox (int x, int y)
{
  tft.fillRect(x, y, 100, 58,tft.color565(255, 190, 200)); // red box 
  tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);               
  tft.setTextColor(ILI9341_BLACK);
  tft.setCursor((x+25), (y+22));
  tft.print("Sensor");
  tft.setCursor((x+22), (y+42));
  tft.print("Offline");
}

void Gauge (int input,int x_centre, int y_centre, int radius) 
{
 for(int i=30; i<=150; i+=5)
{
 float sx = sin(i*(3.14/180));
 float sy = cos(i*(3.14/180));
 int xs0 = x_centre+sx*(radius-20);
 int ys0 = y_centre+sy*(radius-20);
 int xe0 = x_centre+sx*radius;
 int ye0 = y_centre+sy*radius;
 int xe1 = x_centre+3+sx*(radius-20);
 int ye1 = y_centre+3+sy*(radius-20);
 int xs1 = x_centre+3+sx*radius;
 int ys1 = y_centre+3+sy*radius;
  if(i<=input) 
  {
   tft.fillTriangle(xs0,ys0,xe0,ye0,xe1,ye1,tft.color565(255, 150, 0));
   tft.fillTriangle(xs1,ys1,xe1,ye1,xe0,ye0,tft.color565(255, 150, 0) );
  } 
  else 
  {
   tft.fillTriangle(xs0,ys0,xe0,ye0,xe1,ye1, tft.color565(235, 210, 240));
   tft.fillTriangle(xs1,ys1,xe1,ye1,xe0,ye0, tft.color565(235, 206, 230));
  }
 } 
}

 
 
