//Que:-7 To interface PULLUP BUTTON with Arduino. write a program to turn ON/OFF as per the button pullup.

const int buttonpin=2;
const int ledpin=3;
int buttonstate=0;
void setup()
{
    pinMode(ledpin,OUTPUT);
    pinMode(buttonpin,INPUT);
}
void loop()
{
    buttonstate=digitalRead(buttonpin);
    if(buttonstate==HIGH)
    {
        digitalWrite(ledpin,HIGH);
    }
    else
    {
        digitalWrite(ledpin,LOW);
    }
}
