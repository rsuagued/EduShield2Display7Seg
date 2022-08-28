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
* Resumen: Representación de dos valores con codificación BCD en los dos
* displays de multiplexándoles en el tiempo.
*************************************************************************/

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
