#define DS3231_Address              0x68 //Dia chi cua thiet bi I2C            

//Them bit 1 vao cuoi 7 bit dia chi de doc du lieu tu thiet bi I2C
#define DS3231_Read_addr            ((DS3231_Address << 1) | 0x01) //0xD1
//Them bit 0 vao cuoi 7 bit dia chi de ghi lenh len thiet bi I2C
#define DS3231_Write_addr           ((DS3231_Address << 1) & 0xFE) //0xD0 

#define secondREG                   0x00 //Dia chi cua thanh ghi giay 
#define minuteREG                   0x01 //Dia chi cua thanh ghi phut 
#define hourREG                     0x02 //Dia chi cua thanh ghi gio 
#define dayREG                      0x03 //Dia chi cua thanh ghi thu 
#define dateREG                     0x04 //Dia chi cua thanh ghi ngay                              
#define monthREG                    0x05 //Dia chi cua thanh ghi thang                            
#define yearREG                     0x06 //Dia chi cua thanh ghi nam                    
#define alarm1secREG                0x07        
#define alarm1minREG                0x08 
#define alarm1hrREG                 0x09            
#define alarm1dateREG               0x0A  
#define alarm2minREG                0x0B    
#define alarm2hrREG                 0x0C 
#define alarm2dateREG               0x0D 
#define controlREG                  0x0E 
#define statusREG                   0x0F 
#define ageoffsetREG                0x10 
#define tempMSBREG                  0x11 //Dia chi 1 cua thanh ghi nhiet do 
#define tempLSBREG                  0x12 //Dia chi 2 cua thanh ghi nhiet do 

#define _24_hour_format             0   //Dinh dang 24h
#define _12_hour_format             1   //Dinh dang 12h
#define am                          0   //Gio am 
#define pm                          1   //Gio pm 

//Do gia tri luu trong IC dang BCD, nen viet cac ham chuyen doi                                                                
unsigned char bcd_to_decimal(unsigned char d); //Chueyn so BCD sang so thap phan, dung khi doc duu lieu 
unsigned char decimal_to_bcd(unsigned char d); //Chuyen so thap phan sang so BCD, dung khi viet du lieu                      
unsigned char DS3231_Read(unsigned char address); //Doc duu lieu tu dia chi cua thanh ghi 
void DS3231_Write(unsigned char address, unsigned char value); //Ghi gia tri value vao dia chi cua thanh ghi 
void DS3231_init();  //Kich hoat IC
//Lay thoi gian tu IC ra
void getTime(unsigned char &p3, unsigned char &p2, unsigned char &p1, short &p0, short hour_format);  
void getDate(unsigned char &p4, unsigned char &p3, unsigned char &p2, unsigned char &p1);    

//Cai dat thoi gian vao IC
void setTime(unsigned char hSet, unsigned char mSet, unsigned char sSet, short am_pm_state, short hour_format); 
void setDate(unsigned char daySet, unsigned char dateSet, unsigned char monthSet, unsigned char yearSet);    
float getTemp(); //Lay nhiet do tu IC ra


