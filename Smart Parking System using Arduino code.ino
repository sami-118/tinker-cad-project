int pot = A5;

int value = 0;

int led1 = 13;

int led2 = 12;

int led3 = 11;

int led4 = 10;

int led5 = 9;

int led6 = 8;

void setup()

{

Serial.begin(9600);

pinMode (led1, OUTPUT);

pinMode(led2, OUTPUT);

pinMode (led3, OUTPUT);

pinMode (led4, OUTPUT);

pinMode (led5, OUTPUT);

pinMode (led6, OUTPUTI);
pinMode (pot, INPUT);
}
void loop(){
value = analogRead(pot);

Serial.println(value);

delay(400);

if(value==0)

{

digitalWrite(13, 0);

digitalWrite(12, 0);

}

else if (value>0 && value<=250)

{

digitalWrite(led1, HIGH);

digitalWrite(led2, HIGH);
digitalWrite(led3, 0);
digitalWrite(led4, 0);

}
else if (value>=251&&value<=500){

digitalWrite(led3, HIGH);


digitalWrite(led4, HIGH);

digitalWrite(led5, 0);


digitalWrite(led6, 0);
}
else if (value>=501){
digitalWrite(led5, HIGH);
digitalWrite(led6, HIGH);
}
}