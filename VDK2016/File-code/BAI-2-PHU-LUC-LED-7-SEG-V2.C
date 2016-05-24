/*Yeu cau:
  Chuong trinh hien thi so tu 0 - 9, A - F hien thi len LED 7 DOAN
  ( Phuong phap dieu khien thong qua IC ghi dich 74HC595)
 */
//Ten file: BAI-2-PHU-LUC-LED-7-SEG-V2.C
#include<16F887.h> //Khai bao ten PIC
#include<def_887.h> //Thu vien do nguoi dung dinh nghia

#FUSES NOWDT, HS, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP, NOCPD, NOWRT
#use delay(clock = 20000000) //Tan so thach anh 20MHz

#define Clock PIN_E0 //Chan SH_CP
#define Data PIN_E1  //Chan SD
#define Latch PIN_E2 //Chan ST_CP

void add_byte_74hc595(unsigned char data_byte); //Ghi 1 byte vao IC
void output_byte_74hc595(); //Cho phep xuat du lieu ra cac chan Q0 - Q7

//Khai bao ma code cho LED 7 doan co Anode chung
//Cac so tu 0 - 9; cac chu tu A - F
unsigned char code7seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};
void main(){
    int i;
    TRISE = 0x00; //Tat ca cac chan o PORT E la chan xuat (output)
    
    while (True){
        for (i = 0; i <= 16; i++){
            add_byte_74hc595(Code7seg[i]);
            output_byte_74hc595();
            delay_ms(1000);
        }
    }
    
}

void add_byte_74hc595(unsigned char data_byte){//Ghi 1 byte vao IC
    int i;
    output_low(Clock); //Muc thap
    for (i=0; i<8; i++){
        //Lay ra tung bit de ghi vao chip
        if ((data_byte & 0x80) == 0){ //So sanh bit
            output_low(Data); //ghi vao IC bit 0
        }
        else{
            output_high(Data); //ghi vao IC bit 1 
        }
        
        data_byte = data_byte << 1; //Bo di bit da duoc o tren
        output_high(Clock); //Muc cao
        //Ghi duoc 1 bit vao IC
        
        //Tiep tuc ghi cac bit tiep theo
        output_low(Clock); //Muc thap
    }
}

void output_byte_74hc595(){//Cho phep xuat du lieu trong ra cac chan Q0 - Q7
    output_low(Latch); //Muc thap
    delay_us(5);
    output_high(Latch); //Muc cao
    //Cho phep xuat du lieu
}
