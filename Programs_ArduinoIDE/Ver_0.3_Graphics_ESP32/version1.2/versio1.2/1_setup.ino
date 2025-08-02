
void setup() 
{
  Wire.begin();
  sensor0.begin(); sensor1.begin(); sensor2.begin(); sensor3.begin(); sensor4.begin(); sensor5.begin(); sensor6.begin(); 
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
  tft.setFont(&FreeSerif9pt7b);
  tft.fillRect(0, 0, tftw, tfth, ILI9341_WHITE); 
  sensor_scanning();
  RTC.begin();
   if (! RTC.isrunning()) 
   {
     Serial.println("RTC is NOT running!");
     RTC.adjust(DateTime(F(__DATE__),F( __TIME__))); // following line sets the RTC to the date & time this sketch was compiled
     //RTC.adjust(DateTime(2021, 7, 11, 9, 45, 0)); // for custom audjustments
   }
   digitalWrite(14, LOW);
   digitalWrite(12, LOW);
   digitalWrite(13, LOW);
 // RTC.adjust(DateTime(F(__DATE__),F( __TIME__)));
 /*WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());*/
 }
