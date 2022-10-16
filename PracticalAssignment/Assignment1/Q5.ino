//Que:-5 To interface 2 LED with different colour and write a program to turn ON/OFF LED light on after another, which works light police Van Light. And also play the buzzer of police van or ambulance.

int led1=3;
int led2=4;
int buzz=5;

void setup()
{
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
    pinMode(buzz,OUTPUT);
}
void loop()
{
    digitalWrite(led1,High);
    digitalWrite(led2,LOW);
    digitalWrite(buzz,HIGH);
    delay(500);
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(buzz,LOW);
    delay(500);
}