#include <16f887.h> //Ten chip
#include "def_887.h" //Dinh nghia cac dia chi cac chan cua chip
#FUSES NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT,NOLVP, NOCPD, NOWRT
#use delay(clock=20000000) //Tan so thach anh 20MHz

#include <MATH.H> //Khai bao thu vien de su dung cac ham tinh toan

#include "DEF_PIN.H" //Dinh nghia cac chan duoc su dung trong chuong trinh

#include "ADDRESS_EEPROM.H" //Khai bao dia chi EEPROM de luu du lieu

#include "LCD_LIB_4BIT.C" //Thu vien LCD

//Khai bao cac ham cua cam bien DS18B20 
#include "ONEWIRE.C" //Giao tiep 1 day
#include "DS18B20.C" //Doc nhiet do tu cam bien DS18B20

#include "BUTTON.C" //Doc gia tri tu ban phim
#include "RELAY.C"


