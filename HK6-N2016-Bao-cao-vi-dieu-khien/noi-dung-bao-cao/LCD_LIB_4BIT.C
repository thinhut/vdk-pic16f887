#include <stddef.h>

#define Line_1 0x80
#define Line_2 0xC0
#define Clear_Scr = 0x01


#separate void LCD_Init(void);
#separate void LCD_SetPosition(unsigned int cX);
#separate void LCD_PutChar(unsigned int cX);
#separate void LCD_PutCmd(unsigned int cX);
#separate void LCD_PulseEnable(void);
#separate void LCD_setData(unsigned int cX);

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

