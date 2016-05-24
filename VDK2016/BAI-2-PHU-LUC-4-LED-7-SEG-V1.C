/*Yeu cau:
  Chuong trinh hien thi so tu 0 - 9, A - F hien thi len LED 7 DOAN
  ( Phuong phap dieu khien truc tiep)
 */
//Ten file: BAI-2-PHU-LUC-4-LED-7-SEG-V1.C
#include<16F887.h> //Khai bao ten PIC
#include<def_887.h> //Thu vien do nguoi dung dinh nghia
#FUSES NOWDT, HS, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP, NOCPD, NOWRT
#use delay(clock = 20000000) //Tan so thach anh 20MHz

//Khai bao ma code cho LED 7 doan co Anode chung
//Cac so tu 0 - 9; cac chu tu A - F
unsigned char code7seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
unsigned char digits[] = {PIN_C0, PIn_C1, PIN_C2, PIN_C3};
void main(){    
    unsigned long count,i;
    int a,b,c,d;
    
    TRISD = 0x00; //Chan Ouput, dieu khien 7 thanh LED
    TRISC = 0x00; // Chan Output, dieu khien 4 LED
    PORTC = 0x00;

    while (True){
        for (count = 0; count <=9999; count++){
            a = count / 1000;
            b = (count%1000)/100;
            c = (count%100)/10;
            d = (count%100)%10;
            
            for (i=0; i<250; i++){
                output_high(PIN_C3);
                PORTD = Code7seg[d];
                delay_ms(1);                
                output_low(PIN_C3);
                
                output_high(PIN_C2);
                PORTD = Code7seg[c];
                delay_ms(1);
                output_low(PIN_C2);
                
                output_high(PIN_C1);
                PORTD = Code7seg[b];
                delay_ms(1);
                output_low(PIN_C1);
                
                output_high(PIN_C0);
                PORTD = Code7seg[a];
                delay_ms(1);
                output_low(PIN_C0);
            }
        }
    }
}

