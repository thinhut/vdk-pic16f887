#include "DS3231.h"                                                        

// Thuc hien chuye so BCD sang so thap phan
//Tach 8 bit cua ma BCD: chuyen 4 bit do thanh mo so thap phan
//Ghep 2 so thap phan do lai voi nhau.
//Ham nay dung chuyen doi khi doc du lieu
unsigned char bcd_to_decimal(unsigned char d){
   return ((d & 0x0F) + (((d & 0xF0) >> 4) * 10)); 
}                                


//Chuyen so thap phan sang ma BCD
//Bien doi tung so thap phan thanh ma nhi phan
//Ghep cac ma nhi phan nay theo thu tu duoc ma BCD
//Ham nay dung khi muon ghi vao IC
unsigned char decimal_to_bcd(unsigned char d){
   return (((d / 10) << 4) & 0xF0) | ((d % 10) & 0x0F); 
}                                                    

//Doc du lieu tu thanh ghi dia chi                  
unsigned char DS3231_Read(unsigned char address){
   unsigned char value = 0; 
   I2C_start();                //Tao dieu kien Start                                                      
   I2C_write(DS3231_Write_addr); //Ghi len dia chi (da them bit 1) vao cuoi 7 bit     
   I2C_write(address);          //Gui lenh yeu cau (tuy thuoc vao gia tri address)  
   I2C_start();                 //Tao dieu kien Start, giao tiep moi 
   I2C_write(DS3231_Read_addr); //Ghi len dia chi (da them bit 1) vao cuoi 7 bit   
   value = I2C_read(0);         //Gui lenh doc du lieu tu IC             
   I2C_stop();                  //Tao dieu kien Stop, ket thuc giao tiep
   return value; 
}                      

//Ghi du lieu tu thanh ghi dia chi
//Giai thich tuong tu nhu ham DS3231_Read
void DS3231_Write(unsigned char address, unsigned char value){
   I2C_start();                  
   I2C_write(DS3231_Write_addr); 
   I2C_write(address); 
   I2C_write(value);    
   I2C_stop(); 
}  

//Khoi tao hoat dong cho IC
void DS3231_init(){
   DS3231_Write(controlREG, 0x00);  
   DS3231_Write(statusREG, 0x08); 
}                        


//Lay thoi gian (h,m,s) tu IC, doc duoc o gia tri BCD --> so thap phan
void getTime(unsigned char &p3, unsigned char &p2, unsigned char &p1, short &p0, short hour_format){
   unsigned char tmp = 0; 
   p1 = DS3231_Read(secondREG); 
   p1 = bcd_to_decimal(p1); 
   p2 = DS3231_Read(minuteREG); 
   p2 = bcd_to_decimal(p2); 
   switch(hour_format){                                              
      case 1:{          
                tmp = DS3231_Read(hourREG); 
                tmp &= 0x20; 
                p0 = (short)(tmp >> 5);              
                p3 = (0x1F & DS3231_Read(hourREG)); 
                p3 = bcd_to_decimal(p3);                            
                break;      
             }    
      default: { 
             p3 = (0x3F & DS3231_Read(hourREG));            
             p3 = bcd_to_decimal(p3);    
             break;      
          } 
   }  
}                                  

//Lay thoi gian (year,month,date,day) tu IC, doc duoc o gia tri BCD --> so thap phan
void getDate(unsigned char &p4, unsigned char &p3, unsigned char &p2, unsigned char &p1){
   p1 = DS3231_Read(yearREG); 
   p1 = bcd_to_decimal(p1);                  
   p2 = (0x1F & DS3231_Read(monthREG)); 
   p2 = bcd_to_decimal(p2);                                
   p3 = (0x3F & DS3231_Read(dateREG)); 
   p3 = bcd_to_decimal(p3);    
   p4 = (0x07 & DS3231_Read(dayREG));    
   p4 = bcd_to_decimal(p4);                    
} 

//Cai dat gio, phut, giay vao IC
void setTime(unsigned char hSet, unsigned char mSet, unsigned char sSet, short am_pm_state, short hour_format)  
{
   unsigned char tmp = 0; 
   DS3231_Write(secondREG, (decimal_to_bcd(sSet))); 
   DS3231_Write(minuteREG, (decimal_to_bcd(mSet)));        
   switch(hour_format){
      case 1:{        
                switch(am_pm_state){ 
                   case 1:{            
                        tmp = 0x60; 
                        break; 
                     } 
                   default:{    
                         tmp = 0x40; 
                         break; 
                      } 
                }                            
                DS3231_Write(hourREG, ((tmp | (0x1F & (decimal_to_bcd(hSet))))));                    
                break; 
             }                                              

      default:{ 
            DS3231_Write(hourREG, (0x3F & (decimal_to_bcd(hSet)))); 
            break; 
         }  
   }    
}                                                  

//Cai dat thu, ngay, thang, nam vao IC
void setDate(unsigned char daySet, unsigned char dateSet, unsigned char monthSet, unsigned char yearSet){          
   DS3231_Write(dayREG, (decimal_to_bcd(daySet)));            
   DS3231_Write(dateREG, (decimal_to_bcd(dateSet)));  
   DS3231_Write(monthREG, (decimal_to_bcd(monthSet))); 
   DS3231_Write(yearREG, (decimal_to_bcd(yearSet)));    
} 

//Lay gia tri nhiet do tu IC
float getTemp(){ 
   register float t = 0.0; 
   unsigned char lowByte = 0; 
   signed char highByte = 0; 
   lowByte = DS3231_Read(tempLSBREG); 
   highByte = DS3231_Read(tempMSBREG);  
   lowByte >>= 6;                  
   lowByte &= 0x03;      
   t = ((float)lowByte);  
   t *= 0.25;      
   t += highByte;          
   return t;                                      
}

