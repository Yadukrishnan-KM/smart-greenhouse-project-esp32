#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "XPT2046_Touchscreen.h"
#include "Fonts/FreeSerif9pt7b.h"
#include "Fonts/Org_01.h"
#include "Fonts/FreeSerif12pt7b.h"
#include <Wire.h>
#include "DHT.h"

#define TS_CS 2
#define TFT_CS   5
#define TFT_DC   16
#define TFT_MOSI 23
#define TFT_CLK  18
#define TFT_RST  17
#define TFT_MISO 19

DHT sensor0(4, DHT11);DHT sensor1(13, DHT11);DHT sensor2(12, DHT11);DHT sensor3(14, DHT11);DHT sensor4(27, DHT11);DHT sensor5(26, DHT11);DHT sensor6(25, DHT11);
// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC/RST
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);
XPT2046_Touchscreen ts(TS_CS);

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


      /***********************   class for taking two values together from touch(getScreenCoords) method   *******************/

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

                /****************************                         ***************************/
              
 int soilsensorcount = 0;
 boolean soilsensorstatus[7]; // array starts from 0, first data is [0] last data is[6]
 float ph[7];
 int moisture[7];
 float averageph;
 int averagemoisture;
 
 int atmsensorcount = 0;
 boolean atmsensorstatus[7];  // array starts from 0, first data is [0] last data is[6]
 int temperature[7];
 int humidity[7];
 int averagetemperature; 
 int averagehumidity;

 int old_averagehumidity =0;
int old_averagetemperature = 0;
int old_averagemoisture = 0;
float old_averageph = 0;

int old_humidity[7];
int old_temperature[7];
int old_moisture[7];
float old_ph[7];

boolean humiditySensorCount[7];
boolean temperatureSensorCount[7];
boolean moistureSensorCount[7];
boolean phSensorCount[7];

boolean humidityscreen_count = LOW; //for working only 1 time the home page at initial
boolean temperaturescreen_count = LOW; //for working only 1 time the home page at initial
boolean phscreen_count = LOW; //for working only 1 time the home page at initial
boolean moisturescreen_count = LOW;   //for working only 1 time the home page at initial    
                
// touch screen calibration default values

float xCalM = -0.11, yCalM = -0.09;
float xCalC = 392.33, yCalC = 296.84;

int counter = 0;  // Global variable Gauge
int pre_hy; int pre_te; float pre_ph; int pre_me; //Home_Autogauge
int pre_hum; int pre_tem; float pre_phf; int pre_moi; // for the home screen right side box data
boolean pre_fan = LOW; boolean pre_ven = LOW; boolean pre_pum = LOW; boolean pre_val = LOW;
int tfth,tftw;

int menu_window = 1; // menu window selecting variable
boolean homescreen_count = LOW; //for home page codes working only single time at initial








                  /********   screen point to tft pixel converter   ***********/
                  
ScreenPoint getScreenCoords(int16_t x, int16_t y){
  int16_t xCoord = round((x * xCalM) + xCalC);
  int16_t yCoord = round((y * yCalM) + yCalC);
  if(xCoord < 0) xCoord = 0;
  if(xCoord >= tftw) xCoord = tftw - 1;
  if(yCoord < 0) yCoord = 0;
  if(yCoord >= tfth) yCoord = tfth - 1;
  return(ScreenPoint(xCoord, yCoord));
  
}





               

              




 
