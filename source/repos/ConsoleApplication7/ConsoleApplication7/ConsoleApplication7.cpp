#include <stdio.h>
#include <malloc.h>
#include <windows.h>

struct list
{
	//текущий символ
	char symbol_1;
	//указатель на следующий символ
	struct list* symbol_2;
};

struct list* initiate(char c)
{
	struct list* list;
	list = (struct list*)malloc(sizeof(struct list));
	if (list == NULL)
	{
		printf_s("Память не выделена\n");
		return(0);
	}
	list->symbol_1 = c;
	list->symbol_2 = NULL;
	return(list);
}

struct list* addelement(struct list* result, char c)
{
	struct list* newlist = initiate(c);
	if (result->symbol_2 != NULL)
	{
		struct list* nextnext = result->symbol_2;
		newlist->symbol_2 = nextnext;
	}
	result->symbol_2 = newlist;
	return(newlist);
}

void printlist(struct list* list)
{
	while (list->symbol_2 != NULL)
	{
		printf_s("%c", list->symbol_1);
		list = list->symbol_2;
	}
	printf_s("%c\n", list->symbol_1);
}

struct list* deletecurrentelement(struct list* core, struct list* deleted)
{
	struct list* next = deleted->symbol_2;
	struct list* previous = core;
	if (previous != deleted)
	{
		while (previous->symbol_2 != deleted)
		{
			previous = previous->symbol_2;
		}
	}
	free(deleted);
	previous->symbol_2 = next;
	return(previous);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	struct list* result;
	struct list* temp;
	char c;
	int n = 0;
	printf_s("Введите строку:\n");
	c = getchar();
	temp = initiate(c);
	result = temp;
	c = getchar();
	while (c != '\n')
	{
		result = addelement(result, c);
		c = getchar();
	}
	result = temp;
	printlist(temp);

	while (result != NULL)
	{
		if (result->symbol_1 == 'A')
		{
			if (result == temp)
			{
				addelement(result, 'B');
				temp = temp->symbol_2;
			}
			else
			{
				result = deletecurrentelement(temp, result);
			}
			result = addelement(result, 'B');
		}

		result = result->symbol_2;
	}
	if (temp == NULL)
	{
		printf("Удалён весь список\n");
		return(0);
	}
	result = temp;
	printlist(temp);
	while (result != NULL)
	{
		if (result->symbol_1==' ') {
			n=0;
		}
		if (result->symbol_1 == 'a') {
			n++;
		}
		result = result->symbol_2;
	}

	printf_s("\nКоличество букв 'a' в последнем слове = %d", n);
	result = temp;
	while (result->symbol_2 != NULL) result = result->symbol_2;
	while (result != temp) result = deletecurrentelement(temp, result);

	free(temp);
	return(0);
}