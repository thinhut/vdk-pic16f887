/*Yeu cau:
  Chuong trinh dem so lan nhat nut voi Timer va hien thi LCD
 */
//Ten file: BAI-5-3.C
#include<16F887.h> //Khai bao ten PIC
#include<def_887.h> //Thu vien do nguoi dung dinh nghia
#FUSES NOWDT,HS, PUT, NOPROTECT

#use delay(clock = 20000000) //Tan so thach anh 20MHz
#include<LCD_LIB_4BIT.C>  //Them thu vien LCD vao

int32 count, value, over = 0;
void main(){

   TRISA = 0xFF; //PORT A la INPUT

   OUTPUT_LOW(LCD_RW); //Che do ghi 
   LCD_Init();        //Khoi tao LCD

   LCD_PutCmd(0x01);  //Xoa man hinh

   //Cai dat Timer 0 voi che do la canh xuong (H to L) tu chan A4
   //Su dung bo chia 1 (khong thay doi)
   SETUP_TIMER_0(RTCC_EXT_H_TO_L|RTCC_DIV_1);
   SET_TIMER0(0); //Bat dau dem tu 0.


   LCD_SetPosition(0x00); //Cot 1 dong 1
   LCD_PutChar("Count:");

   while (True){ //Duy tri hoat dong cua vi dieu khien  
      if (value == 255){ //Bat dau tran
         over++; //Tang so lan tran len
         SET_TIMER0(0); //Reset la bo dem
         value = GET_TIMER0(); //Cap nhan lai gia tri value
      }
      else{ //Khi khong tran thi doc gia tri tu Timer        
         value = GET_TIMER0(); //Doc gia tri cua Timer

         //Gia tri cua bien dem = gia_tri_doc_duoc + so_lan_tran*255
         count = value + over*255;  
         LCD_SetPosition(0x06); //Cot 7 dong 1
         printf(LCD_PutChar,"%lu",count); //Hien thi len LCD
      }
   }
}

