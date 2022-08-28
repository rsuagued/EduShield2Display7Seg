#include <Edushield2display7Seg.h>

bool a,b,c,d;
DoubleDisplay mydisplay;

void setup()
{  
   
}

void loop()
{     
    mydisplay.clearDisplayNumber(1);
    delay(1000);
    a=true;
    b=false;
    c=false;
    d=false;
    mydisplay.setSegmentDigit1(SEGMENTO_a, ((c&~d)|(b&c)|(~a&c)|(~a&b&d)));
    mydisplay.setSegmentDigit1(SEGMENTO_b, (~a&~b)|(~b&~d)|(a&~c&d)|(~a&~c&~d)|(~a&c&d));
    mydisplay.setSegmentDigit1(SEGMENTO_c, (a&~b)|(~c&d)|(~a&b)|(~a&~c)|(~a&~d));
    mydisplay.setSegmentDigit1(SEGMENTO_d, false);
    mydisplay.setSegmentDigit1(SEGMENTO_e, false);
    mydisplay.setSegmentDigit1(SEGMENTO_f, false);
    mydisplay.setSegmentDigit1(SEGMENTO_g, false);
    mydisplay.writeDigit(1);
    delay(1000);
    a=true;
    b=true;
    c=true;
    d=false;
    mydisplay.clearDisplayNumber(1);
    mydisplay.setSegmentDigit1(SEGMENTO_a, ((c&~d)|(b&c)|(~a&c)|(~a&b&d)));
    mydisplay.setSegmentDigit1(SEGMENTO_b, (~a&~b)|(~b&~d)|(a&~c&d)|(~a&~c&~d)|(~a&c&d));
    mydisplay.setSegmentDigit1(SEGMENTO_c, (a&~b)|(~c&d)|(~a&b)|(~a&~c)|(~a&~d));
    mydisplay.setSegmentDigit1(SEGMENTO_d, false);
    mydisplay.setSegmentDigit1(SEGMENTO_e, false);
    mydisplay.setSegmentDigit1(SEGMENTO_f, false);
    mydisplay.setSegmentDigit1(SEGMENTO_g, false);
    mydisplay.writeDigit(1);
    delay(1000);
}
