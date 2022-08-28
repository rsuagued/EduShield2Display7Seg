#include <Edushield2display7Seg.h>

short valor=0;
int timerefresh=5;
unsigned long timeview;
DoubleDisplay mydisplay;

void setup()
{  
   
}

void loop()
{     
    mydisplay.displaysOFF();
    delay(1000);
    valor=1;
    for (int i=0; i<8;i++){
      mydisplay.byteWrite(valor);
      timeview=millis()+1000;
      while (millis()<timeview){
        mydisplay.selectDigitDisplay(1);
        delay(timerefresh);
        mydisplay.selectDigitDisplay(2);
        delay(timerefresh);
      }
      valor=valor<<1;
    }
}
