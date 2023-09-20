#include <windows.h>
#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct vector //вектор
{
	int size; //размер вектора
	int* data; //элементы вектора
};
typedef struct Node // узел дека
{
	vector* vector; // содержимое дека
	struct Node* next; // указатель на next элемент дека
	struct Node* pred;//указатель на pred элемент дека
};
typedef struct core //дек
{
	Node* head; //начало дека(левая сторона)
	Node* tail; //конец дека(правая сторона)
};
core* createdeck() //создание дека
{
	core* tmp = (core*)malloc(sizeof(core)); //динамическое выделение памяти
	if (tmp == NULL) //проверка на выделение памяти
	{
		printf("Проблемы с оперативной памятью компьютера! Завершение программы...\n");
		return (0); //аварийное завершение программы
	}
	tmp->head = NULL; //обнуляем указатель на левый крайний элемент
	tmp->tail = NULL; //крайний правый элемент
	return tmp; //возвращаем указатель на первый элемент дека
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
	vector* Vector = (vector*)malloc(sizeof(vector)); //динамическое выделение памяти
	if (Vector == NULL) //проверка на выделение памяти
	{
		printf("Проблемы с оперативной памятью компьютера! Завершение программы...\n");
		return(0);
	}
	Vector->size = 0; //обнулям размер создаваемого вектора

	do {
		printf("Введите размер вектора: ");
		rez = scanf_s("%d", &Vector->size); //размер вектора
		if (Vector->size <= 0) {
			rez = 0;
		}
		while (getchar() != '\n');
		if (rez < 1)
		{
			printf("Ошибка. Введите  положительное число: \n");
			

		}
		
	} while (rez < 1);

	(Vector->data) = (int*)malloc(Vector->size * sizeof(int)); //динамическое выделение памяти
	//m = (char*)malloc(Vector->size * sizeof(char));
	if (Vector->data == NULL) //проверка на выделение памяти
	{
		printf("Проблемы с оперативной памятью компьютера! Завершение программы...\n");
		return (0);
	}
	for (i = 0; i < Vector->size; i++) //пока не п4олучим все элементы вектора
	{
		do
		{
			printf("%d элемент равен = ", i + 1);

			res = scanf_s("%d", &m);//записываем результат
			while (getchar() != '\n');//проверка на букву
			if (res < 1)
			{
				printf("Ошибка. Введите число: \n");
				Sleep(1000);

			}
		} while (res < 1);



		Vector->data[i] = m;
		
	}
	system("cls");
	return(Vector); //возвращаем полученный вектор
}
Node* newNode() //создание нового узла
{
	Node* tmp = (Node*)malloc(sizeof(Node)); //динамическое выделение памяти
	if (tmp == NULL) //если памяти недостаточно, malloc вернёт нулевой указатель
	{
		printf("Проблемы с оперативной памятью компьютера! Завершение программы...\n"); //сообщение пользователю
		return(0); //аварийное завершение программы
	}
	return tmp; //возвращаем указатель на этот узел
}
void ochered(core* deck, vector* vector) {
	Node* tmp;
	tmp = newNode();
	tmp->vector = vector; // присваиваем tmp значение нашего вектора
	tmp->next = NULL;
	Node* tmp2 = deck->head; //создаём указатель на начало дека
	if (deck->head == NULL && deck->tail == NULL)//если элементов в деке не оказалось
	{
		deck->head = tmp;
		deck->tail = tmp;
	}
	else
	{
		while (tmp2->next != NULL) {	//пока не конец дека
			tmp2 = tmp2->next;
		}
		tmp2->next = tmp;
		deck->tail = tmp;
	}
}
void empty_stack_check(core* stack)
{
	if (stack->head == NULL && stack->tail == NULL) //если дек действительно пуст
	{
		printf("Дек пуст!\n");
	}
	else
	{
		printf("Дек не пуст!\n");
	}
}
void deletedeck(core* deck)
{
	Node* tmp = deck->head; //создаём указатель на начало дека
	Node* aft = NULL; //вспомогательный указатель
	while (tmp->next != NULL)
	{ //пока не конец дека
		aft = tmp->next; //идём по деку
		free(tmp); //по очереди освобождаем память
		tmp = aft; //и передвигаем указатель вперёд
	}
	free(deck); //удаляем дек
}
void valueEndOfDeck(core* deck) {
	int i = 0;
	Node* tmp = deck->head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	printf("Элемент правой стороны дека:\n");
	printf("(");
	while (i < tmp->vector->size - 1)
	{
		printf("%d, ", *(tmp->vector->data + i)); //вывод вектора
		i++;
	}
	printf("%d", *(tmp->vector->data + i)); //вывод вектора
	printf(")\n");
}
void valueStartOfDeck(core* deck) {
	int i = 0;
	

	Node* tmp = deck->head;

	printf("Элемент левой стороны дека:\n");
	printf("(");
	while (i < tmp->vector->size - 1)
	{
		printf("%d, ", *(tmp->vector->data + i)); //вывод вектора
		i++;
	}
	printf("%d", *(tmp->vector->data + i)); //вывод вектора
	printf(")\n");

	

}
void DeleteEndOfDeck(core* deck) {
	if (deck->head->next != NULL) {
		Node* tmp = deck->head;

		while (tmp->next->next != NULL) {	//пока не предпоследний элемент дека
			tmp = tmp->next;
		}
		Node* tmp2 = tmp->next;
		deck->tail = tmp;
		tmp->next = NULL;
		free(tmp2);		//освобождаем память

	}
	else {
		free(deck->head); //очищаем дек
		deck->head = NULL; //обнуляем указатель на первый элемент
		deck->tail = NULL; //обнуляем указатель на последний элемент
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
		free(deck->head); //очищаем дек
		deck->head = NULL; //обнуляем указатель на первый элемент
		deck->tail = NULL; //обнуляем указатель на последний элемент
	}
}
void PickElemStartOfDeck(core* deck) {
	int i = 0;
	Node* tmp = deck->head; // присваиваем переменной tmp в начало
	printf("(");
	for (i = 0; i < tmp->vector->size - 1; i++) {
		printf("%d, ", *(tmp->vector->data + i));
	}
	printf("%d", *(tmp->vector->data + i)); //вывод вектора
	printf(")\n");
}
void PickElemEndOfDeck(core* deck) {
	int i = 0;
	Node* tmp = deck->tail; //присваиваем в переменную tmp конец дека
	printf("(");
	for (i = 0; i < tmp->vector->size - 1; i++) {
		printf("%d, ", *(tmp->vector->data + i));
	}
	printf("%d", *(tmp->vector->data + i)); //вывод вектора
	printf(")\n");
}
void changestart(core* deck) {
	int rez;
	Node* tmp = deck->head;
	int i = 0;
	int n = 0;
	int number;
	printf("Крайний левый вектор дека\n(");
	while (i < tmp->vector->size - 1)
	{
		printf("%d ", *(tmp->vector->data + i));  //вывод вектора
		i++;
	}
	printf("%d", *(tmp->vector->data + i));  //вывод вектора
	printf(")\n");
	while (n <= 0 || n > tmp->vector->size)
	{
		//do
		//{
		printf("Введите номер изменяемого элемента вектора:");
		scanf_s("%d", &n);
		if (n <= 0 || n > tmp->vector->size) printf("Некорректный номер изменяемого элемента!\n");
		while (getchar() != '\n');

	}
	n--;
	do
	{
		printf("Введите значение изменяемого элемента вектора:");
		rez = scanf_s("%d", &number);
		while (getchar() != '\n');
		if (rez < 1)
		{

			printf("Введено неверное значение. Повторите попытку!\n");


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
	printf("Крайний правый вектор дека\n(");
	while (i < tmp->vector->size - 1)
	{
		printf("%d ", *(tmp->vector->data + i));        //вывод вектора
		i++;
	}
	printf("%d", *(tmp->vector->data + i));         //вывод вектора
	printf(")\n");
	while (n <= 0 || n > tmp->vector->size)
	{
		//do
		//{
		printf("Введите номер изменяемого элемента вектора:");
		scanf_s("%d", &n);
		if (n <= 0 || n > tmp->vector->size) printf("Некорректный номер изменяемого элемента!\n");
		while (getchar() != '\n');

	}
	n--;
	do
	{
		printf("Введите значение изменяемого элемента вектора:");
		rez = scanf_s("%d", &number);
		while (getchar() != '\n');
		if (rez < 1)
		{

			printf("Введено неверное значение. Повторите попытку!\n");


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
			printf("%d, ", *(tmp->vector->data + i)); //вывод вектора
			i++;
		}
		printf("%d", *(tmp->vector->data + i)); //вывод вектора
		tmp = tmp->next; //передвижение указателя на следующий вектор
		printf(") ");
	}
	printf("\n");
}
int menu(core* deck, int n) //функция menu принимает на вход указатель на дек
{
	vector* Vector;
	int rez;
	int comm = 0; //команда пользователя
	int f = 0;
	system("cls");
	while (comm != 15)
	{
		printf("Выберите, что должна сделать программа:\n"); //сообщение пользователю
		if (deck->head == NULL && deck->tail == NULL)
		{
			printf("1. Добавить первый элемент\n"); //сообщение пользователю
		}
		//сообщения пользователю
		printf("2. Очистить дек\n");
		printf("3. Проверить на пустоту дек\n");
		printf("4. Показать значение в начале дека\n");
		printf("5. Показать значение в конце дека\n");
		printf("6. Удалить начало дека\n");
		printf("7. Удалить конец дека\n");
		printf("8. Взять элемент из начала дека\n");
		printf("9. Взять элемент из конца дека\n");
		printf("10. Изменить значение в начале дека\n");
		printf("11. Изменить значение в конце дека\n");
		printf("12. Добавить элемент в начало дека\n");
		printf("13. Добавить элемент в конец дека\n");
		printf("14. Распечатать структуру\n");
		printf("15. Завершить работу с деком\n");
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
				printf("Невозможно выполнить данную операцию, так как дек переполнен!\n");
			}
			break;
		case(2):
			if (deck->head != NULL && deck->tail != NULL)
			{
				deletedeck(deck);
				deck = createdeck(); //и создаём новый пустой список
				printf("Список очищен!\n\n");//сообщение пользователю
			}
			else {
				printf("Это нельзя сделать, так как дек и так пуст.\n");
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
				printf("Невозможно выполнить данную операцию, поскольку дек пуст!\n");
			}
			break;
		case(5):
			if (deck->head != NULL && deck->tail != NULL)
			{

				valueEndOfDeck(deck);
				printdeck(deck);
			}
			else {
				printf("Невозможно выполнить данную операцию, поскольку дек пуст!\n");
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
				printf("Невозможно выполнить данную операцию, поскольку дек пуст!\n");
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
				printf("Невозможно выполнить данную операцию, поскольку дек пуст!\n");
			}
			break;
		case(8):
			if (deck->head != NULL && deck->tail != NULL)
			{
				PickElemStartOfDeck(deck);
				DeleteStartOfDeck(deck);
				printf("Элемент удалён!\n");
				f--;
			}
			else {
				printf("Невозможно выполнить данную операцию, поскольку дек пуст!\n");
			}
			break;
		case(9):
			if (deck->head != NULL && deck->tail != NULL)
			{
				PickElemEndOfDeck(deck);
				DeleteEndOfDeck(deck);
				printf("Элемент удалён!\n");
				f--;
			}
			else {
				printf("Невозможно выполнить данную операцию, поскольку дек пуст!\n");
			}
			break;
		case(10):
			if (deck->head != NULL && deck->tail != NULL)
			{
				changestart(deck);
			}
			else {
				printf("Это нельзя сделать, так как дек пуст.\n");
			}
			break;
		case(11):
			if (deck->head != NULL && deck->tail != NULL)
			{
				printdeck(deck);
				changeend(deck);
			}
			else {
				printf("Это нельзя сделать, так как дек пуст.\n");
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
				printf("Невозможно выполнить данную операцию, так как дек переполнен!\n");
			}
			break;
		case(13):
			if (n > f) {
				Vector = newVector();
				ochered(deck, Vector);
				f++;
			}
			else {
				printf("Невозможно выполнить данную операцию, так как дек переполнен!\n");
			}
			break;
		case(14):
			if (deck->head != NULL && deck->tail != NULL)
			{
				printf("дек:\n");
				printdeck(deck);
			}
			else {
				printf("Это нельзя сделать, так как дек пуст.\n");
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
				printf("Введено неверное значение. Повторите попытку!\n");
				Sleep(1000);
				system("cls");
			}
			printf("Введены некорректные данные!\n");
		}


	}
	return 2;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	core* Start;//Создаем указатель на 1 элемент
	core* Endling;//Создаем указатель на последний элемент
	int c = 2;
	int n = 0;
	int pv;
	printf("Организация дека: \n");
	printf("Введите 1, чтобы организовать дек или введите 0, чтобы выйти из програмы:\n");
	while (c != 0)
	{
		scanf_s("%d", &c);

		if (c == 1)
		{
			do {
				printf("введите размер дека: ");
				pv = scanf_s("%d", &n);
				while (getchar() != '\n');
				if (pv < 1)
				{
					system("cls");
					printf("Введено неверное значение. Повторите попытку!\n");
					Sleep(1000);
					system("cls");
				}
			} while (pv < 1);
			Start = createdeck();
			c = menu(Start, n);
			printf("Введите 1, чтобы организовать новый дек или введите 0, чтобы выйти из програмы:\n");

		}
		else if (c != 1 && c != 0)
		{
			system("cls");
			printf("Пожалуйста, введите корректный пункт меню.\n");
			printf("Введите 1, чтобы организовать дек или введите 0, чтобы выйти из програмы:\n");
		}
	}
	return (0);
}
