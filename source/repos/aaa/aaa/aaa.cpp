#include <stdio.h>
#include<Windows.h>
#include <iostream>





void vvedi_menya(int a[20][20], int Q, int M)
{
	int i, j,e;
	char q;
	printf("Vvedite massiv\n");
	for (i = 1; i <= Q; i++)
	{
		for (j = 1; j <= M; j++)
		{
			a[i][j] = rand() % 10;
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}


}




int poschitai_menya(int a[20][20], int N, int M)
{
	int i, j, i1, j1, otv, s, n;
	printf("Np/p i j rez\n");
	n = 1;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			otv = 0;
			for (i1 = i; i1 > 0; i1--) {
				otv = otv + a[i1][j];
			}
			for (j1 = j; j1 > 0; j1--) {
				otv += a[i][j1];
			}
			otv -= a[i][j];
			printf("%4d %4d %4d %4d\n", n, i, j, otv);

		}
	}
	return otv;


}

using namespace std;
int main()
{
	int N, M, a[20][20];
	printf("Vvedite N i M\n");
	scanf_s("%d %d", &N, &M);
	vvedi_menya(a, N, M);
	poschitai_menya(a, N, M);
	printf("\n");


}