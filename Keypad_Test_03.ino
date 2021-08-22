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

char password [5] = "9819";
char inputstr[5];

LiquidCrystal lcd(12, 11, 14, 15, 16, 17);
int LCD_POS = 0;
void setup(){
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.cursor();
  lcd.setCursor(0, 0);
  Serial.println("Press Any Key");
  lcd.print("Enter Password");
}
   
void loop(){
  lcd.setCursor(LCD_POS,1);
  char key = keypad.getKey();
  char keystr[2] = " ";
   
  if (key != NO_KEY){
    Serial.println(key);
    keystr[0] = key;
    strcat(inputstr, keystr);
    Serial.println(inputstr);   
    lcd.print(inputstr);
    
    if(strlen(inputstr) == 4)
    {
      if(strcmp(inputstr, password) == 0)
      {
        lcd.clear();
        lcd.print("SUCCESS");
        inputstr[0] = '\0';
        delay(1500);
        lcd.setCursor(0, 0);
        lcd.print("Enter Password");   
      }
      else
      {
        lcd.clear();
        lcd.print("FAILURE");
        inputstr[0] = '\0';
        delay(1500);
        lcd.setCursor(0, 0);
        lcd.print("Enter Password");          
      }
    }  
    
  }
}
