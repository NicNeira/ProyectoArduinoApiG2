

/*Sketchup tomada de Robo India Tutorial portal
 * Adaptada Prof: Bolanos 19-5-19
 * Este programa muestra temperatura y humedad mediante DHT11
 * Funciona con la libreria DHT.h contenida en esta carpeta del
 * programa.
 * El PIN del Nodemcu es el D4
 *
 4
 */
#include <DHT.h>// including the library of DHT11
#include <DHT_U.h>
#define DHTTYPE DHT11 // DHT 11 sensor usado
#define dht_dpin 0
DHT dht(dht_dpin, DHTTYPE);
void setup(void)
{
 dht.begin();
 Serial.begin(9600);
 Serial.println("\n");
 Serial.println("****************************************\n");

 Serial.println("Humedad y temperatura con DHT11 \n\n");
 Serial.println("****************************************\n");

 //delay();//tiempo para mostrar el mensaje anterior
}
void loop() {
 float h = dht.readHumidity();
 float t = dht.readTemperature();
 Serial.print("Humedad = ");
 Serial.print(h);
 Serial.print(" % ");
 Serial.print("Temperatura = ");
 Serial.print(t);
 Serial.println(" C ");
 Serial.println();
 Serial.println("------------------------------------------");

 delay(5000);
}
