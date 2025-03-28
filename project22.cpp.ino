#include <avr/io.h>
#include <util/delay.h>

const int sensorPin = A1;
const int redPin = 0, greenPin = 1, bluePin = 2;
float temp;

bool yellow[] = {1, 1, 0}, red[] = {1, 0, 0}, green[] = {0, 1, 0}, blue[] = {0, 0, 1}, 
     white[] = {1, 1, 1}, cyan[] = {0, 1, 1}, off[] = {0, 0, 0};

void setup() {
    pinMode(redPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(greenPin, OUTPUT);
}

void loop() {
    readSensor();
    colorConditions();
    _delay_ms(1000);  // ATtiny85 does not support delay() like Arduino
}

void readSensor() {
    int sensor = analogRead(sensorPin);
    float voltage = sensor * (3.3 / 1024.0); // ATtiny85 runs on 3.3V or 5V
    temp = (voltage - 0.5) * 100.0;  // TMP36 formula
}

void colorConditions() {
    if(temp <= 9) ledControlBlink(white);
    if(temp >= 35) ledControlBlink(red);
    if(temp >= 10 && temp < 14.0) ledControl(white);
    if(temp >= 15.0 && temp < 20.0) ledControl(cyan);
    if(temp >= 21 && temp <= 24) ledControl(green);
    if(temp >= 25 && temp <= 29) ledControl(yellow);
    if(temp >= 30) ledControl(red);
}

void ledControl(bool color[]) {
    digitalWrite(redPin, color[0]);
    digitalWrite(greenPin, color[1]);
    digitalWrite(bluePin, color[2]);
}

void ledControlBlink(bool color[]) {
    ledControl(color);
    _delay_ms(500);
    ledControl(off);
    _delay_ms(500);
}
