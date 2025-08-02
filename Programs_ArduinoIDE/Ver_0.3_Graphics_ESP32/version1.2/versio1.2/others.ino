
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
     old_averagehumidity =0 ; old_averagetemperature=0 ; old_averageph =0 ; old_averagemoisture=0 ;
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

/************************************************************* Digital Clock Updation **********************************************************************/
// updating clock data from RTC
void digitalClockUpdation()
{
  DateTime now = RTC.now();
  old_Year = Year; old_Month = Month; old_Day = Day; old_Hour = Hour; old_Minute = Minute; old_Second = Second; 
  Year = now.year();
  Month = now.month();
  Day = now.day();
  Hour = now.hour();
  Minute = now.minute();
  Second = now.second(); 
}
