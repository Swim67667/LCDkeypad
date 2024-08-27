#ifndef LCDkeypad_h
#define LCDkeypad_h

#include "Arduino.h"
#include <LiquidCrystal.h>

#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

class LCDkeypad : public LiquidCrystal {
  public:
    LCDkeypad();  // Constructor without pins
    int read();
  void part(const char* text, int cur);  // Method to read button states

  private:
    int _adc_key_in;

};

#endif
