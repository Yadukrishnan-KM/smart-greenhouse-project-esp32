              /************     home_screen case1     *************/

void Homescreen ( boolean fan, boolean ven, boolean pum, boolean val)
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
 if (old_averagehumidity != averagehumidity)
 {
  tft.setTextColor(tft.color565(255, 194, 14));
  tft.setCursor(177, 71); // clear the old humidity data
  tft.print(old_averagehumidity); tft.print("%");
  tft.setTextColor(ILI9341_BLACK);
  tft.setCursor(177, 71); // new humidity data
  tft.print(averagehumidity); tft.print("%");
  old_averagehumidity = averagehumidity;
 }
 if (old_averagetemperature != averagetemperature) 
 {
  tft.setTextColor(tft.color565(255, 194, 14));
  tft.setCursor(205, 111); // clear old temp data
  tft.print(old_averagetemperature); tft.print("*C");
  tft.setTextColor(ILI9341_BLACK);
  tft.setCursor(205, 111); // new temp data
  tft.print(averagetemperature); tft.print("*C");
  old_averagetemperature != averagetemperature;
 }
 if (old_averageph != averageph)
 {
  tft.setTextColor(tft.color565(255, 194, 14));
  tft.setCursor(205, 153); //clear old ph data
  tft.print(old_averageph); 
  tft.setTextColor(ILI9341_BLACK);
  tft.setCursor(205, 153); //new ph data
  tft.print(averageph);
  old_averageph = averageph;
 }
 if (old_averagemoisture != averagemoisture) 
 {
  tft.setTextColor(tft.color565(255, 194, 14));
  tft.setCursor(177, 193); //clear old moisture data
  tft.print(old_averagemoisture); tft.print("%");
  tft.setTextColor(ILI9341_BLACK);  
  tft.setCursor(177, 193); //new moisture data
  tft.print(averagemoisture); tft.print("%");
  old_averagemoisture = averagemoisture;
 } 
}



//  *************** Graph cycling codes ****************//

void Home_Autogauge(int hy, int te, float ph, int me) // humi 10-100, temp 10-50, ph 3-9, moist 0-10
{
 counter++; 
 if (counter==4000) counter=0;
 
 if(counter<1000 && counter>=0)
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
  
 else if (counter <2000 && counter >=1000)
 {
  if(te != pre_te || counter ==1000)
  {
   if(counter ==1000)
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
  
 else if (counter <3000 && counter >=2000)
 {
  if(ph != pre_ph || counter ==2000)
  {
   if(counter ==2000)
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
  
 else if (counter <4000 && counter >=3000)
 {
  if(me != pre_me || counter ==3000)
  {
   if(counter ==3000)
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

 /*************************************************************** Digital Clock ********************************************************************************/
void digitalClockDisplay()
{
 if (old_Minute != Minute)
 { 
   tft.setFont(&Org_01);
   tft.setTextColor(ILI9341_WHITE); tft.setTextSize(3);
   tft.setCursor(225, 228);
   if (old_Hour > 12) tft.print(String(old_Hour-12)+":"+String(old_Minute));
   else tft.print(String(old_Hour)+":"+String(old_Minute));
   tft.setTextSize(2);
   if (Hour > 12) tft.print("AM");
   else tft.print("PM");
   tft.setTextColor(ILI9341_RED); tft.setTextSize(3);
   tft.setCursor(225, 228);
   if (Hour > 12) tft.print(String(Hour-12)+":"+String(Minute));
   else tft.print(String(Hour)+":"+String(Minute));
   tft.setTextSize(2);
   if (Hour < 12) tft.print("AM");
   else tft.print("PM");
 }
 
}
