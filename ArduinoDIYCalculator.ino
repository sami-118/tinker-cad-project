#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

long first = 0;
long second = 0;
double total = 0;
char customKey;

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
    {'1', '2', '3', '+'},
    {'4', '5', '6', '-'},
    {'7', '8', '9', '*'},
    {'C', '0', '=', '/'}
};

byte rowPins[ROWS] = {7, 6, 5, 4};  // Row pin connections
byte colPins[COLS] = {3, 2, 1, 0};  // Column pin connections

Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
    lcd.begin(16, 2);  // Start LCD
    lcd.setCursor(0, 0);
    lcd.print("Calculator");
    lcd.setCursor(0, 1);
    lcd.print("Enter numbers");
    delay(4000);
    lcd.clear();
    lcd.setCursor(0, 0);
}

void loop() {
    customKey = customKeypad.getKey();

    switch (customKey) {
        case '0' ... '9':  // Collect the first value
            lcd.setCursor(0, 0);
            first = first * 10 + (customKey - '0');
            lcd.print(first);
            break;

        case '+':
        case '-':
        case '*':
        case '/':
            first = (total != 0 ? total : first);
            lcd.setCursor(0, 1);
            lcd.print(customKey);
            second = SecondNumber();
            
            if (customKey == '+') total = first + second;
            if (customKey == '-') total = first - second;
            if (customKey == '*') total = first * second;
            if (customKey == '/') {
                if (second == 0) {
                    lcd.setCursor(0, 3);
                    lcd.print("Invalid");
                    break;
                } else {
                    total = (float)first / second;
                }
            }

            lcd.setCursor(0, 3);
            lcd.print(total);
            first = 0;
            second = 0;
            break;

        case 'C':  // Clear everything
            total = 0;
            first = 0;
            second = 0;
            lcd.clear();
            break;
    }
}

long SecondNumber() {
    long secondNum = 0;
    while (1) {
        customKey = customKeypad.getKey();
        if (customKey >= '0' && customKey <= '9') {
            secondNum = secondNum * 10 + (customKey - '0');
            lcd.setCursor(7, 0);
            lcd.print(secondNum);
        }
        if (customKey == '=') break;
    }
    return secondNum;
}
