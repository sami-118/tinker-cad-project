//volt 3-6
//remove rmarks if u r using cc 7-seg dosplay
#define segDISPLAY CAATHODE
#define d250 delay(250);
const int buttonPin=0;
const int ledPin=1;//common pin
//pin 11 of 74HC595(SHCP)
const int clockPin=2;
//pin 12 of 74HC595(STCP)
const int latchkPin=3;
//pin 14 of 74HC595(DS)
const int datakPin=4;
//digit pattern for 7seg display
const byte digit[] =
{
    //Dgfedcba
    B00111111, // 0
    B00000110, // 1
    B01011011, // 2
    B01001111, // 3
    B01100110, // 4
    B01101101, // 5
    B01111101, // 6
    B00000000, // OFF
}
void setup() {

    pinMode (dataPin, OUTPUT);
    
    pinMode (clockPin, OUTPUT);
    
    pinMode (latchPin, OUTPUT);
    
    pinMode (buttonPin, INPUT);
    
    pinMode (ledPin, OUTPUT);
    
    #ifdef segDISPLAY
    
    digitalWrite(ledPin, LOW);
    
    #else
    
    digitalWrite(ledPin, HIGH);
    
    #endif
    
    LEDwrite (8); delay(1000);
    
    LEDwrite (7); d250;
    
    LEDwrite(0);
    
    }
    
    void LEDwrite(int data) {

        // turn off the output of 74HC595
        
        digitalWrite(latchPin, LOW);
        
        // update data to output from 74HC595
        
        #ifdef segDISPLAY
        
        // It's a CA LED invert num
        
        shiftout (dataPin, clockPin, MSBFIRST, digit (data));
        
        #else
        
        // It's a CC LED
        
        shiftout (dataPin, clockPin, MSBFIRST, digit [data]);
        
        #endif
        
        // turn on the output of 74HC595
        
        digitalWrite(latchPin, HIGH);
    }
    int RND() {

        int seed= 0;
        
        int digit = 0;
        
        while (digit > 6 || digit <= 0) {
        
        seed (seed 53) + 21;
        
        digit seed & 6;
        
        randomSeed (analogRead (PB5));
        
        seed random (50) + digit;
        
        digit += seed;
        
        }
        
        return digit;
        
        }
        
        void rollDice (int times) {
        
        for (int i = 0; i < times; i++) {
        
        LEDwrite(1); d250;
        
        LEDwrite (2); d250;
        
        LEDwrite (3); d250;
        
        LEDwrite (4); d250;
        
        LEDwrite (5); d250;
        
        LEDwrite (6); d250;
        
        LEDwrite (5); d250;
        
        LEDwrite (4); d250;
        
        LEDwrite (3); d250;
        
        LEDwrite (2); d250;
        
        LEDwrite(1); d250;
        
        }
        
        }
        
                
                void loop() {
                
                int btn = 0;
                
                btn = digitalRead (buttonPin);
                
                if (btn == HIGH) {
                
                LEDwrite (7); d250;
                
                int digit = RND();
                
                rollDice (2);
                
                LEDwrite (7); d250;
                
                if (digit == 1) LEDWrite(1);
                
                if (digit == 2) LEDwrite(2);
                
                if (digit == 3) LEDwrite(3);
                
                if (digit == 4) LEDwrite(4);
                
                if (digit == 5) LEDwrite(5);
                
                if (digit == 6) LEDwrite(6);
                
                }
                
                }
            

