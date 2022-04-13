#include<Servo.h>
#define trig D1 //d1
#define echo D2 //d2
#define buzz D7
#define srv D4
int dt=10;   //delay_time
Servo servo;

#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701
long duration;
float distanceCm;
float distanceInch;


//int distance,duration;
void setup() 
{
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzz,OUTPUT);
  Serial.begin(9600);
  servo.attach(srv); //d4
}
  
void loop() 
{
  if (calc_dis()>10)
  {
    digitalWrite(buzz,LOW);
    for (int i=0;i<=180;i+=5)
    
    {
      servo.write(i);
      
      calc_dis();
    }
    delay(1000);
    for (int i=180;i>=0;i-=5)
    {
      servo.write(i);
      
      calc_dis();
    
    }
    delay(1000);
  }
  else{
    digitalWrite(buzz,HIGH);
  }
}
//This code is written to calculate the DISTANCE using ULTRASONIC SENSOR



int calc_dis()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  // Sets the trig on HIGH state for 10 micro seconds
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  // Reads the echo, returns the sound wave travel time in microseconds
  duration = pulseIn(echo, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_VELOCITY/2;
  
  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);    
  delay(100);
  return distanceCm;
}
