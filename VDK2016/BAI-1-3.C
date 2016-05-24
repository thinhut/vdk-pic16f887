/* Yeu cau:
   Chuong trinh chop tat LED - RE1 voi thoi gian delay 1s; 
   LED - RE2 voi thoi gian delay 0.5s
 */
//Ten file: BAI-1-3.C
#include<16F887.h>
#include<def_887.h>

#FUSES NOWDT, HS, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP, NOCPD, NOWRT

#use delay(clock = 20000000)//Tan so thach anh 20MHz

void main(){
    TRISE = 0x00; //Tat ca cac chan o PORT E la chan xuat (output)

    while (True){
        PORTE = 0x06; // 0b110;
        delay_ms(500);
        PORTE = 0x02; // 0b010;
        delay_ms(500);
        PORTE = 0x04; // 0b100;
        delay_ms(500);
        PORTE = 0x00; // 0b000;
        delay_ms(500);
    }
}

