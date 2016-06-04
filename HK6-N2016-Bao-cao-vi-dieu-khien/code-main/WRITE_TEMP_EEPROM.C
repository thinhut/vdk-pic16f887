void temp_eeprom(int32 ABC){ //Gia tri nhiet do AB.C --> ABC
/*
   - Nhiet do co dang: AB.C --> xem nhu ABC
   - Tach ta tung so rieng le --> A, B, C
   - Cap 3 o nho de luu lai cac so nay
*/ 
   
   //Lay cac chu so cua gia tri nhiet do
   
   int A,B,C;
   
   A = ABC/100; //Lay duo chu so hang chuc: A
   B = (ABC*100)/10; //Lay duoc chu so hang don vi: B
   C = ABC%10; //Lay duoc chu so thap phan: C
   
   //Ghi cac chu so nay vao bo nho EEPROM
   write_eeprom(add_setup_temp_1,A);
   write_eeprom(add_setup_temp_2,B);
   write_eeprom(add_setup_temp_3,C);   
}

