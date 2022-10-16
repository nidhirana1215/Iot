//Que:-13 To interface IR Sensor with Arduino and write a program to blink red or white LED. If the Transmitter transmit and Photodiode receives the rays then glow White LED else glow Red LED/play the buzzer.

int IRSensor=2;
int led1=3;
int led2=4;
int buzz=5;
void setup()
{
    pinMode(IRSensor,INPUT);
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
    pinMode(buzz,OUTPUT);
    Serial.begin(9600);
}
void loop()
{
    int SensorData=digitalRead(IRSensor);
    Serial.print("Sensor value: ");
    Serial.println(SensorData);
    if(SensorData==1)
    {
        digitalWrite(led1,HIGH);
        digitalWrite(led2,LOW);
        digitalWrite(buzz,LOW);
    }
    else
    {
        digitalWrite(led1,LOW);
        digitalWrite(led2,HIGH);
        digitalWrite(buzz,HIGH);
    }
}