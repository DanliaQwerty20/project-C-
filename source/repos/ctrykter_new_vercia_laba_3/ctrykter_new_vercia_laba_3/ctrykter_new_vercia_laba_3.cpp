#include <malloc.h>
#include <stdio.h>
#include <locale.h>

using namespace std;

struct list
{
	//текущий символ
	char symbol_1;

	//хранит следующий символ
	struct list* sumbol_2;
};

struct list* iniz(char head)
{
	struct list* list_1;
	list_1 = (struct list*)malloc(sizeof(struct list));

	list_1->symbol_1 = head;
	
	list_1->sumbol_2 = NULL;
	return list_1;
};


struct list* add(struct list* list, char head)
{
	struct list* temp = iniz(head);
	if (list->sumbol_2!= NULL)
	{
		struct list* nextnext = list->sumbol_2;	
		temp->sumbol_2 = nextnext;
	}
	
	list->sumbol_2 = temp;
	return temp;
};

struct list* add_len(struct list* list_1, int number) {
	struct list* temp;

	temp = list_1;
	int cc = 0;
	bool flag = true;
	while (temp->sumbol_2 != NULL) {
		
		cc++;
		if (cc == number/2) {
			struct list* news = iniz('#');
			news->sumbol_2 = temp->sumbol_2;
			temp->sumbol_2 = news;
			break;
			flag = false;
		}
		if (flag) {
			printf("%c", temp->symbol_1);
			temp = temp->sumbol_2;
		}
	}
	return temp;
};

void printlist(struct list* list_1)
{
	while (list_1->sumbol_2!= NULL)
	{
		printf("%c", list_1->symbol_1);
		list_1 = list_1->sumbol_2;
	}
	printf("%c", list_1->symbol_1);
}
struct list* deletecurrentelement(struct list* core, struct list* deleted)
{
	struct list* sumbol_2 = deleted;
	struct list* previous = core;
	if (previous != deleted)
	{
		while (previous->sumbol_2 != deleted)
		{
			previous = previous->sumbol_2;
		}
	}
	free(deleted);
	previous->sumbol_2 = sumbol_2;
	return(previous);
}
struct list* deletelem(list* core, list* deleted) 
{
	struct list* next = deleted->sumbol_2;
	struct list* previous = core;
	if (previous != deleted)
	{
		while (previous->sumbol_2 != deleted)
		{
			previous = previous->sumbol_2;
		}
	}
	free(deleted);
	previous->sumbol_2 = next;
	return(previous);
}

int main() {
	setlocale(LC_ALL, "rus");
	printf("Введите строку: \n");
	struct list* result;
	struct list* list_1;
	struct list* list_2;
	struct list* list_3;
	char head;
	int count_a = 0, count_len = 0;
	head = getchar();
	list_1= iniz(head);//добавили в result 1 элемент
	result = list_1;
	list_2 = result;
	list_3 = result;
	//сохранен в symbol1
	//сохраняем в конечный лист
	head = getchar();
	while (head != '\n') {
		result = add(result, head);
		//копия
		list_2 = result;
		list_3 = result;
		head = getchar();
		count_len++;//подсчет длины
	}
	result = list_1;
	//для записи в середину нужна копия
	list_2 = result;
	list_3 = result;
	printlist(list_1);
	while (result!= NULL) {
		if (result->symbol_1 == ' ') {
			count_a = 0;
		}
		if (result->symbol_1 == 'a') {
			count_a++;
		}
		result = result->sumbol_2;
	}
	//пробегаемся по всем элементам
	
	printf("\nКоличество 'a' в последнем слове = %d\n", count_a);
	int number;
	printf("\nНужно ли добавление элемента: 1-да,отрицательное число-нет\n");
	scanf_s("%d", &number);
	if (number >= 0) {
		list_2 = add_len(list_2, count_len);
	}
	
	while (result !=NULL) {
		if (result->symbol_1 == 'A') {
			result = deletecurrentelement(list_3, result);
		}
		result = result->sumbol_2;
	} 

	printlist(result);
	free(list_2);
}