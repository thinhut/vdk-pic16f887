/*Yeu cau
  Chuong trinh hien thi len LCD:
  - Dong 1: Ho ten sinh vien
  - Dong 2: Ma so sinh vien
 */
//Ten file BAI-2-2.C
#include<16f887.h>
#include<def_887.h>
#fuses HS,NOWDT, NOPROTECT, NOLVP
#use delay(clock=20000000) //Tan so thach anh 20MHz
#include<LCD_LIB_4BIT.C>  //Them thu vien LCD vao

void main(){
	OUTPUT_LOW(LCD_RW); //Che do ghi 
	LCD_Init();        //Khoi tao LCD

	LCD_PutCmd(0x01);  //Xoa man hinh
	LCD_SetPosition(0x01); //Cot 2 dong 1
	LCD_PutChar("Thi Minh Nhut");
	LCD_SetPosition(0x44); //Cot 5 dong 2
	LCD_PutChar("1350366");  
}

