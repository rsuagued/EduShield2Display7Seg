#include "Edushield2display7Seg.h"
#include <Arduino.h>
#include <Wire.h>

#ifdef EdushieldESP32mini
int eduPorts[2][2]={{33,18},{32,27}}; //Placa Edushield ESP32 mini R1 con 2 puertos RJ11 6P6C
int eduNumPorts=2;
#endif

/*************************************************************************
* Método constructor con asignación de los pines del puerto de conexión 1.
*************************************************************************/
DoubleDisplay::DoubleDisplay(){
  _dig1=0;
  _dig2=0;
  _pinDig1=eduPorts[0][0]; //S1 puerto 1 -> pin 32
  _pinDig2=eduPorts[0][1]; //S2 puerto 1 -> pin 18
  pinMode(_pinDig1,OUTPUT);
  pinMode(_pinDig2,OUTPUT);
  Wire.begin();
}

/***********************************************************************
* Método constructor con asignación de los pines del puerto de conexión.
***********************************************************************/
DoubleDisplay::DoubleDisplay(int port){
  _dig1=0;
  _dig2=0;
  if (port<1 || port > eduNumPorts){port = 1;} //Si el puerto es el 0 o es mayor que el último puerto se reasigna al puerto 1
  _pinDig1=eduPorts[port-1][0]; //S1 puerto 1 -> pin 33 ó S1 puerto 2 -> pin 32
  _pinDig2=eduPorts[port-1][1]; //S2 puerto 1 -> pin 18 ó S1 puerto 2 -> pin 27 
  pinMode(_pinDig1,OUTPUT);
  pinMode(_pinDig2,OUTPUT);
  Wire.begin();
}

DoubleDisplay::DoubleDisplay(int address, int port){
  _pcfAddress=address;
  _dig1=0;
  _dig2=0;
  if (port<1 || port > eduNumPorts){port = 1;} //Si el puerto es el 0 o es mayor que el último puerto se reasigna al puerto 1
  _pinDig1=eduPorts[port-1][0]; //S1 puerto 1 -> pin 33 ó S1 puerto 2 -> pin 32
  _pinDig2=eduPorts[port-1][1]; //S2 puerto 1 -> pin 18 ó S1 puerto 2 -> pin 27
  pinMode(_pinDig1,OUTPUT);
  pinMode(_pinDig2,OUTPUT);
  Wire.begin();
}
short DoubleDisplay::segment2Byte(int seg, bool valor){
  if (valor){return bit(seg);}
  return 0;
}

void DoubleDisplay::byteWrite(short dato){
      Wire.beginTransmission(_pcfAddress);
      Wire.write(dato);
      Wire.endTransmission();
}

void DoubleDisplay::writeBCD(int digito){
  if (digito<10){byteWrite(_BCDCodification[digito]);}
}

void DoubleDisplay::setSegmentDigit1(int seg, bool value){  
  if (value){_dig1=_dig1 | bit(seg); }
  else {{_dig1=_dig1 & (~bit(seg));}}
  byteWrite(_dig1);
}

void DoubleDisplay::setSegmentDigit2(int seg, bool value){  
  if (value){_dig2=_dig2 | bit(seg);}
  else {{_dig2=_dig2 & (~bit(seg));}}
  byteWrite(_dig2);
}

void DoubleDisplay::displaysOFF(){
  digitalWrite(_pinDig1,LOW);
  digitalWrite(_pinDig2,LOW);
}
void DoubleDisplay::clearDisplayNumber(int displaynumber){
 switch (displaynumber){
  case 0:
      _dig1=0;
      _dig2=0;
      break;
  case 1:
      _dig1=0;
      byteWrite(_dig1);
      break;
  case 2:
      _dig2=0;
      byteWrite(_dig2);
      break;
 }
}

/***********************************************************************
* Método que activa el dígito 2 si dig es 2 o el dígito 1 si no lo es.
***********************************************************************/
void DoubleDisplay::selectDigitDisplay(int dig){
  
  if (dig==2){
    digitalWrite(_pinDig2,HIGH);
    digitalWrite(_pinDig1,LOW);
  }else {
    digitalWrite(_pinDig1,HIGH);
    digitalWrite(_pinDig2,LOW);
  } 
}

/***********************************************************************
* Método que activa el dígito 2 si dig es 2 o el dígito 1 si no lo es.
* Una vez activo escribe el valor de la variable del digito 2 o del 1
* según corresponda.
***********************************************************************/
void DoubleDisplay::writeDigit(int dig){
  
  if (dig==2){
    digitalWrite(_pinDig2,HIGH);
    digitalWrite(_pinDig1,LOW);
    byteWrite(_dig2);
  }else {
    digitalWrite(_pinDig1,HIGH);
    digitalWrite(_pinDig2,LOW);
    byteWrite(_dig1);
  } 
}
