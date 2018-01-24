#include <stdio.h>

int duocDat(int a[][10], int N, int hang, int cot);
void nhapmang(int a[][10], int N);

int main()
{
    int a[8][10], hang, cot, kt = 1;
    nhapmang(a, 8);
    printf("\n");

    while (kt == 1) {
        printf("Kiem tra\nNhap vao vi tri can kiem tra\n");
        printf("Hang: ");
        scanf("%d", &hang);
        printf("Cot: ");
        scanf("%d", &cot);
        printf("Ket qua kiem tra la %d\n", duocDat(a, 8, hang, cot));
        printf("Kiem tra nua hay khong 1 (co) / 0 (khong) : ");
        scanf("%d", &kt);
    }
    return 0;
}

void nhapmang(int a[][10], int N) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

int duocDat(int a[][10], int N, int hang, int cot) {
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
