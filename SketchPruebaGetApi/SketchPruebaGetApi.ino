#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "tu wifi";
const char* password = "tu clave";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando...");
  }
}

void loop() {
    
  if (WiFi.status() == WL_CONNECTED) {
    
    WiFiClient client;
    HTTPClient http;
    String link = "http://nodemcuesp8266test.herokuapp.com/contacto";
    Serial.println("conectado");
    http.begin(client, link);
    int httpCode = http.GET();
      
    Serial.println("GET");
    //En este punto despues de "GET" me muestra -1 tratando de hacer get a mi api local, no asi otras app como arc que si realiza bien el get
    //Con este mismo cogio pero en la api de Gabriel No sucede 
    String payload = http.getString();
    Serial.println(payload);
    Serial.println(httpCode);

    
    
    http.end();

  }
      delay(15000);
}
