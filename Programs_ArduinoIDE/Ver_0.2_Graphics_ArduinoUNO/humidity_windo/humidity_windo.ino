#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "XPT2046_Touchscreen.h"
#include "Fonts/FreeSerif9pt7b.h"
#include "Fonts/Org_01.h"
#include "Fonts/FreeSerif12pt7b.h"


#define TFT_CS 10
#define TFT_DC 9
#define TS_CS 7
//#define TFT_MOSI 11
//#define TFT_CLK 13
//#define TFT_RST 8
//#define TFT_MISO 12
//Global ariables
int counter = 0;  // Global variable Gauge
int pre_hy; int pre_te; float pre_ph; int pre_me; //Home_Autogauge
boolean homescreen_count = LOW; //for working only 1 time the home page at initial
int pre_hum; int pre_tem; float pre_phf; int pre_moi; // for the home screen right side box data
boolean pre_fan = LOW; boolean pre_ven = LOW; boolean pre_pum = LOW; boolean pre_val = LOW;
int tfth,tftw;
int menu_window = 1; // menu window selecting variable

boolean humidityscreen_count = LOW; //for working only 1 time the home page at initial

float xCalM = 0.0, yCalM = 0.0;
float xCalC = 0.0, yCalC = 0.0;

// logo memory
const uint8_t refresh [] PROGMEM = {
0xf8, 0x01, 0xc0, 0xe0, 0x00, 0x00, 0xc3, 0xfc, 0x00, 0x8f, 0xfe, 0x00, 0x1f, 0xf8, 0x00, 0x1f,  
0xff, 0xf0, 0x3f, 0xff, 0xf0, 0x3f, 0xff, 0xf0, 0x1f, 0xff, 0xf0, 0x9f, 0xff, 0xf0, 0xcf, 0xff, 
0xf0, 0xc3, 0xfc, 0x70, 0xe0, 0x00, 0x70, 0xf8, 0x01, 0xf0, 
}; // 'refresh', 20x14px

const uint8_t settings []PROGMEM = {
0xf8, 0x3f, 0xfc, 0x00, 0xfc, 0x0f, 0xf0, 0x00, 0xff, 0x07, 0xc0, 0x40, 0x3f, 0x07, 0x80, 0xc0, 
0x8e, 0x06, 0x03, 0xc0, 0x80, 0x07, 0x03, 0xc0, 0xc0, 0x03, 0x9f, 0xc0, 0xff, 0x80, 0x7f, 0xc0, 
0xff, 0xe0, 0x3f, 0xc0, 0xfe, 0x38, 0x0f, 0xc0, 0xfe, 0x18, 0x03, 0xc0, 0xf8, 0x1e, 0x01, 0xc0, 
0xe1, 0xff, 0x80, 0x40, 0xc3, 0xff, 0xe0, 0x00, 0x07, 0xff, 0xf8, 0x00, 0x0f, 0xff, 0xfc, 0x40
}; // 'settings', 26x16px

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC/RST
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
XPT2046_Touchscreen ts(TS_CS);
void setup() 
{
 Serial.begin(9600);
 tft.begin();
 tft.setRotation(1);
 tftw = tft.width();
 tfth = tft.height();
 Serial.println (tftw);
 Serial.println (tfth);
 ts.begin();
 ts.setRotation(1);






}
void loop() {
  // put your main code here, to run repeatedly:
humidityPage (0,29,0,0,0,0,0,29);
}

                               /******** humidity page case2  *********/
 
void humidityPage(int hs1d,int hs2d,int hs3d,int hs4d,int hs5d,int hs6d,int hs7d,int hs)
{
  int pre_hs1d, pre_hs2d, pre_hs3d,pre_hs4d, pre_hs5d, pre_hs6d, pre_hs7d, pre_hs;

  
  if (humidityscreen_count == LOW)
  {
    tft.fillRect(0, 0, tftw, tfth, ILI9341_WHITE); 
    tft.fillCircle(27,213,21,tft.color565(8, 160, 223)); //back button circle
    tft.setFont(&FreeSerif12pt7b); tft.setTextSize(1); //for home symbol H
    tft.setTextColor( tft.color565(255, 194, 14));
    tft.setCursor(20, 220);
    tft.print("H"); 
    offlineBox (5, int 5)

    humidityscreen_count = HIGH;
  }
  else 
  {
    if (hs1 == LOW)
    {
      if(pre_hs1 != hs1)
      {
        tft.fillRect(5, 5, 100, 58,tft.color565(255, 190, 200)); // red box 
        tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);               
        tft.setTextColor(ILI9341_BLACK);
        tft.setCursor(30, 27);
        tft.print("Sensor");
        tft.setCursor(27, 47);
        tft.print("Offline");
        pre_hs1 = hs1;
      }
    }
    else
    {
      if(pre_hs1 != hs1)
      {
        tft.fillRect(5, 5, 100, 58,tft.color565(65, 200, 23)); // green box
        pre_hs1 = hs1;
      }
      if (pre_hs1d != hs1d)
      {
        tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);               
        tft.setTextColor(ILI9341_BLACK);
        tft.setCursor(30, 24); 
        tft.print("Humidity"); 
        tft.setCursor(30, 44); 
        tft.print(hs1d); tft.print("%");
        pre_hs1d = hs1d;
      }
    }

    if (hs2 == LOW)
    {
      tft.fillRect(110, 5, 100, 58,tft.color565(255, 190, 200)); // red box 
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);               
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(120, 27);
      tft.println("Sensor");
      tft.setCursor(119, 47);
      tft.print("Offline");
      
    }
    else
    {
      tft.fillRect(110, 5, 100, 58,tft.color565(65, 200, 23)); // green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);               
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(125, 27); 
      tft.print("Humidity"); 
      tft.setCursor(143, 47); 
      tft.print(hs2d); tft.print("%");
    }
    
   
    tft.fillRect(215, 5, 100, 58,tft.color565(255, 190, 200)); // red box
    tft.fillRect(5, 68, 100, 58,tft.color565(255, 190, 200)); // red box
    tft.fillRect(110, 68, 100, 58,tft.color565(255, 190, 200)); // red box
    //tft.fillRect(215, 68, 100, 58,tft.color565(255, 190, 200)); // red box
    tft.fillRect(5, 131, 100, 58,tft.color565(255, 190, 200)); // red box
    tft.fillRect(110, 131, 100, 58,tft.color565(255, 190, 200)); // red box
    //tft.fillRect(215, 131, 100, 58,tft.color565(255, 190, 200)); // red box
    int newhs = map(hs, 10, 100, 30, 150);
    Gauge (newhs,220, 155, 90);
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
