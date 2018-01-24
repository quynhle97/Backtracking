#include <stdio.h>

int duocDat(int a[][8], int N, int hang, int cot);
int datHau(int a[][8], int N, int cot);
void xuatmang(int a[][8], int N);

int main()
{
    int a[8][8] = {
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0}
    };

    datHau(a, 8, 0);
    xuatmang(a, 8);

    return 0;
}

void xuatmang(int a[][8], int N) {
    printf("Xuat mang\n");
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int duocDat(int a[][8], int N, int hang, int cot) {
    for (int i=0; i<N; i++)
        if (a[hang][i] == 1) return 0;

    int tmp_h = hang, tmp_c = cot;

    while (tmp_h >= 0 && tmp_c >=0) {
        if (a[tmp_h][tmp_c] == 1) return 0;
        else {
            tmp_h--;
            tmp_c--;
        }
    }

    tmp_h = hang; tmp_c = cot;
    while (tmp_h <= N && tmp_c <= N) {
        if (a[tmp_h][tmp_c] == 1) return 0;
        else {
            tmp_h++;
            tmp_c++;
        }
    }

    tmp_h = hang; tmp_c = cot;
    while (tmp_h >= 0 && tmp_c <= N) {
        if (a[tmp_h][tmp_c] == 1) return 0;
        else {
            tmp_h--;
            tmp_c++;
        }
    }

    tmp_h = hang; tmp_c = cot;
    while (tmp_h <= N && tmp_c >= 0) {
        if (a[tmp_h][tmp_c] == 1) return 0;
        else {
            tmp_h++;
            tmp_c--;
        }
    }

    return 1;
}

int datHau(int a[][8], int N, int cot) {
    if (cot == N) {
        return 1;
    }

    for (int i=0; i<N; i++) {
        if (duocDat(a, N, i, cot) == 1) {
            a[i][cot] = 1;
            if (datHau(a, N, cot + 1) == 1)
                return 1;
            a[i][cot] = 0;
        }
    }

    return 0;
}
