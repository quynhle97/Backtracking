#include <stdio.h>

static const int X[8] = {-2, -1, 2, 1,  2,  1, -1, -2};
static const int Y[8] = {-1, -2, 1, 2, -1, -2,  2,  1};

void quanMa(int a[][100], int kt, int x, int y, int N);

int main()
{
    int N, a[100][100] = {{0}};
    a[0][0] = 1;
    printf("Nhap N: ");
    scanf("%d", &N);

    quanMa(a,1,0,0,N);

    return 0;
}

void quanMa(int a[][100], int kt, int x, int y, int N) {
    if (kt == N*N) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                printf("%2d  ", a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    } else {
        for (int i=0; i<8; i++) {
            x = x + X[i];
            y = y + Y[i];
            if (x>=0 && y>=0 && y<N && x<N) {
                if (a[x][y] == 0) {
                    a[x][y] = kt+1;
                    quanMa(a,kt+1,x,y,N);
                    a[x][y] = 0;
                }
            }
            x = x - X[i];
            y = y - Y[i];
        }
    }
}

