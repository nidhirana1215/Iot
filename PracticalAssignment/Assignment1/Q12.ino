//Que:-12 To interface IR Sensor with Arduino and write a program to print readings of IR sensor


int IRSensor=2;
void setup()
{
    pinMode(IRSensor,INPUT);
    Serial.begin(9600);
}
void loop()
{
    int SensorData=digitalRead(IRSensor);
    Serial.print("Sensor value: ");
    Serial.println(SensorData);
}