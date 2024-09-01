#include <LCDkeypad.h>

LCDkeypad lcd;

void setup() {
  lcd.begin(16, 2);  // Initialize the LCD for 16x2 characters
  lcd.print("Welcome!");  // Use the LiquidCrystal function to print text
}

void loop() {
  int button = lcd.readButtons();

  lcd.setCursor(0, 1);
  switch(button) {
    case btnRIGHT:
      lcd.print("RIGHT ");
      break;
    case btnLEFT:
      lcd.print("LEFT ");
      break;
    case btnUP:
      lcd.print("UP ");
      break;
    case btnDOWN:
      lcd.print("DOWN ");
      break;
    case btnSELECT:
      lcd.print("SELECT ");
      break;
    case btnNONE:
      lcd.print("NONE ");
      break;
  }

  delay(500);  // Add a small delay to avoid overwhelming the LCD
}
