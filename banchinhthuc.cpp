#include <bits/stdc++.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct sinhvien	{		
	float lab;
	float pres;
	float mid;
	float final;
	float dtb; 
};
typedef struct sinhvien diem;

void Title() {
	printf(" +------------------------------------------------------------------------------------------------------+\n");
	printf(" |	    		CHUONG TRINH QUAN LI DIEM SINH VIEN		      				|\n");
	printf(" |		    	Supervisor:  Tran Ho Thuy Tien		              				|\n");
	printf(" | 		    	Students:  Le Hoang Ngoc Han		       				  	|\n");
	printf(" |		         	   Truong Thi My Duyen			      				|\n");
	printf(" |			Class:  19TCLC - DT4				      				|\n");
	printf(" +------------------------------------------------------------------------------------------------------+\n");
}
void Login()	{
	char user[10];
	int pass;
	int i=0, j=0;
	printf("\nNhap ten dang nhap:	  ");
	gets(user);
	while(((strcmp(user,"tien"))!=0)&&((strcmp(user,"hoa"))!=0)) {
		printf("\t\tNhap sai user! Nhap lai:  ");
		gets(user);
		i+=1;
		if (i==3) {
			printf("\t\tNhap sai qua 3 lan. Thoat chuong trinh!");
			exit(0);
		}
	}
	do {
		printf("Nhap password:	          ");
		scanf("%d",&pass);
		j+=1;
		if(j==4) {
		printf("\t\tNhap sai qua 3 lan. Thoat chuong trinh!");
		exit(0);
		}
	}
	while(pass!=2020);
	printf("\n\t\tNhap mat khau thanh cong!");
	printf("\n +------------------------------------------------------------------------------------------------------+");
	printf("\n |		 	CHUONG TRINH BAT DAU THUC HIEN!	 				    		 |");
	printf("\n +------------------------------------------------------------------------------------------------------+");
	getch();
}

void Menu() {
	system("cls");
	printf(" +------------------------------------------------------------------------------------------------------------------+");
	printf("\n |		 	                 	MENU CHUC NANG	  					       	    |");
	printf("\n +------------------------------------------------------------------------------------------------------------------+");
	printf("\n |				1 - NHAP DIEM				      			        	    |");
	printf("\n |				2 - XEM DIEM				      					    |");
	printf("\n |				3 - SUA DIEM				      					    |");
	printf("\n |				4 - SAP XEP DIEM			     					    |");
	printf("\n |				5 - IN DANH SACH			      					    |");
	printf("\n |				0 - THOAT			    	      					    |");
	printf("\n +-------------------------------------------------------------------------------------------------------------------+");
}

void mangmsv(int n, char msv[][100],FILE *fmsv)  {			// Doc ma SV tu file vao mang 1 chieu
	fmsv=fopen("C:\\Users\\PC\\Desktop\\project\\msv.txt","r");
	for(int i=0;i<=n;i++){
			fscanf(fmsv,"%s",&msv[i]);
	}
	fclose(fmsv);
}

void mangten(int n, char ten[][100],FILE *ften)  {		   // Doc ho ten SV tu file vao mang 1 chieu			
	ften=fopen("C:\\Users\\PC\\Desktop\\project\\ten.txt","r");
	for(int i=0;i<=n;i++){
			fgets(ten[i],100,ften);
			fflush(stdin);
		}
	fclose(ften);
}

void mangdiem(int n, float diem[][5],FILE *fd, float dtb[])  {		// Doc diem tu file vao mang 2 chieu
	fd=fopen("C:\\Users\\PC\\Desktop\\project\\diem13.txt","r");
		for(int i=0;i<n;i++)  {
		for(int j=0;j<5;j++)  {
				fscanf(fd,"%f",&diem[i][j]);
			}
		}
		for(int i=0;i<n;i++)  {
			dtb[i]=diem[i][4];
		}
	fclose(fd);
}

void DTB(diem &sv)  {		// Tinh diem trung binh
	sv.dtb=0.1*sv.lab+0.1*sv.pres+0.3*sv.mid+0.5*sv.final;
}

void nhap(diem &sv,FILE *fd)	{		// Nhap diem 1 sinh vien vao file
	do {
		printf("Nhap diem cot Lab: ");
		scanf("%f",&sv.lab);
	}
	while((sv.lab<0)||(sv.lab>10));
	fprintf(fd,"%.2f\t",sv.lab);
	do {
		printf("Nhap diem cot Pres: ");
		scanf("%f",&sv.pres);
	}
	while((sv.pres<0)||(sv.pres>10));
	fprintf(fd,"%.2f\t",sv.pres);
	do {
		printf("Nhap diem cot Mid: ");
		scanf("%f",&sv.mid);
	}
	while((sv.mid<0)||(sv.mid>10));
	fprintf(fd,"%.2f\t",sv.mid);
	do {
		printf("Nhap diem cot Final: ");
		scanf("%f",&sv.final);
	}
	while((sv.final<0)||(sv.final>10));
	fprintf(fd,"%.2f\t",sv.final);
	DTB(sv);
	fprintf(fd,"%.2f\n",sv.dtb);
}

void nhapN(diem sv[],int n,char (msv[100])[100] ,char (ten[100])[100],FILE *fd)  {		// Nhap diem n SV vao file
	fd=fopen("C:\\Users\\PC\\Desktop\\project\\diem13.txt","w");
	for(int i=0;i<n;i++){
		printf("\nNhap diem cho msv %s : \n",msv[i]);
		nhap(sv[i],fd);
	}
	fclose(fd);
}

char xeploai(float x)  {		// Quy doi diem he 10 sang he A,B,C,D
		if(x>=8) return 'A';
		if(x>=6.5&&x<8) return 'B';
		if(x>=5.0&&x<6.5) return 'C';
		if(x<5) return 'D';
}

void xem(char (msv[100])[100], char (ten[100])[100], int n, float diem[][5],char key[])	{		// Xem diem 1 SV theo ma SV	
	int  count = 0;
	for(int i=0;i<n;i++){
		if(strcmp(msv[i],key)!=0) ++count;
		else break;
	}
	if(count==n) printf("\n\tKhong tim thay ma sinh vien !");
	else {
		printf(" +----------------------------------------------------------------------------+\n");
		printf("\t\tKet qua cua SV: %s", ten[count+1]);
		printf(" +----------------------------------------------------------------------------+");
		printf("\n |    Lab     |    Pres    |    Mid    |    Final    |    Avg    |   Grade    |");
		printf("\n +----------------------------------------------------------------------------+");
		printf("\n |    %.2f    |    %.2f    |    %.2f   |    %.2f     |   %.2f    |     %2c     |",diem[count][0],diem[count][1],diem[count][2],diem[count][3],diem[count][4],xeploai(diem[count][4]));
		printf("\n +----------------------------------------------------------------------------+");
	}
}

void sua(FILE *fd, char (msv[100])[100],char (ten[100])[100],int n, float diem[][5],char key1[])  {		// Sua diem theo cot
	int cot;
	int count =0;
	for(int i=0;i<n;i++)	{
		if(strcmp(msv[i],key1)!=0) ++count;
		else break;
	}
	if(count == n ) printf("\n\tKhong co ma so sinh vien ban can sua !");
	else  {	
		printf("\n\tDiem truoc khi sua:\n ");
		printf("\tLab: %.2f\tPres: %.2f\tMid: %.2f\tFinal: %.2f\n",diem[count][0], diem[count][1], diem[count][2], diem[count][3]);
		printf("\n\tNhap cot diem ban muon sua : 1.Lab	2.Pres	 3.Mid	4.Final   ");
		scanf("%d",&cot);
		fd=fopen("C:\\Users\\PC\\Desktop\\project\\diem13.txt","w+");
		switch(cot){
			case 1 : 	// Sua diem cot Lab
				do {
				printf("\n\tNhap diem ban muon sua ( 0 <= diem <= 10 ) : ");
				scanf("%f",&diem[count][0]);
				} while((diem[count][0]<0)||(diem[count][0]>10));
				diem[count][4]=0.1*diem[count][0]+0.1*diem[count][1]+0.3*diem[count][2]+0.5*diem[count][3];
				printf("\tLab: %.2f   Pres: %.2f   Mid: %.2f   Final: %.2f   Avg: %.2f",diem[count][0], diem[count][1], diem[count][2], diem[count][3], diem[count][4]);
				for(int i=0;i<n;i++)	{
					for(int j=0;j<5;j++)	{
						fprintf(fd,"%.2f\t",diem[i][j]);
					}
					fprintf(fd,"\n");
				}
				break;
			case 2 : 	// Sua diem cot Pres
				do {
				printf("\n\tNhap diem ban muon sua ( 0 <= diem <= 10 ) : ");
				scanf("%f",&diem[count][1]);
				} while((diem[count][1]<0)||(diem[count][1]>10));
				diem[count][4]=0.1*diem[count][0]+0.1*diem[count][1]+0.3*diem[count][2]+0.5*diem[count][3];
				printf("\tLab: %.2f   Pres: %.2f   Mid: %.2f   Final: %.2f   Avg: %.2f",diem[count][0], diem[count][1], diem[count][2], diem[count][3], diem[count][4]);				
				for(int i=0;i<n;i++)	{
					for(int j=0;j<5;j++)	{
						fprintf(fd,"%.2f\t",diem[i][j]);
					}
					fprintf(fd,"\n");
				}
				break;
			case 3 : 	// Sua diem cot Mid
				do {
				printf("\n\tNhap diem ban muon sua ( 0 <= diem <= 10 ) : ");
				scanf("%f",&diem[count][2]);
				} while((diem[count][2]<0)||(diem[count][2]>10));
				diem[count][4]=0.1*diem[count][0]+0.1*diem[count][1]+0.3*diem[count][2]+0.5*diem[count][3];
				printf("\tLab: %.2f   Pres: %.2f   Mid: %.2f   Final: %.2f   Avg: %.2f",diem[count][0], diem[count][1], diem[count][2], diem[count][3], diem[count][4]);
				for(int i=0;i<n;i++)	{
					for(int j=0;j<5;j++)	{
						fprintf(fd,"%.2f\t",diem[i][j]);
					}
					fprintf(fd,"\n");
				}
				break;
			case 4 : 	// Sua diem cot Final
				do {
				printf("\n\tNhap diem ban muon sua ( 0 <= diem <= 10 ) : ");
				scanf("%f",&diem[count][3]);
				} while((diem[count][3]<0)||(diem[count][3]>10));
				diem[count][4]=0.1*diem[count][0]+0.1*diem[count][1]+0.3*diem[count][2]+0.5*diem[count][3];
				printf("\tLab: %.2f   Pres: %.2f   Mid: %.2f   Final: %.2f   Avg: %.2f ",diem[count][0], diem[count][1], diem[count][2], diem[count][3], diem[count][4]);
				for(int i=0;i<n;i++)	{
					for(int j=0;j<5;j++)	{
						fprintf(fd,"%.2f\t",diem[i][j]);
					}
					fprintf(fd,"\n");
				}
				break;
			default : 	// Ngoai le
				printf("Khong co cot diem ban can sua !");
				break;
		}
		fclose(fd);
	}
}

void swap(float &a,float &b)  {		// Trao doi so
	float temp;
	temp=a;
	a=b;
	b=temp;
}

void traodoi(char a[],char b[])  {		// Trao doi ki tu
	char temp[100];
	strcpy(temp,a);
	strcpy(a,b);
	strcpy(b,temp);
}

void sapxep(char (msv[100])[100],int n,char (ten[100])[100],float dtb[])  {		// Sap xep theo DTB
	for(int i=0;i<n-1;i++) {
		for(int j=i+1;j<n;j++) {
			if(dtb[i]<dtb[j]) {
				swap(dtb[i],dtb[j]);
				traodoi(msv[i],msv[j]);
				traodoi(ten[i],ten[j]);
			}
		}
	}
	printf("+----------------------------------------------------------------------------+");
	printf("\n|          Ma Sinh Vien         |     Diem trung binh    |      Xep loai     |\n");
	printf("+----------------------------------------------------------------------------+");
	for(int i=0;i<n;i++){
		printf("\n|          %s            |           %.2f         |        %c          |\n",msv[i],dtb[i],xeploai(dtb[i]));
		printf("+----------------------------------------------------------------------------+");
	}
}

void xuat(int n, char(ten[30])[100], char(msv[15])[100], float diem[][5]) {
		printf("+--------------------------------------------------------------------------------------------+\n");		// Xuat danh sach SV
	for(int i=0; i<n; i++) {
		printf("\n\t\t Ho va ten:       %s",ten[i+1]);
		printf("\t\t Ma SV:           %s",msv[i]);
		printf("\n\t\t Diem cot Lab:    %.2f",diem[i][0]);
		printf("\n\t\t Diem cot Pres:   %.2f",diem[i][1]);
		printf("\n\t\t Diem cot Mid:    %.2f",diem[i][2]);
		printf("\n\t\t Diem cot Final:  %.2f",diem[i][3]);
		printf("\n\t\t Diem cot Avg: 	  %.2f",diem[i][4]);
		printf("\n\t\t Xep loai:        %c\n",xeploai(diem[i][4]));
		printf(" +--------------------------------------------------------------------------------------------+\n");
	}
}

int main() {
	int n, chon;
	diem sv[10];
	char key[20], key1[20];
	char (msv[100])[100];
	char (ten[100])[100];
	float diem[40][5], dtb[40];
	FILE *fmsv,*fd,*ften;
	ften=fopen("C:\\Users\\PC\\Desktop\\project\\ten.txt","r");
	fscanf(ften,"%d\n",&n);			// Doc n tu file ten vao chuong trinh
	fclose(ften);
	mangten(n,ten,ften);		
	mangmsv(n,msv,fmsv);
	if ((fd = fopen("C:\\Users\\PC\\Desktop\\project\\diem13.txt","r")) != NULL)	{
		mangdiem(n,diem,fd,dtb);
	}
	Title();
	Login();
	while(true)	{		
		Menu();
			printf("\n\t\t\tNhap lua chon cua ban:	");
			scanf("%d",&chon);
			switch(chon){
				case 1:		// Nhap diem
                	nhapN(sv,n,msv,ten,fd);		
                	mangdiem(n, diem, fd, dtb);		
                	printf("\n\tBan da nhap thanh cong!");
                	printf("\n\tBam phim bat ky de tiep tuc!");
                	getch();
                	break;
				case 2:		// Xem diem
					if ((fd = fopen("C:\\Users\\PC\\Desktop\\project\\diem13.txt","r")) != NULL)	{
                    	printf("\n\tNhap ma sinh vien muon xem diem: ");
                    	scanf("%s",&key);
                    	xem(msv,ten,n,diem,key);
                	}
					else	{
                    	printf("\n\tNhap diem truoc!");
                	}
                	printf("\n\tBam phim bat ky de tiep tuc!");
                	getch();
                	break;
                case 3:		// Sua diem
					if ((fd = fopen("C:\\Users\\PC\\Desktop\\project\\diem13.txt","r")) != NULL)	{
                    	printf("\n\tNhap ma sinh vien can sua diem: ");
                    	scanf("%s",&key1);
                    	sua(fd,msv,ten,n,diem,key1);
                	}
					else	{
                    	printf("\n\tNhap diem truoc!");
                	}
                	printf("\n\tBam phim bat ky de tiep tuc!");
                	getch();
                	break;
                case 4:		// Sap xep diem
					if ((fd = fopen("C:\\Users\\PC\\Desktop\\project\\diem13.txt","r")) != NULL)	{
                    	sapxep(msv, n, ten, dtb);
                	}
					else	{
                    	printf("\n\tNhap diem truoc!");
                	}
                	printf("\n\tBam phim bat ky de tiep tuc!");
                	getch();
                	break;
                case 5:		// In danh sach
                	if ((fd = fopen("C:\\Users\\PC\\Desktop\\project\\diem13.txt","r")) != NULL)	{
                		mangten(n,ten,ften);
						mangmsv(n,msv,fmsv);
						mangdiem(n, diem,fd,dtb);
						xuat(n, ten, msv, diem);
                	}
                	else	{
                    	printf("\n\tNhap diem truoc!");
                	}
                	printf("\n\tBam phim bat ky de tiep tuc!");
                	getch();
                	break;
                case 0:		// Thoat chuong trinh 
					printf("\n\tBan da chon thoat chuong trinh!");
                	exit(0);
            	default:	// Ngoai le
                	printf("\n\tKhong co chuc nang nay!");
                	printf("\n\tBam phim bat ky de tiep tuc!");
                	getch();
                	break;
            }
    }
}


		






                	
                
                
					
	
	
	
		
