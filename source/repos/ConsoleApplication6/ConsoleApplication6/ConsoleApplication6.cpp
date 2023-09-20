#include <malloc.h>
#include <windows.h>
#include <stdio.h>

struct list
{
	char symbol;
	struct list* next;
};

struct list* initiate(char c)
{
	struct list* list;
	list = (struct list*)malloc(sizeof(struct list));

	list->symbol = c;
	list->next = NULL;
	return(list);
}

struct list* addelement(struct list* current, char c)
{
	struct list* newlist = initiate(c);
	if (current->next != NULL)
	{
		struct list* nextnext = current->next;
		newlist->next = nextnext;
	}
	current->next = newlist;
	return(newlist);
}

struct list* add_len(struct list* list_1, int number) {
	struct list* temp;

	temp = list_1;
	int cc = 0;
	bool flag = true;
	while (temp->next != NULL) {

		cc++;
		if (cc == number / 2) {
			struct list* news = initiate('#');
			news->next = temp->next;
			temp->next = news;
			break;
			flag = false;
		}
		if (flag) {
			printf("%c", temp->next);
			temp = temp->next;
		}
	}
	return temp;
};
void printlist(struct list* list)
{
	while (list->next != NULL)
	{
		printf_s("%c", list->symbol);
		list = list->next;
	}
	printf_s("%c\n", list->symbol);
}

struct list* deletecurrentelement(struct list* core, struct list* deleted)
{
	struct list* next = deleted->next;
	struct list* previous = core;
	if (previous != deleted)
	{
		while (previous->next != deleted)
		{
			previous = previous->next;
		}
	}
	free(deleted);
	previous->next = next;
	return(previous);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	struct list* current;
	struct list* core;
	char c;
	int n = 0;
	printf_s("Введите строку:\n");
	c = getchar();
	core = initiate(c);
	current = core;
	c = getchar();
	int count_len = 0;
	while (c != '\n')
	{
		current = addelement(current, c);
		c = getchar();
		count_len++;
	}
	current = core;

	while (current != NULL)
	{
		if (current->symbol == 'a') {
			n++;
		}
		if (current->symbol == ' ') {
			n = 0;
		}
		current = current->next;
	}
	current = core;
	printlist(core);

	while (current != NULL)
	{
		if (current->symbol == '1')
		{
			current = deletecurrentelement(core, current);
		}
		current = current->next;
	}
	current = core;
	printlist(core);
	int count = 0;
	while (current != NULL) {
		count++;
		if (count == count_len / 2) {
			current= add_len(current,count);
		}
	}
	current = core;
	printf("\nКоличество 'a' в последнем слове = %d\n", n);
	while (current->next != NULL) current = current->next;
	while (current != core) current = deletecurrentelement(core, current);
	free(core);
	return(0);
}