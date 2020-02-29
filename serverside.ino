/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-client-server-wi-fi/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

// Import required libraries
#include <WiFi.h>
#include <ESPAsyncWebServer.h>

#include <Wire.h>

// Set your access point network credentials
const char* ssid = "ESP32-Access-Point";
const char* password = "put-your-pswd-here";

/*#include <SPI.h>
#define BME_SCK 18
#define BME_MISO 19
#define BME_MOSI 23
#define BME_CS 5*/

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

String readEMG1() {
  return String(analogRead(34));
  //return String(1.8 * bme.readTemperature() + 32);
}

String readEMG2() {
  return String(analogRead(35));
}

String readEMG3()  {
  return String(analogRead(32));
}

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  Serial.println();
  
  // Setting the ESP as an access point
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/emg1", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readEMG1().c_str());
  });
  server.on("/emg2", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readEMG2().c_str());
  });
  server.on("/emg3", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readEMG3().c_str());
  });
  
  bool status;


  // Start server
  server.begin();
}
 
void loop(){
  Serial.println(String(analogRead(34)) + " " + String(analogRead(35)) + " " + String(analogRead(32)));
  delay(100);
}
