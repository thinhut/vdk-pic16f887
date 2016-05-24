/*Yeu cau:
  Chuong trinh dao chieu dong co voi nut nhan
 */
//Ten file: BAI-8-1.C
#include<16F887.h> //Khai bao ten PIC
#include<def_887.h> //Thu vien do nguoi dung dinh nghia

#FUSES NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP, NOCPD, NOWRT
#use delay(clock = 20000000) //Tan so thach anh 20MHz

//Do phan cung bi nhieu, nen xay ra 1 ngat truoc.
unsigned long count = -1; 

#INT_EXT //Ngat ngoai - chan B0
void NgatNgoai(){
	CLEAR_INTERRUPT(INT_EXT); //Xoa co ngat
	DISABLE_INTERRUPTS(GLOBAL); //vo hieu hoa ngat toan cuc

	//Xu ly chuong trinh ngat
	delay_ms(500); //Chong nhieu
	count++; //Tang gia tri bien dem    
	/*  E0 - ENABLE1
	 *  E1 - INPUT1
	 *  E2 - INPUT2
	 */
	if (count ==  0){ //Dung quay
		PORTE = 0x00; // Chan ENABLE = 0
	}
	else
		if ((count % 2 == 0) & (count>0)){//Quay thuan
			PORTE = 0x03; //011 - INPUT2 = 0; INPUT1 = 1; ENABLE = 1
		}
		else
			if (count % 2 == 1){ //Quay nghich
				PORTE = 0x05; //101 - INPUT2 = 1; INPUT1 = 0; ENABLE = 1
			}

	ENABLE_INTERRUPTS(GLOBAL); //Cho phep ngat toan cuc
}

void main(){
	TRISB = 0xFF; //Chan INPUT
	TRISE = 0x00; //Chan tin hieu dieu khien la OUTPUT
	PORT_B_PULLUPS(1); //Noi dien tro len nguon

	ENABLE_INTERRUPTS(INT_EXT); //Kich hoat ngat ngoai
	EXT_INT_EDGE(H_TO_L); //Chon canh ngat, cao xuong thap
	ENABLE_INTERRUPTS(GLOBAL); //Cho phep ngat toan cuc

	while (True){ //Duy tri hoat dong cua vi dieu khien
		;    
	}
}

