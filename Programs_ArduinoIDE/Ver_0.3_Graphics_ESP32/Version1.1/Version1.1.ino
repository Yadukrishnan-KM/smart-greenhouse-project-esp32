#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "XPT2046_Touchscreen.h"
#include "Fonts/FreeSerif9pt7b.h"
#include "Fonts/Org_01.h"
#include "Fonts/FreeSerif12pt7b.h"
#include <Wire.h>

#define TS_CS 2

#define TFT_CS   5
#define TFT_DC   16
#define TFT_MOSI 23
#define TFT_CLK  18
#define TFT_RST  17
#define TFT_MISO 19
//Global ariables



      /***********************   class for taking two values together from above method   *******************/

class ScreenPoint {
  public:
    int16_t x;
    int16_t y;

    ScreenPoint(){
      // default contructor
    }

    ScreenPoint(int16_t xIn, int16_t yIn){
      x = xIn;
      y = yIn;
    }
};

 int nDevices = 0;  // no of soil sensors

int counter = 0;  // Global variable Gauge
int pre_hy; int pre_te; float pre_ph; int pre_me; //Home_Autogauge
int pre_hum; int pre_tem; float pre_phf; int pre_moi; // for the home screen right side box data
boolean pre_fan = LOW; boolean pre_ven = LOW; boolean pre_pum = LOW; boolean pre_val = LOW;
int tfth,tftw;

int menu_window = 1; // menu window selecting variable
boolean homescreen_count = LOW; //for working only 1 time the home page at initial

boolean hs1dcount = LOW; boolean hs2dcount = LOW; boolean hs3dcount = LOW; boolean hs4dcount = LOW; boolean hs5dcount = LOW; boolean hs6dcount = LOW; boolean hs7dcount = LOW;
int pre_hs1d, pre_hs2d, pre_hs3d,pre_hs4d, pre_hs5d, pre_hs6d, pre_hs7d, pre_hs;
boolean humidityscreen_count = LOW; //for working only 1 time the home page at initial


int pre_ts1d, pre_ts2d, pre_ts3d,pre_ts4d, pre_ts5d, pre_ts6d, pre_ts7d, pre_ts;
boolean ts1dcount = LOW; boolean ts2dcount = LOW; boolean ts3dcount = LOW; boolean ts4dcount = LOW; boolean ts5dcount = LOW; boolean ts6dcount = LOW; boolean ts7dcount = LOW;
boolean temperaturescreen_count = LOW; //for working only 1 time the home page at initial

boolean phscreen_count = LOW;    // for working only 1 time the home page at initial
boolean phsdcount[7];            // to find the sensor is active or not
float ph[7];                     // new ph data from the sensor
float avg_ph;                    // new average ph value
float pre_phsd[7];               // data array for old ph value for screen refreshment
float pre_avgph;                 // old average ph value for screen refreshment

boolean moisturescreen_count = LOW;    // for working only 1 time the home page at initial
boolean msdcount[7];                   // to find the sensor is active or not
float moisture[7];                     // new ph data from the sensor
float avg_moisture;                    // new average ph value
float pre_msd[7];                      // data array for old ph value for screen refreshment
float pre_avgmoisture;                 // old average ph value for screen refreshment

float xCalM = -0.11, yCalM = -0.09;
float xCalC = 392.33, yCalC = 296.84;

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
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);
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
 //calibrateTouchScreen();
 I2C_Scan ();
 Serial.print ("no of devices ");
 Serial.println (nDevices);
 tft.setFont(&FreeSerif9pt7b);
 tft.fillRect(0, 0, tftw, tfth, ILI9341_WHITE); 

 
}

void loop() 
{

I2C_Read();
if (nDevices!=0)
{
 avg_ph = ((ph[0]+ph[1]+ph[2]+ph[3]+ph[4]+ph[5]+ph[6])/nDevices);
 avg_moisture = ((moisture[0]+moisture[1]+moisture[2]+moisture[3]+moisture[4]+moisture[5]+moisture[6])/nDevices);
}

switch(menu_window)
{
 case 1:
  Homescreen (45, 20, avg_ph, avg_moisture, LOW, HIGH, LOW, HIGH);
  Home_Autogauge (45,20,avg_ph,avg_moisture);
  homeTouchDetection();
  
 break;
 case 2:
  humidityPage (55,0,25,2,0,50,0,55);
  backButtonTouchDetection();
 break;
 case 3:
  temperaturePage(25,0,35,0,55,66,8,63);
  backButtonTouchDetection();
 break;
 case 4:
  phPage();
  backButtonTouchDetection();
 break;
 case 5:
  tft.fillRect(0, 0, tftw, tfth, ILI9341_RED);
  tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1); tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(100, 120);
  tft.print("MOISTURE");
 break;
 case 6:
  tft.fillRect(0, 0, tftw, tfth, ILI9341_RED);
  tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1); tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(100, 120);
  tft.print("FAN");
 break;
 case 7:
  tft.fillRect(0, 0, tftw, tfth, ILI9341_RED);
  tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1); tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(100, 120);
  tft.print("VENTILATION");
 break;
 case 8:
  tft.fillRect(0, 0, tftw, tfth, ILI9341_RED);
  tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1); tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(100, 120);
  tft.print("PUMP");
 break;
 case 9:
  tft.fillRect(0, 0, tftw, tfth, ILI9341_RED);
  tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1); tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(100, 120);
  tft.print("VALVE"); 
 break;
 case 10:
  tft.fillRect(0, 0, tftw, tfth, ILI9341_RED);
  tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1); tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(100, 120);
  tft.print("ABOUT");
 break;
 case 11:
  tft.fillRect(0, 0, tftw, tfth, ILI9341_RED);
  tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1); tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(100, 120);
  tft.print("SETTINGS");
 break;
 case 12:
  tft.fillRect(0, 0, tftw, tfth, ILI9341_RED);
  tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1); tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(100, 120);
  tft.print("REFRESH");
 break;
}
 

}

               

              
              /************     home_screen case1     *************/
void Homescreen (int hum, int tem, float phf, int moi, boolean fan, boolean ven, boolean pum, boolean val)
{
               /********* not changable **************/
               
 if (homescreen_count == LOW) // for working only 1 time at initial //imp. (for each time come back to home page change the value to LOW)
 {
  homescreen_count = HIGH;
  tft.fillRect(0, 0, tftw, tfth, ILI9341_WHITE); 
   
  // top output status boxes run for first time only
  
  tft.setFont(&FreeSerif9pt7b);  tft.setTextSize(1);               
  tft.setTextColor(ILI9341_WHITE);
  tft.fillRoundRect(5, 5, 75, 28,3,tft.color565(255, 40, 0)); //top box1 fan off ferrari red
  tft.setCursor(30, 24);
  tft.print("Fan");
  tft.fillRoundRect(83, 5, 75, 28,3, tft.color565(255, 40, 0)); //top box2 ventilation off ferrari red
  tft.setCursor(94, 24);
  tft.print("Ventiln");
  tft.fillRoundRect(163,5, 75, 28,3, tft.color565(255, 40, 0)); // top box3 pump off ferrari red
  tft.setCursor(179, 24);
  tft.print("Pump");
  tft.fillRoundRect(241, 5, 75, 28,3, tft.color565(255, 40, 0)); // top box4 valve off ferrari red 
  tft.setCursor(256, 24);
  tft.print("Valve");
 
  //bottom menu boxes
  
  tft.fillRoundRect(66, 213, 42, 20,3, tft.color565(204, 153, 255)); // bottom box1 settings
  tft.fillRoundRect(122, 213, 42, 20,3, tft.color565(204, 153, 255));// bottom box refresh
  tft.fillRect(75, 215, 26, 16, ILI9341_BLACK); // for color for the symbol
  tft.fillRect(133, 216, 20, 14, ILI9341_BLACK);// for color for the symbol
  tft.drawBitmap(75, 215, settings, 26, 16,tft.color565(204, 153, 255)); //symbol
  tft.drawBitmap(133,216, refresh, 20, 14,tft.color565(204, 153, 255)); //symbol

  tft.fillCircle(27,213,21,tft.color565(8, 160, 223)); // bottom circle about
  tft.setTextColor( tft.color565(255, 194, 14)); tft.setTextSize(2); //foe letter X
  tft.setCursor(15, 224);
  tft.print("X");
  
  // right side menu boxes
  tft.fillRoundRect(224, 56, 90, 20,3,ILI9341_BLACK); // side rect1 humidity
  tft.setTextColor(ILI9341_WHITE); tft.setTextSize(1);
  tft.setCursor(235, 71);
  tft.print("Humidity");
  tft.drawRoundRect(171, 48, 56, 36,30, tft.color565(0, 0, 0)); // side ellipsebox border humidity
  tft.fillRoundRect(172, 49, 54, 34,30, tft.color565(255, 194, 14)); // side ellipsebox humidity
  
  tft.fillRoundRect(224, 178, 90, 20,3,ILI9341_BLACK); // side rect4 soil moisture
  tft.setCursor(237, 193);
  tft.print("Moisture");
  tft.drawRoundRect(171, 170, 56, 36,30, tft.color565(0, 0, 0)); // side ellipsebox border moist
  tft.fillRoundRect(172, 171, 54, 34,30, tft.color565(255, 194, 14)); // side ellipsebox moist
  
  tft.fillRoundRect(252, 95, 62, 20,3,ILI9341_BLACK); // side rect2 temp
  tft.setCursor(259, 110);
  tft.print("Temp.");
  tft.fillRoundRect(199, 88, 56, 36,30, tft.color565(0, 0, 0)); // side ellipsebox border temp
  tft.fillRoundRect(200, 89, 54, 34,30, tft.color565(255, 194, 14)); // side ellipsebox temp
  
  tft.fillRoundRect(252, 137, 62, 20,3,ILI9341_BLACK); // side rect3 ph
  tft.setCursor(273, 151);
  tft.print("pH");
  tft.fillRoundRect(199, 130, 56, 36,30, tft.color565(0, 0, 0)); // side ellipsebox border ph
  tft.fillRoundRect(200, 131, 54, 34,30, tft.color565(255, 194, 14)); // side ellipsebox ph
 }

                     /******   changing data  ******/
     
 // top menu boxes
 
 tft.setFont(&FreeSerif9pt7b);               
 tft.setTextColor(ILI9341_WHITE); tft.setTextSize(1);
 if (pre_fan != fan)
 {
  if (fan == LOW) 
  {
   tft.fillRoundRect(5, 5, 75, 28,3,tft.color565(255, 40, 0)); //top box1 fan off ferrari red
   tft.setCursor(30, 24);
   tft.print("Fan");
  }
  else if (fan == HIGH) 
  {
   tft.fillRoundRect(5, 5, 75, 28,3,tft.color565(65, 163, 23)); //top box1 fan on green
   tft.setCursor(30, 24);
   tft.print("Fan");
  }
  pre_fan = fan;
 } 
 if (pre_ven != ven)
 {
  if (ven == LOW) 
  {
   tft.fillRoundRect(83, 5, 75, 28,3, tft.color565(255, 40, 0)); //top box2 ventilation off ferrari red
   tft.setCursor(94, 24);
   tft.print("Ventiln");
  }
  else if (ven == HIGH) 
  {
   tft.fillRoundRect(83, 5, 75, 28,3, tft.color565(65, 163, 23)); //top box2 ventilation fan on green
   tft.setCursor(94, 24);
   tft.print("Ventiln");
  }
  pre_ven = ven;
 } 
 if (pre_pum != pum)
 {
  if (pum == LOW) 
  {
   tft.fillRoundRect(163,5, 75, 28,3, tft.color565(255, 40, 0)); // top box3 pump off ferrari red
   tft.setCursor(179, 24);
   tft.print("Pump");
  }
  else if (pum == HIGH) 
  {
   tft.fillRoundRect(163,5, 75, 28,3, tft.color565(65, 163, 23)); // top box3 pump fan on green
   tft.setCursor(179, 24);
   tft.print("Pump"); 
  }
  pre_pum = pum;
 }
 if (pre_val != val)
 { 
  if (val == LOW) 
  {
   tft.fillRoundRect(241, 5, 75, 28,3, tft.color565(255, 40, 0)); // top box4 valve off ferrari red 
   tft.setCursor(256, 24);
   tft.print("Valve");   
  }
  else if(val == HIGH) 
  {
   tft.fillRoundRect(241, 5, 75, 28,3, tft.color565(65, 163, 23)); // top box4 valve fan on green
   tft.setCursor(256, 24);
   tft.print("Valve");                 
  }
  pre_val = val;
 }                      
 // Input data print on boxes right side
 
 tft.setFont(&FreeSerif9pt7b);  tft.setTextSize(1);
 if (pre_hum != hum)
 {
  tft.setTextColor(tft.color565(255, 194, 14));
  tft.setCursor(177, 71); // clear the old humidity data
  tft.print(pre_hum); tft.print("%");
  tft.setTextColor(ILI9341_BLACK);
  tft.setCursor(177, 71); // new humidity data
  tft.print(hum); tft.print("%");
  pre_hum = hum;
 }
 if (pre_tem != tem) 
 {
  tft.setTextColor(tft.color565(255, 194, 14));
  tft.setCursor(205, 111); // clear old temp data
  tft.print(pre_tem); tft.print("*C");
  tft.setTextColor(ILI9341_BLACK);
  tft.setCursor(205, 111); // new temp data
  tft.print(tem); tft.print("*C");
  pre_tem != tem;
 }
 if (pre_phf != phf)
 {
  tft.setTextColor(tft.color565(255, 194, 14));
  tft.setCursor(205, 153); //clear old ph data
  tft.print(phf); 
  tft.setTextColor(ILI9341_BLACK);
  tft.setCursor(205, 153); //new ph data
  tft.print(phf);
  pre_phf = phf;
 }
 if (pre_moi != moi) 
 {
  tft.setTextColor(tft.color565(255, 194, 14));
  tft.setCursor(177, 193); //clear old moisture data
  tft.print(moi); tft.print("%");
  tft.setTextColor(ILI9341_BLACK);  
  tft.setCursor(177, 193); //new moisture data
  tft.print(moi); tft.print("%");
  pre_moi = moi;
 }
 //Digital Clock
 
 tft.setFont(&Org_01);
 tft.setTextColor(ILI9341_RED); tft.setTextSize(3);
 tft.setCursor(237, 228);// sample
 tft.print("11:25");
 tft.setTextSize(2);
 tft.print("AM"); 
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


                               /******** humidity page case2  *********/
 
void humidityPage(int hs1d,int hs2d,int hs3d,int hs4d,int hs5d,int hs6d,int hs7d,int hs)
{

  
  if (humidityscreen_count == LOW)
  {
    tft.fillRect(0, 0, tftw, tfth, ILI9341_WHITE);
    backButtton(); 
    tft.setFont(&FreeSerif12pt7b); tft.setTextSize(1); 
    tft.setTextColor(ILI9341_BLACK);
    tft.setCursor(130, 220);
    tft.print("Humidity"); 
    offlineBox (5,5);
    offlineBox (110,5);
    offlineBox (215,5);
    offlineBox (5,68);
    offlineBox (110,68);
    offlineBox (5,131);
    offlineBox (110,131);
    humidityscreen_count = HIGH;
  }
  else 
  { 
    if (pre_hs != hs)
    {
      tft.setFont(&Org_01); tft.setTextSize(3);
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(225, 155);
      tft.print(pre_hs);tft.print("%"); 
      tft.setTextColor(ILI9341_RED);
      tft.setCursor(225, 155);
      tft.print(hs);tft.print("%"); 
      pre_hs = hs;
    }
    /****  sensor 1   *****/
  if (hs1d == 0 && (pre_hs1d != hs1d))
  {
    offlineBox (5,5);
    pre_hs1d = hs1d;
    hs1dcount= LOW;  
  }
  if (hs1d != 0 && (pre_hs1d != hs1d))
  {
    if (hs1dcount == LOW)
    {
      tft.fillRect(5, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(20,27);
      tft.print("Humidity"); 
      hs1dcount = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(38,47); 
    tft.print(pre_hs1d); tft.print("%");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(38,47); 
    tft.print(hs1d); tft.print("%");
    pre_hs1d = hs1d;
  }
    /********  sensor2 *****/
if (hs2d == 0 && (pre_hs2d != hs2d))
  {
    offlineBox (110,5);
    pre_hs2d = hs2d;
    hs2dcount= LOW;  
  }
  if (hs2d != 0 && (pre_hs2d != hs2d))
  {
    if (hs2dcount == LOW)
    {
      tft.fillRect(110, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(125,27);
      tft.print("Humidity"); 
      hs2dcount = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(143,47); 
    tft.print(pre_hs2d); tft.print("%");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(143,47); 
    tft.print(hs2d); tft.print("%");
    pre_hs2d = hs2d;
  }
    /********  sensor3 *****/
if (hs3d == 0 && (pre_hs3d != hs3d))
  {
    offlineBox (215,5);
    pre_hs3d = hs3d;
    hs3dcount= LOW;  
  }
  if (hs3d != 0 && (pre_hs3d != hs3d))
  {
    if (hs3dcount == LOW)
    {
      tft.fillRect(215, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(230,27);
      tft.print("Humidity"); 
      hs3dcount = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(248,47); 
    tft.print(pre_hs3d); tft.print("%");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(248,47); 
    tft.print(hs3d); tft.print("%");
    pre_hs3d = hs3d;
  }
    /********  sensor4 *****/
if (hs4d == 0 && (pre_hs4d != hs4d))
  {
    offlineBox (5,68);
    pre_hs4d = hs4d;
    hs4dcount= LOW;  
  }
  if (hs4d != 0 && (pre_hs4d != hs4d))
  {
    if (hs4dcount == LOW)
    {
      tft.fillRect(5, 68, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(20,90);
      tft.print("Humidity"); 
      hs4dcount = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(38,110); 
    tft.print(pre_hs4d); tft.print("%");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(38,110); 
    tft.print(hs4d); tft.print("%");
    pre_hs4d = hs4d;
  }
    /********  sensor5 *****/
if (hs5d == 0 && (pre_hs5d != hs5d))
  {
    offlineBox (110,68);
    pre_hs5d = hs5d;
    hs5dcount= LOW;  
  }
  if (hs5d != 0 && (pre_hs5d != hs5d))
  {
    if (hs5dcount == LOW)
    {
      tft.fillRect(110, 68, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(125,90);
      tft.print("Humidity"); 
      hs5dcount = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(143,110); 
    tft.print(pre_hs5d); tft.print("%");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(143,110); 
    tft.print(hs5d); tft.print("%");
    pre_hs5d = hs5d;
  }
      /********  sensor6 *****/
if (hs6d == 0 && (pre_hs6d != hs6d))
  {
    offlineBox (5,131);
    pre_hs6d = hs6d;
    hs6dcount= LOW;  
  }
  if (hs6d != 0 && (pre_hs6d != hs6d))
  {
    if (hs6dcount == LOW)
    {
      tft.fillRect(5, 131, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(20,153);
      tft.print("Humidity"); 
      hs6dcount = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(38,173); 
    tft.print(pre_hs6d); tft.print("%");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(38,173); 
    tft.print(hs6d); tft.print("%");
    pre_hs6d = hs6d;
  }
      /********  sensor7 *****/
if (hs7d == 0 && (pre_hs7d != hs7d))
  {
    offlineBox (110,131);
    pre_hs7d = hs7d;
    hs7dcount= LOW;  
  }
  if (hs7d != 0 && (pre_hs7d != hs7d))
  {
    if (hs7dcount == LOW)
    {
      tft.fillRect(110, 131, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(125,153);
      tft.print("Humidity"); 
      hs7dcount = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(143,173); 
    tft.print(pre_hs7d); tft.print("%");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(143,173); 
    tft.print(hs7d); tft.print("%");
    pre_hs7d = hs7d;
  }
   int newhs = map(hs, 10, 100, 30, 150);
   Gauge (newhs,218, 150, 90);
  }
}

                                     /******** temperature page case3  *********/

void temperaturePage(int ts1d,int ts2d,int ts3d,int ts4d,int ts5d,int ts6d,int ts7d,int ts)
{
  int pre_ts1d, pre_ts2d, pre_ts3d,pre_ts4d, pre_ts5d, pre_ts6d, pre_ts7d, pre_ts;

  
  if (temperaturescreen_count == LOW)
  {
    tft.fillRect(0, 0, tftw, tfth, ILI9341_WHITE);
    backButtton(); 
    tft.setFont(&FreeSerif12pt7b); tft.setTextSize(1); 
    tft.setTextColor(ILI9341_BLACK);
    tft.setCursor(110, 220);
    tft.print("Temperature"); 
    offlineBox (5,5);
    offlineBox (110,5);
    offlineBox (215,5);
    offlineBox (5,68);
    offlineBox (110,68);
    offlineBox (5,131);
    offlineBox (110,131);
    temperaturescreen_count = HIGH;
  }
  else 
  { 
    if (pre_ts != ts)
    {
      tft.setFont(&Org_01); tft.setTextSize(3);
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(217, 155);
      tft.print(pre_ts);tft.print("*C"); 
      tft.setTextColor(ILI9341_RED);
      tft.setCursor(217, 155);
      tft.print(ts);tft.print("*C"); 
      pre_ts = ts;
    }
    /****  sensor 1   *****/
  if (ts1d == 0 && (pre_ts1d != ts1d))
  {
    offlineBox (5,5);
    pre_ts1d = ts1d;
    ts1dcount= LOW;  
  }
  if (ts1d != 0 && (pre_ts1d != ts1d))
  {
    if (ts1dcount == LOW)
    {
      tft.fillRect(5, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(9,27);
      tft.print("Temperature"); 
      ts1dcount = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(35,47); 
    tft.print(pre_ts1d); tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(35,47); 
    tft.print(ts1d); tft.print("*C");
    pre_ts1d = ts1d;
  }
    /********  sensor2 *****/
if (ts2d == 0 && (pre_ts2d != ts2d))
  {
    offlineBox (110,5);
    pre_ts2d = ts2d;
    ts2dcount= LOW;  
  }
  if (ts2d != 0 && (pre_ts2d != ts2d))
  {
    if (ts2dcount == LOW)
    {
      tft.fillRect(110, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(114,27);
      tft.print("Temperature"); 
      ts2dcount = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(140,47); 
    tft.print(pre_ts2d); tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(140,47); 
    tft.print(ts2d); tft.print("*C");
    pre_ts2d = ts2d;
  }
    /********  sensor3 *****/
if (ts3d == 0 && (pre_ts3d != ts3d))
  {
    offlineBox (215,5);
    pre_ts3d = ts3d;
    ts3dcount= LOW;  
  }
  if (ts3d != 0 && (pre_ts3d != ts3d))
  {
    if (ts3dcount == LOW)
    {
      tft.fillRect(215, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(219,27);
      tft.print("Temperature"); 
      ts3dcount = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(245,47); 
    tft.print(pre_ts3d); tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(245,47); 
    tft.print(ts3d); tft.print("*C");
    pre_ts3d = ts3d;
  }
    /********  sensor4 *****/
if (ts4d == 0 && (pre_ts4d != ts4d))
  {
    offlineBox (5,68);
    pre_ts4d = ts4d;
    ts4dcount= LOW;  
  }
  if (ts4d != 0 && (pre_ts4d != ts4d))
  {
    if (ts4dcount == LOW)
    {
      tft.fillRect(5, 68, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(9,90);
      tft.print("Temperature"); 
      ts4dcount = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(35,110); 
    tft.print(pre_ts4d); tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(35,110); 
    tft.print(ts4d); tft.print("*C");
    pre_ts4d = ts4d;
  }
    /********  sensor5 *****/
if (ts5d == 0 && (pre_ts5d != ts5d))
  {
    offlineBox (110,68);
    pre_ts5d = ts5d;
    ts5dcount= LOW;  
  }
  if (ts5d != 0 && (pre_ts5d != ts5d))
  {
    if (ts5dcount == LOW)
    {
      tft.fillRect(110, 68, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(114,90);
      tft.print("Temperature"); 
      ts5dcount = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(140,110); 
    tft.print(pre_ts5d); tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(140,110); 
    tft.print(ts5d); tft.print("*C");
    pre_ts5d = ts5d;
  }
      /********  sensor6 *****/
if (ts6d == 0 && (pre_ts6d != ts6d))
  {
    offlineBox (5,131);
    pre_ts6d = ts6d;
    ts6dcount= LOW;  
  }
  if (ts6d != 0 && (pre_ts6d != ts6d))
  {
    if (ts6dcount == LOW)
    {
      tft.fillRect(5, 131, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(9,153);
      tft.print("Temperature"); 
      ts6dcount = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(35,173); 
    tft.print(pre_ts6d); tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(35,173); 
    tft.print(ts6d); tft.print("*C");
    pre_ts6d = ts6d;
  }
      /********  sensor7 *****/
if (ts7d == 0 && (pre_ts7d != ts7d))
  {
    offlineBox (110,131);
    pre_ts7d = ts7d;
    ts7dcount= LOW;  
  }
  if (ts7d != 0 && (pre_ts7d != ts7d))
  {
    if (ts7dcount == LOW)
    {
      tft.fillRect(110, 131, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(114,153);
      tft.print("Temperature"); 
      ts7dcount = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(140,173); 
    tft.print(pre_ts7d); tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(140,173); 
    tft.print(ts7d); tft.print("*C");
    pre_ts7d = ts7d;
  }
   int newts = map(ts, 10, 50, 30, 150);
   Gauge (newts,218, 150, 90);
  }
}




                                     /******** phpage case3  *********/

void phPage()
{
  //int pre_phs1d, pre_phs2d, pre_phs3d,pre_phs4d, pre_phs5d, pre_phs6d, pre_phs7d, pre_phs;

  
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
    if (pre_avgph != avg_ph)
    {
      tft.setFont(&Org_01); tft.setTextSize(3);
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(220, 155);
      tft.print(pre_avgph);//tft.print("*C"); 
      tft.setTextColor(ILI9341_RED);
      tft.setCursor(220, 155);
      tft.print(avg_ph);//tft.print("*C"); 
      pre_avgph = avg_ph;
    }
    /****  sensor 1   *****/
  if (ph[0] == 0 && (pre_phsd[0] != ph[0]))
  {
    offlineBox (5,5);
    pre_phsd[0] = ph[0];
    phsdcount[0]= LOW;  
  }
  if (ph[0] != 0 && (pre_phsd[0] != ph[0]))
  {
    if (phsdcount[0] == LOW)
    {
      tft.fillRect(5, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(45,27);
      tft.print("pH"); 
      phsdcount[0] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(40,47); 
    tft.print(pre_phsd[0]); //tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(40,47); 
    tft.print(ph[0]);// tft.print("*C");
    pre_phsd[0] = ph[0];
  }
    /********  sensor2 *****/
if (ph[1] == 0 && (pre_phsd[1] != ph[1]))
  {
    offlineBox (110,5);
    pre_phsd[1] = ph[1];
    phsdcount[1]= LOW;  
  }
  if (ph[1] != 0 && (pre_phsd[1] != ph[1]))
  {
    if (phsdcount[1] == LOW)
    {
      tft.fillRect(110, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(150,27);
      tft.print("pH"); 
      phsdcount[1] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(145,47); 
    tft.print(pre_phsd[1]); //tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(145,47); 
    tft.print(ph[1]);// tft.print("*C");
    pre_phsd[1] = ph[1];
  }
    /********  sensor3 *****/
if (ph[2] == 0 && (pre_phsd[2] != ph[2]))
  {
    offlineBox (215,5);
    pre_phsd[2] = ph[2];
    phsdcount[2]= LOW;  
  }
  if (ph[2] != 0 && (pre_phsd[2] != ph[2]))
  {
    if (phsdcount[2] == LOW)
    {
      tft.fillRect(215, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(255,27);
      tft.print("pH"); 
      phsdcount[2] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(250,47); 
    tft.print(pre_phsd[2]); //tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(250,47); 
    tft.print(ph[2]); //tft.print("*C");
    pre_phsd[2] = ph[2];
  }
    /********  sensor4 *****/
if (ph[3] == 0 && (pre_phsd[3] != ph[3]))
  {
    offlineBox (5,68);
    pre_phsd[3] = ph[3];
    phsdcount[3]= LOW;  
  }
  if (ph[3] != 0 && (pre_phsd[3] != ph[3]))
  {
    if (phsdcount[3] == LOW)
    {
      tft.fillRect(5, 68, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(45,90);
      tft.print("pH"); 
      phsdcount[3] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(40,110); 
    tft.print(pre_phsd[3]); //tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(40,110); 
    tft.print(ph[3]); //tft.print("*C");
    pre_phsd[3] = ph[3];
  }
    /********  sensor5 *****/
if (ph[4] == 0 && (pre_phsd[4] != ph[4]))
  {
    offlineBox (110,68);
    pre_phsd[4] = ph[4];
    phsdcount[4]= LOW;  
  }
  if (ph[4] != 0 && (pre_phsd[4] != ph[4]))
  {
    if (phsdcount[4] == LOW)
    {
      tft.fillRect(110, 68, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(150,90);
      tft.print("pH"); 
      phsdcount[4] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(145,110); 
    tft.print(pre_phsd[4]);// tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(145,110); 
    tft.print(ph[4]); //tft.print("*C");
    pre_phsd[4] = ph[4];
  }
      /********  sensor6 *****/
if (ph[5] == 0 && (pre_phsd[5] != ph[5]))
  {
    offlineBox (5,131);
    pre_phsd[5] = ph[5];
    phsdcount[5]= LOW;  
  }
  if (ph[5] != 0 && (pre_phsd[5] != ph[5]))
  {
    if (phsdcount[5] == LOW)
    {
      tft.fillRect(5, 131, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(45,153);
      tft.print("pH"); 
      phsdcount[5] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(40,173); 
    tft.print(pre_phsd[5]); //tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(40,173); 
    tft.print(ph[5]); //tft.print("*C");
    pre_phsd[5] = ph[5];
  }
      /********  sensor7 *****/
if (ph[6] == 0 && (pre_phsd[6] != ph[6]))
  {
    offlineBox (110,131);
    pre_phsd[6] = ph[6];
    phsdcount[6]= LOW;  
  }
  if (ph[6] != 0 && (pre_phsd[6] != ph[6]))
  {
    if (phsdcount[6] == LOW)
    {
      tft.fillRect(110, 131, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(150,153);
      tft.print("pH"); 
      phsdcount[6] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(145,173); 
    tft.print(pre_phsd[6]);// tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(145,173); 
    tft.print(ph[6]); //tft.print("*C");
    pre_phsd[6] = ph[6];
  }
   int newphs = map(avg_ph, 3, 9, 30, 150);
   Gauge (newphs,218, 150, 90);
  }
}




                     /********** touch detection on back button ****************/
void backButtonTouchDetection()                    
{
  if (ts.touched())
  {
    TS_Point p = ts.getPoint();
    ScreenPoint sp = getScreenCoords(p.x, p.y);
    if((sp.x >= 0  && sp.x <= 48 ) && (sp.y >= 192 && sp.y <= 240 ))
    {
     homescreen_count = LOW; 
     pre_hum =0 ; pre_tem=0 ; pre_phf =0 ; pre_moi=0 ;
     pre_fan = LOW; pre_ven = LOW; pre_pum = LOW; pre_val = LOW;
     menu_window =1; 
    }
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
