int potPin=A0;
int LEDpin=9;
int readValue;
int writeValue;

void setup()
{
  pinMode(potPin,INPUT);
  pinMode(LEDpin,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  readValue=analogRead(potPin);
  writeValue=(255./1023)*readValue;
  analogWrite(LEDpin,writeValue);
  Serial.print("You are writing a value of");
  Serial.println(writeValue);
}
