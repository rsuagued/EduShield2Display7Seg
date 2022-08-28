/*************************************************************************
* Código desarrollado para la librería Edushield2display7Seg diseñada
* para la placa EduShield doble display 7 segmentos.
* 
* Digitos del puerto transmitidos por I2C a PCF8574. displays controlados
* por transistores en con los pines S1 y S2 del puerto.
*
* Autor: Roberto José Suárez Guedes
* Fecha: agosto del 2022
* Versión: 1.0
* Página web:https://www3.gobiernodecanarias.org/medusa/ecoblog/rsuagued/
*
* Resumen: Se enciende cada segmento en los dos displays de forma 
* multiplexada durante un segundo.
*************************************************************************/

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
