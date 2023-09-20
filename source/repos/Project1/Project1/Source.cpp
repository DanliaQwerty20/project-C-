#include <stdio.h>
#include <clocale>
int main() {
	int n, m;
	//найти сумму в выделенной области
	setlocale(LC_ALL, "rus");
	scanf_s("%d %d", &n, &m);
	if (n <= 0 || m <= 0) {
		printf("Недопустимые значения n,m\n");
		return 1;
	}
	int a[25][25];
	int i, j,i1,j1;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}
	int sum = 0;
	int count = 0;//для вывода номеров
	printf("-----------------\n");
	printf("  # ! i ! j ! sum\n");
	printf("-----------------\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			count++;
			sum = a[i][j];//начинаем искать нужную сумму с элемента i,j

			i1 = i;
			for (int i = 0; i < i1; i++) {
				sum =sum+a[i][j];//тут добавляем каждый элемент с i=0 до a[i][j];
			}
			
			j1 = j;
			for (int j = 0; j < j1; j++) {
				sum =sum+a[i][j];//точно такэе добавляем элемент с j=0 до a[i][j]
			}			
			printf("%3d %3d %3d %4d\n", count, i, j, sum);
		}
	}
	printf("----------------\n");
	return 0;
}