//Que:-4 To interface BUZZER and write a program to turn ON/OFF Buzzer.

int buzz=3;

void setup()
{
    pinMode(led,HIGH);
}
void loop()
{
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    delay(1000);
}