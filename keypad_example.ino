#include <LCDkeypad.h>

// Initialize the LCDkeypad (pins are hardcoded, so no arguments needed)
LCDkeypad lcd;

void setup() {
  lcd.begin(16, 2);  // Initialize the LCD for 16x2 characters
  lcd.print("Welcome!");  // Use the LiquidCrystal function to print text
}

void loop() {
  int button = lcd.readButtons();  // Read the button state

  lcd.setCursor(0, 1);
    // Move to the second row

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
