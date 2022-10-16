//Que:-8 To interface DHT11 Sensor with Arduino and write a program to print temperature and humidity reading.


#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
void setup()
{
    Serial.begin(9600);
    Serial.println("DHT 11...!");
    dht.begin();
}
void loop()
{
    delay(2000);
    float h= dht.readHumidity();
    float t=dht.readTemperature();
    float f = dht.readTemperature(true);
    if(isnan(h)||isnan(t)||isnan(f))
    {
        Serial.begin(F("Failed to read from DHT 11 Sensor..."));
        return;
    }
    float hf=dht.computeHeatIndex(f,h);
    float hc=dht.computeHeatIndex(f,h,false);

    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("% Temperature : "));
    Serial.print(t);
    Serial.print(F("C"));
    Serial.print(f);
    Serial.print(F("F Heat Index : "));
    Serial.print(hc);
    Serial.print(F("C"));
    Serial.print(hf);
    Serial.print(F("F"));
}