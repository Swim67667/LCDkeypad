#include "LCDkeypad.h"

// Hardcoded pins for the LCD
#define RS 8
#define EN 9
#define D4 4
#define D5 5
#define D6 6
#define D7 7

LCDkeypad::LCDkeypad()
  : LiquidCrystal(RS, EN, D4, D5, D6, D7)  // Call the parent class constructor with hardcoded pins
{
}

int LCDkeypad::read() {
  _adc_key_in = analogRead(0);  // Read the analog value from A0

  if (_adc_key_in > 1000) return btnNONE;
  if (_adc_key_in < 50)   return btnRIGHT;
  if (_adc_key_in < 150)  return btnUP;
  if (_adc_key_in < 350)  return btnDOWN;
  if (_adc_key_in < 550)  return btnLEFT;
  if (_adc_key_in < 650)  return btnSELECT;

  return btnNONE;  // Default to btnNONE if no buttons are pressed
}
void LCDkeypad::part(const char* text,int cur) {
  this->clear();

  for (int l=0; l < 2; l++) {
    int index = (cur+l) * 16;
    int len = strlen(text);
    int total = (len + 15) / 16;

    if (index < len) {
      this->setCursor(0, l);
      for (int i = 0; i < 16 && index + i < len; i++) {
        this->print(text[index + i]);
      }
    }
  }
}
