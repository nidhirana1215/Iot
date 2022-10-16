//Que:-9 Use DHT 11 and glow the red light if temperature goes above 30’c and play the buzzer and blink the green LED if temperature goes below 30’c and stop the buzzer. 


#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
int led1=3;
int led2=4;
int buzz=5;
void setup()
{
    Serial.begin(9600);
    Serial.println("DHT 11...!");
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
    pinMode(buzz,OUTPUT);
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

    if(t>30)
    {
        digitalWrite(led1,HIGH);
        digitalWrite(buzz,HIGH);
    }
    else
    {
        digitalWrite(led2,HIGH);
        digitalWrite(buzz,LOW);
    }

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