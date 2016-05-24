/*Yeu cau:
  Chuong trinh dao trang thai cac LED o PORT E voi xu ly ngat va chong nhieu
 */
//Ten file: BAI-3-4.C
#include<16F887.h> //Khai bao ten PIC
#include<def_887.h> //Thu vien do nguoi dung dinh nghia

#FUSES NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP, NOCPD, NOWRT

#use delay(clock = 20000000) //Tan so thach anh 20MHz

#INT_EXT //Ngat ngoai - chan B0
void NgatNgoai(){
    CLEAR_INTERRUPT(INT_EXT); //Xoa co ngat
    DISABLE_INTERRUPTS(GLOBAL); //vo hieu hoa ngat toan cuc

    //Xu ly chuong trinh ngat
    delay_ms(20);
    if (INPUT(PIN_B0) == 0){ 
        PORTE = ~PORTE; //Dao trang thai PORT E
    }
    ENABLE_INTERRUPTS(GLOBAL); //Cho phep ngat toan cuc
}

void main(){
    TRISB = 0XFF; //Chan INPUT
    TRISE = 0x00; //Chan OUTPUT

    PORT_B_PULLUPS(0x01); //Noi dien tro len nguon
    PORTE = 0x00; //Set gia tri ban dau la muc 0

    ENABLE_INTERRUPTS(INT_EXT); //Kich hoat ngat ngoai
    EXT_INT_EDGE(H_TO_L); //Chon canh ngat, cao xuong thap
    ENABLE_INTERRUPTS(GLOBAL); //Cho phep ngat toan cuc

    while (True){ //Duy tri hoat dong cua vi dieu khien
        ;
    }
}

