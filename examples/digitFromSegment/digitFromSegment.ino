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
* Resumen: Asignación y visualización en el display 1 asignándole los 
* valores de cada segmento del dígito de ese display como verdadero o 
* falso.
*************************************************************************/

#include <Edushield2display7Seg.h>

short valor=0;
DoubleDisplay mydisplay;

void setup()
{  
   Serial.begin(115200);
   
}

void loop()
{     
    mydisplay.clearDisplayNumber(1);
    delay(1000);

    mydisplay.setSegmentDigit1(SEGMENTO_a, true);
    mydisplay.setSegmentDigit1(SEGMENTO_b, true);
    mydisplay.setSegmentDigit1(SEGMENTO_c, true);
    mydisplay.setSegmentDigit1(SEGMENTO_d, true);
    mydisplay.setSegmentDigit1(SEGMENTO_g, true);
    mydisplay.setSegmentDigit1(SEGMENTO_dp, true);
    mydisplay.writeDigit(1);
    delay(1000);
    mydisplay.clearDisplayNumber(1);
    mydisplay.setSegmentDigit1(SEGMENTO_b, true);
    mydisplay.setSegmentDigit1(SEGMENTO_c, true);
    mydisplay.setSegmentDigit1(SEGMENTO_dp, false);
    mydisplay.writeDigit(1);
    delay(1000);
}
