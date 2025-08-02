
                                         /******** humidity page case1  *********/
                                         
void humidityPage()
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
    if (old_averagehumidity != averagehumidity)
    {
      tft.setFont(&Org_01); tft.setTextSize(3);
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(225, 155);
      tft.print(old_averagehumidity);tft.print("%"); 
      tft.setTextColor(ILI9341_RED);
      tft.setCursor(225, 155);
      tft.print(averagehumidity);tft.print("%"); 
      old_averagehumidity = averagehumidity;
    }
    /****  sensor 1   *****/
  if (humidity[0] == 0 && (old_humidity[0] != humidity[0]))
  {
    offlineBox (5,5);
    old_humidity[0] = humidity[0];
    humiditySensorCount[0]= LOW;  
  }
  if (humidity[0] != 0 && (old_humidity[0] != humidity[0]))
  {
    if (humiditySensorCount[0] == LOW)
    {
      tft.fillRect(5, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(20,27);
      tft.print("Humidity"); 
      humiditySensorCount[0] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(38,47); 
    tft.print(old_humidity[0]); tft.print("%");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(38,47); 
    tft.print(humidity[0]); tft.print("%");
    old_humidity[0] = humidity[0];
  }
    /********  sensor2 *****/
if (humidity[1] == 0 && (old_humidity[1] != humidity[1]))
  {
    offlineBox (110,5);
    old_humidity[1] = humidity[1];
    humiditySensorCount[1]= LOW;  
  }
  if (humidity[1] != 0 && (old_humidity[1] != humidity[1]))
  {
    if (humiditySensorCount[1] == LOW)
    {
      tft.fillRect(110, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(125,27);
      tft.print("Humidity"); 
      humiditySensorCount[1] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(143,47); 
    tft.print(old_humidity[1]); tft.print("%");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(143,47); 
    tft.print(humidity[1]); tft.print("%");
    old_humidity[1] = humidity[1];
  }
    /********  sensor3 *****/
if (humidity[2] == 0 && (old_humidity[2] != humidity[2]))
  {
    offlineBox (215,5);
    old_humidity[2] = humidity[2];
    humiditySensorCount[2]= LOW;  
  }
  if (humidity[2] != 0 && (old_humidity[2] != humidity[2]))
  {
    if (humiditySensorCount[2] == LOW)
    {
      tft.fillRect(215, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(230,27);
      tft.print("Humidity"); 
      humiditySensorCount[2] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(248,47); 
    tft.print(old_humidity[2]); tft.print("%");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(248,47); 
    tft.print(humidity[2]); tft.print("%");
    old_humidity[2] = humidity[2];
  }
    /********  sensor4 *****/
if (humidity[3] == 0 && (old_humidity[3] != humidity[3]))
  {
    offlineBox (5,68);
    old_humidity[3] = humidity[3];
    humiditySensorCount[3]= LOW;  
  }
  if (humidity[3] != 0 && (old_humidity[3] != humidity[3]))
  {
    if (humiditySensorCount[3] == LOW)
    {
      tft.fillRect(5, 68, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(20,90);
      tft.print("Humidity"); 
      humiditySensorCount[3] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(38,110); 
    tft.print(old_humidity[3]); tft.print("%");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(38,110); 
    tft.print(humidity[3]); tft.print("%");
    old_humidity[3] = humidity[3];
  }
    /********  sensor5 *****/
if (humidity[4] == 0 && (old_humidity[4] != humidity[4]))
  {
    offlineBox (110,68);
    old_humidity[4] = humidity[4];
    humiditySensorCount[4]= LOW;  
  }
  if (humidity[4] != 0 && (old_humidity[4] != humidity[4]))
  {
    if (humiditySensorCount[4] == LOW)
    {
      tft.fillRect(110, 68, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(125,90);
      tft.print("Humidity"); 
      humiditySensorCount[4] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(143,110); 
    tft.print(old_humidity[4]); tft.print("%");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(143,110); 
    tft.print(humidity[4]); tft.print("%");
    old_humidity[4] = humidity[4];
  }
      /********  sensor6 *****/
if (humidity[5] == 0 && (old_humidity[5] != humidity[5]))
  {
    offlineBox (5,131);
    old_humidity[5] = humidity[5];
    humiditySensorCount[5]= LOW;  
  }
  if (humidity[5] != 0 && (old_humidity[5] != humidity[5]))
  {
    if (humiditySensorCount[5] == LOW)
    {
      tft.fillRect(5, 131, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(20,153);
      tft.print("Humidity"); 
      humiditySensorCount[5] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(38,173); 
    tft.print(old_humidity[5]); tft.print("%");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(38,173); 
    tft.print(humidity[5]); tft.print("%");
    old_humidity[5] = humidity[5];
  }
      /********  sensor7 *****/
if (humidity[6] == 0 && (old_humidity[6] != humidity[6]))
  {
    offlineBox (110,131);
    old_humidity[6] = humidity[6];
    humiditySensorCount[6]= LOW;  
  }
  if (humidity[6] != 0 && (old_humidity[6] != humidity[6]))
  {
    if (humiditySensorCount[6] == LOW)
    {
      tft.fillRect(110, 131, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(125,153);
      tft.print("Humidity"); 
      humiditySensorCount[6] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(143,173); 
    tft.print(old_humidity[6]); tft.print("%");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(143,173); 
    tft.print(humidity[6]); tft.print("%");
    old_humidity[6] = humidity[6];
  }
   int newhs = map(averagehumidity, 10, 100, 30, 150);
   Gauge (newhs,218, 150, 90);
  }
}

                                     /******** temperature page case3  *********/

void temperaturePage()
{
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
    if (old_averagetemperature != averagetemperature)
    {
      tft.setFont(&Org_01); tft.setTextSize(3);
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(217, 155);
      tft.print(old_averagetemperature);tft.print("*C"); 
      tft.setTextColor(ILI9341_RED);
      tft.setCursor(217, 155);
      tft.print(averagetemperature);tft.print("*C"); 
      old_averagetemperature = averagetemperature;
    }
    /****  sensor 1   *****/
  if (temperature[0] == 0 && (old_temperature[0] != temperature[0]))
  {
    offlineBox (5,5);
    old_temperature[0] = temperature[0];
    temperatureSensorCount[0]= LOW;  
  }
  if (temperature[0] != 0 && (old_temperature[0] != temperature[0]))
  {
    if (temperatureSensorCount[0] == LOW)
    {
      tft.fillRect(5, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(9,27);
      tft.print("Temperature"); 
      temperatureSensorCount[0] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(35,47); 
    tft.print(old_temperature[0]); tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(35,47); 
    tft.print(temperature[0]); tft.print("*C");
    old_temperature[0] = temperature[0];
  }
    /********  sensor2 *****/
if (temperature[1] == 0 && (old_temperature[1] != temperature[1]))
  {
    offlineBox (110,5);
    old_temperature[1] = temperature[1];
    temperatureSensorCount[1]= LOW;  
  }
  if (temperature[1] != 0 && (old_temperature[1] != temperature[1]))
  {
    if (temperatureSensorCount[1] == LOW)
    {
      tft.fillRect(110, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(114,27);
      tft.print("Temperature"); 
      temperatureSensorCount[1] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(140,47); 
    tft.print(old_temperature[1]); tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(140,47); 
    tft.print(temperature[1]); tft.print("*C");
    old_temperature[1] = temperature[1];
  }
    /********  sensor3 *****/
if (temperature[2] == 0 && (old_temperature[2] != temperature[2]))
  {
    offlineBox (215,5);
    old_temperature[2] = temperature[2];
    temperatureSensorCount[2]= LOW;  
  }
  if (temperature[2] != 0 && (old_temperature[2] != temperature[2]))
  {
    if (temperatureSensorCount[2] == LOW)
    {
      tft.fillRect(215, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(219,27);
      tft.print("Temperature"); 
      temperatureSensorCount[2] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(245,47); 
    tft.print(old_temperature[2]); tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(245,47); 
    tft.print(temperature[2]); tft.print("*C");
    old_temperature[2] = temperature[2];
  }
    /********  sensor4 *****/
if (temperature[3] == 0 && (old_temperature[3] != temperature[3]))
  {
    offlineBox (5,68);
    old_temperature[3] = temperature[3];
    temperatureSensorCount[3]= LOW;  
  }
  if (temperature[3] != 0 && (old_temperature[3] != temperature[3]))
  {
    if (temperatureSensorCount[3] == LOW)
    {
      tft.fillRect(5, 68, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(9,90);
      tft.print("Temperature"); 
      temperatureSensorCount[3] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(35,110); 
    tft.print(old_temperature[3]); tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(35,110); 
    tft.print(temperature[3]); tft.print("*C");
    old_temperature[3] = temperature[3];
  }
    /********  sensor5 *****/
if (temperature[4] == 0 && (old_temperature[4] != temperature[4]))
  {
    offlineBox (110,68);
    old_temperature[4] = temperature[4];
    temperatureSensorCount[4]= LOW;  
  }
  if (temperature[4] != 0 && (old_temperature[4] != temperature[4]))
  {
    if (temperatureSensorCount[4] == LOW)
    {
      tft.fillRect(110, 68, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(114,90);
      tft.print("Temperature"); 
      temperatureSensorCount[4] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(140,110); 
    tft.print(old_temperature[4]); tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(140,110); 
    tft.print(temperature[4]); tft.print("*C");
    old_temperature[4] = temperature[4];
  }
      /********  sensor6 *****/
if (temperature[5] == 0 && (old_temperature[5] != temperature[5]))
  {
    offlineBox (5,131);
    old_temperature[5] = temperature[5];
    temperatureSensorCount[5]= LOW;  
  }
  if (temperature[5] != 0 && (old_temperature[5] != temperature[5]))
  {
    if (temperatureSensorCount[5] == LOW)
    {
      tft.fillRect(5, 131, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(9,153);
      tft.print("Temperature"); 
      temperatureSensorCount[5] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(35,173); 
    tft.print(old_temperature[5]); tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(35,173); 
    tft.print(temperature[5]); tft.print("*C");
    old_temperature[5] = temperature[5];
  }
      /********  sensor7 *****/
if (temperature[6] == 0 && (old_temperature[6] != temperature[6]))
  {
    offlineBox (110,131);
    old_temperature[6] = temperature[6];
    temperatureSensorCount[6]= LOW;  
  }
  if (temperature[6] != 0 && (old_temperature[6] != temperature[6]))
  {
    if (temperatureSensorCount[6] == LOW)
    {
      tft.fillRect(110, 131, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(114,153);
      tft.print("Temperature"); 
      temperatureSensorCount[6] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(140,173); 
    tft.print(old_temperature[6]); tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(140,173); 
    tft.print(temperature[6]); tft.print("*C");
    old_temperature[6] = temperature[6];
  }
   int newts = map(averagetemperature, 10, 50, 30, 150);
   Gauge (newts,218, 150, 90);
  }
}




                                     /******** phpage case3  *********/

void phPage()
{
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
    if (old_averageph != averageph)
    {
      tft.setFont(&Org_01); tft.setTextSize(3);
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(220, 155);
      tft.print(old_averageph);//tft.print("*C"); 
      tft.setTextColor(ILI9341_RED);
      tft.setCursor(220, 155);
      tft.print(averageph);//tft.print("*C"); 
      old_averageph = averageph;
    }
    /****  sensor 1   *****/
  if (ph[0] == 0 && (old_ph[0] != ph[0]))
  {
    offlineBox (5,5);
    old_ph[0] = ph[0];
    phSensorCount[0]= LOW;  
  }
  if (ph[0] != 0 && (old_ph[0] != ph[0]))
  {
    if (phSensorCount[0] == LOW)
    {
      tft.fillRect(5, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(45,27);
      tft.print("pH"); 
      phSensorCount[0] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(40,47); 
    tft.print(old_ph[0]); //tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(40,47); 
    tft.print(ph[0]);// tft.print("*C");
    old_ph[0] = ph[0];
  }
    /********  sensor2 *****/
if (ph[1] == 0 && (old_ph[1] != ph[1]))
  {
    offlineBox (110,5);
    old_ph[1] = ph[1];
    phSensorCount[1]= LOW;  
  }
  if (ph[1] != 0 && (old_ph[1] != ph[1]))
  {
    if (phSensorCount[1] == LOW)
    {
      tft.fillRect(110, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(150,27);
      tft.print("pH"); 
      phSensorCount[1] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(145,47); 
    tft.print(old_ph[1]); //tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(145,47); 
    tft.print(ph[1]);// tft.print("*C");
    old_ph[1] = ph[1];
  }
    /********  sensor3 *****/
if (ph[2] == 0 && (old_ph[2] != ph[2]))
  {
    offlineBox (215,5);
    old_ph[2] = ph[2];
    phSensorCount[2]= LOW;  
  }
  if (ph[2] != 0 && (old_ph[2] != ph[2]))
  {
    if (phSensorCount[2] == LOW)
    {
      tft.fillRect(215, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(255,27);
      tft.print("pH"); 
      phSensorCount[2] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(250,47); 
    tft.print(old_ph[2]); //tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(250,47); 
    tft.print(ph[2]); //tft.print("*C");
    old_ph[2] = ph[2];
  }
    /********  sensor4 *****/
if (ph[3] == 0 && (old_ph[3] != ph[3]))
  {
    offlineBox (5,68);
    old_ph[3] = ph[3];
    phSensorCount[3]= LOW;  
  }
  if (ph[3] != 0 && (old_ph[3] != ph[3]))
  {
    if (phSensorCount[3] == LOW)
    {
      tft.fillRect(5, 68, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(45,90);
      tft.print("pH"); 
      phSensorCount[3] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(40,110); 
    tft.print(old_ph[3]); //tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(40,110); 
    tft.print(ph[3]); //tft.print("*C");
    old_ph[3] = ph[3];
  }
    /********  sensor5 *****/
if (ph[4] == 0 && (old_ph[4] != ph[4]))
  {
    offlineBox (110,68);
    old_ph[4] = ph[4];
    phSensorCount[4]= LOW;  
  }
  if (ph[4] != 0 && (old_ph[4] != ph[4]))
  {
    if (phSensorCount[4] == LOW)
    {
      tft.fillRect(110, 68, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(150,90);
      tft.print("pH"); 
      phSensorCount[4] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(145,110); 
    tft.print(old_ph[4]);// tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(145,110); 
    tft.print(ph[4]); //tft.print("*C");
    old_ph[4] = ph[4];
  }
      /********  sensor6 *****/
if (ph[5] == 0 && (old_ph[5] != ph[5]))
  {
    offlineBox (5,131);
    old_ph[5] = ph[5];
    phSensorCount[5]= LOW;  
  }
  if (ph[5] != 0 && (old_ph[5] != ph[5]))
  {
    if (phSensorCount[5] == LOW)
    {
      tft.fillRect(5, 131, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(45,153);
      tft.print("pH"); 
      phSensorCount[5] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(40,173); 
    tft.print(old_ph[5]); //tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(40,173); 
    tft.print(ph[5]); //tft.print("*C");
    old_ph[5] = ph[5];
  }
      /********  sensor7 *****/
if (ph[6] == 0 && (old_ph[6] != ph[6]))
  {
    offlineBox (110,131);
    old_ph[6] = ph[6];
    phSensorCount[6]= LOW;  
  }
  if (ph[6] != 0 && (old_ph[6] != ph[6]))
  {
    if (phSensorCount[6] == LOW)
    {
      tft.fillRect(110, 131, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(150,153);
      tft.print("pH"); 
      phSensorCount[6] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(145,173); 
    tft.print(old_ph[6]);// tft.print("*C");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(145,173); 
    tft.print(ph[6]); //tft.print("*C");
    old_ph[6] = ph[6];
  }
   int newphs = map(averageph, 3, 9, 30, 150);
   Gauge (newphs,218, 150, 90);
  }
}

                                         /******** moisture page case4  *********/
                                         
void moisturePage()
{
  if (moisturescreen_count == LOW)
  {
    tft.fillRect(0, 0, tftw, tfth, ILI9341_WHITE);
    backButtton(); 
    tft.setFont(&FreeSerif12pt7b); tft.setTextSize(1); 
    tft.setTextColor(ILI9341_BLACK);
    tft.setCursor(130, 220);
    tft.print("Moisture"); 
    offlineBox (5,5);
    offlineBox (110,5);
    offlineBox (215,5);
    offlineBox (5,68);
    offlineBox (110,68);
    offlineBox (5,131);
    offlineBox (110,131);
    moisturescreen_count = HIGH;
  }
  else 
  { 
    if (old_averagemoisture != averagemoisture)
    {
      tft.setFont(&Org_01); tft.setTextSize(3);
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(225, 155);
      tft.print(old_averagemoisture);tft.print("%"); 
      tft.setTextColor(ILI9341_RED);
      tft.setCursor(225, 155);
      tft.print(averagemoisture);tft.print("%"); 
      old_averagemoisture = averagemoisture;
    }
    /****  sensor 1   *****/
  if (moisture[0] == 0 && (old_moisture[0] != moisture[0]))
  {
    offlineBox (5,5);
    old_moisture[0] = moisture[0];
    moistureSensorCount[0]= LOW;  
  }
  if (moisture[0] != 0 && (old_moisture[0] != moisture[0]))
  {
    if (moistureSensorCount[0] == LOW)
    {
      tft.fillRect(5, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(20,27);
      tft.print("Moisture"); 
      moistureSensorCount[0] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(38,47); 
    tft.print(old_moisture[0]); tft.print("%");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(38,47); 
    tft.print(moisture[0]); tft.print("%");
    old_moisture[0] = moisture[0];
  }
    /********  sensor2 *****/
if (moisture[1] == 0 && (old_moisture[1] != moisture[1]))
  {
    offlineBox (110,5);
    old_moisture[1] = moisture[1];
    moistureSensorCount[1]= LOW;  
  }
  if (moisture[1] != 0 && (old_moisture[1] != moisture[1]))
  {
    if (moistureSensorCount[1] == LOW)
    {
      tft.fillRect(110, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(125,27);
      tft.print("Moisture"); 
      moistureSensorCount[1] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(143,47); 
    tft.print(old_moisture[1]); tft.print("%");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(143,47); 
    tft.print(moisture[1]); tft.print("%");
    old_moisture[1] = moisture[1];
  }
    /********  sensor3 *****/
if (moisture[2] == 0 && (old_moisture[2] != moisture[2]))
  {
    offlineBox (215,5);
    old_moisture[2] = moisture[2];
    moistureSensorCount[2]= LOW;  
  }
  if (moisture[2] != 0 && (old_moisture[2] != moisture[2]))
  {
    if (moistureSensorCount[2] == LOW)
    {
      tft.fillRect(215, 5, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(230,27);
      tft.print("Moisture"); 
      moistureSensorCount[2] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(248,47); 
    tft.print(old_moisture[2]); tft.print("%");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(248,47); 
    tft.print(moisture[2]); tft.print("%");
    old_moisture[2] = moisture[2];
  }
    /********  sensor4 *****/
if (moisture[3] == 0 && (old_moisture[3] != moisture[3]))
  {
    offlineBox (5,68);
    old_moisture[3] = moisture[3];
    moistureSensorCount[3]= LOW;  
  }
  if (moisture[3] != 0 && (old_moisture[3] != moisture[3]))
  {
    if (moistureSensorCount[3] == LOW)
    {
      tft.fillRect(5, 68, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(20,90);
      tft.print("Moisture"); 
      moistureSensorCount[3] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(38,110); 
    tft.print(old_moisture[3]); tft.print("%");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(38,110); 
    tft.print(moisture[3]); tft.print("%");
    old_moisture[3] = moisture[3];
  }
    /********  sensor5 *****/
if (moisture[4] == 0 && (old_moisture[4] != moisture[4]))
  {
    offlineBox (110,68);
    old_moisture[4] = moisture[4];
    moistureSensorCount[4]= LOW;  
  }
  if (moisture[4] != 0 && (old_moisture[4] != moisture[4]))
  {
    if (moistureSensorCount[4] == LOW)
    {
      tft.fillRect(110, 68, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(125,90);
      tft.print("Moisture"); 
      moistureSensorCount[4] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(143,110); 
    tft.print(old_moisture[4]); tft.print("%");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(143,110); 
    tft.print(moisture[4]); tft.print("%");
    old_moisture[4] = moisture[4];
  }
      /********  sensor6 *****/
if (moisture[5] == 0 && (old_moisture[5] != moisture[5]))
  {
    offlineBox (5,131);
    old_moisture[5] = moisture[5];
    moistureSensorCount[5]= LOW;  
  }
  if (moisture[5] != 0 && (old_moisture[5] != moisture[5]))
  {
    if (moistureSensorCount[5] == LOW)
    {
      tft.fillRect(5, 131, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(20,153);
      tft.print("Moisture"); 
      moistureSensorCount[5] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(38,173); 
    tft.print(old_moisture[5]); tft.print("%");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(38,173); 
    tft.print(moisture[5]); tft.print("%");
    old_moisture[5] = moisture[5];
  }
      /********  sensor7 *****/
if (moisture[6] == 0 && (old_moisture[6] != moisture[6]))
  {
    offlineBox (110,131);
    old_moisture[6] = moisture[6];
    moistureSensorCount[6]= LOW;  
  }
  if (moisture[6] != 0 && (old_moisture[6] != moisture[6]))
  {
    if (moistureSensorCount[6] == LOW)
    {
      tft.fillRect(110, 131, 100, 58,tft.color565(65, 200, 23)); //green box
      tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
      tft.setTextColor(ILI9341_BLACK);
      tft.setCursor(125,153);
      tft.print("Moisture"); 
      moistureSensorCount[6] = HIGH;
    }
    
    tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1);
    tft.setTextColor(tft.color565(65, 200, 23));
    tft.setCursor(143,173); 
    tft.print(old_moisture[6]); tft.print("%");               
    tft.setTextColor(ILI9341_BLACK); 
    tft.setCursor(143,173); 
    tft.print(moisture[6]); tft.print("%");
    old_moisture[6] = moisture[6];
  }
   int newhs = map(averagemoisture, 10, 100, 30, 150);
   Gauge (newhs,218, 150, 90);
  }
}
