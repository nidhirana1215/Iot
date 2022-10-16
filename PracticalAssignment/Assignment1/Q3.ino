//Que:-3 To interface 2 LED with different colour and write a program to turn ON/OFF LED light at a same time. 

int led1=6;
int led2=7;
void setup()
{
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
}
void loop()
{
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    delay(1000);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    delay(1000);
}