//Que:-6 Write a program to play a melody using buzzer.

#include "pitches.h"
int buzz=8;
int melody[]={
    NOTE_C4,NOTE_G3,NOTE_G3,NOTE_A3,NOTE_G3,0,NOTE_B3,NOTE_C4;
}
int noteDuration[]={
    4,8,8,4,4,4,4,4;
}
void setup()
{
    pinMode(buzz,OUTPUT);
}
void loop()
{
    for(int i=0;i<8;i++)
    {
        int noteDuration=1000/noteDuration[i];
        tone(buzz,melody[i],noteDuration);
        int pauseBetweenNotes=noteDuration * 1.30;
        delay(pauseBetweenNotes);
        noTone(buzz);
    }
}