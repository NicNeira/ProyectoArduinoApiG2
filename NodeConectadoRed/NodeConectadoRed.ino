/*Programa DHT11_Nodemcu_WLAN Version 1
 * FUNCIONO SATISFACTORIAMENTE-
 * LA PAGINA NO REFESCA SOLA - USE F5
 *
 * Envia por red a una pagina de INTRANET los datos del DHT11
 * Sketchup sobre DHT11 tomada de Robo India Tutorial portal
 * Adaptada Prof: Bolaños 19-5-19
 * Este programa muestra temperatura y humedad mediante DHT11
 * Funciona con la libreria DHT.h contenida en esta carpeta del
 * programa.
 * El PIN del Nodemcu es el D3
 *
 */
#include "DHT.h" // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11 // DHT 11
#define dht_dpin 0
DHT dht(dht_dpin, DHTTYPE);
/*PARA QUE APAREZCA LA IP SE DEBE RESETEAR Y EL MONITOR
 * SERIE DEBE ESTAR EN LA MISMA VELOCIDAD*/
#include <ESP8266WiFi.h>

const char* ssid = "Pebre";
const char* password = "Olivia957";

int LED = 16; // led connected to D0
WiFiServer server(80);
void setup(void)
{
 dht.begin(); //Inicializamos el sensor

Serial.begin(115200);


 Serial.print("Conectando a red DJB ");
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED)
 {
 delay(500);
 Serial.print(".");
 }
 Serial.println("WiFi conectada");

 /*-------- server started---------*/
 server.begin();
 Serial.println("Server started");

 /*------printing ip address--------*/
 Serial.print("IP en la red DJB: ");
 Serial.println(WiFi.localIP());
 Serial.print("Copie en su navegador URL: https://");
 Serial.print(WiFi.localIP());
 Serial.println("/");
}
void loop()
{

//***********************************************
//Seccion fundamental para atender al cliente
//Copiela exactamente en su programa-------------

 WiFiClient client = server.available();
 if (!client)
 {
 return;
 }
 Serial.println("Esperando nuevo cliente");
 while(!client.available())
 {
 delay(1);
 }

 String request = client.readStringUntil('\r');
 Serial.println(request);
 client.flush(); 
 //Fin Seccion fundamental para atender al cliente
 //Debio haberla copiado en su programa----------
 //**********************************************

 //----------------------------------------------
 //Definimos variables tipo float para lectura
 //de temperatura y humedad y realizamos la lectura

 float h = dht.readHumidity();
 float t = dht.readTemperature();
//-----------------------------------------------
//---Creacion de la pagina html-----------------
 client.println("HTTP/1.1 200 OK");
 client.println("Content-Type: text/html");
 client.println("");
 client.println("<!DOCTYPE HTML>");

 client.println("<html>");

 client.print("Temperatura : ");
 client.print(t);
 client.print(" C ");
 client.print("Humedad : ");
 client.print(h);
 client.print(" % ");
 client.println("</html>");
//--Fin de la pagina html---------------------
/*Esta pagina la podra ver en el navegador
 * mediante la direccion IP que se le asigno a
 * la placa Nodemcu su router
 * refresque la pagina con F5
 */

 delay(800);
} 
