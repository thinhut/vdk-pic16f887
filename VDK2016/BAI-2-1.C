/*Yeu cau
  Chuong trinh hien thi chuoi "DAI HOC KTCN CAN THO" len LCD
*/
//Ten file BAI-2-1.C
#include<16f887.h>
#include<def_887.h>
#fuses HS,NOWDT, NOPROTECT, NOLVP
#use delay(clock=20000000) //Tan so thach anh 20MHz
#include<LCD_LIB_4BIT.C>  //Them thu vien LCD vao

void main(){
    OUTPUT_LOW(LCD_RW); //Che do ghi 
    LCD_Init();        //Khoi tao LCD

    LCD_PutCmd(0x01);  //Xoa man hinh

    LCD_SetPosition(0x05); //Cot 6 dong 1
    LCD_PutChar("DAI HOC");
    LCD_SetPosition(0x42); //Cot 3 dong 2
    LCD_PutChar("KTCN CAN THO");  
}

