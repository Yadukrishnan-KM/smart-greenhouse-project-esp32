 
                     /********** touch detection on home screen  ****************/
                     
void homeTouchDetection()                    
{
  if (ts.touched())
  {
    TS_Point p = ts.getPoint();
    ScreenPoint sp = getScreenCoords(p.x, p.y);
    if((sp.x >= 224  && sp.x <= 314 ) && (sp.y >= 56  && sp.y <= 76 ))
    {
     humidityscreen_count = LOW;
     pre_hs1d=0; pre_hs2d =0; pre_hs3d =0; pre_hs4d =0; pre_hs5d =0; pre_hs6d =0; pre_hs7d =0; pre_hs =0;
     hs1dcount = LOW; hs2dcount = LOW; hs3dcount = LOW; hs4dcount = LOW; hs5dcount = LOW; hs6dcount = LOW; hs7dcount = LOW; 
     menu_window =2; 
    }
    else if((sp.x >= 252  && sp.x <= 314 ) && (sp.y >= 95 && sp.y <= 115 ))
    {
     temperaturescreen_count = LOW;
     pre_ts1d=0; pre_ts2d =0; pre_ts3d =0; pre_ts4d =0; pre_ts5d =0; pre_ts6d =0; pre_ts7d =0; pre_ts =0; 
     ts1dcount = LOW; ts2dcount = LOW; ts3dcount = LOW; ts4dcount = LOW; ts5dcount = LOW; ts6dcount = LOW; ts7dcount = LOW; 
     menu_window =3; 
    }
    else if((sp.x >= 252  && sp.x <= 314 ) && (sp.y >= 137 && sp.y <= 157 ))
    {
     phscreen_count = LOW;
     pre_avgph =0; 
     for (int i=0; i<7; i++) 
     {
      pre_phsd[i] = 0;
     } 
     for (int i=0; i<7; i++) 
     {
      phsdcount[i] = LOW;
     } 
     menu_window =4; 
    }
    else if((sp.x >= 224  && sp.x <= 314 ) && (sp.y >= 178  && sp.y <= 198 ))
    {
     menu_window =5; 
    }
     else if((sp.x >= 5  && sp.x <= 80 ) && (sp.y >= 5  && sp.y <= 33 ))
    {
     menu_window =6; 
    }
    else if((sp.x >= 83  && sp.x <= 158 ) && (sp.y >= 5  && sp.y <= 33 ))
    {
     menu_window =7; 
    }
    else if((sp.x >= 163  && sp.x <= 238 ) && (sp.y >= 5  && sp.y <= 33 ))
    {
     menu_window =8; 
    }
    else if((sp.x >= 241  && sp.x <= 316 ) && (sp.y >= 5  && sp.y <= 33 ))
    {
     menu_window =9; 
    }
    else if((sp.x >= 122  && sp.x <= 164 ) && (sp.y >= 213  && sp.y <= 233 ))
    {
     menu_window =10; 
    }
    else if((sp.x >= 0  && sp.x <= 50 ) && (sp.y >= 190  && sp.y <= 240 ))
    {
     menu_window =11; 
    }
    else if((sp.x >= 122  && sp.x <= 164 ) && (sp.y >= 213  && sp.y <= 233 ))
    {
     menu_window =12; 
    }
  }
}
