/*Yeu cau
  Chuong trinh nhan chuoi "TT VI DIEU KHIEN" tu PC hien thi len LCD
 */
//Ten file BAI-7-2.C
#include<16f887.h>
#include<def_887.h>
#fuses HS,NOWDT, NOPROTECT, NOLVP
#use delay(clock=20000000) //Tan so thach anh 20MHz
#use rs232(baud = 9600, xmit = PIN_C6, rcv = PIN_C7)
#include<LCD_LIB_4BIT.C>  //Them thu vien LCD vao

char string[30]; 

#INT_RDA
void RDA_interrupts(){       
   gets(string); //Doc vao mot chuoi tu PC
}


void main(){ 
   ENABLE_INTERRUPTS(INT_RDA); //Cho phep ngat RS232
   ENABLE_INTERRUPTS(GLOBAL);  // Cho phep ngat toan cuc
   OUTPUT_LOW(LCD_RW); //Che do ghi 
   LCD_Init();        //Khoi tao LCD

   while (True){       
      LCD_PutCmd(0x01);  //Xoa man hinh
      LCD_SetPosition(0x00); //Cot 6 dong 1
      printf(LCD_PutChar,"%s",string);
      delay_ms(3000);
   }
}

