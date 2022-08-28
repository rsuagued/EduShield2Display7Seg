#include <Edushield2display7Seg.h>


DoubleDisplay mydisplay;

void setup()
{  
   Serial.begin(115200);
   
}

void loop()
{
      mydisplay.displaysOFF();
      delay(1000);
      mydisplay.selectDigitDisplay(1);
      for (int i=0;i<10;i++){
        mydisplay.writeBCD(i);  
        delay(1000);
      }
      mydisplay.selectDigitDisplay(2);
      for (int i=0;i<10;i++){
        mydisplay.writeBCD(i);  
        delay(1000);
      }

}
