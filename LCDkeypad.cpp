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
void LCDkeypad::part(String text,int cur,bool ex) {
  this->clear();
  if(ex){
  text=text+"                 Press Left To Exit";
}
  for(int l=0; l < 2; l++) {
    int index = (cur+l) * 16;
    int len = text.length();

    if (index < len) {
      this->setCursor(0, l);
      for (int i = 0; i < 16 && index + i < len; i++)
        this->print(text[index+i]);
      }
    }
  }

void LCDkeypad::makeChars(){
  byte arrow[8] = {
    B11111,
    B11011,
    B10011,
    B00000,
    B00000,
    B10011,
    B11011,
    B11111
  };
  byte invM[8] = {
    0b11111,
    0b10101,
    0b10001,
    0b10101,
    0b10101,
    0b10101,
    0b10101,
    0b11111
  };

  byte invA[8] = {
    0b11111,
    0b10001,
    0b10101,
    0b10001,
    0b10101,
    0b10101,
    0b10101,
    0b11111
  };

  byte invT[8] = {
    0b11111,
    0b10001,
    0b11011,
    0b11011,
    0b11011,
    0b11011,
    0b11011,
    0b11111
  };

  byte invH[8] = {
    0b11111,
    0b10101,
    0b10101,
    0b10001,
    0b10101,
    0b10101,
    0b10101,
    0b11111
  };
  byte invColon[8]= {
    0b11111,
    0b10011,
    0b10011,
    0b11111,
    0b11111,
    0b10011,
    0b10011,
    0b11111
  };
  byte EX[8] = {
  B11111,
  B10001,
  B10001,
  B11111,
  B10001,
  B01010,
  B00100,
  B01010
};
byte IT[8] = {
  B00100,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B11111
};
  this->createChar(0,arrow);
  this->createChar(1,invM);
  this->createChar(2,invA);
  this->createChar(3,invT);
  this->createChar(4,invH);
  this->createChar(5,invColon);
  this->createChar(6,EX);
  this->createChar(7,IT);
}

void LCDkeypad::select(String data[],String title,int cur){
  this->clear();
  this->setCursor(0,0);
  if(title=="Math"){
    this->write(byte(1));
    this->write(byte(2));
    this->write(byte(3));
    this->write(byte(4));
    this->write(byte(5));
  }
  else{
this->print(title);
}
this->setCursor(0,1);
this->print(data[cur]);
this->write(" ");
this->write(byte(0));
}
