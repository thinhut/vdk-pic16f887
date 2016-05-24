/*Yeu cau:
  Chuong trinh dem so tu 0 den 9999 su dung Timer va cho hien thi len LCD.
 */
//Ten file: BAI-5-2.C
#include<16F887.h> //Khai bao ten PIC
#include<def_887.h> //Thu vien do nguoi dung dinh nghia

#FUSES NOWDT,HS, PUT, NOPROTECT

#use delay(clock = 20000000) //Tan so thach anh 20MHz
#include<LCD_LIB_4BIT.C>  //Them thu vien LCD vao

int32 count = 0, sleep = 500, dem = 0, N_max = 9999;

#INT_TIMER0 //Ngat TIMER0
void Ngat_Timer0(){
	SET_TIMER0(100);

	//Xu ly chuong trinh ngat
	count++; //Tang gia tri bien dem
	if (count == sleep){
		CLEAR_INTERRUPT(INT_TIMER0); //Xoa co ngat
		DISABLE_INTERRUPTS(GLOBAL); //vo hieu hoa ngat toan cuc
		count = 0; 
		dem++; //Tang gia tri cua bien dem len
		ENABLE_INTERRUPTS(GLOBAL); //Cho phep ngat toan cuc
	}
}

void main(){

	OUTPUT_LOW(LCD_RW); //Che do ghi 
	LCD_Init();        //Khoi tao LCD

	LCD_PutCmd(0x01);  //Xoa man hinh

	ENABLE_INTERRUPTS(INT_TIMER0); //Kich hoat ngat ngoai
	SETUP_TIMER_0(RTCC_INTERNAL|RTCC_DIV_32); //Xung kich noi va chia truoc 32
	ENABLE_INTERRUPTS(GLOBAL); //Cho phep ngat toan cuc
	SET_TIMER0(100); //Bat dau dem tu 100, khi tran Timer0 duoc 1ms

	while (True){ //Duy tri hoat dong cua vi dieu khien

		if (dem > N_max){
			dem = 0;
			LCD_PutCmd(0x01);
		}

		LCD_SetPosition(0x00); //Cot 1 dong 1
		LCD_PutChar("Dem so:");
		LCD_SetPosition(0x07); //Cot 8 dong 1
		printf(LCD_PutChar,"%lu",dem);

	}
}

