#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <Windows.h>
void menu();
void BeginRunList();
struct list* deletehead(list* root);
struct list
{
	int field; // ���� ������
	struct list* ptr; // ��������� �� ��������� �������
};



void BeginRunList() {//����� 1 (������ ������ �� ��������)
	system("cls");
	list* list1 = NULL;
	list* list2 = NULL;
	printf("������ ������\n");
	menu();
}
struct list* deletehead(list* root){
	system("cls");
	if (root == NULL) {
		printf("���� ����\n");
	}
	while (root != NULL) {
		struct list* temp;
		temp = root;
		temp = root->ptr;
		free(root);// ������������ ������ �������� �����
	}
	return(root); // ����� ������ ������
}
void ProverkaList(list* root) {//��������
	if (root == NULL) {
		printf("������ ����\n");
	}
	else {
		printf("������ ����\n");
	}
}
struct list* FirstListElement(list* head, list* root) {//��������� �� ������ �������
	if (head == NULL) {
		printf("������ ����\n");
		menu();
	}
	root = head;
	return root;
}
struct list* EndListElement(list* head, list* root) {//��������� �� ��������� �������
	if (head == NULL) {
		printf("������ ����\n");
		menu();
	}
	root = head;
	while (root!= NULL) {
		root = root->ptr;
	}
	return root;
}
struct list* NextFirstListElement(list* head, list* root) {//����������� ������ ���������
	if (head == NULL) {
		printf("������ ����\n");
		menu();
	}
	if (head->ptr != NULL) {
		head = head->ptr;
		return head;
	}

}
void CheckNextFirstListElement(list* head,list* root) {
	if (head == NULL) {
		printf("������ ����\n");
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
		printf("������ ����\n");
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
		printf("������� �� ���������� �����������");
	}
	return temp1;
}

char NextElement(list* head) {
	struct list* temp,*temp_1,*temp_2;
	if (head == NULL) {
		printf("������ ����\n");
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
		printf("��� ��������");
	}
}
void NextElementMenit(list* head){
	char a = ' ';
	struct list* list;
	if (head == NULL) {
		printf("������ ����\n");
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
		printf("\n1. ������ ������ �� ������� \n2. ������� ������ ������ \n3. ��������� �� �������� \n4. ���������� ������� ��������� �� ������ ������");
		printf("\n5. ���������� ������� ��������� �� ����� ������ \n6. ����������� ������� ��������� ������ ������ \n7. �������� �������� �������� ������ �� ����������");
		printf("\n8. ������� ������� ������ �� ���������� \n9. ����� ������� ������ �� ���������� \n10. �������� �������� �������� ������ �� ���������� \n11. �������� ������� �� ����������");
		printf("\n12. ����������� ��������� ������ \n13. ��������� ������ �� ������� \n14. ��������� ������ ���������");
		printf("\n�������� ��������:\n");
		scanf_s("%d", &vvod);
		switch ((vvod)) {
		case 1:
			system("cls");
			BeginRunList();//������ ����� �����
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







//��������� ��������� ���������� ���� ��������� ������������ ������
//��������� ������ �������� � �������
//���� ����
//���������� ��������� � ����� (���� ��������� ���� ������ �� ������� �� ��������� ��������)
//����� ���������� ������� �������� ������ ���������� ������ � ��������� ����� �������� �������������� 
//������� ������
//��� � ��������� ��������

//1 ������ ������ � �������
//2 ������� ������ ������
//3 �������� ������(���� �� ����)
//4 ���������� ��������� � ������ ������
//5 �������� ��������� �� ����� ������
//6 ����������� ������ �� 1 ������� ���������
//7 �������� ������� ������ �� ����������
//8 ������� ������� ������ �� ����������
//9 ����� ������� ������ �� ����������
//10 �������� �������� �� ����������
//11 �������� ������� �� ����������
//12 
//13 ��������� ������ � ����������