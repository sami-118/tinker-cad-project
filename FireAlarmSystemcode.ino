float temp;
float vout, vout1;  // Corrected variable declarations

int LED = 13;
int gasSensor;
int piezo = 7;

void setup() {
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(LED, OUTPUT);
    pinMode(piezo, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    vout = analogRead(A1);  // Corrected analogRead argument
    vout1 = (vout * 5000.0) / 1023;  // Convert analog value to millivolts
    temp = (vout1 - 500) / 10;  // Convert millivolts to temperature

    gasSensor = analogRead(A0);

    if (temp >= 80) {
        digitalWrite(LED, HIGH);
    } else {
        digitalWrite(LED, LOW);
    }

    if (gasSensor >= 100) {
        digitalWrite(piezo, HIGH);
    } else {
        digitalWrite(piezo, LOW);
    }

    Serial.print("Temperature (°C) = ");
    Serial.print(temp);
    Serial.print("\tGas Sensor = ");
    Serial.println(gasSensor);

    delay(1000);  // Delay for stability
}
