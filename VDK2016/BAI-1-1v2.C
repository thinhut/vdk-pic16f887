/*Yeu cau:
  Chuong trinh chop tat cac LED o PORT E voi thoi gian delay 250ms
 */
//Ten file: BAI-1-1v2.C
#include<16F887.h> //Khai bao ten PIC
#include<def_887.h> //Thu vien do nguoi dung dinh nghia
#FUSES NOWDT, HS, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP, NOCPD, NOWRT
#use delay(clock = 20000000) //Tan so thach anh 20MHz

void main(){
    TRISE = 0x00; //Tat ca cac chan o PORT E la chan xuat (output)
    PORTE = 0x00; //Tat ca cac chan o muc thap --> LED tat
    while (True){
        PORTE = ~PORTE; //Tat ca cac chan o muc thap --> LED tat
        delay_ms(250); //Duy tri trang thai cu trong 250ms
        //Dao trang thai cua LED
    }
}

