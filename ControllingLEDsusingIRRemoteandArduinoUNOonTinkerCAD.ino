#include <IRremote.h>

int IR_Recv = 12;       // IR Receiver Pin 3
int bluePin = 2;
int orangePin = 3;
int greenPin = 4;

IRrecv irrecv(IR_Recv);
decode_results results;

void setup(){
    Serial.begin(9600);    // starts serial communication
    irrecv.enableIRIn();   // Starts the receiver
    pinMode(2, OUTPUT);    // sets the digital pin as output
    pinMode(3, OUTPUT);    // sets the digital pin as output
    pinMode(4, OUTPUT);    // sets the digital pin as output
}

void loop(){
    // decodes the infrared input
    if (irrecv.decode(&results)){
        long int deCode = results.value;
        Serial.println(results.value);
        
        // switch case to use the selected remote control button
        switch (results.value){
            case 16582903:  // when you press the 1 button
                digitalWrite(2, HIGH);
                break;
            case 16615543:  // when you press the 2 button
                digitalWrite(2, LOW);
                break;
            case 16623703:  // when you press the 3 button
                digitalWrite(3, HIGH);
                break;
            case 16607383:  // when you press the 4 button
                digitalWrite(3, LOW);
                break;
            case 16599223:  // when you press the 5 button
                digitalWrite(4, HIGH);
                break;
            case 16591063:  // when you press the 6 button
                digitalWrite(4, LOW);
                break;
        }
        irrecv.resume(); // Receive the next value
    }
}

