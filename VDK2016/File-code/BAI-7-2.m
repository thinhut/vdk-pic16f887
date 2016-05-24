%Mo cong COM, thiet lap toc do truyen phai phu hop voi code dieu kien PIC
s = serial('com6','BaudRate',9600);%Thay doi gia tri cong COM
fopen(s); %Mo cong COM
fprintf(s,'TT VI DIEU KHIEN'); %Gui chuoi xuong vi dieu khien
	%Khi khong con lam viec, ta dong cong COM lai
fclose(s)

