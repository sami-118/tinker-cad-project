// include the library code:

#include <LiquidCrystal.h>

#include<Servo.h> //Library for the servo motor

Servo S1, S2; //Object of type servo

#define IR Slotl 7 //Define pins

#define IR Slot2 8

#define IR_entry 6

#define IR exit 13

int pos=0; //Initial Position of servo motor

// initialize the library with the numbers of the interface pin

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

Sl.attach(10);

//Servo 1 on 10 pin

S2.attach (9); //Servo 2 on 9 pin

Sl.write(pos); //Inital position at 0 for both motors

s2.write(pos);

pinMode (IR_Slotl, INPUT);

pinMode (IB_Slot2, INPUT)

pinMode (IR_entry, INPUT);

pinMode (IR_exit, INPUT);

lcd.begin (16, 2); 

// Print a message to the LCD.

lcd.print(" Smart Parking");

lcd.setCursor(0, 1);

//Set cursor to column 1, row 2

led.print(" System");

delay (2000);

//Clear the Icd screen

lcd.clear();

lcd.setCursor(0, 0);

Bet cursor to column I row 0

led.print("Slot 1 = A");

lcd.setCursor(0, 1);

//Set cursor to column 1, row 1

lcd.print("Slot 2 = A");

delay (2000);
}

void loop()

{

if (digitalRead(IR_Slot1)==HIGH)

{

lcd.setCursor(0, 0);

lcd.print("Slot 1 = NA");

}

else

{

lcd.setCursor(0, 0);

lcd.print("Slot 1 = A");

}

if (digitalRead(IR_Slot2)==HIGH)

{

lcd.setCursor(0, 1);

lcd.print("Slot 2 = NA");

}

else

{

lcd.setCursor(0, 1);
lcd.print("Slot 2= A")
}
if(digitalRead(IR_entry)==HIGH)
{
S1.write(pos+90);
}
else
{
  S1.write(pos)
}
if(digitalRead(IR_exit)==HIGH) 
{
 S2.write(pos+90);
}
else
{
  S2.write(pos);
}
}