#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void Title();
void InputTwoDimentionalArray(int *n, int *m, int C[][MAX], const char *File);
void OutputTwoDimensionalArray(int n, int m, int C[][MAX]);
void LowestCost(int n, int m, int C[][MAX], int S[][MAX]);
void TransportPlan(int n, int m, int C[][MAX], int S[][MAX], int P[MAX]);
void OutputTransportPlan(int m, int P[MAX]);
void InputToFile(int n, int m, int S[][MAX], int P[MAX]);
int main ()
{
	int n;
	int m;
	char s,s1;
	int C[MAX][MAX];
	int S[MAX][MAX];
	int P[MAX];
	
	Title();
	fflush(stdin);
	printf("*****ENTER FILE NAME TO INPUT *****\n");
	scanf("%s",&s);
	
	
	
	InputTwoDimentionalArray(&n, &m, C, &s);
	
	OutputTwoDimensionalArray(n, m, C);
	
	LowestCost(n, m, C, S);
	printf("\n===== CHI PHI THAP NHAT DE CHUYEN %d GOI TIN: %d\n",n, S[n][m]);
	
	TransportPlan(n, m, C, S, P);
	
	OutputTransportPlan(m, P);
	
	InputToFile(n, m, S, P);
	printf("\n\n**===== DA CHEP DU LIEU VAO FILE =====**\n");
	return 0;
}

void Title() {
	printf(" -----------------------------------------------------------------------------");
	printf("\n|     			 CHUONG TRINH TIM CHI PHI THAP NHAT                   |");
	printf("\n|          	    	  BANG PHUONG PHAP QUY HOACH DONG                     |");
	printf("\n|                                  *     *     *                              |");
	printf("\n|         - Giang vien huong dan: Nguyen Van Nguyen                           |");
	printf("\n|         - Sinh vien thuc hien:Tran Nguyen Anh Trinh   	              |");
	printf("\n|         - Lop:  19TCLC - DT4			                              |");
	printf("\n|         - Ma sinh vien: 102190195                                           |");
	printf("\n|         - Nhom: 19.13A                                                      |");
	printf("\n|         - Lop: 19TCLC_DT4                                                   |");	
	printf("\n -----------------------------------------------------------------------------\n\n");
	}

void InputTwoDimentionalArray(int *n, int *m, int C[][MAX], const char *File)
{
	int i;
	int j;
	FILE *fin;
	fin = fopen("C:\\Users\\PC\\Desktop\\project\\letuan.txt", "r");
	if (fin == NULL)
	{
		printf("\n***** FILE KHONG TON TAI *****\n");
		exit(1);
	}
	else
	{
		printf("\n========== DANG TIEN HANH NHAP DU LIEU TU FILE ==========\n");
		fscanf(fin, "%d", n);
		fscanf(fin, "%d", m);
		for(i = 0; i <= *n; i++)
		{
			for(j = 1; j <= *m; j++)
			{
				if( i== 0)
				{
					C[i][j] = 0;
				}
				else
				{
					fscanf(fin, "%d", &C[i][j]);
				}
			}
		}
	fclose(fin);
	}
}

void OutputTwoDimensionalArray(int n, int m, int C[][MAX])
{
	int i;
	int j;
	printf("\n***** DU LIEU SAU KHI DOC TU FILE *****\n\n");
	for(i = 1; i <= n; i++)
	{
		for ( j = 1; j <= m; j++)
		{
			printf ("%-10d", C[i][j]);
			
		}
		printf ("\n");
	}
}

void LowestCost(int n, int m, int C[][MAX], int S[][MAX])
{
	int i;
	int j;
	int k;
	int min;
	for(j=0; j<=m; j++) S[0][j]=0;
	for(i=0; i<=n; i++) S[i][0]=0;
	for(i = 0; i <= n; i++) S[i][1] = C[i][1];
	for(j = 2; j <= m; j++)
	{
		for(i = n; i >=0; i--)
		{
			min = C[i][j];
			for(k = 0; k <=i-1; k++) 
			{
				if(min > C[k][j] + S[i-k][j-1])
				{
					min = C[k][j] + S[i-k][j-1];
				}
			}
			S[i][j] = min;
		}
	}
}

void TransportPlan(int n, int m, int C[][MAX], int S[][MAX], int P[MAX])
{
	int i=n;
	int j=m;
	int k;
	for(j;j>0;j--)
	{
		for(k=0; k <=i; k++)
		{
			if(S[i][j]==C[k][j]+S[i-k][j-1])
			{
				P[j]=k;
				if(j!=1) break;
			}
		}
		i-=k;
	}
}

void OutputTransportPlan(int m, int P[MAX])
{
	int i;
	printf("\n===== CACH THUC VAN CHUYEN =====\n");
	printf("\n%20s","Kenh");
	for(i=1; i<=m; i++)
	{
		printf("%10d", i);
	}
	printf("\n%20s","So goi tin");
	for(i = 1; i <= m; i++)
	{
		printf("%10d", P[i]);
	}
}

void InputToFile(int n, int m, int S[][MAX], int P[])
{
	int j;
	FILE *fout = fopen("messages.out", "w");
	fprintf(fout, "%d\n", S[n][m]);
	for(j = 1; j<=m; j++)
	{
		fprintf(fout, "%d\n", P[j]);
	}
}
