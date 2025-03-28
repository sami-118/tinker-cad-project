int buttonState=0;
const int buttonPin=2;
int ledOne=13;
int ledTwo=12;
int ledThree=8;

void setup()
{
  pinMode(ledOne,OUTPUT);
  pinMode(ledTwo,OUTPUT);
  pinMode(ledThree,OUTPUT);
  pinMode(buttonPin,INPUT);
  Serial.begin(9600);
}

void loop()
{
  buttonState=digitalRead(buttonPin);
  if(buttonState==1)
  {
  	digitalWrite(ledOne,1);
    Serial.print("Stop\n");
    delay(2000);
    digitalWrite(ledOne,0);
    delay(500);
    digitalWrite(ledTwo,1);
    Serial.print("Get Ready\n");
    delay(2000);
    digitalWrite(ledTwo,0);
    delay(500);
    digitalWrite(ledThree,1);
    Serial.print("Bye\n");
    delay(2000);
    digitalWrite(ledThree,0);
  }
}
  
  
  
  
  