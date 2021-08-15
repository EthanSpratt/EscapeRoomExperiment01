#include "Arduino.h"
#include "Keypad.h"
#include <LiquidCrystal.h>
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {5, 6, 7, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {2, 3, 4}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

LiquidCrystal lcd(12, 11, 14, 15, 16, 17);
void setup(){
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  Serial.println("Press Any Key");
  lcd.print("Press Any Key");
}
   
void loop(){
  lcd.setCursor(0,1);
  char key = keypad.getKey();
   
  if (key != NO_KEY){
    Serial.println(key);
    lcd.print(key);
  }
}
