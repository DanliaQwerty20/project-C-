#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <Windows.h>
void menu();
void BeginRunList();
struct list* deletehead(list* root);
struct list
{
	int field; // поле данных
	struct list* ptr; // указатель на следующий элемент
};



void BeginRunList() {//пункт 1 (начать работу со списками)
	system("cls");
	list* list1 = NULL;
	list* list2 = NULL;
	printf("Работа начата\n");
	menu();
}
struct list* deletehead(list* root){
	system("cls");
	if (root == NULL) {
		printf("Лист пуст\n");
	}
	while (root != NULL) {
		struct list* temp;
		temp = root;
		temp = root->ptr;
		free(root);// освобождение памяти текущего корня
	}
	return(root); // новый корень списка
}
void ProverkaList(list* root) {//проверка
	if (root == NULL) {
		printf("Список пуст\n");
	}
	else {
		printf("Список есть\n");
	}
}
struct list* FirstListElement(list* head, list* root) {//указатель на первый элемент
	if (head == NULL) {
		printf("Список пуст\n");
		menu();
	}
	root = head;
	return root;
}
struct list* EndListElement(list* head, list* root) {//указатель на последний элемент
	if (head == NULL) {
		printf("Список пуст\n");
		menu();
	}
	root = head;
	while (root!= NULL) {
		root = root->ptr;
	}
	return root;
}
struct list* NextFirstListElement(list* head, list* root) {//передвинуть первый указатель
	if (head == NULL) {
		printf("Список пуст\n");
		menu();
	}
	if (head->ptr != NULL) {
		head = head->ptr;
		return head;
	}

}
void CheckNextFirstListElement(list* head,list* root) {
	if (head == NULL) {
		printf("Список пуст\n");
		menu();
	}
	root=head;
	if (root->ptr != NULL) {
		root = root->ptr;
		printf("%c", root->ptr->field);	
	}
}

struct list* ClearElementList(list* head,list* root) {
	struct list* temp1;
	temp1 = NULL;
	if (head == NULL) {
		printf("Список пуст\n");
		menu();
	}
	if (head->ptr != NULL) {


		temp1 = head;

		while (temp1->ptr != head->ptr) {
			temp1 = temp1->ptr;
		}
		temp1->ptr = head->ptr;

		free(head);
	}
	else {
		printf("Элемент за указателем отсутствует");
	}
	return temp1;
}

char NextElement(list* head) {
	struct list* temp,*temp_1,*temp_2;
	if (head == NULL) {
		printf("Список пуст\n");
		menu();
	}
	temp = head;
	char temp1;
	if (temp->ptr != NULL) {
		temp1 = temp->ptr->field;
		temp_1 = temp->ptr;
		temp_2 = temp->ptr->ptr;
		free(temp_1);
		return temp1;
	}
	else {
		printf("Нет элемента");
	}
}
void NextElementMenit(list* head){
	char a = ' ';
	struct list* list;
	if (head == NULL) {
		printf("Список пуст\n");
		menu();
	}
	list = (struct list*)malloc(sizeof(struct list));
	list = head;
	if (head->ptr != NULL) {
		while (getchar() != '\n');
		a = getchar();
		list->ptr->field= a;
	}
}


void menu() {
	bool flag = true;
	list* list1 = NULL;
	list* list2 = NULL;
	int vvod;
	char a = ' ';
	while (flag) {
		printf("\n1. Начать работу со списком \n2. Сделать список пустым \n3. Проверить на пустотуи \n4. Установить рабочий указатель на начало списка");
		printf("\n5. Установить рабочий указатель на конец списка \n6. Передвинуть рабочий указатель списка вперед \n7. Показать значение элемента списка за указателем");
		printf("\n8. Удалить элемент списка за указателем \n9. Взять элемент списка за указателем \n10. Изменить значение элемента списка за указателем \n11. Добавить элемент за указателем");
		printf("\n12. Распечатать структуру данных \n13. Закончить работу со списком \n14. Закончить работу программы");
		printf("\nВыберите действие:\n");
		scanf_s("%d", &vvod);
		switch ((vvod)) {
		case 1:
			system("cls");
			BeginRunList();//просто точка входа
			break;
		case 2:
			system("cls");
			list1 = deletehead(list1);
			break;
		case 3:
			system("cls");
			ProverkaList(list1);
			break;
		case 4:
			system("cls");
			list2 = FirstListElement(list1, list2);
			break;
			 
		case 5:
			system("cls");
			list2 = EndListElement(list1, list2);
			break;
		case 6:
			system("cls");
			list2 = NextFirstListElement(list1, list2);
			break;
		case 7:
			system("cls");
			CheckNextFirstListElement(list1, list2);
			break;
		case 8:
			system("cls");
			list2 = ClearElementList(list1, list2);
			break;
		case 9:
			system("cls");
			a = NextElement(list2);
			break;
		case 10:
			system("cls");
			NextElement(list2);
		case 11:

		default:

			break;
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	menu();
}







//написание программы выполнение всей программы односвязного списка
//программа должна работать в дилогом
//меню обяз
//адекватное сообщение в ответ (либо результат либо ошибка по которой не выполнено действие)
//после выполнения каждого действия должен печататься список с указанием места текущего местоположения 
//очистка списка
//все в отдельных функциях

//1 начать работу с списком
//2 сделать список пустым
//3 проверка списка(пуст не пуст)
//4 установить указатель в начало списка
//5 проверка указателя на конец списка
//6 передвинуть вперед на 1 элемент указатель
//7 показать элемент списка за указателем
//8 удалить элемент списка за указателем
//9 взять элемент списка за указателем
//10 изменить значение за указателем
//11 добавить элемент за указателем
//12 
//13 закончить работу с указателем