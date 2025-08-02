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
 int lcdw = tft.width();
 int lcdh = tft.height();
 Serial.println (lcdw);
 Serial.println (lcdh);
 tft.setFont(&FreeSerif9pt7b);
  
 //tft.fillScreen(ILI9341_BLACK);
 
 tft.fillRect(0, 0, lcdw, lcdh, ILI9341_WHITE); 
 //tft.fillRoundRect(239, 7, 74, 28,3, tft.color565(50, 40, 60)); //for reference
 tft.setTextColor(ILI9341_WHITE); //tft.setTextSize(1);
 
 tft.fillRoundRect(5, 5, 75, 28,3,tft.color565(255, 40, 0)); //top box1 fan
 tft.setCursor(30, 24);
 tft.println("Fan");
 tft.fillRoundRect(83, 5, 75, 28,3, tft.color565(255, 40, 0)); //top box2 ventilation
 tft.setCursor(94, 24);
 tft.println("Ventiln");
 tft.fillRoundRect(163,5, 75, 28,3, tft.color565(65, 163, 23)); // top box3 pump
 tft.setCursor(179, 24);
 tft.println("Pump");
 tft.fillRoundRect(241, 5, 75, 28,3, tft.color565(65, 163, 23)); // top box4 valve
 tft.setCursor(256, 24);
 tft.println("Valve");
 
 tft.fillRoundRect(66, 213, 42, 20,3, tft.color565(204, 153, 255)); // bottom box1 settings
 tft.fillRoundRect(122, 213, 42, 20,3, tft.color565(204, 153, 255));// bottom box refresh
  tft.fillRect(75, 215, 26, 16, ILI9341_BLACK); 
 tft.fillRect(133, 216, 20, 14, ILI9341_BLACK);
 tft.drawBitmap(75, 215, settings, 26, 16,tft.color565(204, 153, 255));
tft.drawBitmap(133,216, refresh, 20, 14,tft.color565(204, 153, 255));
 
 
 
 //tft.drawCircle(27,213,20,tft.color565(50, 40, 60)); // bottom circle border about
 tft.fillCircle(27,213,21,tft.color565(8, 160, 223)); // bottom circle about
 tft.setTextColor( tft.color565(255, 194, 14)); tft.setTextSize(2);
 tft.setCursor(15, 224);
 tft.println("X");
 //tft.fillCircle(27, 213, 20, tft.color565(50, 40, 60) ); // bottom circle about
 //tft.setFont();
 tft.fillRoundRect(224, 56, 90, 20,3,ILI9341_BLACK); // side rect1 humidity
 tft.setTextColor(ILI9341_WHITE); tft.setTextSize(1);
 tft.setCursor(235, 71);
 tft.println("Humidity");
 tft.drawRoundRect(171, 48, 56, 36,30, tft.color565(0, 0, 0)); // side ellipsebox border humidity
 tft.fillRoundRect(172, 49, 54, 34,30, tft.color565(255, 194, 14)); // side ellipsebox humidity
 tft.fillRoundRect(224, 178, 90, 20,3,ILI9341_BLACK); // side rect4 soil moisture
  tft.setCursor(237, 193);
 tft.println("Moisture");
 tft.drawRoundRect(171, 170, 56, 36,30, tft.color565(0, 0, 0)); // side ellipsebox border moist
 tft.fillRoundRect(172, 171, 54, 34,30, tft.color565(255, 194, 14)); // side ellipsebox moist
 tft.fillRoundRect(252, 95, 62, 20,3,ILI9341_BLACK); // side rect2 temp
 tft.setCursor(259, 110);
 tft.println("Temp.");
 tft.fillRoundRect(199, 88, 56, 36,30, tft.color565(0, 0, 0)); // side ellipsebox border temp
 tft.fillRoundRect(200, 89, 54, 34,30, tft.color565(255, 194, 14)); // side ellipsebox temp
 tft.fillRoundRect(252, 137, 62, 20,3,ILI9341_BLACK); // side rect3 ph
  tft.setCursor(273, 151);
 tft.println("pH");
 tft.fillRoundRect(199, 130, 56, 36,30, tft.color565(0, 0, 0)); // side ellipsebox border ph
 tft.fillRoundRect(200, 131, 54, 34,30, tft.color565(255, 194, 14)); // side ellipsebox ph


// Input data print on boxes right side

  tft.setTextColor(ILI9341_BLACK); tft.setTextSize(1);
  tft.setCursor(177, 193);// sample
 tft.println("10 %");//sample
 tft.setCursor(177, 71);
 tft.println("55 %");
  tft.setCursor(205, 111);
 tft.println("36*C");
  tft.setCursor(205, 153);
 tft.println("4.63");



 
//Digital Clock
 
  tft.setFont(&Org_01);
  tft.setTextColor(ILI9341_RED); tft.setTextSize(3);
  tft.setCursor(237, 228);// sample
 tft.print("11:25");
 tft.setTextSize(2);
tft.print("AM");

// main input data

tft.setFont(&FreeSerif12pt7b);
tft.setTextColor(ILI9341_BLUE); tft.setTextSize(1);
  tft.setCursor(10, 106);
 tft.print("Temperature");
 tft.setFont(&Org_01);
tft.setTextColor(ILI9341_BLACK); tft.setTextSize(5);
  tft.setCursor(20, 144);
 tft.print("25 C");
 tft.fillCircle(95,125,6,ILI9341_BLACK); //*symbol outer black
 tft.fillCircle(95,125,2,ILI9341_WHITE); //*symbol inner white
 
// analog meter

int level=140;
for(int i=30; i<=150; i+=5) {
   float sx = sin(i*(3.14/180));
   float sy = cos(i*(3.14/180));
    Serial.println(sx);
    Serial.println(sy);
 int   xs0 = 80+sx*70;
 int   ys0 = 120+sy*70;
  int  xe0 = 80+sx*90;
  int  ye0 = 120+sy*90;
   int xe1 = 83+sx*70;
 int   ye1 = 123+sy*70;
  int  xs1 = 83+sx*90;
 int   ys1 = 123+sy*90;
      if(i<=level) {
        tft.fillTriangle(xs0,ys0,xe0,ye0,xe1,ye1, ILI9341_RED);
        tft.fillTriangle(xs1,ys1,xe1,ye1,xe0,ye0,tft.color565(255, 40, 0) );
      } else {
        tft.fillTriangle(xs0,ys0,xe0,ye0,xe1,ye1, tft.color565(235, 210, 240));
        tft.fillTriangle(xs1,ys1,xe1,ye1,xe0,ye0, tft.color565(235, 206, 230));
      }
  
  }
 
}

void loop() {
  


}
