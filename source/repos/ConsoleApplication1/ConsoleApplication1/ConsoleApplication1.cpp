#include <stdio.h>
#include <locale.h>


int main(){
    setlocale(LC_ALL, "rus");
    int n, m,i,j,i1,j1;
    scanf_s("%d %d", &n, &m);
    if (n <= 0 || m <= 0) {//или
        printf("Недопустимые значения n,m\n");
        return 1;
    }
    int a[10][10];
    int sum = 0;
    int count = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf_s("%d", &a[i][j]);
        }
    }
    printf("-----------------\n");
    printf(" # ! i ! j ! sum\n");
    printf("-----------------\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            count=count+1;
            sum = a[i][j];
            i1 = i;
            j1 = j;
            for (int i4 = 0; i4 < i1; i4++) {
                sum = sum + a[i4][j];
            }
            for (int j4 = 0; j4 < j1; j4++) {
                sum = sum + a[i][j4];
            }
            printf("%3d %3d %3d %4d\n", count, i, j, sum);
        }
    }
    printf("-----------------\n");
    return 0;
}
