#include "mbed.h"
#include "PinDetect.h"
//#include "USBMouse.h"

Serial pc(USBTX,USBRX);
DigitalOut led1(LED1); 
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);
DigitalIn pb1(p5);
DigitalIn pb2(p6);
DigitalIn pb3(p7);
DigitalIn pb4(p8); 
AnalogIn AnalogXl(p15);
AnalogIn AnalogYl(p16);
AnalogIn AnalogXr(P17);
AnalogIn AnalogYr(p18); 


int main(void)
{  
    while (1)
    {
        pc.printf("%f",AnalogXl.read());
        pc.printf("%f",AnalogYl.read());

    }
}
