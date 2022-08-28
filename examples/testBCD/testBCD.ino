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
* Resumen: Apagado de ambos displays. Se representa por codigicación BCD
* todos los valores, primero en el display 1 y luego en el 2.
*************************************************************************/

#include <Edushield2display7Seg.h>


DoubleDisplay mydisplay;

void setup()
{    
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
