// Define the tone frequencies for each note
#define T_C 262
#define T_D 294
#define T_E 329
#define T_F 349
#define T_G 392
#define T_A 440
#define T_B 493

// Pin assignments for buttons
const int C = 2;
const int D = 3;
const int E = 4;
const int F = 5;
const int G = 6;
const int A = 7;
const int B = 8;

// Pin assignment for the buzzer
const int Buzz = 9;

void setup()
{
    // Configure all button pins as input with pull-up resistors
    pinMode(C, INPUT);
    digitalWrite(C, HIGH);

    pinMode(D, INPUT);
    digitalWrite(D, HIGH);

    pinMode(E, INPUT);
    digitalWrite(E, HIGH);

    pinMode(F, INPUT);
    digitalWrite(F, HIGH);

    pinMode(G, INPUT);
    digitalWrite(G, HIGH);

    pinMode(A, INPUT);
    digitalWrite(A, HIGH);

    pinMode(B, INPUT);
    digitalWrite(B, HIGH);

    // Configure the buzzer pin as output
    pinMode(Buzz, OUTPUT);
}

void loop()
{
    // Check each button, play the corresponding tone when pressed
    if (digitalRead(C) == LOW)
    {
        tone(Buzz, T_C);
    }
    else if (digitalRead(D) == LOW)
    {
        tone(Buzz, T_D);
    }
    else if (digitalRead(E) == LOW)
    {
        tone(Buzz, T_E);
    }
    else if (digitalRead(F) == LOW)
    {
        tone(Buzz, T_F);
    }
    else if (digitalRead(G) == LOW)
    {
        tone(Buzz, T_G);
    }
    else if (digitalRead(A) == LOW)
    {
        tone(Buzz, T_A);
    }
    else if (digitalRead(B) == LOW)
    {
        tone(Buzz, T_B);
    }
    else
    {
        // Turn off the buzzer when no button is pressed
        noTone(Buzz);
    }
}