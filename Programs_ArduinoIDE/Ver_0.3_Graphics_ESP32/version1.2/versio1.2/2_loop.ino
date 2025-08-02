
void loop() 
{
sensor_read();
average_measurement();
digitalClockUpdation();


switch(menu_window)
{
 case 1:
  Homescreen (LOW, HIGH, LOW, HIGH);
  Home_Autogauge (averagehumidity,averagetemperature,averageph,averagemoisture);
  digitalClockDisplay();
  homeTouchDetection();
  
 break;
 case 2:
  humidityPage ();
  backButtonTouchDetection();
 break;
 case 3:
  temperaturePage();
  backButtonTouchDetection();
 break;
 case 4:
  phPage();
  backButtonTouchDetection();
 break;
 case 5:
  moisturePage();
  backButtonTouchDetection();
 break;
 case 6:
  tft.fillRect(0, 0, tftw, tfth, ILI9341_RED);
  tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1); tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(100, 120);
  tft.print("FAN");
  backButtton();
  backButtonTouchDetection();
 break;
 case 7:
  tft.fillRect(0, 0, tftw, tfth, ILI9341_RED);
  tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1); tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(100, 120);
  tft.print("VENTILATION");
  backButtton();
  backButtonTouchDetection();
 break;
 case 8:
  tft.fillRect(0, 0, tftw, tfth, ILI9341_RED);
  tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1); tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(100, 120);
  tft.print("PUMP");
  backButtton();
  backButtonTouchDetection();
 break;
 case 9:
  tft.fillRect(0, 0, tftw, tfth, ILI9341_RED);
  tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1); tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(100, 120);
  tft.print("VALVE");
  backButtton();
  backButtonTouchDetection(); 
 break;
 case 10:
  tft.fillRect(0, 0, tftw, tfth, ILI9341_RED);
  tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1); tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(100, 120);
  tft.print("ABOUT");
  backButtton();
  backButtonTouchDetection();
 break;
 case 11:
  tft.fillRect(0, 0, tftw, tfth, ILI9341_RED);
  tft.setFont(&FreeSerif9pt7b); tft.setTextSize(1); tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(100, 120);
  tft.print("SETTINGS");
  backButtton();
  backButtonTouchDetection();
 break;
 case 12:
  sensor_scanning();
 break;
}
 

}
