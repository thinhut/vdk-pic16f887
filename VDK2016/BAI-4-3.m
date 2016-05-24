s = serial('COM6'); %Thay doi gia tri cong COM
%Thiet lap gia tri cho tham so BytesAvailableFcn de hien thi gia tri do vi dieu khien gui len 
s.BytesAvailableFcn = @Serial_Callback;
fopen(s); %Mo cong COM de giao tiep
%%Du lieu duoc tu dong gui len va hien thi

%%Khi khong giao tiep, dong cong COM lai:
fclose(s);