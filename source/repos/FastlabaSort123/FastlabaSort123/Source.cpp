
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <string>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

void bubbleSort(int list[], int listLength);
void selectionSort(int list[], int listLength);
void insertionSort(int list[], int listLength);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int* a;
	int i, n;

	printf("Введите размер массива: \n");

	cin >> n;

	a = (int*)malloc(n * sizeof(int));
	printf("Введите элементы массива: \n");

	for (i = 0; i < n; i++)
	{
		cin >> (a[i]);
	}
	cout << ("\n");

	int m;
	cout << ("Выберите способ сортировки: \n1).Сортировка Пузырёком \n2).Сортировка Выбором \n3).Сортировка Вставкой \n");
	cout << ("\n");
	cin >> m;

	switch (m)
	{
	case 1:
	{
		bubbleSort(a, n);
		break;
	}
	case 2:
	{
		selectionSort(a, n);
		break;
	}
	case 3:
	{
		insertionSort(a, n);
		break;
	}
	default:
		cout << ("Было введено некоректное значение \n");
		return (0);
	}
	cout << ("\nОтсортированный массив: \n");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	cout << ("\n");
	free(a);
	return 0;
}

void bubbleSort(int num[], int size)
{
	bool flag = true;
	for (int i = 0; i < size - 1; i++)
	{
		flag = false;
		for (int j = (size - 1); j > i; j--)
		{
			if (num[j - 1] > num[j])
			{
				int temp = num[j - 1];
				num[j - 1] = num[j];
				for (int k = 0; k < size; k++)
				{
					printf("%d ", num[k]);
				}
				cout << ("\n");
				num[j] = temp;
				for (int k = 0; k < size; k++)
				{
					printf("%d ", num[k]);
				}
				cout << ("\n");
				flag = true;
			}
		}
		for (int b = 0; b < size; b++)
		{
			if (b == (i + 1))
			{
				cout << ("|");
			}
			printf("%d ", num[b]);
		}
		cout << ("\n");
		if (!flag) break;
	}
}

void selectionSort(int num[], int size)
{
	int min, temp;
	for (int i = 0; i < size - 1; i++)
	{
		min = i;

		for (int j = i + 1; j < size; j++)
		{
			if (num[j] < num[min])
				min = j;
		}
		if (num[min] != num[i])
		{
			temp = num[i];
			num[i] = num[min];
			for (int k = 0; k < size; k++)
			{
				printf("%d ", num[k]);
			}
			cout << ("\n");
			num[min] = temp;
			for (int k = 0; k < size; k++)
			{
				if (k == (i + 1))
				{
					cout << ("|");
				}
				printf("%d ", num[k]);
			}
			cout << ("\n");
		}
	}
}

void insertionSort(int a[], int size)
{
	int x;
	int i, j;

	for (i = 0; i < size; i++)
	{
		x = a[i];

		for (j = i - 1; j >= 0 && a[j] > x; j--)
		{
			a[j + 1] = a[j];
			for (int k = 0; k < size; k++)
			{
				printf("%d ", a[k]);
			}
			cout << ("\n");
		}

		a[j + 1] = x;
		for (int k = 0; k < size; k++)
		{
			if (k == (i + 1))
			{
				cout << ("| ");
			}
			printf("%d ", a[k]);
		}
		cout << ("\n");
	}
}






