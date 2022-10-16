//Que:-14 To interface Ultrasonic Sensor with Arduino. Use the ultrasonic sensor and extract the distance of object.


int trigpin=3;
int echopin=2;
long duration,cm,inches;

void setup()
{
    Serial.begin(9600);
    pinMode(trigpin,OUTPUT);
    pinMode(echopin,INPUT);
}

void loop()
{
    digitalWrite(trigpin,LOW);
    delayMicroseconds(5);
    digitalWrite(trigpin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin,LOW);
    pinMode(echopin,INPUT);
    duration=pulseIn(echopin,HIGH);
    cm=(duration/2)/29.1;
    inches=(duration/2)/74;
    Serial.print(inches);
    Serial.print("inches , ");
    Serial.print(cm);
    Serial.print("cm");
    Serial.print();
}