//Que:-2 To interface LCD with Arduino and write a program to Display your name on LCD.

#include<LiquidCrystal.h>
const int rs=12,en=11,d4=4,d5=5,d6=6,d7=7;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
void setup() {
 lcd.begin(16,2);
 lcd.setCursor(0,0);
 lcd.print("Hello ! world");

}

void loop() {

}
