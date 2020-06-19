#include<bits/stdc++.h>
void hoandoi(float &a,float &b){
	float temp;
	temp=a;
	a=b;
	b=temp;
}
void nhap(float a[][10],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<=n;j++){
			printf("a[%d][%d]= ",i,j);
			scanf("%f",&a[i][j]);
		}
	}
}
void xuat(float a[][10],int n){
		for(int i=0;i<n;i++){
		for(int j=0;j<=n;j++){
			printf("%.2f  ",a[i][j]);
		}
		printf("\n");
	}
}
void doidong(float a[][10],int n,int p,int q){
	int k;
	if(p<=n&&q<=n&&p!=q){
		for(k=1;k<=n+1;k++){
			hoandoi(a[p][k],a[q][k]);
		}
	}
}
int main (){
	int i,j,n;
	float a[10][10],x,m,s;
	printf("\nNhap so phuong trinh : n= ");
	scanf("%d",&n);
	nhap(a,n);
	xuat(a,n);
	for(i=1;i<=n-1;i++){
		if(a[i][i]==0) {
			j=i+1;
			while(j<=n) {
				if(a[j][i]!=0) break;
				else ++j;
			}
			if(j<=n) doidong(a,n,i,j);
		}
		for(j=i+1;j<=n;j++){
			m=-a[j][i]/a[i][i];
		}
	}
	
	for(i=n;i>=1;i--){
		s=0;
		for(j=i+1;j<=n;j++){
			s=s+a[i][j]*x[j];
			x[i]=(a[i][n+1]-s)/a[i][i];
		}
	}
	for(i=0;i<n;i++){
		printf("%.3f\t",x[i]);
	}
	
}

