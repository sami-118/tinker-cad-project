int trigpin=10;
int echopin =9;
long time;
int distance;

void settup()
{
  pinMode(10,OUTPUT);
  pinMode(9,INPUT);
  Seria.begin(9600);
  }

void loop()
{
  digitalWrite(10,LOW);
  delayMicroseconds(2);

  digitalWrite(10,HIGH);
  delayMicroseconds(10);

  digitalWrite(10,LOW);
  time=pilseIn(9,HIGH);
  distance=time*0.032/2;

  Serial.print("distance: ");
  serial.println(distance);
}




