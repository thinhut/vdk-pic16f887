/*Yeu cau:
Chuong trinh do khoang cach tu cam bien sieu am
*/
//Ten file: BAI-9-1.C
#include<16F887.h> //Khai bao ten PIC
#include<def_887.h> //Thu vien do nguoi dung dinh nghia
#include<string.h>
#FUSES HS, NOWDT, NOPROTECT, NOLVP
#use delay(clock = 20000000) //Tan so thach anh 20MHz
#include<LCD_LIB_4BIT.C>
#define PIN_TRIGGER PIN_A3

int1 echo = 0;
int16 value = 0;

void Trigger(){
    OUTPUT_HIGH(PIN_TRIGGER);
    delay_us(12);
    OUTPUT_LOW(PIN_TRIGGER);    
}

#INT_CCP1
void CCP1_ISR(void){
    if (echo == 1){
        SETUP_CCP1(CCP_CAPTURE_FE);
        SET_TIMER1(0);
        echo = 0;
    }
    else{
        SETUP_CCP1(CCP_CAPTURE_RE);
        value = CCP_1;
        echo = 1;
    }
}

void main(){
    float distance = 0;    
    OUTPUT_LOW(LCD_RW);
    LCD_Init();
    LCD_PutCmd(0x01);
    
    SETUP_TIMER_1(T1_INTERNAL|T1_DIV_BY_4);
    SETUP_CCP1(CCP_CAPTURE_RE);
    
    ENABLE_INTERRUPTS(INT_CCP1);
    ENABLE_INTERRUPTS(GLOBAL);  
    
    while (True){
        Trigger();                
        while (echo == 0){
            ;
        }        
        distance = value*0.8/58;
        LCD_PutCmd(0x01);
        LCD_SetPosition(0x00);
        LCD_PutChar("Distance:");
        LCD_SetPosition(0x40);
        printf(LCD_PutChar,"%.2fcm",distance);
        printf("%f\n",distance);
        delay_ms(1000);
    }
}
