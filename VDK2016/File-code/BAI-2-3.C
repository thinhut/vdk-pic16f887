/*Yeu cau
  Chuong trinh hien dem so tu 0 - 999 hien thi len LCD
 */
//Ten file BAI-2-3.C
#include<16f887.h>
#include<def_887.h>
#fuses HS,NOWDT, NOPROTECT, NOLVP
#use delay(clock=20000000) //Tan so thach anh 20MHz
#include<LCD_LIB_4BIT.C>  //Them thu vien LCD vao

void main(){
   unsigned long count,i, N_max = 999; //Gia tri dem gioi han
   int16 sleep = 200; //Thoi gian delay (ms)

   OUTPUT_LOW(LCD_RW); //Che do ghi 
   LCD_Init();        //Khoi tao LCD

   LCD_PutCmd(0x01);  //Xoa man hinh

   LCD_SetPosition(0x00); //Cot 1 dong 1
   LCD_PutChar("Dem so:");
   while (True){  
      count = 0;
      for (i = 0; i<= N_max; i++){        
         LCD_SetPosition(0x07); //Cot 8 dong 1
         printf(LCD_PutChar,"%lu",count);

         delay_ms(sleep);
         count++;
         
         if (count > N_max){ //Reset lai bien count
            count = 0;
            //Thong bao Reset
            LCD_SetPosition(0x46); //Cot 7 dong 2
            LCD_PutChar("Reset!");
            delay_ms(2000);

            //Reset man hanh
            LCD_PutCmd(0x01);  //Xoa man hinh
            LCD_SetPosition(0x00); //Cot 1 dong 1
            LCD_PutChar("Dem so:");
         }      
      }
   }
}

