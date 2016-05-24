/*Yeu cau:
  Chuong trinh hien thi so tu 0 - 9, A - F hien thi len LED 7 DOAN
  ( Phuong phap dieu khien truc tiep)
 */
//Ten file: BAI-2-PHU-LUC-LED-7-SEG-V1.C
#include<16F887.h> //Khai bao ten PIC
#include<def_887.h> //Thu vien do nguoi dung dinh nghia
#FUSES NOWDT, HS, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP, NOCPD, NOWRT
#use delay(clock = 20000000) //Tan so thach anh 20MHz

//Khai bao ma code cho LED 7 doan co Anode chung
//Cac so tu 0 - 9; cac chu tu A - F
unsigned char code7seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};
void main(){    
    int count;    
    TRISD = 0x00; //Tat ca cac chan o PORT D la chan xuat (output)
    PORTD = 0xFF;//Cho Off tat ca cac LED

    while (True){
        for (count = 0; count <= 16; count ++){
            PORTD = code7seg[count]; //Lay vi tri thu count trong mang Code7seg
            delay_ms(1000);
        }   
   }
}

