/*Yeu cau:
  Chuong trinh dem so lan nhat nut hien thi len LCD su dung ngat
 */
//Ten file: INPUT_BUTTON.C
#include<16F887.h> //Khai bao ten PIC
#include<def_887.h> //Thu vien do nguoi dung dinh nghia

#FUSES NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP, NOCPD, NOWRT
#use delay(clock = 20000000) //Tan so thach anh 20MHz
#include<LCD_LIB_4BIT.C>  //Them thu vien LCD vao

unsigned long count = 0;

void main(){
   TRISB = 0XFF; //Chan INPUT   
   PORT_B_PULLUPS(1); //Noi dien tro len nguon

   OUTPUT_LOW(LCD_RW); //Che do ghi 
   LCD_Init();        //Khoi tao LCD

   LCD_PutCmd(0x01);  //Xoa man hinh   
   LCD_SetPosition(0x00); //Cot 1 dong 1
   LCD_PutChar("Count= ");

   ENABLE_INTERRUPTS(INT_EXT); //Kich hoat ngat ngoai
   EXT_INT_EDGE(H_TO_L); //Chon canh ngat, cao xuong thap
   ENABLE_INTERRUPTS(GLOBAL); //Cho phep ngat toan cuc

   while (True){ //Duy tri hoat dong cua vi dieu khien
      LCD_SetPosition(0x06); //Cot 7 dong 1
      printf(LCD_PutChar,"%lu",count);
      if (INPUT(PIN_B0) == 0){//Da nhan nut nhan
         delay_ms(500);
         count ++;
      }
   }
}

