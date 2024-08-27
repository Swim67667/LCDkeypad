#include <LCDkeypad.h>


LCDkeypad lcd;
int total;
int curline=0;

void setup() {
lcd.begin(16, 2);
}


void loop() {
  // Example usage
if(lcd.read()==btnUP && curline>0){
  curline-=1;
  
}
if(lcd.read()==btnDOWN){
  curline+=1;
}

 lcd.part("hello this is a really long string that should be partitiond.",curline);
 delay(300);
}
