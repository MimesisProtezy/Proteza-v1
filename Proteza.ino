/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-client-server-wi-fi/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/


#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "ESP32-Access-Point";
const char* password = "put-your-pswd-here";

//Your IP address or domain name with URL path
const char* serverNameemg1 = "http://192.168.4.1/emg1";
const char* serverNameemg2 = "http://192.168.4.1/emg2";
const char* serverNameemg3 = "http://192.168.4.1/emg3";

#include <Wire.h>


String EMG1;
String EMG2;
String EMG3;

unsigned long previousMillis = 0;
const long interval = 5; 

#include <ESP32Servo.h>

Servo pinring, middle, ind, thumb;

int pos = 0, thumb_pos = 0;

int emg1min = 4095, emg2min = 4095, emg3min = 4095, emg1max = 0, emg2max = 0, emg3max = 0;
int emg1val, emg2val, emg3val;

#include <string>

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  pinring.attach(21);
  middle.attach(22);
  ind.attach(18);
  thumb.attach(19);
}

void loop() {
  unsigned long currentMillis = millis();
  
  if(currentMillis - previousMillis >= interval) {
     // Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED ){ 
      EMG1 = httpGETRequest(serverNameemg1);
      EMG2 = httpGETRequest(serverNameemg2);
      EMG3 = httpGETRequest(serverNameemg3);
      Serial.println("emg1: " + EMG1 + " emg2:" + EMG2 + " emg3:" + EMG3);
  
      
      // save the last HTTP GET Request
      previousMillis = currentMillis;
    }
    else {
      Serial.println("WiFi Disconnected");
    }
  }

  emg1val = atoi(EMG1.c_str()); emg2val = atoi(EMG2.c_str()); emg3val = atoi(EMG3.c_str());
  
  
  if(emg1val < emg1min)  emg1min = emg1val;
  if(emg1val > emg1max)  emg1max = emg1val;
  if(emg2val < emg2min)  emg2min = emg2val;
  if(emg2val > emg2max)  emg2max = emg2val;
  if(emg3val < emg3min)  emg3min = emg3val;
  if(emg3val > emg3max)  emg3max = emg3val;

  if(emg2val > (emg2min+emg2max)/6) pos+=2;
  else pos-=2;
  
  if(pos < 0) pos = 0;
  else if(pos > 180) 
  {
  pos = 180;
  }
  else if(pos > 40)  thumb_pos = pos - 40;

  Serial.println(pos);
  Serial.println(thumb_pos);
  
  pinring.write(180-pos);
  delay(10);
  middle.write(pos);
  delay(10);
  ind.write(pos);
  delay(10);
  thumb.write(thumb_pos);
  delay(10); 
}

String httpGETRequest(const char* serverName) {
  HTTPClient http;
    
  // Your IP address with path or Domain name with URL path 
  http.begin(serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "--"; 
  
  if (httpResponseCode>0) {
    //Serial.print("HTTP Response code: ");
    //Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }

  // Free resources
  http.end();

  return payload;
}
