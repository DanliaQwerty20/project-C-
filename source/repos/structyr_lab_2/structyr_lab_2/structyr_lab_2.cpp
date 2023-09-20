//##1

//#include <stdio.h>
////массив символов
//int main()
//{
//	char str[10];
//	printf("Vvedite string:\n");
//
//	scanf_s("%9c", str);
//	int i = 0;
//	int count = 0;
//	while (str[i] != NULL) {
//		if (str[i] == 'a') {
//			count++;
//		}
//		if (str[i] == ' ') {
//			count = 0;
//		}
//		i++;
//	}
//	printf("%d", count);
//}

//##2

//#include <stdio.h>
//#include <string.h>
//using namespace std;
//
////решение через символьную строку.
//int main() {
//	char str[100];//обычный массив,с которым будем работать
//	char ch = 'a';
//	printf("Please enter string: ");
//	int count1 = 0;
//	for (int i = 0; (str[i] = getchar()) != '\n'; i++) {
//		if (str[i] == 'a') {
//			count1++;
//		}
//		if (str[i] == ' ') {
//			count1 = 0;
//		}
//
//	}
//	printf("%d", count1);
//	return 0;
//}


//##3

//#include <malloc.h>
//#include <stdio.h>
//#include <iostream>
//#include <locale.h>
//using namespace std;
//int main() {
//	setlocale(LC_ALL, "rus");
//	int i, count = 0,k=3;
//	char* str;
//	str = (char*)calloc(k, sizeof(char*));//выделяем память под первые 2 элемента
//	printf("Введите строку: \n");
//	int count_pam = 0;
//	i = 0;
//	str[i] = getchar();
//	i++;
//	while (str[i] != '\n') {
//		str[i] = getchar();
//		if (str[i] == '\n') {
//			break;
//		}
//		i++;
//		if (i > k) {
//			k += 3;
//			str = (char*)realloc(str,k * sizeof(char*));
//		}
//	}
//
//	if (str == NULL) {
//		free(str);
//		return 1;
//	}
//	while (*str != '\0') {
//		if (*str == ' ' || *str=='a') {
//			if (*str == ' ') {
//				count = 0;
//			}
//			else {
//				count++;
//			}
//			str++;
//		}
//		else {
//			str++;
//		}
//
//		
//	}
//	printf("%d", count);
//
//	if (str == NULL) {
//		free(str);
//		return 1;
//	}
//
//}



//##4
//#include <malloc.h>
//#include <stdio.h>
//
//#include <locale.h>
//using namespace std;
//int main() {
//	setlocale(LC_ALL, "rus");
//	int i = 0 , count = 0;
//	int k = 1;
//	char* str = NULL;
//	str = (char*)malloc(sizeof(char*));//выделяем память под 1 элемент
//	printf("Введите строку: \n");
//	str[i] = getchar();
//	i++;
//	while (str[i] != '\n') {
//		str[i] = getchar();
//		if (str[i] == '\n') {
//			break;
//		}
//		i++;
//		str = (char*)realloc(str,i * sizeof(char*));
//	}
//
//	if (str == NULL) {
//		free(str);
//		return 1;
//	}
//	while (*str != '\0') {
//		if (*str == ' ' || *str == 'a') {
//			if (*str == ' ') {
//				count = 0;
//			}
//			else {
//				count++;
//			}
//			str++;
//		}
//		else {
//			str++;
//		}
//
//
//	}
//	printf("%d", count);
//}
//Условия те же
//Дана строка символов,ввести ее,используя функцию келлок,память захватывать под некоторое фиксирование число(3..5),Если памяти не хватает,то добавить ее с помощью реаллок


//Дана строка символов,ввести ее,используя функцию меллок,при вводе очередного символа под строку с помощью функции реаллок

#include <stdio.h>
#include <malloc.h>
#include <windows.h>

struct list
{
	char symbol;
	struct list* next;
	struct list* previous;
};

struct list* initiate(char c)
{
	struct list* list;
	list = (struct list*)malloc(sizeof(struct list));
	list->symbol = c;
	list->next = NULL;
	list->previous = NULL;
	return(list);
}

struct list* addelement(struct list* list, char c)
{
	struct list* temp = initiate(c);
	list->next = temp;
	temp->previous = list;
	return(temp);
}

void printlist(struct list* list)
{
	while (list->next != NULL)
	{
		printf_s("| %c ", list->symbol);
		list = list->next;
	}
	printf_s("| %c | ", list->symbol);
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	struct list* current;
	struct list* list;
	char c;
	int n = 0;
	c = getchar();
	list = initiate(c);
	current = list;
	c = getchar();
	while (c != '\n')
	{
		current = addelement(current, c);
		c = getchar();
	}
	current = list;
	printlist(list);
	while (current->next != NULL)
	{
		if (current->symbol == ' ')
		{
			current = current->next;
		}
		else
		{
			while ((current->symbol != ' ') && (current->next != NULL))
			{
				current = current->next;
			}
			n++;
		}
	}
	if (n == 0 && current->symbol != ' ') n++;
	if (current->symbol != ' ' && current->previous != NULL)
	{
		current = current->previous;
		if (current->symbol == ' ')n++;
	}
	printf_s("\nКоличество слов в списке = %d", n);
	return(0);
}

//нельзя,чтобы a была первой и последней,понял боб?








