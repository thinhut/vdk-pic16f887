/*Yeu cau:
  Chuong trinh toc do va dao chieu dong co voi nut nhan.
 */
//Ten file: BAI-8-2-1.C
#include<16F887.h> //Khai bao ten PIC
#include<def_887.h> //Thu vien do nguoi dung dinh nghia

#FUSES NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP, NOCPD, NOWRT
#use delay(clock = 20000000) //Tan so thach anh 20MHz


#INT_EXT //Ngat ngoai - chan B0
void NgatNgoai(){
   int i;
   CLEAR_INTERRUPT(INT_EXT); //Xoa co ngat
   DISABLE_INTERRUPTS(GLOBAL); //vo hieu hoa ngat toan cuc

   //Xu ly chuong trinh ngat
   delay_ms(500); //Chong nhieu
   //count++; //Tang gia tri bien dem
   SETUP_TIMER_2(T2_DIV_BY_4,124,1);
   SETUP_CCP1(CCP_PWM);
   while (i < 125){
      i++;
      SET_PWM1_DUTY(i); 
      delay_ms(10);
   }
   ENABLE_INTERRUPTS(GLOBAL); //Cho phep ngat toan cuc
}

void main(){
   TRISB = 0xFF; //Chan INPUT
   TRISC = 0x00; //Chan OUTPUT
   PORT_B_PULLUPS(1); //Noi dien tro len nguon

   ENABLE_INTERRUPTS(INT_EXT); //Kich hoat ngat ngoai
   EXT_INT_EDGE(H_TO_L); //Chon canh ngat, cao xuong thap
   ENABLE_INTERRUPTS(GLOBAL); //Cho phep ngat toan cuc

   //Cai dat tan so dieu xung la 10kHz
   SETUP_TIMER_2(T2_DIV_BY_4,124,1);

   SETUP_CCP1(CCP_PWM);//Su dung ca 2 chan PWM
   SETUP_CCP2(CCP_PWM);

   //INPUT2 = 0; INPUT1 = 0;  ---> Dong co khong quay
   SET_PWM1_DUTY(0); 
   //SET_PWM2_DUTY(0);

   while (True){

   }

}

