#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include "DHT.h"

//DHT11
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//WiFi
const char* SSID = "NomeWiFI";               
const char* PASSWORD = "SenhaWiFI"; 
const char* Nome = "NomeParaSensor"; 
WiFiClient wifiClient;                        

void setup() { 
  dht.begin();      
  Serial.begin(115200);
  WiFi.begin(SSID, PASSWORD); 
   while (WiFi.status() != WL_CONNECTED) {
      delay(100);
      Serial.print(".");
  }
  
  Serial.println();
  Serial.print("Conectado com sucesso, na rede: ");
  Serial.print(SSID);  
  Serial.print("  IP obtido: ");
  Serial.println(WiFi.localIP()); 
}

void loop() {
  
  float u = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(t) || isnan(u) || t == 2147483647 || u == 2147483647) 
  {
    char json[1024];
    DynamicJsonDocument doc(1024);
    doc["Nome"] = Nome;
    doc["Temperatura"] = 0;
    doc["Unidade"]   = 0;
    serializeJson(doc, json);
    Serial.println(json);
    HTTPClient http;    
    http.begin("http://IP:PORTA/api/Sensors");
    http.addHeader("Content-Type", "application/json");
    int httpCode = http.POST(json);
    http.end(); 
  }else
  {  
    char json[1024];
    DynamicJsonDocument doc(1024);
    doc["Nome"] = Nome;
    doc["Temperatura"] = t;
    doc["umidade"]   = u;
    serializeJson(doc, json);
    Serial.println(json);
    HTTPClient http;    
    http.begin("http://IP:PORTA/api/Sensors");
    http.addHeader("Content-Type", "application/json");
    int httpCode = http.POST(json);
    http.end(); 
  }
  delay(10000);
}