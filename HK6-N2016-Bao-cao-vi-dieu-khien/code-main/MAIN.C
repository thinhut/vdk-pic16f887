#include "INCLUDES.H"


float temp_float;
float nhietdo_setup;

void main(){
   int temp1, temp2,temp3; // Bien duoc do ra tu EEPROM
   int keypad[10],i, position;
   int B_ENTER, B_EXIT, E0;
   
   temp1 = read_eeprom(add_setup_temp_1);
   temp2 = read_eeprom(add_setup_temp_2);
   temp3 = read_eeprom(add_setup_temp_3);
   nhietdo_setup = temp1*10 + temp2 + temp3*0.1; //Gia tri nhiet do setup
   
   Output_low(LCD_RW);
   LCD_Init();
   
   TRISB = 0xFF;
   TRISE = 0xFF;
   LCD_PutCmd(0x01);
   LCD_SetPosition(0x00); //Chuyen vi tri con tro sang dong 1
      
   printf(lcd_putchar,"Setup: %.1f",nhietdo_setup);
   lcd_putchar(223);
   printf(lcd_putchar,"C");   
 
   while (true){
      //Doc gia tri nhiet do tu cam bien DS18B20
      temp_float = ds18b20_read(); 
      LCD_SetPosition(0x40); //Chuyen vi tri con tro sang dong 2
      printf(lcd_putchar,"Measure: %.1f",temp_float);
      lcd_putchar(223);
      printf(lcd_putchar,"C");
      OF_RELAY(temp_float, nhietdo_setup);
      E0 = input(SETUP_EXIT);
      if (E0 == 0){
         //while (input(SETUP_EXIT)==0) ;
         
         LCD_PutCmd(0x01);
         LCD_SetPosition(0x00);
         printf(lcd_putchar,"SETUP TEMP: ");
        
         delay_ms(1000);
         i = 0;
         position = 64;
         //Khi chua nhan nut EXIT hay ENTER 
         B_EXIT = input(SETUP_EXIT);
         B_ENTER = input(ENTER);
         while ((B_ENTER==1) | (B_EXIT == 1)){
            int value;
            B_EXIT = input(SETUP_EXIT);
            B_ENTER = input(ENTER);
            value = READ_BUTTON();
            //Chi cho nhap va hien thi 3 so
            if ((value >= 0) && (value < 10) && (i<=2)){
              LCD_SetPosition(position);
              printf(lcd_putchar,"%d",value);
              delay_ms(1000);
              keypad[i] = value; 
              i++;
              position++;
            }
            else 
               //Khi da nhap du 3 so va nhan nut ENTER
               if ((value == 100) && (i>=3)){
                  write_eeprom(add_setup_temp_1,keypad[0]);
                  write_eeprom(add_setup_temp_2,keypad[1]);
                  write_eeprom(add_setup_temp_3,keypad[2]);
                  
                  temp1 = read_eeprom(add_setup_temp_1);
                  temp2 = read_eeprom(add_setup_temp_2);
                  temp3 = read_eeprom(add_setup_temp_3);
                  nhietdo_setup = temp1*10 + temp2 + temp3*0.1; //Gia tri nhiet do setup
                  
                  LCD_PutCmd(0x01);
                  LCD_SetPosition(0x00); //Chuyen vi tri con tro sang dong 1
      
                  printf(lcd_putchar,"Setup: %.1f",nhietdo_setup);
                  lcd_putchar(223);
                  printf(lcd_putchar,"C");
                  
                  temp_float = ds18b20_read(); 
      
                  LCD_SetPosition(0x40); //Chuyen vi tri con tro sang dong 2
                  printf(lcd_putchar,"Measure: %.1f",temp_float);
                  lcd_putchar(223);
                  printf(lcd_putchar,"C");
                  break;                  
               }
               else 
                  if (value == 50){ //Khi da nhan nut EXIT thi thoat khoi vong lap
                     LCD_PutCmd(0x01);
                     LCD_SetPosition(0x00); //Chuyen vi tri con tro sang dong 1
      
                     printf(lcd_putchar,"Setup: %.1f",nhietdo_setup);
                     lcd_putchar(223);
                     printf(lcd_putchar,"C");
                     
                     temp_float = ds18b20_read(); 
      
                     LCD_SetPosition(0x40); //Chuyen vi tri con tro sang dong 2
                     printf(lcd_putchar,"Measure: %.1f",temp_float);
                     lcd_putchar(223);
                     printf(lcd_putchar,"C");
     
                     break;
                 }
            }
      }
   }
}
