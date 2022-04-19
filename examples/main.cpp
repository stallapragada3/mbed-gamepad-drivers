#include "mbed.h"
#include "USBGamepad.h"
 
USBGamepad gamepad;

DigitalIn pb1(p5);
DigitalIn pb2(p6);
DigitalIn pb3(p7);
DigitalIn pb4(p8); 
AnalogIn AnalogXl(p15);
AnalogIn AnalogYl(p16);
AnalogIn AnalogXr(P17);
AnalogIn AnalogYr(p18); 

 
int main() {
	pb1.mode(PullUp);
    pb2.mode(PullUp);
    pb3.mode(PullUp);
    pb4.mode(PullUp); 

    while (1) {
        if (!pb1) {
            //gamepad actions upon press of pb1
        } 

         if (!pb2) {
            //gamepad actions upon press of pb2
        } 

         if (!pb3) {
            //gamepad actions upon press of pb3

        }
        
         if (!pb4) {
            //gamepad actions upon press of pb4
        }  
    }

    
}
