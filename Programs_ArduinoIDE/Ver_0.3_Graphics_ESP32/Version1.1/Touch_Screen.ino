                                             
                                             
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
