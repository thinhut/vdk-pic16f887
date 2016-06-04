#include <16f887.h> //Ten chip
#include "def_887.h" //Dinh nghia cac dia chi cac chan cua chip
#FUSES NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT,NOLVP, NOCPD, NOWRT
//Tan so thach anh 20MHz
#use delay(clock=20000000) 
//Khai bao thu vien de su dung cac ham tinh toan
#include <MATH.H> 

//Dinh nghia cac chan duoc su dung trong chuong trinh
#include "DEF_PIN.H" 

//Khai bao dia chi EEPROM de luu du lieu
#include "ADDRESS_EEPROM.H" 

//Thu vien LCD
#include "LCD_LIB_4BIT.C" 

//Khai bao cac ham cua cam bien DS18B20 
#include "ONEWIRE.C" //Giao tiep 1 day
//Doc nhiet do tu cam bien DS18B20
#include "DS18B20.C" 

//Doc gia tri tu ban phim
#include "BUTTON.C" 
#include "RELAY.C"
