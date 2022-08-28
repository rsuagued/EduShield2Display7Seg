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
