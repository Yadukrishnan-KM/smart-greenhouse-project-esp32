
                                             /***********   TFT Touch Calibration   *****/
          
void calibrateTouchScreen()
{
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
 tft.drawFastHLine(tftw - 30,tfth - 20,20,ILI9341_RED);
 tft.drawFastVLine(tftw - 20,tfth - 30,20,ILI9341_RED);
 while(!ts.touched());
 p = ts.getPoint();
 x2 = p.x;
 y2 = p.y;
 tft.drawFastHLine(tftw - 30,tfth - 20,20,ILI9341_BLACK);
 tft.drawFastVLine(tftw - 20,tfth - 30,20,ILI9341_BLACK);

 int16_t xDist = tftw - 40;
 int16_t yDist = tfth - 40;

 // translate in form pos = m x val + c
 // x
 xCalM = (float)xDist / (float)(x2 - x1);
 xCalC = 20.0 - ((float)x1 * xCalM);
 // y
 yCalM =  (float)yDist / (float)(y2 - y1);
 yCalC = 20.0 - ((float)y1 * yCalM);
} 
