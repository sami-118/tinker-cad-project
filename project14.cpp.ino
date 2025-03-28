#include <Servo.h>

// Define pins
#define trigPin 9
#define echoPin 10
#define  servoPin 6

Servo myServo;

float duration,distance;

void setup() {
    myServo.attach(9);
  	Serial.begin(9600);
  	pinMode(trigPin,OUTPUT);
  	pinMode(echoPin,OUTPUT);
}


void loop() {
    digitalWrite(trigPin,LOW);
  	delayMicroseconds(2);
  	digitalWrite(trigPin,HIGH);
  	delayMicroseconds(10);
  	digitalWrite(trigPin,LOW);
    
  	duration =pulseIn(echoPin,HIGH);
  	distance=(duration/2)*0.0343;
  	Serial.print("Distance= ");
  
    if (distance >=4 || distance<=2) {
        Serial.println("Out of range");
    	} 
  	else {
        myServo.attach(9);
        myServo.write(90);
      	delay(1000);
      	myServo.write(180);
      	delay(1000);
      	myServo.write(90);
    
    	Serial.print(distance);
  		Serial.print("cm");
    	delay(500);
}
delay(500);
myServo.detach();    
}