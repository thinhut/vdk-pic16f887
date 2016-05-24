//Yeu cau: Mo phong cam bien nhiet TC74 voi Protues
//Ten file BAI-6-1V2.C - Mo phong duoc voi Protues
#include<16f887.h>
#include<def_887.h>
#fuses HS,NOWDT, NOPROTECT, NOLVP
#use i2c(master, SDA = PIN_C4, SCL = PIN_C3)
#use delay(clock=20000000)
#include<lcd_lib_4bit.c>

int temp;
void main(){
	Output_low(LCD_RW); //Che do ghi 
	LCD_init(); //Khoi tao LCD  
	lcd_putcmd(0x01);
	delay_ms(100);
	printf(lcd_putchar,"Nhiet do: ");
	while (true){
		i2c_start();   //Tao dieu kien start de giao tiep
		i2c_write(0x9A); //Dia chi thiet bi I2C, tra trang 9 cua Datasheet
		i2c_write(0x00); //Gui lenh yeu cau doc nhiet do
		i2c_start();   //Tao lai dieu kien start
		i2c_write(0x9B); //Thiet bi chu yeu cau duoc doc du lieu cua thiet bi to
		temp = i2c_read(0); //Gui lenh doc gia tri nhiet do
		i2c_stop();      //Tao dieu kien Stop, ket thuc giao tiep
		LCD_SetPosition(0x09);
		printf(lcd_putchar,"%u",temp); //Hien thi nhiet do doc duoc len LCD 
		lcd_putchar(223);
		printf(lcd_putchar,"C");
		delay_ms(1000);
	}
}

