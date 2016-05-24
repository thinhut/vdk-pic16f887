/*Yeu cau
  Chuong trinh doc ADC tu bien tro va hien thi len LCD
 */
//Ten file BAI-4-1.C
#include<16f887.h>
#include<def_887.h>
#device *= 16 ADC = 10
#fuses HS,NOWDT, NOPROTECT, NOLVP
#use delay(clock=20000000) //Tan so thach anh 20MHz
#include<LCD_LIB_4BIT.C>  //Them thu vien LCD vao

void main(){
   int16 adc;

   OUTPUT_LOW(LCD_RW); //Che do ghi 
   LCD_Init();        //Khoi tao LCD

   LCD_PutCmd(0x01);  //Xoa man hinh

   //Xac dinh cach thuc hoat dong cua bo ADC
   //Thoi gian lay mau bang xung clock
   SETUP_ADC(ADC_CLOCK_INTERNAL);
   SET_ADC_CHANNEL(3);      //Su dung chan A3 doc ADC
   delay_us(10);            //Dam bao doc gia gia ADC chinh xac

   while (True){
      LCD_PutCmd(0x01);
      adc = READ_ADC();   //Doc ADC tu chan A3
      LCD_SetPosition(0x00); //Cot 1 dong 1
      LCD_PutChar("Read ADC:");
      printf(LCD_PutChar,"%lu",adc); //Hien thi len LCD
      delay_ms(1000);
   }      
}

