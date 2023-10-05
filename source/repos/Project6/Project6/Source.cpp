#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>	
#include <locale.h>


struct perem { 
	int x;
	char a[15]; 
	char b[15];
	char c[15];
	int d;
};


struct www {
	int x;
	int y;
};

int sl;//отвечает за кол-во строк
void vvod(struct perem k[100])
{
	struct perem mm;



	int i;
	int n;
	printf("Введите количество строк для заполнения\n");
	scanf_s("%d", &n);
	sl = n;
	system("cls");
	printf("Заполните таблицу\n");
	printf("Марка       Модель        Страна     Год\n");
	i = 1;

	while (i <=n) {
		scanf_s("%s", mm.a, 15);
		scanf_s("%s", mm.b, 15);
		scanf_s("%s", mm.c, 15);
		scanf_s("%d", &mm.d);

		mm.x = i;
		k[i] = mm;
		
		i++;
	}

	system("cls");
	printf("Готовая таблица\n");
	printf(" Np/p      Марка       Модель        Страна     Год\n");
	for (i = 1; i <= n; i++)
		printf("%5d %12s %12s %14s %12d\n", k[i].x, k[i].a, k[i].b, k[i].c, k[i].d);
}

void dobavit(struct perem k[100])
{
	struct perem mm;
	int i, b;

	system("cls");
	printf("Сколько строк добавить?\n");
	scanf_s("%d", &b);
	printf("Марка       Модель        Страна     Год\n");
	i = sl + 1;
	sl += b;
	
	while (i <= sl) {
		scanf_s("%s", mm.a, 15);
		scanf_s("%s", mm.b, 15);
		scanf_s("%s", mm.c, 15);
		scanf_s("%d", &mm.d);

		mm.x = i;
		k[i] = mm;
		
		i++;
	}

	system("cls");
	printf("Готовая таблица\n");
	printf(" Np/p      Марка       Модель        Страна     Год\n");
	for (i = 1; i <= sl; i++)
		printf("%5d %12s %12s %14s %12d\n", k[i].x, k[i].a, k[i].b, k[i].c, k[i].d);
}
void poisk(struct perem k[100])
{
	int i, s;
	char t[15];
	system("cls");
	printf("Введите искомое значение?\n");
	scanf_s("%s", t, 15);
	s = 0;
	for (i = 1; i <= sl; i++)
	{
		if (strcmp(k[i].a, t) == 0) {
			printf("%5d %12s %12s %14s %12d\n", k[i].x, k[i].a, k[i].b, k[i].c, k[i].d);
			s--;
		}
		if (strcmp(k[i].b, t) == 0) {
			printf("%5d %12s %12s %14s %12d\n", k[i].x, k[i].a, k[i].b, k[i].c, k[i].d);
			s--;
		}
		if (strcmp(k[i].c, t) == 0) {
			printf("%5d %12s %12s %14s %12d\n", k[i].x, k[i].a, k[i].b, k[i].c, k[i].d);
			s--;
		}
		if (k[i].d == atoi(t)) {
			printf("%5d %12s %12s %14s %12d\n", k[i].x, k[i].a, k[i].b, k[i].c, k[i].d);
			s--;
		}
		
		s++;
	}
	if (s == sl)
		printf("Искомое значение не существует\n");
	printf(" Np/p      Марка       Модель        Страна     Год\n");
	
	for (i = 1; i <= sl; i++)
		printf("%5d %12s %12s %14s %12d\n", k[i].x, k[i].a, k[i].b, k[i].c, k[i].d);
}

void main()
{
	setlocale(LC_ALL, "Rus");
	struct perem k[100];
	int n, y, che;
	n = 0;
	che = 1;
	while (che==1)
	{
		printf("Какое действие хотите совершить: \n1.Заполнить БД\n2.Добавить строку в БД\n3.Найти строку\n4.Закончить работу\n");
		scanf_s("%d", &y);
		switch (y)
		{
		case (1):
		{

			system("cls");
			vvod(k);
			break;
		}

		case (2):
		{
			dobavit(k);
			break;
		}

		case (3):
		{
			poisk(k);
			break;
		}
		case (4):
		{ che = 0;
		}
		}
	}
}
