#include <stdio.h>
#include <math.h>
 
#define N 100
#define eps 0.00001
void swap(float &a,float &b){
	float temp;
	temp=a;
	a=b;
	b=temp;
}
 
float dt(float a[][N], int n) {
    for (int i = 1; i <= n; i++) {		// Doi dong
        if (a[i][i] == 0) {
            for (int j = i+1; j <= n; j++) {
                if (a[j][i] != 0) {
                    for (int k = i; k <= n; k++) {
                       swap(a[i][k],a[j][k]);
                    }
                    break;
                }
            }
        }
        for (int j = i+1; j <= n; j++) {		// Bien doi ma tran tam giac
            float m = (-a[j][i])/a[i][i];
            for (int k = 1; k <= n; k++) {
                a[j][k] += a[i][k]*m;
            }
        }
    }
     
    // tinh dinh thuc
    float res = 1;
    for (int i = 1; i <= n; i++) {
    	res*=a[i][i];
    return res;
}
}
int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    float a[N][N], t[N][N];
    printf("\nNhap n = ");
    scanf("%d", &n);
    printf("\nNhap ma tran: \n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n+1; j++) {
            scanf("%f", &a[i][j]);
            t[i][j] = a[i][j];
        }
    }
     
    float D[N];
    D[0] = dt(t, n);
    if (D[0] == 0) {
        printf("Khong giai duoc he bang phuong phap nay");
        return 0;
    }
    else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    if (k == i) t[j][k] = a[j][n+1];
                    else t[j][k] = a[j][k];
                }
            }
            D[i] = dt(t, n);
        }
        printf("He co nghiem la: \n");
        for (int i = 1; i <= n; i++) {
            printf("X[%d] = %f\n", i, D[i]/D[0]);
        }
    }
     
    return 0;
}
