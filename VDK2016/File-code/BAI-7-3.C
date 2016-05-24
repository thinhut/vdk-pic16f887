/*Yeu cau
  Chuong trinh hien thi nhiet do len PC
 */
//Ten file BAI-7-3.C 
#include<16f887.h>
#include<def_887.h>
#include<string.h>
#fuses HS,NOWDT, NOPROTECT, NOLVP
#use delay(clock=20000000) //Tan so thach anh 20MHz
#use I2C(Master, SDA = pin_C4, SCL = pin_C3) //Giao tiep I2C
#use rs232(baud = 9600, xmit = PIN_C6, rcv = PIN_C7)
#include<LCD_LIB_4BIT.C>  //Them thu vien LCD vao
#include<DS3231.C>

void main(){
    OUTPUT_LOW(LCD_RW); //Che do ghi 
    LCD_Init();        //Khoi tao LCD
    DS3231_init();

    LCD_PutCmd(0x01);  //Xoa man hinh

    while (True){
        LCD_SetPosition(0x00);
        printf(LCD_PutChar,"%.1f",getTemp());   //Hien thi nhiet do len LCD
        printf("%.1fC\n",getTemp());           //Gui nhiet do len may tinh
        LCD_PutChar(223);
        printf(LCD_PutChar,"C");
    }

}

