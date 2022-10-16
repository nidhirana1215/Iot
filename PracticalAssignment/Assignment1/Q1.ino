//Que:-1 To interface LED with Arduino and write a program to turn ON/OFF LED light at interval of every 1 Sec.


int led=5;
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