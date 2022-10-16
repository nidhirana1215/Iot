//Que:-10 Write a Program to read three values of temperature and 10 values of humidity. Perform Addition of three temperature readings and print the number is odd or even. Calculate the average of 10 humidity readings.


#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
int f=0;
void setup()
{
    Serial.begin(9600);
    Serial.println("DHT 11...!");
    dht.begin();
    primeTempreture();
    avgHumidity();
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
        int sum=0;
        for(int i=0;i<3;i++)
        {
            float t=dht.readTemperature();
            sum +=(int)t;
        }
        Serial.print("Sum of Tempreture");
        Serial.print(sum);
        for(int i=2;i<sum/2;i++)
        {
            if(sum%2==0)
            {
                f=0;
            }
            else
            {
                f=1;
            }
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

#include <SimpleDHT.h>
int pinDHT11 = 3; 
SimpleDHT11 dht11(pinDHT11);
static int i = 1;
int sumOfTemprature = 0; 
int sumOfHumidity = 0;
void setup() {
  Serial.begin(9600);
  Serial.println("-----------Temprature (Celcius) Humidity ------------"); 
 }
  void loop() { 
}
byte temperature = 0;
byte humidity = 0;
int err = SimpleDHTErrSuccess;
if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
  Serial.print("Read DHT11 failed, err=");
  Serial.print(SimpleDHTErrCode(err)); 
  Serial.print(",");
  Serial.println(SimpleDHTErrDuration(err));
  delay(1000); 
  return;
 }
  if(i <= 3)
  { sumOfTemprature += (int)temperature; if(i == 3){ 
    Serial.print("Sum of first three temprature is "); 
    Serial.println(sumOfTemprature); 
    }
   
   else if(i <= 5)
   { 
      sumOfHumidity += (int)humidity; if(i == 5){
        Serial.print("Average of first five humidity is "); 
        Serial.println(sumOfHumidity / 5); 
        } 
       }
       i++;
        delay(1500);
       }