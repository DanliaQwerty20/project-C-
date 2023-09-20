#include <stdio.h>
#include<Windows.h>
#include<time.h>

//void vvod(int a[20][20], int, int);
//void vivdod(int a[20][20], int, int);
//void resh(int a[20][20], int, int);

void vvod(int a[20][20], int N, int M)
{
	int i, j;
	printf("Vvedite massiv\n");
	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
}
void resh(int a[20][20], int N, int M)
{
	int i, j, t, in, jn, jk, j0, s, otv;
	printf("Np/p i j rez\n");
	t = 0;
	for (in = 1; in <= N; in++)
	{
		for (j0 = 1; j0 <= M; j0++)
		{
			t++;//номер #
			otv = 0;//кол-во положительных
			i = in;//для столбца вниз
			if (a[i][j0] > 0)
				otv++;
			i++;
			jn = j0 - 1;
			jk = j0 + 1;
			for (i; i <= N; i++)
			{
				if (jn == 0)
					jn = 1;
				if (jk == M + 1)
					jk = M;
				j = jn;
				for (s = 1; j <= jk; j++)
				{
					if (a[i][j] > 0)
						otv++;
				}
				jn--;
				jk++;
			}
			printf("   %d %d %d   %d\n", t, in, j0, otv);
		}
	}
}
void vivdod(int a[20][20], int N, int M)
{
	int i, j;
	printf("\n");
	printf("Itogoviy massiv\n");
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
void main()
{
	int N, M, a[20][20], c;
	printf("Vvedite N i M\n");
	scanf_s("%d %d", &N, &M);
	vvod(a, N, M);
	resh(a, N, M);
}

