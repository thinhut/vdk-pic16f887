/* Yeu cau: 
    Viet chuong bat tat cac LED o PORT E qua Matlab: b--bat led; t--tat led
*/
//Ten file: BAI-7-1.C
#include<16f887.h>
#include<def_887.h>

#fuses HS, NOWDT, NOPROTECT, NOLVP
#use delay(clock = 20000000)
#use rs232(baud = 9600, xmit = PIN_C6, rcv = PIN_C7)
char value;

#INT_RDA
void RDA_interrupts(){ 
    value =getc();
    if (value == 'b')
        PORTE = 0xFF;
    if (value == 't')
        PORTE = 0x00;
}

void main(){
    TRISE = 0x00; //Pin OUTPUT
    ENABLE_INTERRUPTS(INT_RDA); //Cho phep ngat RS232
    ENABLE_INTERRUPTS(GLOBAL);  // Cho phep ngat toan cuc

    while (True){
        ;
    }
}

