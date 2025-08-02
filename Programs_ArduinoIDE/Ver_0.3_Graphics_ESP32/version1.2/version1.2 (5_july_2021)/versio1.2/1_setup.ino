
void setup() {
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
 }
