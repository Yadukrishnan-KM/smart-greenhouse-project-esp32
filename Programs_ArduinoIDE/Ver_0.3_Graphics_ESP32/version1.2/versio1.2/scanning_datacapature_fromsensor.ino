
// Developed by Yadukrishnan K M
// date 4/7/2021
// It is for checking the sensor is available or not(connected or not) = [void sensor_scanning()]
// It is working at the starting time (void setup) and when pressing the refresh button
// It is for capure data from active (connected) sensors = [void sensor_read()]
// It is working in the loop function everytime 

   /*************************************************************************** sensor Scanning *************************************************************************************/
   /**********//*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*//***********/
 
void sensor_scanning()
{
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
}

 /******************************************************************************* Sensor Reading *********************************************************************************/
 /*********************************//*////////////////////////////////////////////////////////////////////////////////////////////////////////////*//****************************/

 void sensor_read()
 {
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
        moisture[address] = map(local_moisture, 0, 1023, 10, 100);
      
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
           
 }

   /**********************************************************  ********* Finding average sensor data values *********************** ************************************************/
   /**********//*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*//***********/

 void average_measurement()
 {
   if(soilsensorcount != 0)
   {
    averageph = (ph[0]+ph[1]+ph[2]+ph[3]+ph[4]+ph[5]+ph[6])/soilsensorcount;
    averagemoisture = (moisture[0]+moisture[1]+moisture[2]+moisture[3]+moisture[4]+moisture[5]+moisture[6])/soilsensorcount;
   }
   else
   {
     averageph = 0;
     averagemoisture = 0;
   }
   if(atmsensorcount != 0)
   {
     averagetemperature = (temperature[0]+temperature[1]+temperature[2]+temperature[3]+temperature[4]+temperature[5]+temperature[6])/atmsensorcount;
     averagehumidity = (humidity[0]+humidity[1]+humidity[2]+humidity[3]+humidity[4]+humidity[5]+humidity[6])/atmsensorcount;    
   }
   else
   {
     averagetemperature = 0; 
     averagehumidity = 0;
   }
 }
