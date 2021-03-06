/*Yeu cau
  Chuong trinh lay thoi gian thuc tu IC DS3231
 */
//Ten file BAI-6-2-2.C 
#include<16f887.h>
#include<def_887.h>
#include<string.h>
#fuses HS,NOWDT, NOPROTECT, NOLVP
#use delay(clock=20000000) //Tan so thach anh 20MHz
#use I2C(Master, SDA = pin_C4, SCL = pin_C3) //Giao tiep I2C
#include<LCD_LIB_4BIT.C>  //Them thu vien LCD vao
#include<DS3231.C>
unsigned char s, min, hr, dy, dt, mt, yr;
short am_pm;
char day[3],ampm[2];
void main(){
	OUTPUT_LOW(LCD_RW); //Che do ghi 
	LCD_Init();        //Khoi tao LCD
	DS3231_init();

	//Ta danh dau chu thich di 2 dong cai dat thoi gian ban dau, 
	//de lay thoi gian thuc
	//setTime(10,30,0,0, _12_hour_format);
	//setDate(3,19,4,16);
	getTime(hr, min, s, am_pm, _12_hour_format);
	getDate(dy, dt, mt, yr);
	LCD_PutCmd(0x01);  //Xoa man hinh

	while (True){
		getTime(hr, min, s, am_pm, _12_hour_format);
		getDate(dy, dt, mt, yr);

		switch(dy){ //Tu cac so 1 - 7: dung cau truc switch - case tinh ra thu
			case 1:{
				       strcpy(day,"Sun"); //Copy chuoi "Sun" vao chuoi day
				       break;
			       }
			case 2:{
				       strcpy(day,"Mon");
				       break;
			       }
			case 3:{
				       strcpy(day,"Tus");
				       break;
			       }
			case 4:{
				       strcpy(day,"Wed");
				       break;
			       }
			case 5:{
				       strcpy(day,"Thu");
				       break;
			       }
			case 6:{
				       strcpy(day,"Fri");
				       break;
			       }
			case 7:{
				       strcpy(day,"Sat");
				       break;
			       }
		}

		switch (am_pm){ //Tinh ra gio AM hay gio PM
			case 0:{
				       strcpy(ampm,"AM"); //Copy chuoi "AM" vao chuoi ampm
				       break;
			       }
			case 1:{
				       strcpy(ampm,"PM");
				       break;
			       }
		}

		//Hien thi ket qua len LCD
		LCD_SetPosition(0x03);
		printf(LCD_PutChar,"%02d:%02d:%02d %c%c",hr,min,s,ampm[0],ampm[1]);
		LCD_SetPosition(0x41);
		printf(LCD_PutChar,"%c%c%c-%02d-%02d-20%02d",day[0],day[1],day[2],dt,mt,yr);    
	}

}

