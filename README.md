# EduShield2Display7Seg
Tarjeta de display doble de 7 segmentos para EduShield Canarias, compatible con mBot, Arduino, ESP32

## Arduino Library for EduShield 2 Display 7 Segment
## Usage

This library supports the following devices :


* EduShield 2 Display 7 Segment with PCF8574

You will need conect the board at port EduShield. The board used I2C conection 
for comunication with PCF8574 and pins S1 and S2 with OUTPUT for control the display activation.

We have included a definition ports control for:
* EduShield Canarias ESP32  mini R1: 	EdushieldESP32mini
* EduShield Canarias R3:			EdushieldR3
* EduShield Canarias R2:			EdushieldR2
* mCore:					mCore

Used h file to defined, but ports defined is in file cpp.

## Credits
Created by Roberto José Suárez Guedes

## Website

You can find the latest version of the library at
https://www3.gobiernodecanarias.org/medusa/ecoblog/rsuagued

## La placa
Se trata de una placa con doble display 7 segmentos de ánodo común controlada por un PCF8574. Como el integrado da poca corriente de alimentación a Vcc, debido a que funciona como drenador abierto, se tienen que usar resistencias de pull-up, aparte de las limitadoras. Adicionalmente se controla el encendido de cada display con dos transistores en emisor común. Los valores que atacan a los displays se envían por medio de I2C.
Mire el esquema anexo.
