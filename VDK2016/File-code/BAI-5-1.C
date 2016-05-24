/*Yeu cau:
  Chuong trinh chop tat LED o PORT voi thoi gian delay 1s su dung Timer
 */
//Ten file: BAI-5-1.C
#include<16F887.h> //Khai bao ten PIC
#include<def_887.h> //Thu vien do nguoi dung dinh nghia

#FUSES NOWDT, PUT, NOPROTECT

#use delay(clock = 20000000) //Tan so thach anh 20MHz

int32 count = 0;

#INT_TIMER0 //Ngat TIMER0
void Ngat_Timer0(){
   SET_TIMER0(100);

   //Xu ly chuong trinh ngat
   ++count; //Tang gia tri bien dem
   if (count == 1000){
      CLEAR_INTERRUPT(INT_TIMER0); //Xoa co ngat
      DISABLE_INTERRUPTS(GLOBAL); //vo hieu hoa ngat toan cuc
      count = 0;
      PORTE = ~PORTE;
      ENABLE_INTERRUPTS(GLOBAL); //Cho phep ngat toan cuc
   }
}

void main(){
   TRISE = 0x00; //Chan OUTPUT

   ENABLE_INTERRUPTS(INT_TIMER0); //Kich hoat ngat tran Timer0
   SETUP_TIMER_0(RTCC_INTERNAL|RTCC_DIV_32); //Xung kich noi va chia truoc 32
   ENABLE_INTERRUPTS(GLOBAL); //Cho phep ngat toan cuc
   SET_TIMER0(100); //Bat dau dem tu 100, khi tran Timer0 duoc 1ms

   while (True){ //Duy tri hoat dong cua vi dieu khien
      ;    
   }
}

