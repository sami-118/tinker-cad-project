#include <IRremote.h>
#include <Servo.h>

int RECV_PIN = 5;
IRrecv irrecv(RECV_PIN);
decode_results results;
Servo myservo;
int pos = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn();
  Serial.println("Enabled IRin");
  myservo.attach(3);
  myservo.write(pos);
}

void loop() {
  if (irrecv.decode(&results)) {  // Fixed missing parenthesis and added '&' before results
    Serial.println(results.value, DEC);

    if (results.value == 16582903) {  // Fixed typo in 'results'
      myservo.write(45);
      delay(1000);
    } 
    else if (results.value == 16615543) {  // Fixed typo in 'results'
      myservo.write(90);
      delay(1000);
    } 
    else if (results.value == 16591063) {  // Fixed typo in 'results'
      myservo.write(180);
      delay(2000);
    }
    
    myservo.write(0);
    irrecv.resume();  // Fixed 'irrev' to 'irrecv'
    delay(100);
  }
}
