#include <DHT.h>
#include <Wire.h>
DHT sensor0(4, DHT11);DHT sensor1(13, DHT11);DHT sensor2(12, DHT11);DHT sensor3(14, DHT11);DHT sensor4(27, DHT11);DHT sensor5(26, DHT11);DHT sensor6(25, DHT11);
 int soilsensorcount = 0;
 boolean soilsensorstatus[7]; // array starts from 0, first data is [0] last data is[6]
 int atmsensorcount = 0;
 boolean atmsensorstatus[7];  // array starts from 0, first data is [0] last data is[6]
 float ph[7];
 int moisture[7];
 int temperature[7];
 int humidity[7];               
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
   /*******************************    soil sensor (moisture & ph) scanning, max sensor count is 7    ****************************************/
   
// fixing the values to zero

  soilsensorcount = 0;
  for (int i=0; i<7 ;i++)
  {
    soilsensorstatus[i]= LOW;
    ph[i] = 0;
    moisture[i] = 0;
  }

// scanning the sensors
  
  Wire.begin();
  for (byte address = 1; address < 8; address++) 
  {
    Wire.beginTransmission(address);
    byte error = Wire.endTransmission();
    if (error == 0) 
    {
      soilsensorstatus[address-1]= HIGH;
      soilsensorcount++;
    }
  else soilsensorstatus[address-1]= LOW;
  }

   /*******************************    atmosphere sensor (temp & humidityt) scanning, max sensor count is 7    ****************************************/ 
  
// fixing the values to zero
  
  atmsensorcount = 0;
  for (int i=0; i<7 ;i++)
  {
    atmsensorstatus[i]= LOW;
    temperature[i] = 0;
    humidity[i] = 0;
  }

// scanning the sensors

  sensor0.begin(); sensor1.begin(); sensor2.begin(); sensor3.begin(); sensor4.begin(); sensor5.begin(); sensor6.begin();
  float h = sensor0.readHumidity();
  float t = sensor0.readTemperature();
  float f = sensor0.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) atmsensorstatus[0]= LOW;
  else 
  {
    atmsensorstatus[0]= HIGH;
    atmsensorcount++;
  }
  
  h = sensor1.readHumidity();
  t = sensor1.readTemperature();
  f = sensor1.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) atmsensorstatus[1]= LOW;
  else 
  {
    atmsensorstatus[1]= HIGH;
    atmsensorcount++;
  }
  
  h = sensor2.readHumidity();
  t = sensor2.readTemperature();
  f = sensor2.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) atmsensorstatus[2]= LOW;
  else 
  {
    atmsensorstatus[2]= HIGH;
    atmsensorcount++;
  }
  
  h = sensor3.readHumidity();
  t = sensor3.readTemperature();
  f = sensor3.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) atmsensorstatus[3]= LOW;
  else 
  {
    atmsensorstatus[3]= HIGH;
    atmsensorcount++;
  }

  h = sensor4.readHumidity();
  t = sensor4.readTemperature();
  f = sensor4.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) atmsensorstatus[4]= LOW;
  else 
  {
    atmsensorstatus[4]= HIGH;
    atmsensorcount++;
  }

  h = sensor5.readHumidity();
  t = sensor5.readTemperature();
  f = sensor5.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) atmsensorstatus[5]= LOW;
  else 
  {
    atmsensorstatus[5]= HIGH;
    atmsensorcount++;
  }
  
  h = sensor6.readHumidity();
  t = sensor6.readTemperature();
  f = sensor6.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) atmsensorstatus[6]= LOW;
  else 
  {
    atmsensorstatus[6]= HIGH;
    atmsensorcount++; 
  }
  Serial.print("soilsensorcount: ");
  Serial.println(soilsensorcount);
  Serial.print("atmsensorcount: ");
  Serial.println(atmsensorcount);
  delay(1000);
     

 /******************************************************************************* Sensor Reading *********************************************************************************/
 /*********************************//*////////////////////////////////////////////////////////////////////////////////////////////////////////////*//****************************/

        /*************************************************** Soil sensor data (moisture and ph) reading using the I2C protocol *************************************************/

  int16_t  local_ph;
  int16_t  local_light;
  int16_t  local_moisture;
 
  byte a,b;
  
  for ( int address=0 ; address < 7; address++)
  {
    if(soilsensorstatus[address] == HIGH)
    {
      Wire.requestFrom((address+1), 6);    // request 6 bytes from slave device #address
      while (Wire.available()) 
      { 
        a = Wire.read();
        b = Wire.read();
        local_ph = a;
        local_ph = local_ph << 8 | b; 
        ph[address]= map(local_ph, 0, 1023, 8.0, 3.5);
    
        a = Wire.read();
        b = Wire.read();
        local_light = a;
        local_light = local_light << 8 | b;
    
        a = Wire.read();
        b = Wire.read();
        local_moisture = a;
        local_moisture = local_moisture << 8 | b;
        moisture[address] =map(local_moisture, 0, 1023, 10, 100);
        Serial.print("ph :");
        Serial.println(ph[address]);
        Serial.print("moisture: ");
        Serial.println(moisture[address]);
        Serial.print(" loccal ph :");
        Serial.println(local_ph);
        Serial.print("local moisture: ");
        Serial.println(local_moisture);
      }
    }
  }

       /*************************************************** Atmosphere sensor data (humidity andtemperature) reading DHT11 sensor *************************************************/     
      if(atmsensorstatus[0]== HIGH)
     {
       humidity[0] = sensor0.readHumidity();
       temperature[0] = sensor0.readTemperature();   // Read temperature as Celsius (the default)
     }
     if(atmsensorstatus[1]== HIGH)
     {
       humidity[1] = sensor1.readHumidity();
       temperature[1] = sensor1.readTemperature();   // Read temperature as Celsius (the default)
     }
     if(atmsensorstatus[2]== HIGH)
     {
       humidity[2] = sensor2.readHumidity();
       temperature[2] = sensor2.readTemperature();   // Read temperature as Celsius (the default)
     }
     if(atmsensorstatus[3]== HIGH)
     {
       humidity[3] = sensor3.readHumidity();
       temperature[3] = sensor3.readTemperature();   // Read temperature as Celsius (the default)
     }
     if(atmsensorstatus[4]== HIGH)
     {
       humidity[4] = sensor4.readHumidity();
       temperature[4] = sensor4.readTemperature();   // Read temperature as Celsius (the default)
     }
     if(atmsensorstatus[5]== HIGH)
     {
       humidity[5] = sensor5.readHumidity();
       temperature[5] = sensor5.readTemperature();   // Read temperature as Celsius (the default)
     }
     if(atmsensorstatus[6]== HIGH)
     {
       humidity[6] = sensor6.readHumidity();
       temperature[6] = sensor6.readTemperature();   // Read temperature as Celsius (the default)
     }  
     Serial.print("hum temp : ");Serial.print(humidity[0]);Serial.println( temperature[0]);  
}
  
