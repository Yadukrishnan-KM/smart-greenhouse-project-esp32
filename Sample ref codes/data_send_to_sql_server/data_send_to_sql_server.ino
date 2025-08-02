/*
 * Created by esp32io.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://esp32io.com/tutorials/esp32-mysql
 */

#include <WiFi.h>
#include "HTTPClient.h"

const char WIFI_SSID[] = "Kuzhiyadithazhath";
const char WIFI_PASSWORD[] = "geethuyadu1991";

String HOST_NAME = "localhost/sqlserver";
String PATH_NAME   = "/sensordata.php";
String queryString = "?temperature=29&humidity=22&ph=4&moisture=50";

void setup() {
  Serial.begin(9600); 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  
  HTTPClient http;

 // http.begin("http://localhost/sqlserver/sensordata.php?temperature=29&humidity=22&ph=4&moisture=50"); //HTTP
 http.begin("http://localhost");
  int httpCode = http.GET();

  // httpCode will be negative on error
  if(httpCode > 0) {
    // file found at server
    if(httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);
    } else {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);
    }
  } else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();
}

void loop() {

}
