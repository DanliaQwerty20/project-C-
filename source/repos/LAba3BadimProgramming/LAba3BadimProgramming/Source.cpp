#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include <windows.h>

struct list {
	char value;
	struct list* ptr;
};
struct list* Create(char data) {
	struct list* root;
	root = (struct list*)malloc(sizeof(struct list));
	if (root == NULL) {
		printf("�� �������\n");
		exit(0);
	}
	root->value = data;
	root->ptr = NULL;
	return(root);
}

void Begin() {
	list* head = NULL;
	list* WPtr = NULL;
	printf("������ ������\n");
}
struct list* initiate(char c)
{
	struct list* list;
	list = (struct list*)malloc(sizeof(struct list));
	if (list == NULL)
	{
		printf_s("������ �� ��������. ���������� ���������...\n");
		return(0);
	}
	list->value = c;
	list->ptr = NULL;
	return(list);
}

struct list* Clear(list* head) {
	while (head != NULL) {
		struct list* p;
		p = head;
		head = head->ptr;
		free(p);
	}
	head = NULL;
	return(head);
}

void CheckEmptiness(list* head) {
	if (head == NULL)
		printf("True");
	else
		printf("False");
}

struct list* WPointerToBegin(list* head, list* WPtr) {
	WPtr = head;
	return(WPtr);
}

struct list* WPointerToEnd(list* head, list* WPtr) {
	WPtr = head;
	while (WPtr->ptr != NULL) {
		WPtr = WPtr->ptr;
	}
	return(WPtr);
}
struct list* NextElem(list* head, list* WPtr) {
	if (WPtr->ptr != NULL)
		WPtr = WPtr->ptr;
	return(WPtr);
}

void ShowValue(list* head, list* WPtr) {
	if (WPtr->ptr != NULL)
		printf("%c", WPtr->ptr->value);
}

struct list* RemoveElem(list* head, list* WPtr) {
	struct list* qwe, * asd;
	if (WPtr->ptr != NULL) {
		qwe = WPtr->ptr;
		asd = WPtr->ptr->ptr;
		WPtr->ptr = asd;
		free(qwe);
	}
	else
		printf("������� �� ���������� �����������");
	return(WPtr);
}

char TakeElem(list* WPtr) {
	struct list* qwe, * asd;
	char Saved;
	if (WPtr->ptr != NULL) {
		Saved = WPtr->ptr->value;
		qwe = WPtr->ptr;
		asd = WPtr->ptr->ptr;
		WPtr->ptr = asd;
		free(qwe);
		return(Saved);
	}
	else
		printf("������� �� ���������� �����������");
}

void ChangeValue(list* WPtr) {
	char a = ' ';
	if (WPtr->ptr != NULL) {
		while (getchar() != '\n');
		a = getchar();
		WPtr->ptr->value = a;
	}
}

struct list* AddElem(list* head, list* WPtr) {
	struct list* temp;
	char a;
	while (getchar() != '\n');
	a = getchar();
	temp = (struct list*)malloc(sizeof(list));
	if (temp == NULL) {
		printf("�� �������\n");
		exit(0);
	}
	if (head != NULL) {
		temp->value = a;
		temp->ptr = WPtr->ptr;
		WPtr->ptr = temp;
	}
	else {
		temp->value = a;
		temp->ptr = NULL;
		head = temp;
		return(head);
	}
}

void PrintList(list* head) {
	if (head == NULL)
		printf("������ ����\n");
	else
		while (head != NULL) {
			printf("%c", head->value);
			head = head->ptr;
		}
}

void End(list* head, list* WPtr) {
	while (head != NULL) {
		struct list* p;
		p = head;
		head = head->ptr;
		free(p);
	}
	head = NULL, WPtr = NULL;
	printf("������ ���������\n");
}

int main() {
	int flag = 0, ActionsMenu;
	char Saved = ' ';
	int c = 0, i = 0;
	list* head = NULL;
	list* WPtr = NULL;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	flag = 0;
	while (flag != 1)
	{
		printf("\n1. ������ ������ �� ������� \n2. ������� ������ ������ \n3. ��������� �� �������� \n4. ���������� ������� ��������� �� ������ ������");
		printf("\n5. ���������� ������� ��������� �� ����� ������ \n6. ����������� ������� ��������� ������ ������ \n7. �������� �������� �������� ������ �� ����������");
		printf("\n8. ������� ������� ������ �� ���������� \n9. ����� ������� ������ �� ���������� \n10. �������� �������� �������� ������ �� ���������� \n11. �������� ������� �� ����������");
		printf("\n12. ����������� ��������� ������ \n13. ��������� ������ �� ������� \n14. ��������� ������ ���������");
		printf("\n�������� ��������:\n");
		scanf_s("%d", &ActionsMenu);
		switch (ActionsMenu) {
		case (1):
			Begin();
			initiate(Saved);
			break;
		case (2):
			head = Clear(head);
			break;
		case (3):
			CheckEmptiness(head);
			break;
		case (4):
			WPtr = WPointerToBegin(head, WPtr);
			break;
		case (5):
			WPtr = WPointerToEnd(head, WPtr);
			break;
		case (6):
			WPtr = NextElem(head, WPtr);
			break;
		case (7):
			ShowValue(head, WPtr);
			break;
		case (8):
			WPtr = RemoveElem(head, WPtr);
			break;
		case (9):
			Saved = TakeElem(WPtr);
			break;
		case (10):
			ChangeValue(WPtr);
			break;
		case (11):
			if (head != NULL)
				AddElem(head, WPtr);
			else {
				head = AddElem(head, WPtr);
				WPtr = head;
			}
			break;
		case (12):
			PrintList(head);
			break;
		}
	}
}