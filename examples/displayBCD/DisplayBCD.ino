#include <Edushield2display7Seg.h>


DoubleDisplay mydisplay;
byte valor1, valor2;
int timeRefresh=10;  //Para que la frecuencia de refresco esté por encima de 50Hz es necesario que este valor sea 10 o inferior.
void setup()
{  
   valor1=3;
   valor2=7;
}

void loop()
{
      mydisplay.selectDigitDisplay(1);
      mydisplay.writeBCD(valor1);  
      delay(timeRefresh);
      mydisplay.selectDigitDisplay(2);
      mydisplay.writeBCD(valor2);  
      delay(timeRefresh);
}
