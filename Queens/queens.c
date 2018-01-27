#include <stdio.h>

void quanHau(int a[][100], int cot, int N, int hang[], int db_tn[], int dn_tb[]);

int main()
{
    int a[100][100] = {{0}}, N, db_tn[100] = {0}, dn_tb[100] = {0}, hang[100] = {0};
    printf("Nhap N: ");
    scanf("%d", &N);
    quanHau(a,0,N,hang,db_tn,dn_tb);
    return 0;
}

void quanHau(int a[][100], int cot, int N, int hang[], int db_tn[], int dn_tb[]) {
    if (cot == N) {
        printf("Ban co quan Hau\n");
        for (int l=0; l<N; l++) {
            for (int m=0; m<N; m++) {
                printf("%d ", a[l][m]);
            }
            printf("\n");
        }
    } else {
        for (int i=0; i<N; i++) {
            if (hang[i] == 0 && db_tn[i-cot+N-1] == 0 && dn_tb[i+cot] == 0) {
                a[i][cot] = 1;
                hang[i] = -1;
                db_tn[i-cot+N-1] = -1;
                dn_tb[i+cot] = -1;
                quanHau(a,cot+1,N,hang,db_tn,dn_tb);
                a[i][cot] = 0;
                hang[i] = 0;
                db_tn[i-cot+N-1] = 0;
                dn_tb[i+cot] = 0;
            }
        }
    }
}

