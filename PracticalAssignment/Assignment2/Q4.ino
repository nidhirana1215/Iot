//Que:-4 Take only 3 readings of ultrasonic sensor (after trigger) at the intervals of 2 seconds then stop taking further readings. Average the readings and find out if that number is palindrome number or not. And display the output in LCD.

#include<LiquidCrystal.h>
#include<Mouse.h>
const int rs=5,en=6,d4=7,d5=8,d6=9,d7=10;
const int trigpin=12;
const int echopin=13;
long duration;
int distance;
String res="";
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
void setup() {

    pinMode(trigpin,OUTPUT);  
    pinMode(echopin,INPUT);  
    Serial.begin(9600);
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    palindrome();
    lcd.print(res);
   
}

void palindrome(){
        int sum=0;
        float avg=0.0;
        for(int i=0;i<3;i++){
              digitalWrite(trigpin,HIGH);  
              delayMicroseconds(2000);  
              digitalWrite(trigpin,LOW);  
              duration=pulseIn(echopin,HIGH);  
              distance = duration*0.034/2;  
              Serial.println(distance);
              sum+=distance;
        }
        Serial.println(sum);
        avg=sum/3;
        int n=avg,r=0,newn=0;
        while(n!=0){
            r=n%10;
            newn=newn*10+r;
            n/=10;
        }
        if(newn==avg){
          res="Palindrome";
        }
        else{
          res="Not Palindrome";
        }
  
    
}
void loop() {

}
