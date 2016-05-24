%Mo cong COM, thiet lap toc do truyen phai phu hop voi code dieu kien PIC
s = serial('com6','BaudRate',9600);%Thay doi gia tri cong COM
fopen(s); %Mo cong COM
fprintf(s,'b'); %Gui lenh thu nhat: bat LED
%Tiep tuc gui lenh thu 2
fprintf(s,'t') %Lenh thu 2: tat LED

	%Khi khong con lam viec, ta dong cong COM lai
fclose(s)

