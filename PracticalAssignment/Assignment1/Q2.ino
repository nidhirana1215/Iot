//Que:-2 To interface LED with ESP32(Node MCU-8266) and write a program to turn ON/OFF LED light at interval of every 1 Sec.

int led=D2;
void setup()
{
    pinMode(led,OUTPUT);
}
void loop()
{
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    delay(1000);
}