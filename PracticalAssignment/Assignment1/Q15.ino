//Que:-15 Take only 3 readings of ultrasonic sensor (after trigger) at the intervals of 2 seconds then stop taking further readings. Average the readings and find out if that number is an Armstrong number or not. 


#define echoPin 2
#define trigPin 3 

static int i = 1;
long duration; 
int distance; 
int avgDist = 0;
void setup(){ 
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT); 
  pinMode(echoPin,INPUT); 
}
void loop(){ 
  if(i <= 3){
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    duration=pulseIn(echoPin,HIGH);
    distance=(duration*0.034/2);
    Serial.print("Distance : ");
    Serial.print(distance); 
  Serial.println(" cm ");
  avgDist += distance; 
if(i == 3){
  Serial.print("Average Distance : "); 
  Serial.println(avgDist / 3);
  int originalNum = avgDist / 3;
  int num = avgDist / 3, remainder, result = 0;
  while (originalNum != 0) { 
    remainder = originalNum % 10; 
    result += remainder * remainder * remainder; 
    originalNum /= 10; 
    }
    if (result == num){
      Serial.print(num); Serial.print(" is an Armstrong number.");
      }
      else{ 
        Serial.print(num); Serial.print(" is not an Armstrong number.");
        }
       }
      }
      i++;
      delay(2000);
    }