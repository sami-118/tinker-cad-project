#include <Keypad.h>

// Define the keypad size
const byte row = 4;
const byte col = 4;

// Define the pin connections for LEDs and buzzer
const int redLed = 10;
const int greenLed = 11;
const int piezo = 12;

// Define the keypad layout
char numPad[row][col] = {
    {'1', '2', '3', '4'},
    {'5', '6', '7', '8'},
    {'9', '0', '*', '#'},
};

// Define the row and column pins
byte rowPin[row] = {9, 8, 7, 6};
byte colPin[col] = {5, 4, 3, 2};

// Define the correct passcode
String password = "6556";
String vstup = "";

// Initialize the keypad
Keypad cKeypad = Keypad(makeKeymap(numPad), rowPin, colPin, row, col);

void setup() {
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(piezo, OUTPUT);
    
    digitalWrite(redLed, HIGH); // Start with red LED ON
    digitalWrite(greenLed, LOW); // Start with green LED OFF

    Serial.begin(9600);
    Serial.print("Enter Passcode: ");
}

void loop() {
    char cKey = cKeypad.getKey(); // Read the pressed key from the keypad

    if (cKey) {
        if (vstup.length() < 4) {
            Serial.print("*"); // Hide actual input for security
            vstup += cKey;
        }
    }

    if (vstup.length() == 4) {
        delay(1500); // Wait for input completion

        if (password == vstup) { // If entered passcode is correct
            Serial.println("\nAccess Granted");
            digitalWrite(redLed, LOW);
            digitalWrite(greenLed, HIGH);
            tone(piezo, 500);
            delay(100);
            noTone(piezo);
        } else { // If entered passcode is incorrect
            Serial.println("\nWrong Passcode");
            digitalWrite(redLed, HIGH);
            digitalWrite(greenLed, LOW);
            tone(piezo, 1000);
            delay(800);
            noTone(piezo);
        }

        delay(1500); // Wait before resetting
        vstup = ""; // Reset the input buffer
        Serial.println("Enter Passcode: ");
        digitalWrite(redLed, HIGH);
        digitalWrite(greenLed, LOW);
    }
}

