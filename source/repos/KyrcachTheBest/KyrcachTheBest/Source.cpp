#include <windows.h>
#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct vector //������
{
	int size; //������ �������
	int* data; //�������� �������
};
typedef struct Node // ���� ����
{
	vector* vector; // ���������� ����
	struct Node* next; // ��������� �� next ������� ����
	struct Node* pred;//��������� �� pred ������� ����
};
typedef struct core //���
{
	Node* head; //������ ����(����� �������)
	Node* tail; //����� ����(������ �������)
};
core* createdeck() //�������� ����
{
	core* tmp = (core*)malloc(sizeof(core)); //������������ ��������� ������
	if (tmp == NULL) //�������� �� ��������� ������
	{
		printf("�������� � ����������� ������� ����������! ���������� ���������...\n");
		return (0); //��������� ���������� ���������
	}
	tmp->head = NULL; //�������� ��������� �� ����� ������� �������
	tmp->tail = NULL; //������� ������ �������
	return tmp; //���������� ��������� �� ������ ������� ����
}
vector* newVector()
{
	int i;
	int m;
	int s;
	int doc = 0;
	int flag = 0;
	bool rez;
	int res;
	vector* Vector = (vector*)malloc(sizeof(vector)); //������������ ��������� ������
	if (Vector == NULL) //�������� �� ��������� ������
	{
		printf("�������� � ����������� ������� ����������! ���������� ���������...\n");
		return(0);
	}
	Vector->size = 0; //������� ������ ������������ �������

	do {
		printf("������� ������ �������: ");
		rez = scanf_s("%d", &Vector->size); //������ �������
		if (Vector->size <= 0) {
			rez = 0;
		}
		while (getchar() != '\n');
		if (rez < 1)
		{
			printf("������. �������  ������������� �����: \n");
			

		}
		
	} while (rez < 1);

	(Vector->data) = (int*)malloc(Vector->size * sizeof(int)); //������������ ��������� ������
	//m = (char*)malloc(Vector->size * sizeof(char));
	if (Vector->data == NULL) //�������� �� ��������� ������
	{
		printf("�������� � ����������� ������� ����������! ���������� ���������...\n");
		return (0);
	}
	for (i = 0; i < Vector->size; i++) //���� �� �4������ ��� �������� �������
	{
		do
		{
			printf("%d ������� ����� = ", i + 1);

			res = scanf_s("%d", &m);//���������� ���������
			while (getchar() != '\n');//�������� �� �����
			if (res < 1)
			{
				printf("������. ������� �����: \n");
				Sleep(1000);

			}
		} while (res < 1);



		Vector->data[i] = m;
		
	}
	system("cls");
	return(Vector); //���������� ���������� ������
}
Node* newNode() //�������� ������ ����
{
	Node* tmp = (Node*)malloc(sizeof(Node)); //������������ ��������� ������
	if (tmp == NULL) //���� ������ ������������, malloc ����� ������� ���������
	{
		printf("�������� � ����������� ������� ����������! ���������� ���������...\n"); //��������� ������������
		return(0); //��������� ���������� ���������
	}
	return tmp; //���������� ��������� �� ���� ����
}
void ochered(core* deck, vector* vector) {
	Node* tmp;
	tmp = newNode();
	tmp->vector = vector; // ����������� tmp �������� ������ �������
	tmp->next = NULL;
	Node* tmp2 = deck->head; //������ ��������� �� ������ ����
	if (deck->head == NULL && deck->tail == NULL)//���� ��������� � ���� �� ���������
	{
		deck->head = tmp;
		deck->tail = tmp;
	}
	else
	{
		while (tmp2->next != NULL) {	//���� �� ����� ����
			tmp2 = tmp2->next;
		}
		tmp2->next = tmp;
		deck->tail = tmp;
	}
}
void empty_stack_check(core* stack)
{
	if (stack->head == NULL && stack->tail == NULL) //���� ��� ������������� ����
	{
		printf("��� ����!\n");
	}
	else
	{
		printf("��� �� ����!\n");
	}
}
void deletedeck(core* deck)
{
	Node* tmp = deck->head; //������ ��������� �� ������ ����
	Node* aft = NULL; //��������������� ���������
	while (tmp->next != NULL)
	{ //���� �� ����� ����
		aft = tmp->next; //��� �� ����
		free(tmp); //�� ������� ����������� ������
		tmp = aft; //� ����������� ��������� �����
	}
	free(deck); //������� ���
}
void valueEndOfDeck(core* deck) {
	int i = 0;
	Node* tmp = deck->head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	printf("������� ������ ������� ����:\n");
	printf("(");
	while (i < tmp->vector->size - 1)
	{
		printf("%d, ", *(tmp->vector->data + i)); //����� �������
		i++;
	}
	printf("%d", *(tmp->vector->data + i)); //����� �������
	printf(")\n");
}
void valueStartOfDeck(core* deck) {
	int i = 0;
	

	Node* tmp = deck->head;

	printf("������� ����� ������� ����:\n");
	printf("(");
	while (i < tmp->vector->size - 1)
	{
		printf("%d, ", *(tmp->vector->data + i)); //����� �������
		i++;
	}
	printf("%d", *(tmp->vector->data + i)); //����� �������
	printf(")\n");

	

}
void DeleteEndOfDeck(core* deck) {
	if (deck->head->next != NULL) {
		Node* tmp = deck->head;

		while (tmp->next->next != NULL) {	//���� �� ������������� ������� ����
			tmp = tmp->next;
		}
		Node* tmp2 = tmp->next;
		deck->tail = tmp;
		tmp->next = NULL;
		free(tmp2);		//����������� ������

	}
	else {
		free(deck->head); //������� ���
		deck->head = NULL; //�������� ��������� �� ������ �������
		deck->tail = NULL; //�������� ��������� �� ��������� �������
	}
}
void DeleteStartOfDeck(core* deck) {
	if (deck->head->next != NULL) {

		Node* tmp = deck->head;
		Node* tmp2 = deck->head;
		tmp = tmp->next;
		free(tmp2);
		deck->head = tmp;
	}
	else {
		free(deck->head); //������� ���
		deck->head = NULL; //�������� ��������� �� ������ �������
		deck->tail = NULL; //�������� ��������� �� ��������� �������
	}
}
void PickElemStartOfDeck(core* deck) {
	int i = 0;
	Node* tmp = deck->head; // ����������� ���������� tmp � ������
	printf("(");
	for (i = 0; i < tmp->vector->size - 1; i++) {
		printf("%d, ", *(tmp->vector->data + i));
	}
	printf("%d", *(tmp->vector->data + i)); //����� �������
	printf(")\n");
}
void PickElemEndOfDeck(core* deck) {
	int i = 0;
	Node* tmp = deck->tail; //����������� � ���������� tmp ����� ����
	printf("(");
	for (i = 0; i < tmp->vector->size - 1; i++) {
		printf("%d, ", *(tmp->vector->data + i));
	}
	printf("%d", *(tmp->vector->data + i)); //����� �������
	printf(")\n");
}
void changestart(core* deck) {
	int rez;
	Node* tmp = deck->head;
	int i = 0;
	int n = 0;
	int number;
	printf("������� ����� ������ ����\n(");
	while (i < tmp->vector->size - 1)
	{
		printf("%d ", *(tmp->vector->data + i));  //����� �������
		i++;
	}
	printf("%d", *(tmp->vector->data + i));  //����� �������
	printf(")\n");
	while (n <= 0 || n > tmp->vector->size)
	{
		//do
		//{
		printf("������� ����� ����������� �������� �������:");
		scanf_s("%d", &n);
		if (n <= 0 || n > tmp->vector->size) printf("������������ ����� ����������� ��������!\n");
		while (getchar() != '\n');

	}
	n--;
	do
	{
		printf("������� �������� ����������� �������� �������:");
		rez = scanf_s("%d", &number);
		while (getchar() != '\n');
		if (rez < 1)
		{

			printf("������� �������� ��������. ��������� �������!\n");


		}
	} while (rez < 1);
	*(tmp->vector->data + n) = number;
}
void changeend(core* deck) {
	Node* tmp = deck->tail;
	int i = 0;
	int n = 0;
	int rez;
	int number;
	printf("������� ������ ������ ����\n(");
	while (i < tmp->vector->size - 1)
	{
		printf("%d ", *(tmp->vector->data + i));        //����� �������
		i++;
	}
	printf("%d", *(tmp->vector->data + i));         //����� �������
	printf(")\n");
	while (n <= 0 || n > tmp->vector->size)
	{
		//do
		//{
		printf("������� ����� ����������� �������� �������:");
		scanf_s("%d", &n);
		if (n <= 0 || n > tmp->vector->size) printf("������������ ����� ����������� ��������!\n");
		while (getchar() != '\n');

	}
	n--;
	do
	{
		printf("������� �������� ����������� �������� �������:");
		rez = scanf_s("%d", &number);
		while (getchar() != '\n');
		if (rez < 1)
		{

			printf("������� �������� ��������. ��������� �������!\n");


		}
	} while (rez < 1);
	*(tmp->vector->data + n) = number;
}
void addInStart(core* deck, vector* vector) {
	Node* tmp;
	Node* tmp2;
	tmp = newNode();
	tmp->vector = vector;
	if (deck->head == NULL && deck->tail == NULL)
	{
		tmp->next = NULL;
		deck->head = tmp;
		deck->tail = tmp;
	}
	else
	{
		tmp2 = deck->head;
		tmp->next = tmp2;
		deck->head = tmp;
	}

}
void printdeck(core* deck) {
	int i;
	Node* tmp = deck->head;
	while (tmp != NULL) {
		i = 0;
		printf("(");
		while (i < tmp->vector->size - 1)
		{
			printf("%d, ", *(tmp->vector->data + i)); //����� �������
			i++;
		}
		printf("%d", *(tmp->vector->data + i)); //����� �������
		tmp = tmp->next; //������������ ��������� �� ��������� ������
		printf(") ");
	}
	printf("\n");
}
int menu(core* deck, int n) //������� menu ��������� �� ���� ��������� �� ���
{
	vector* Vector;
	int rez;
	int comm = 0; //������� ������������
	int f = 0;
	system("cls");
	while (comm != 15)
	{
		printf("��������, ��� ������ ������� ���������:\n"); //��������� ������������
		if (deck->head == NULL && deck->tail == NULL)
		{
			printf("1. �������� ������ �������\n"); //��������� ������������
		}
		//��������� ������������
		printf("2. �������� ���\n");
		printf("3. ��������� �� ������� ���\n");
		printf("4. �������� �������� � ������ ����\n");
		printf("5. �������� �������� � ����� ����\n");
		printf("6. ������� ������ ����\n");
		printf("7. ������� ����� ����\n");
		printf("8. ����� ������� �� ������ ����\n");
		printf("9. ����� ������� �� ����� ����\n");
		printf("10. �������� �������� � ������ ����\n");
		printf("11. �������� �������� � ����� ����\n");
		printf("12. �������� ������� � ������ ����\n");
		printf("13. �������� ������� � ����� ����\n");
		printf("14. ����������� ���������\n");
		printf("15. ��������� ������ � �����\n");
		rez = scanf_s("%d", &comm);
		system("cls");
		switch (comm)
		{
		case (1):
			if (n > f) {
				Vector = newVector();
				ochered(deck, Vector);
				f++;
			}
			else {
				printf("���������� ��������� ������ ��������, ��� ��� ��� ����������!\n");
			}
			break;
		case(2):
			if (deck->head != NULL && deck->tail != NULL)
			{
				deletedeck(deck);
				deck = createdeck(); //� ������ ����� ������ ������
				printf("������ ������!\n\n");//��������� ������������
			}
			else {
				printf("��� ������ �������, ��� ��� ��� � ��� ����.\n");
			}
			break;
		case(3):
			empty_stack_check(deck);
			break;
		case(4):
			if (deck->head != NULL && deck->tail != NULL)
			{

				valueStartOfDeck(deck);
				printdeck(deck);
			}
			else {
				printf("���������� ��������� ������ ��������, ��������� ��� ����!\n");
			}
			break;
		case(5):
			if (deck->head != NULL && deck->tail != NULL)
			{

				valueEndOfDeck(deck);
				printdeck(deck);
			}
			else {
				printf("���������� ��������� ������ ��������, ��������� ��� ����!\n");
			}
			break;
		case(6):
			if (deck->head != NULL && deck->tail != NULL)
			{

				DeleteStartOfDeck(deck);
				printdeck(deck);
				f--;
			}
			else {
				printf("���������� ��������� ������ ��������, ��������� ��� ����!\n");
			}
			break;
		case(7):
			if (deck->head != NULL && deck->tail != NULL)
			{
				printdeck(deck);
				DeleteEndOfDeck(deck);
				f--;
			}
			else {
				printf("���������� ��������� ������ ��������, ��������� ��� ����!\n");
			}
			break;
		case(8):
			if (deck->head != NULL && deck->tail != NULL)
			{
				PickElemStartOfDeck(deck);
				DeleteStartOfDeck(deck);
				printf("������� �����!\n");
				f--;
			}
			else {
				printf("���������� ��������� ������ ��������, ��������� ��� ����!\n");
			}
			break;
		case(9):
			if (deck->head != NULL && deck->tail != NULL)
			{
				PickElemEndOfDeck(deck);
				DeleteEndOfDeck(deck);
				printf("������� �����!\n");
				f--;
			}
			else {
				printf("���������� ��������� ������ ��������, ��������� ��� ����!\n");
			}
			break;
		case(10):
			if (deck->head != NULL && deck->tail != NULL)
			{
				changestart(deck);
			}
			else {
				printf("��� ������ �������, ��� ��� ��� ����.\n");
			}
			break;
		case(11):
			if (deck->head != NULL && deck->tail != NULL)
			{
				printdeck(deck);
				changeend(deck);
			}
			else {
				printf("��� ������ �������, ��� ��� ��� ����.\n");
			}
			break;
		case(12):
			if (n > f) {
				printdeck(deck);
				Vector = newVector();
				addInStart(deck, Vector);
				f++;
			}
			else {
				printf("���������� ��������� ������ ��������, ��� ��� ��� ����������!\n");
			}
			break;
		case(13):
			if (n > f) {
				Vector = newVector();
				ochered(deck, Vector);
				f++;
			}
			else {
				printf("���������� ��������� ������ ��������, ��� ��� ��� ����������!\n");
			}
			break;
		case(14):
			if (deck->head != NULL && deck->tail != NULL)
			{
				printf("���:\n");
				printdeck(deck);
			}
			else {
				printf("��� ������ �������, ��� ��� ��� ����.\n");
			}
			break;
		case(15):
			if (deck->head != NULL && deck->tail != NULL)
			{
				deletedeck(deck);
			}
			else {
				free(deck);
			}
			break;
		default:
			while (getchar() != '\n');
			if (rez < 1)
			{
				system("cls");
				printf("������� �������� ��������. ��������� �������!\n");
				Sleep(1000);
				system("cls");
			}
			printf("������� ������������ ������!\n");
		}


	}
	return 2;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	core* Start;//������� ��������� �� 1 �������
	core* Endling;//������� ��������� �� ��������� �������
	int c = 2;
	int n = 0;
	int pv;
	printf("����������� ����: \n");
	printf("������� 1, ����� ������������ ��� ��� ������� 0, ����� ����� �� ��������:\n");
	while (c != 0)
	{
		scanf_s("%d", &c);

		if (c == 1)
		{
			do {
				printf("������� ������ ����: ");
				pv = scanf_s("%d", &n);
				while (getchar() != '\n');
				if (pv < 1)
				{
					system("cls");
					printf("������� �������� ��������. ��������� �������!\n");
					Sleep(1000);
					system("cls");
				}
			} while (pv < 1);
			Start = createdeck();
			c = menu(Start, n);
			printf("������� 1, ����� ������������ ����� ��� ��� ������� 0, ����� ����� �� ��������:\n");

		}
		else if (c != 1 && c != 0)
		{
			system("cls");
			printf("����������, ������� ���������� ����� ����.\n");
			printf("������� 1, ����� ������������ ��� ��� ������� 0, ����� ����� �� ��������:\n");
		}
	}
	return (0);
}
