/*Yeu cau
  Chuong trinh doc ADC tu bien tro va xuat ra LED
 */
//Ten file BAI-4-2.C
#include<16f887.h>
#include<def_887.h>
#device *= 16 ADC = 10
#fuses HS,NOWDT, NOPROTECT, NOLVP
#use delay(clock=20000000) //Tan so thach anh 20MHz
#include<LCD_LIB_4BIT.C>  //Them thu vien LCD vao

void main(){
    int16 adc, a[10];
    int count, i, pos;

    TRISE = 0x00;
    OUTPUT_LOW(LCD_RW); //Che do ghi 
    LCD_Init();        //Khoi tao LCD

    LCD_PutCmd(0x01);  //Xoa man hinh

    //Xac dinh cach thuc hoat dong cua bo ADC
    //Thoi gian lay mau bang xung clock
    SETUP_ADC(ADC_CLOCK_INTERNAL);
    SET_ADC_CHANNEL(3);      //Su dung chan A3 doc ADC
    delay_us(10);            //Dam bao doc gia gia ADC chinh xac

    while (True){
        adc = READ_ADC();   //Doc ADC tu chan A3
        OUTPUT_E(adc); //Dua gia tri ADC vao cong E

        LCD_SetPosition(0x00); //Cot 1 dong 1
        LCD_PutChar("Read ADC:");
        LCD_SetPosition(0x09); //Cot 10 dong 1
        printf(LCD_PutChar,"%lu",adc); //Hien thi len LCD


        //Chuyen sang nhi phan hien thi LCD        
        count = 0;

        //Chuyen sang ma nhi phan
        while (adc > 0){  //Con chia duoc
            a[count] = adc%2;
            adc = adc/2;
            count++;
        }

        //Hien len LCD
        LCD_SetPosition(0x40);
        LCD_PutChar("Bin:"); //Gia tri nhi phan
        LCD_SetPosition(0x44);
        pos = 68; //0x44 = 64
        for (i = count - 1; i>=0; i--){
            printf(LCD_PutChar,"%lu",a[i]);
            pos++;
            LCD_SetPosition(pos);
            if (i == 0){ 
                break;
            }
        }

        delay_ms(1000);
    }      
}

