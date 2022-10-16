//Que:-11 Write a Program to read five values of temperature and calculate the average of readings. Run the loop up to the average values of temperature and print the Fibonacci series up to the average temperature value.

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
int f=0;
int temp=0;
void setup()
{
    Serial.begin(9600);
    Serial.println("DHT 11...!");
    dht.begin();
    avgTempreture();
}
void loop()
{
}
void primeTempreture()
{
    delay(2000);
    float h= dht.readHumidity();
    float t=dht.readTemperature();
    float f = dht.readTemperature(true);
    if(isnan(h)||isnan(t)||isnan(f))
    {
        Serial.begin(F("Failed to read from DHT 11 Sensor..."));
    }
    else
    {
        int sum=0,i,j;
        float avg=0.0;
        int h[5];
        for(int i=0;i<5;i++)
        {
            h[i]=(int)dht.readTemperature();
            sum +=(int)h[i];
        }
        avg=sum/5;
        Serial.print("Average of Tempreture");
        Serial.print(avg);
        for(i=0;i<4;i++)
        {
            for(j=i+1;j<5;j++)
            {
                if(h[i]>h[j])
                {
                    temp=h[i];
                    h[i]=h[j];
                    h[j]=temp;
                }
            }
        }
        for(int i=0;i<5;i++)
        {
            Serial.println(h[i]);
        }
    }  
}
void avgHumidity()
{
    int sum=0;
    float avg=0.0;
    for(int i=0;i<10;i++)
    {
        float h=dht.readHumidity();
        sum+=(int)h;
    }
    avg=sum/10;
    Serial.println("\n Average of Humidity ");
    Serial.print(avg);
}