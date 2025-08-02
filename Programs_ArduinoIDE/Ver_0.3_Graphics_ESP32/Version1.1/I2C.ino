
                            /*   //////  I2C scanner for finding the soil sensor address and number /////// */

void I2C_Scan ()
{
  Wire.begin(21,22);  // join i2c bus (address optional for master) 
  
  byte error, address;

  for(address = 0; address < 7; address++ ) 
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    
    Wire.beginTransmission(address+1);
    error = Wire.endTransmission();

    if (error == 0)
    {
      msdcount[address] = HIGH;
      phsdcount[address] = HIGH;
      nDevices++;
    }
    else  
    {
      msdcount[address] = LOW;
      phsdcount[address] = LOW;
    }    
  }
}


                       /*    ///////// I2C data receiver    //////////  */

void I2C_Read()
{
  int16_t  local_ph;
  int16_t  local_light;
  int16_t  local_moisture;
 
  byte a,b;
  int address;
  
  for ( address=0 ; address<7; address++)
  {
    if(phsdcount[address] == HIGH)
    {
      Wire.requestFrom((address+1), 6);    // request 6 bytes from slave device #address
      while (Wire.available()) 
      { 
        a = Wire.read();
        b = Wire.read();
        local_ph = a;
        local_ph = local_ph << 8 | b; 
        ph[address]= map(local_ph, 8.0, 3.5, 0, 1023);
    
        a = Wire.read();
        b = Wire.read();
        local_light = a;
        local_light = local_light << 8 | b;
    
        a = Wire.read();
        b = Wire.read();
        local_moisture = a;
        local_moisture = local_moisture << 8 | b;
        moisture[address] = map(local_moisture, 10, 100, 0, 1023);
      
      }
    }
  }
}
