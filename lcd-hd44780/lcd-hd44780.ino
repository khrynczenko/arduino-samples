#include <LiquidCrystal.h>

#define PIN_RS 2
#define PIN_E 3
#define PIN_D4 4
#define PIN_D5 5
#define PIN_D6 6
#define PIN_D7 7

LiquidCrystal lcd(PIN_RS, PIN_E, PIN_D4, PIN_D5, PIN_D6, PIN_D7);


void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Display works!");
  lcd.setCursor(0, 1);
  lcd.print("And blinks!");
//  lcd.blink();
}

void loop() {
//  lcd.noCursor();
//  delay(250);
//  lcd.cursor();
//  delay(250);
  lcd.display();
  delay(500);
  lcd.noDisplay();
  delay(500);
}
