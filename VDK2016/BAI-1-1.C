/*Yeu cau:
  Chuong trinh chop tat cac LED o PORT E voi thoi gian delay 250ms
 */
//Ten file: BAI-1-1.C
#include<16F887.h> //Khai bao ten PIC
#include<def_887.h> //Thu vien do nguoi dung dinh nghia
#FUSES NOWDT, HS, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP, NOCPD, NOWRT
#use delay(clock = 20000000) //Tan so thach anh 20MHz

void main(){
    TRISE = 0x00; //Tat ca cac chan o PORT E la chan xuat (output)

    while (True){
        PORTE = 0x00; //Tat ca cac chan o muc thap --> LED tat
        delay_ms(250); //Duy tri trang thai cu trong 250ms
        PORTE = 0x07; //Chan RE2,RE1,RE0 o muc cao-->LED D3,D4,D5 sang
        delay_ms(250);
    }
}

