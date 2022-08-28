#ifndef Edushield2display7Seg_h
#define Edushield2display7Seg_h
#define EdushieldESP32mini
//#define EdushieldR3
//#define EdushieldR2
//#define mCore


#define SEGMENTO_a 0
#define SEGMENTO_b 1
#define SEGMENTO_c 2
#define SEGMENTO_d 3
#define SEGMENTO_e 4
#define SEGMENTO_f 5
#define SEGMENTO_g 6
#define SEGMENTO_dp 7

class DoubleDisplay{
 private:
    short segment2Byte(int seg, bool valor);
    int _pcfAddress = 0x38; //Normalmente el puerto I2C será el 0x38
    short _BCDCodification[10]={63,6,91,79,102,109,125,7,127,103}; //Codificación prefefinida para BCD
    short _dig1,_dig2;
    int _pinDig1, _pinDig2;
     
  public:
    DoubleDisplay();
    DoubleDisplay(int port);
    DoubleDisplay(int address, int port);
    void byteWrite(short dato);
    void clearDisplayNumber(int displaynumber);
    void displaysOFF();
    void setSegmentDigit1(int segment, bool value);
    void setSegmentDigit2(int segment, bool value);
    void selectDigitDisplay(int dig);
    void writeBCD(int dato);
    void writeDigit(int dig); 
};
#endif
