#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <malloc.h>
typedef struct dequ//���������� ��������� "���"
{
	char* mass;//������ ����
	int size;//������ 
	struct dequ* next_el;//��������� �� ��������� �������
	struct dequ* pred_el;//��������� �� ���������� �������
} dec;

int vybor();//�������� �������
char* input_per_word();//�������� �������
int ckeck_word(char* word);//�������� �������
int isSpaces(char* word);//�������� �������
int isEmpty(dec* Decq_Start);//�������� �������
void clearDec(dec** Decq_Start, dec** Decq_Ending);//�������� �������
void showLeft(dec* Decq_Start);//�������� �������
void showRight(dec* Decq_Ending);//�������� �������
void delRight(dec** Decq_Start, dec** Decq_Ending);//�������� �������
void delLeft(dec** Decq_Start, dec** Decq_Ending);//�������� �������
void Take_Left(dec** Decq_Start, dec** Decq_Ending);//�������� �������
void Take_Right(dec** Decq_Start, dec** Decq_Ending);//�������� �������
void change_Left(dec** Decq_Start, dec** Decq_Ending);//�������� �������
void change_Right(dec** Decq_Start, dec** Decq_Ending);//�������� �������
void addLeft(dec** Decq_Start, dec** Decq_Ending);//�������� �������
void addRight(dec** Decq_Start, dec** Decq_Ending);//�������� �������
void printDec(dec* Decq_Start);//�������� �������
void glavnoeMenu(dec** Decq_Start, dec** Decq_Ending);//�������� �������
void zakonchitRaboty(dec** Decq_Start, dec** Decq_Ending);//�������� �������
void menuDeca(dec** Decq_Start, dec** Decq_Ending);//�������� �������
int dec_Size_elem = 0;//������� ���������� ����
int limit_on_input = 5;//����� ����

int main()
{
	setlocale(LC_ALL, "ru");
	dec* Decq_Start = NULL;//��������� �� ������ ������� ���� �������
	dec* Decq_Ending = NULL;//��������� �� ��������� �������  ���� �������
	glavnoeMenu(&Decq_Start, &Decq_Ending);
	return 0;
}

void glavnoeMenu(dec** Decq_Start, dec** Decq_Ending)//�������, ����������� ��������(������) ����
{
	int v;
	while (1)//����������� ����
	{
		printf("1. ������ ������\n");
		printf("2. ���������\n");
		v = vybor();//�������, ������������ ����� ������������
		switch (v)
		{
		case 1:
			menuDeca(Decq_Start, Decq_Ending);//�������, ����������� �������� ����
			break;
		case 2:
			printf("������ ��������\n");
			exit(0);//����� �� ���������
			break;
		default:
			printf("��� ������ ������\n");
			break;
		}
	}
}
void menuDeca(dec** Decq_Start, dec** Decq_Ending)//������� ��������� ����
{
	int v = 0;
	while (1)
	{
		printf("�����: \n");
		if (*Decq_Start != NULL)//���� ������ ������� ���� �� ����
			printDec(*Decq_Start);//������� ������ ����
		printf("\n1. ������� ��� ������\n");
		printf("2. �������� ������� ����\n");
		printf("3. �������� ������ ����\n");
		printf("4. �������� ����� ����\n");
		printf("5. ������� ������ ����\n");
		printf("6. ������� ����� ����\n");
		printf("7. ����� � ������\n");
		printf("8. ����� � �����\n");
		printf("9. �������� � ������\n");
		printf("10. �������� � �����\n");
		printf("11. �������� � ������ ����\n");
		printf("12. �������� � ����� ����\n");
		printf("13. ����������� ��������� ����\n");
		printf("14. ��������� ������\n");
		v = vybor();
		switch (v)
		{
		case 1:
			clearDec(Decq_Start, Decq_Ending);//������� ������� ����
			break;

		case 2:
			if (!isEmpty(*Decq_Start))//������� �������� ���� �� �������
				printf("����!\n");
			else
				printf("�� ����!\n");
			break;

		case 3:
			showLeft(*Decq_Start);//������� ������ ������� ��������
			break;

		case 4:
			showRight(*Decq_Ending);//������� ������ ���������� ��������
			break;

		case 5:
			delLeft(Decq_Start, Decq_Ending);//������� �������� ������� ��������
			break;

		case 6:
			delRight(Decq_Start, Decq_Ending);//������� �������� ���������� ��������
			break;

		case 7:
			Take_Left(Decq_Start, Decq_Ending);//������� ������ ���������� ��������
			break;
		case 8:
			Take_Right(Decq_Start, Decq_Ending);//������� ������ ���������� ��������
			break;
		case 9:
			change_Left(Decq_Start, Decq_Ending);//�������, ���������� ������ �������
			break;

		case 10:
			change_Right(Decq_Start, Decq_Ending);////�������, ���������� ������ �������
			break;

		case 11:
			addLeft(Decq_Start, Decq_Ending);//�������, ����������� ������� � ������ ����
			break;

		case 12:
			addRight(Decq_Start, Decq_Ending);//�������, ����������� ������� � ����� ����
			break;

		case 13:
			printDec(*Decq_Start);//����� ����
			break;

		case 14:
			zakonchitRaboty(Decq_Start, Decq_Ending);//����� ���������
			break;

		default:
			printf("����� ����� � ���� �����������\n");
			break;
		}
	}
}
void printDec(dec* Decq_Start)//����� ����
{
	if (Decq_Start == NULL)//���� ������ ������� ����� ����, �� ��� ����
	{
		printf("��� ����!\n");
		return;
	}

	dec* wek = Decq_Start;//� ���������� wek ���������� ������ �������
	printf("_");
	while (wek != NULL)//���� wek �� ����� ����
	{

		printf("%s", wek->mass);//����� �������

		if (wek->next_el != NULL)//���� ��������� ������� �� ����
		{
			printf("_");
		}
		wek = wek->next_el;//wek ����� ���������� �������� 
	}
	printf("_\n");
}
int vybor()
{
	printf("�������� ����: ");

	char str[100];
	scanf_s("%s", str, 100);

	int length = strlen(str);//������������ ������ ������ 
	if (length > 2)//���� ����� ������ 2
		return 0;//������� 0

	for (int i = 0; i < length; i++)// ���� ������� i �� ����� ����� lenght. ����� ������� ������� for, i ������������� �� 1
	{
		if (isdigit(str[i]) == 0)//isdigit ���������� 0 ���� �����
			return 0;//������� 0
	}

	return atoi(str);//atoi ������������ ������ � int
}
void clearDec(dec** Decq_Start, dec** Decq_Ending)
{
	if (*Decq_Start == NULL)//��������, ������ �� ���, ���� ������ ������� ����� ����, �� ����
	{
		printf("��� ����!\n");
		return;
	}

	while (*Decq_Start != NULL)//���� ������ ������� �� ����� ����
		delLeft(Decq_Start, Decq_Ending);//������� delLeft ������� ������ �������

}
char* input_per_word()//���� �����
{
	char* word = (char*)malloc(1024);//������������ ��������� ������ ��� �����
	if (word == NULL)//��������, ���� �� ������ ��� �����, ���� ���, �� �������
	{
		printf("%s", "��� ������\n");
		exit(1);//���������� ��������� � �������
	}
	getc(stdin);//
	do
	{
		printf("%s", "�������: ");//���� �����
		scanf_s("%s", word, 1024);
	} while (isSpaces(word) || !ckeck_word(word));//��������, ���� �� ������� ��� ����� � �����
	if (word == NULL)//��������, ���� �� ������ ��� �����, ���� ���, �� �������
	{
		printf("%s", "��� ������\n");
		exit(1);
	}
	return word;
}

int isEmpty(dec* Decq_Start)//��������, ���� �� ���
{
	if (Decq_Start == NULL)//���� ������ ������� ����
		return 0;
	return 1;
}
void addLeft(dec** Decq_Start, dec** Decq_Ending)//���������� ����� � ������ 
{
	if (dec_Size_elem == limit_on_input)//��������, �������� �� ������ ����
	{
		printf("�������� ������ ����!\n");
		return;
	}

	dec* tmp = (dec*)malloc(sizeof(dec));//������������ ��������� ������ ��� ��������� ���������� tmp
	if (tmp == NULL)//��������, ���������� �� ������
	{
		printf("��� ������!\n");
		exit(1);
	}
	tmp->mass = NULL;//��������� ���������� mass
	tmp->mass = input_per_word();//� ���� ����������� ��������� ������� input_per_word
	if (tmp->mass == NULL)//��������, ��������� �� ������� �����
	{
		printf("�������� ����\n");
		free(tmp);//������������ ������ ��� ���������� tmp
		return;
	}

	dec_Size_elem++;//���������� �������� ���������� ���� � ����
	if (*Decq_Start == NULL)//���� ��������� �� ������ ������� ���� ����� ����
	{
		tmp->next_el = NULL;//��������� ������� ����� ����
		tmp->pred_el = NULL;//���������� ������� ����� ����
		(*Decq_Ending) = tmp;//��������� ������� ����� tmp
	}
	else
	{
		(*Decq_Start)->pred_el = tmp;//����������� �������� ������ ������������� tmp 
		tmp->next_el = *Decq_Start;//�������� ���������� �������� ����� ����������
		tmp->pred_el = NULL;//���������� ������� ����� ����
	}
	(*Decq_Start) = tmp;//��������� ������� ����� tmp
}
void addRight(dec** Decq_Start, dec** Decq_Ending)//���������� ����� � ����� 
{
	if (dec_Size_elem == limit_on_input)//��������, �������� �� ������ ����
	{
		printf("�������� ������ ����!\n");
		return;
	}
	dec* tmp = (dec*)malloc(sizeof(dec));//������������ ��������� ������
	if (tmp == NULL)
	{
		printf("��� ������!\n");
		exit(1);
	}
	tmp->mass = NULL;
	tmp->mass = input_per_word();
	if (tmp->mass == NULL)
	{
		printf("�������� ����\n");
		free(tmp);
		return;
	}

	dec_Size_elem++;
	if (*Decq_Start == NULL)//���� ��������� �� ������ ������� ����� ����
	{
		tmp->next_el = NULL;//��������� ������� ����� ����
		tmp->pred_el = NULL;//���������� ������� ����� ����
		(*Decq_Start) = tmp;//��������� �������� ����� tmp

	}
	else
	{
		(*Decq_Ending)->next_el = tmp;//��������� ����� ����� ������� ����� tmp
		tmp->pred_el = (*Decq_Ending);//�������� ����������� �������� ����� ���������
		tmp->next_el = NULL;//��������� ������� ����� ����
	}

	(*Decq_Ending) = tmp;//�������� �������� ����� tmp
}
void Take_Left(dec** Decq_Start, dec** Decq_Ending)//����� ������ �������
{
	if (*Decq_Start == NULL)//��������, ���� �� ���
	{
		printf("��� ����!\n");
		return;
	}

	showLeft(*Decq_Start);//������� ������ ������
	delLeft(Decq_Start, Decq_Ending);//������� ������ ������
}
void Take_Right(dec** Decq_Start, dec** Decq_Ending)//����� ��������� �������
{
	if (*Decq_Start == NULL)//��������, ���� �� ���
	{
		printf("��� ����!\n");
		return;
	}

	showRight(*Decq_Start);//������� ��������� �������
	delRight(Decq_Start, Decq_Ending);//������� ��������� ������� 
}
void showLeft(dec* Decq_Start)//����� ������� ������� 
{
	if (Decq_Start == NULL)//��������, ���� �� ���
	{
		printf("��� ����!\n");
		return;
	}

	printf("%s", Decq_Start->mass);//����� ������� �������� �� mass

	printf("\n");//������� �� ��������� ������ � ���� ������
}
void showRight(dec* Decq_Ending)//����� ���������� ��������
{
	if (Decq_Ending == NULL)//��������, ���� �� ���
	{
		printf("��� ����!\n");
		return;
	}

	printf("%s", Decq_Ending->mass);//����� ���������� �������� �� mass

	printf("\n");//������� �� ��������� ������ � ���� ������
}
void change_Left(dec** Decq_Start, dec** Decq_Ending)//�������� ������ ������ 
{
	if (*Decq_Start == NULL)//��������, ���� �� ���
	{
		printf("��� ����!\n");
		return;
	}
	else//���� ��� ��� ����
	{
		(*Decq_Start)->mass = input_per_word();//� ������ ������� mass �������� ��������� ������� input_per_word
	}

}
int ckeck_word(char* word)//�������� ��������� �����
{
	int length = strlen(word);//� ���������� lenght ����� �������� ���-�� �������� � ����� 
	for (int i = 0; i < length; i++)//���� ������� i �� ����� ����� lenght
	{
		if (('a' <= word[i] && word[i] <= 'z') || ('A' <= word[i] && word[i] <= 'Z'))//���� � ����� ������������ �����
			continue;//���������� 
		else
			return 0;//������� 0

	}
	return 1;//������� 1
}
void change_Right(dec** Decq_Start, dec** Decq_Ending)//�������� ��������� �������
{
	if (*Decq_Ending == NULL)//��������, ���� �� ���
	{
		printf("��� ����!\n");
		return;
	}
	else//���� �� ���� ��
	{
		(*Decq_Ending)->mass = input_per_word();//� ��������� ������� mass �������� ��������� ������� input_per_word
	}

}
int isSpaces(char* word)
{
	int length = strlen(word);
	for (int i = 0; i < length; i++)
	{
		if (word[i] == '\0' || word[i] == '\n')//���� � ����� ������� ������� ������ ��� ����� ������
			break;//���������� ��������� if
		if (word[i] == ' ')//���� ������ ������
			return 1;
	}
	return 0;
}
void delRight(dec** Decq_Start, dec** Decq_Ending)//������� ������
{
	if (*Decq_Ending == NULL)//��������, ���� �� ���
	{
		printf("��� ����!\n");
		return;
	}

	dec* wek = *Decq_Ending;//� wek ����� ��������� �� ��������� ������� 
	if ((*Decq_Ending)->pred_el == NULL)//���� ���������� �� ����� ������� ���� ����� ����
	{
		(*Decq_Ending) = (*Decq_Start) = NULL;//��������� � �������� �������� ���� ����� ����
	}
	else
	{
		(*Decq_Ending) = (*Decq_Ending)->pred_el;//� ��������� ��������� �������� �������� ���������� �������
		(*Decq_Ending)->next_el = NULL;//��������� �� ������ ���������� �������� ���� �������� ���������
	}

	free(wek->mass);//������������ ������ 
	free(wek);
	dec_Size_elem--;//���-�� ��������� ���������� �� 1
}
void delLeft(dec** Decq_Start, dec** Decq_Ending)//������� ������ �����
{
	if (*Decq_Start == NULL)//��������, ���� �� ���
	{
		printf("��� ����!\n");
		return;
	}

	dec* wek = *Decq_Start;
	if ((*Decq_Start)->next_el == NULL)//������ ������� ����� ����?
	{
		(*Decq_Start) = NULL;
		(*Decq_Ending) = NULL;
	}
	else
	{
		(*Decq_Start) = (*Decq_Start)->next_el;//��������� ����� ���������� ������� ���������� ���������
		(*Decq_Start)->pred_el = NULL;//������ ������ �������� ���������
	}
	free(wek->mass);
	free(wek);
	dec_Size_elem--;
}
void zakonchitRaboty(dec** Decq_Start, dec** Decq_Ending)//��������� ������ 
{
	clearDec(Decq_Start, Decq_Ending);//������� ����
	printf("������ ��������\n");
	exit(0);//����� �� ���������
};
