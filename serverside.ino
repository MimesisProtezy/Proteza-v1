/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-client-server-wi-fi/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

#include <WiFi.h>
#include <ESPAsyncWebServer.h>

#include <Wire.h>

// Set your access point network credentials
const char* ssid = "ESP32-Access-Point";
const char* password = "put-your-pswd-here";

itn emg1val, emg2val, emg3val;

AsyncWebServer server(80);

String readEMG1() 
{
  emg1val = 0;
  for(int i = 0; i <= 20; i++)
    emg1val += analogRead(34);
  emg1val /= 20;
  return String(emg1val);
}

String readEMG2() 
{
  emg2val = 0;
  for(int i = 0; i <= 20; i++)
    emg2val += analogRead(35);
  emg2val /= 20;
  return String(emg2val);
}

String readEMG3()  
{
  emg3val = 0;
  for(int i = 0; i <= 20; i++)
    emg3val += analogRead(32);
  emg3val /= 20;
  return String(emg3val);
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
