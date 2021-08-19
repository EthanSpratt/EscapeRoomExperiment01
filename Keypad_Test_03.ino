#include "Arduino.h"
#include "Keypad.h"
#include <LiquidCrystal.h>
#include "string.h"
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

const String password = "9819";
String Input[4]="";

LiquidCrystal lcd(12, 11, 14, 15, 16, 17);
int LCD_POS = 0;
void setup(){
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  Serial.println("Press Any Key");
  lcd.print("Press Any Key");
}
   
void loop(){
  lcd.setCursor(LCD_POS,1);
  char key = keypad.getKey();
   
  if (key != NO_KEY){
    Serial.println(key);
    strcat(Input, key);
    Serial.println(Input);   
    lcd.print(Input);
    if(strlen(Input) == 4)
    {
      if(strcmp(Input) == password)
      {
        lcd.clear();
        lcd.print("SUCCESS");
      }
      else
      {
        lcd.clear();
        lcd.print("FAILURE");
      }
    }  
    
  }
}
