/*Yeu cau:
  Chuong trinh hien thi so tu 0-9999 hien thi len 4 LED 7 DOAN
  ( Phuong phap dieu khien thong qua IC ghi dich 74HC595)
 */
//Ten file: BAI-2-PHU-LUC-4-LED-7-SEG-V2.C
#include<16F887.h> //Khai bao ten PIC
#include<def_887.h> //Thu vien do nguoi dung dinh nghia

#FUSES NOWDT, HS, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP, NOCPD, NOWRT
#use delay(clock = 20000000) //Tan so thach anh 20MHz

#define Clock PIN_E0 //Chan SH_CP
#define Data PIN_E1  //Chan SD
#define Latch PIN_E2 //Chan ST_CP

void add_byte_74hc595(unsigned char data_byte); //Ghi 1 byte vao IC
void output_byte_74hc595(); //Cho phep xuat du lieu trong ra cac chan Q0 - Q7


//Khai bao ma code cho LED 7 doan co Anode chung
//Cac so tu 0 - 9; cac chu tu A - F
unsigned char code7seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
unsigned char digits[] = {0x01, 0x02, 0x04, 0x08};
void main(){
    unsigned long count, i;
    int a,b,c,d;
    TRISE = 0x00; //Tat ca cac chan o PORT E la chan xuat (output)
    
    while (True){
        for (count = 0; count <= 9999; count++){
            a = count / 1000;
            b = (count%1000)/100;
            c = (count%100)/10;
            d = (count%100)%10;
            for (i = 0; i < 1500; i ++){
                add_byte_74hc595(digits[0]);
                add_byte_74hc595(Code7seg[a]);
                output_byte_74hc595();
                
                add_byte_74hc595(digits[1]);
                add_byte_74hc595(Code7seg[b]);
                output_byte_74hc595();
                    
                add_byte_74hc595(digits[2]);
                add_byte_74hc595(Code7seg[c]);
                output_byte_74hc595();
                
                add_byte_74hc595(digits[3]);
                add_byte_74hc595(Code7seg[d]);
                output_byte_74hc595();               
            }
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
