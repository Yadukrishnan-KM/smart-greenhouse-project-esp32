#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "XPT2046_Touchscreen.h"
#include "Fonts/FreeSerif9pt7b.h"
#include "Fonts/Org_01.h"
#include "Fonts/FreeSerif12pt7b.h"
#define MAXSIN 255
#define TFT_CS 10
#define TFT_DC 9
#define TS_CS 7
//#define TFT_MOSI 11
//#define TFT_CLK 13
//#define TFT_RST 8
//#define TFT_MISO 12


// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC/RST
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
XPT2046_Touchscreen ts(TS_CS);



int counter = 0;  // Global variable Gauge
int pre_hy; int pre_te; float pre_ph; int pre_me; //Home_Autogauge

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
 tft.begin();
 tft.setRotation(1);
 tft.fillScreen(ILI9341_WHITE);
}


void loop() 
{
  Home_Autogauge (50,50,4.5,1);
 delay(100);
}

//  *************** Graph cycling codes ****************//

void Home_Autogauge(int hy, int te, float ph, int me) // humi 10-100, temp 10-50, ph 3-9, moist 0-10
{
 counter++; 
 if (counter==200) counter=0;
 
 if(counter<50 && counter>=0)
 {
  if(hy != pre_hy || counter ==0)
  {
   if(counter ==0)
   {
   tft.setFont(&FreeSerif12pt7b); tft.setTextColor(ILI9341_WHITE); tft.setTextSize(1);
   tft.setCursor(25, 106);
   tft.print("Moisture");
   tft.setFont(&Org_01); tft.setTextSize(5);
   tft.setTextColor(ILI9341_WHITE);
   tft.setCursor(30, 144);
   tft.print (pre_me);
   tft.print("%"); 
   }
   tft.setFont(&FreeSerif12pt7b); tft.setTextColor(ILI9341_BLUE); tft.setTextSize(1);
   tft.setCursor(25, 106);
   tft.print("Humidity");
   tft.setFont(&Org_01); tft.setTextSize(5);
   tft.setTextColor(ILI9341_WHITE);
   tft.setCursor(27, 144);
   tft.print (pre_hy);
   tft.setTextColor(ILI9341_BLACK);
   tft.setCursor(27, 144);
   tft.print (hy);
   tft.print("%");
   pre_hy = hy;
   hy = map(hy, 10, 100, 30, 150);
   Gauge (hy, 80, 120, 90);
  }
 }
  
 else if (counter <100 && counter >=50)
 {
  if(te != pre_te || counter ==50)
  {
   if(counter ==50)
   {
   tft.setFont(&FreeSerif12pt7b); tft.setTextColor(ILI9341_WHITE); tft.setTextSize(1);
   tft.setCursor(25, 106);
   tft.print("Humidity");
   tft.setFont(&Org_01); tft.setTextSize(5);
   tft.setTextColor(ILI9341_WHITE);
   tft.setCursor(27, 144);
   tft.print (pre_hy);
   tft.print("%"); 
   }
   tft.setFont(&FreeSerif12pt7b); tft.setTextColor(ILI9341_BLUE); tft.setTextSize(1);
   tft.setCursor(10, 106);
   tft.print("Temperature");
   tft.setFont(&Org_01); tft.setTextSize(5);
   tft.setTextColor(ILI9341_WHITE);
   tft.setCursor(15, 144);
   tft.print (pre_te);
   tft.setTextColor(ILI9341_BLACK);
   tft.setCursor(15, 144);
   tft.print (te);
   tft.print(" C");
   tft.fillCircle(90,125,6,ILI9341_BLACK); //*symbol outer black
   tft.fillCircle(90,125,2,ILI9341_WHITE); //*symbol inner white
   pre_te = te;
   int newte = map(te, 10, 50, 30, 150);
   Gauge (newte, 80, 120, 90);
  }
 }
  
 else if (counter <150 && counter >=100)
 {
  if(ph != pre_ph || counter ==100)
  {
   if(counter ==100)
   {
    tft.setFont(&FreeSerif12pt7b); tft.setTextColor(ILI9341_WHITE); tft.setTextSize(1);
    tft.setCursor(10, 106);
    tft.print("Temperature");
    tft.setFont(&Org_01); tft.setTextSize(5);
    tft.setTextColor(ILI9341_WHITE);
    tft.setCursor(15, 144);
    tft.print (pre_te);
    tft.print(" C");
    tft.fillCircle(90,125,6,ILI9341_WHITE); //*symbol outer black removel
   }
   tft.setFont(&FreeSerif12pt7b); tft.setTextColor(ILI9341_BLUE); tft.setTextSize(1);
   tft.setCursor(55, 106);
   tft.print("pH");
   tft.setFont(&Org_01); tft.setTextSize(5);
   tft.setTextColor(ILI9341_WHITE);
   tft.setCursor(20, 144);
   tft.print (pre_ph);
   tft.setTextColor(ILI9341_BLACK);
   tft.setCursor(20, 144);
   tft.print (ph);
   pre_ph = ph;
   ph = map(ph, 3, 9, 30, 150);
   Gauge (ph, 80, 120, 90);
  }
 } 
  
 else if (counter <200 && counter >=150)
 {
  if(me != pre_me || counter ==150)
  {
   if(counter ==150)
   {
   tft.setFont(&FreeSerif12pt7b); tft.setTextColor(ILI9341_WHITE); tft.setTextSize(1);
   tft.setCursor(55, 106);
   tft.print("pH");
   tft.setFont(&Org_01); tft.setTextSize(5);
   tft.setTextColor(ILI9341_WHITE);
   tft.setCursor(20, 144);
   tft.print (pre_ph);
   }
   tft.setFont(&FreeSerif12pt7b); tft.setTextColor(ILI9341_BLUE); tft.setTextSize(1);
   tft.setCursor(25, 106);
   tft.print("Moisture");
   tft.setFont(&Org_01); tft.setTextSize(5);
   tft.setTextColor(ILI9341_WHITE);
   tft.setCursor(30, 144);
   tft.print (pre_me);
   tft.setTextColor(ILI9341_BLACK);
   tft.setCursor(30, 144);
   tft.print (me);
   tft.print("%");
   pre_me = me;
   me = map(me, 0, 10, 30, 150);
   Gauge (me, 80, 120, 90);
  }
 }
}


// *************   Graph drawing codes  ***************//
//              input data in between 30-150
                                                          
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
   tft.fillTriangle(xs0,ys0,xe0,ye0,xe1,ye1, ILI9341_RED);
   tft.fillTriangle(xs1,ys1,xe1,ye1,xe0,ye0,tft.color565(255, 40, 0) );
  } 
  else 
  {
   tft.fillTriangle(xs0,ys0,xe0,ye0,xe1,ye1, tft.color565(235, 210, 240));
   tft.fillTriangle(xs1,ys1,xe1,ye1,xe0,ye0, tft.color565(235, 206, 230));
  }
 } 
}
