

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
