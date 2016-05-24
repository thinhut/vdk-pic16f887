#include <stddef.h>
#define LCD_RS PIN_D1
#define LCD_RW PIN_D2
#define LCD_EN PIN_D3

#define LCD_D4 PIN_D4
#define LCD_D5 PIN_D5
#define LCD_D6 PIN_D6
#define LCD_D7 PIN_D7

#define Line_1 0x80
#define Line_2 0xC0
#define Clear_Scr = 0x01


#separate void LCD_Init(void); //Ham khoi tao LCD
#separate void LCD_SetPosition(unsigned int cX); //Thiet lap vi tri con tro
#separate void LCD_PutChar(unsigned int cX); //Ham viet mot ky tu hoac mot chuoi len LCD
#separate void LCD_PutCmd(unsigned int cX); //Ham gui lenh len LCD
#separate void LCD_PulseEnable(void); //Xung kich hoat
#separate void LCD_setData(unsigned int cX); //Dat du lieu len chan Data

//Dinh nghia cong
#use standard_io(C)
#use standard_io(D)

#separate void LCD_Init(void){
	LCD_SetData(0x00);
	delay_ms(200);
	output_low(LCD_RS);
	LCD_SetData(0x03);
	LCD_PulseEnable();
	LCD_PulseEnable();
	LCD_PulseEnable();
	LCD_SetData(0x02);   
	LCD_PulseEnable();
	LCD_PutCmd(0x2C);
	LCD_PutCmd(0x0C);
	LCD_PutCmd(0x06);
	LCD_PutCmd(0x01);
}

#separate void LCD_SetPosition(unsigned int cX){
	LCD_setData(swap(cX)|0x08);
	LCD_PulseEnable();
	LCD_setData(swap(cX));
	LCD_PulseEnable();
}

#separate void LCD_PutChar(unsigned int cX){
	output_high(LCD_RS);
	LCD_PutCmd(cX);
	output_low(LCD_RS);  
}

#separate void LCD_PutCmd(unsigned int cX){
	LCD_SetData(swap(cX));
	LCD_PulseEnable();
	LCD_SetData(swap(cX));
	LCD_PulseEnable();
}

#separate void LCD_PulseEnable(void){
	output_high(LCD_EN);
	delay_us(3);
	output_low(LCD_EN);
	delay_ms(3);   
}

#separate void LCD_setData(unsigned int cX){
	output_bit(LCD_D4,cX & 0x01);
	output_bit(LCD_D5,cX & 0x02);
	output_bit(LCD_D6,cX & 0x04);
	output_bit(LCD_D7,cX & 0x08);
}

