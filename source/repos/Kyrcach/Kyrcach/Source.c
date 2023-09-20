#include<stdio.h>
#include<malloc.h>
#include<conio.h>

#define _CRT_SECURE_NO_WARNINGS
typedef struct list
{
	struct list* prev;
	int* word;
	struct list* next;
}listing;

int vvod()
{
	long long int c = NULL;
	int flag = 1, i = 0, fl = 0, fll = 1, fgg = 1, fhh = 0, ffl = 0, k, kk;
	char cc = ' ', cg[12], cgg[13];

	while (flag)
	{
		if (fl == 0)
		{
			if (cc == '\n')
				cc = ' ';
			while (fll)
			{
				while (cc != '\n')
				{
					if (i > 10)
					{
						if (ffl == 0)
						{
							printf("previshen limit,vvodite po novoi");
							Sleep(1500);
							system("cls");
							ffl = 1;
						}
						i = 0;
						fgg = 0;
						char cgg[12];
						continue;
					}
					cc = getchar();
					cgg[i] = cc;
					i++;
				}
				if ((cc == '\n') && (fgg == 0))
				{
					fgg = 1;
					i = 0;
					cc = ' ';
					ffl = 0;
					continue;
				}

				if ((cc == '\n') && (fgg == 1))
					fll = 0;
			}

			i = 0;
			fl = 1;
		}
		if (fhh == 0)
		{
			while (cgg[i] != '\n')
			{
				cg[i] = cgg[i];
				cgg[i] = 0;
				i++;
			}
			fhh = 1;
			cg[i] = '\n';
			i = 0;
		}
		if (cg[0] == '\n')
		{
			return NULL;
		}
		if (((cg[i] < 48) || (cg[i] > 57)) && (cg[i] != '+') && (cg[i] != '-'))
		{
			printf("Nevern znachenie, vvedite eche");
			Sleep(1500);
			system("cls");
			i = 0;
			fl = 0;
			fll = 1;
			fhh = 0;
			ffl = 0;
			continue;
		}
		else
		{
			i++;
		}
		if (cg[i] == '\n')
		{
			flag = 0;
		}
	}
	c = atoll(cg);
	return c;
}

listing* arsonist(int* wort)
{
	listing* node;
	node = (listing*)malloc(sizeof(listing));
	if (node == NULL)
	{
		printf("Memory two blocks down");
		exit(1);
	}
	node->prev = NULL;
	node->word = wort;
	node->next = NULL;
	return node;
}

int letsgo(listing* head)
{
	listing* slave;
	int i = 0;
	char c;
	char* stroka = NULL;
	char sem = getchar();
	sem = ' ';
	stroka = (char*)malloc(sizeof(char));
	if (stroka == NULL)
	{
		free(stroka);
		return 0;
	}
	printf("Vvedite stroku:\n");
	c = ' ';
	for (i = 0; (c != '\n'); i++)
	{
		stroka = (char*)realloc(stroka, ((i + 1)) * sizeof(char));
		if (stroka == NULL)
		{
			free(stroka);
			return 0;
		}
		*(stroka + i) = getchar();
		c = *(stroka + i);
	}
	listing* master = arsonist(stroka);
	listing* buff = head;

	slave = head;
	while (buff->next != NULL)
	{
		buff = buff->next;
	}
	buff->next = master;
	return head;
}

int back_here(listing* head)
{
	int i = 0;
	int k, h = 0;
	char c;
	int* stroka = NULL;
	char sem = getchar();
	sem = ' ';
	stroka = (int*)malloc(sizeof(int));
	if (stroka == NULL)
	{
		free(stroka);
		return 0;
	}
	printf("Vvedite vecktor:\n");
	c = ' ';
	printf("\n");
	for (i = 0; (h != 1); i++)
	{
		stroka = (int*)realloc(stroka, ((i + 1)) * sizeof(int));
		if (stroka == NULL)
		{
			free(stroka);
			return 0;
		}
		if ((k = vvod()) != NULL)
			*(stroka + i) = k;
		else
			h = 1;
	}
	*(stroka + i) = NULL;
	int flag = 1;
	int boy = head;
	head = arsonist(stroka);
	boy = head;
	flag = 0;
	head = boy;
	return head;
}

int spanking(listing* head)
{
	int k = 0, kp = 0;
	int boy = head;
	if (head == NULL)
	{
		printf("Spisok two blocks down");
		return 1;
	}
	while (head != NULL)
	{
		if (head->word == ' ')
			kp += 1;
		else
		{
			if (kp >= k)
			{
				k = kp;
				kp = 0;
			}
			else
				kp = 0;
		}
		head = head->next;
	}
	head = boy;
	return k;
}

listing* pull_up2(listing* head)
{
	listing* end = NULL;
	int boy = head;
	char c;
	int i = 0;
	int k, h = 0;
	int* stroka = NULL;
	char sem = getchar();
	sem = ' ';
	stroka = (int*)malloc(sizeof(int));
	if (stroka == NULL)
	{
		free(stroka);
		return 0;
	}
	printf("Vvedite vecktor:\n");
	c = ' ';
	printf("\n");
	for (i = 0; (h != 1); i++)
	{
		stroka = (int*)realloc(stroka, ((i + 1)) * sizeof(int));
		if (stroka == NULL)
		{
			free(stroka);
			return 0;
		}
		if ((k = vvod()) != NULL)
			*(stroka + i) = k;
		else
			h = 1;
	}
	*(stroka + i) = NULL;
	listing* buff = head;
	if (head == NULL)
	{
		printf("Spisok two blocks down");
		return 1;
	}
	buff = head;
	listing* newboy = arsonist(stroka);
	if (buff->prev == NULL)
	{
		buff->prev = newboy;
		newboy->next = buff;
		head = newboy;
	}
	else
	{
		newboy->prev = buff->prev;
		buff->prev->next = newboy;
		newboy->next = buff;
		buff->prev = newboy;
	}
	head = boy;
	buff = boy;
	while (buff->next != NULL)
	{
		buff = buff->next;
	}
	end = buff;
	return end;
}

listing* headslave(listing* head)
{
	int boy = head;
	int cc = 0;
	listing* buff = head;
	if (head == NULL)
	{
		printf("Spisok two blocks down");
		return 1;
	}
	if (head->next == NULL)
	{
		head = freedom(head);
		return head;
	}
	else
	{
		listing* pv = head;
		head = head->next;
		head->prev = NULL;
		free(pv);
	}
	return head;
}

listing* endslave(listing* head)
{
	int boy = head;
	int cc = 0;
	listing* buff = head;
	if (head == NULL)
	{
		printf("Spisok two blocks down");
		return 1;
	}
	if (head->prev == NULL)
	{
		head = freedom(head);
		return head;
	}
	else
	{
		listing* pv = head;
		head = head->prev;
		head->next = NULL;
		free(pv);
	}
	return head;
}

int freedom(listing* head)
{
	if (head == NULL)
	{
		printf("Spisok two blocks down");
		return 1;
	}
	else
		while (head)
		{
			listing* buff = head;
			head = head->next;
			free(buff);
		}
	head = NULL;
}

int cots(listing* head)
{
	int boy = head;
	int cc = 0;
	listing* buff = head;
	if (head == NULL)
	{
		printf("Spisok two blocks down");
		return 1;
	}
	else
		while (buff->next != NULL)
		{
			cc += 1;
			buff = buff->next;
		}
	head = boy;
	return cc;
}


void sucktion(listing* head, int flag, listing* end)
{
	int i = 0;
	listing* buff = head;
	if (flag == 0)
	{
		while (buff != NULL)
		{

			while (*((buff->word) + i + 1) != NULL)
			{
				printf("%d", *(buff->word + i));
				printf(" ");
				i++;
			}
			printf(" ");
			printf("|");
			printf(" ");
			buff = buff->next;
			i = 0;
		}
		buff = end;
		printf("\n");
		while (buff != NULL)
		{
			while (*(buff->word + i + 1) != NULL)
			{
				printf("%d", *(buff->word + i));
				printf(" ");
				i++;
			}
			printf(" ");
			printf("|");
			printf(" ");
			buff = buff->prev;
			i = 0;
		}
	}
	else
		printf("no spisok");
}

int lonelines(listing* head, int cot)
{
	listing* buff = head;
	int fl = 0;
	int i = 0;
	if (head == NULL)
	{
		cot = 0;
		fl = 1;
	}

	while (i < cot)
	{
		if (buff->next == NULL)
		{
			fl = 1;
			break;
		}
		else
			buff = buff->next;
		i++;
	}
	if (fl == 1)
		printf("no spisok");
	else
		printf("yes spisok");
	return fl;
}


void change2(listing* head)
{
	int i = 0;
	int k, h = 0;
	char c;
	int* stroka = NULL;
	char sem = getchar();
	sem = ' ';
	stroka = (int*)malloc(sizeof(int));
	if (stroka == NULL)
	{
		free(stroka);
		return 0;
	}
	printf("Vvedite vecktor:\n");
	c = ' ';
	printf("\n");
	for (i = 0; (h != 1); i++)
	{
		stroka = (int*)realloc(stroka, ((i + 1)) * sizeof(int));
		if (stroka == NULL)
		{
			free(stroka);
			return 0;
		}
		if ((k = vvod()) != NULL)
			*(stroka + i) = k;
		else
			h = 1;
	}
	*(stroka + i) = NULL;
	head->word = stroka;
}

void change(listing* head)
{
	char c;
	char* stroka = NULL;
	int i = 0;
	stroka = (char*)malloc(sizeof(char));
	if (stroka == NULL)
	{
		free(stroka);
		return 0;
	}
	printf("Vvedite stroku:\n");
	c = getchar();
	c = ' ';
	if (head->next != NULL)
	{
		for (i = 0; (c != '\n'); i++)
		{
			stroka = (char*)realloc(stroka, ((i + 1)) * sizeof(char));
			if (stroka == NULL)
			{
				free(stroka);
				return 0;
			}
			*(stroka + i) = getchar();
			c = *(stroka + i);
		}
	}

	if (head->next != NULL)
		head->next->word = stroka;
	else
		printf("nothing");
}

listing* takehead(listing* head)
{
	int boy = head;
	int cc = 0, i = 0;
	listing* buff = head;
	if (head == NULL)
	{
		printf("Spisok two blocks down");
		return 1;
	}
	while (*(head->word + i + 1) != NULL)
	{
		printf("%d", *(head->word + i));
		printf(" ");
		i++;
	}
	if (head->next == NULL)
	{
		head = freedom(head);
		return head;
	}
	else
	{
		listing* pv = head;
		head = head->next;
		head->prev = NULL;
		free(pv);
	}
	return head;
}

listing* takeend(listing* head)
{
	int boy = head;
	int cc = 0, i = 0;
	listing* buff = head;
	if (head == NULL)
	{
		printf("Spisok two blocks down");
		return 1;
	}
	while (*(head->word + i + 1) != NULL)
	{
		printf("%d", *(head->word + i));
		printf(" ");
		i++;
	}
	if (head->prev == NULL)
	{
		head = freedom(head);
		return head;
	}
	else
	{
		listing* pv = head;
		head = head->prev;
		head->next = NULL;
		free(pv);
	}
	return head;
}

void menu()
{
	
	int k, prov, i = 0, flag = 1, cot = 0;
	int ii = 1;
	listing* head = NULL;
	listing* end = head;
	listing* bb = head;
	listing* ba = NULL;
	listing* boy = head;
	int fl = 0, fll = 1, flll = 0, fa = 0, hf = 0;
	while (ii)
	{
		printf("1:Nachalo Raboti");
		printf("\n");
		printf("2:Pustoy");
		printf("\n");
		printf("3:Pustoi?");
		printf("\n");
		printf("4:Znach Vnachale deka");
		printf("\n");
		printf("5:Znach vkonche deka");
		printf("\n");
		printf("6:udal nach deka");
		printf("\n");
		printf("7:udal konec deka");
		printf("\n");
		printf("8:Vziat nachalo");
		printf("\n");
		printf("9:Vziat konec");
		printf("\n");
		printf("10:Izmenit nachalo deka");
		printf("\n");
		printf("11:Izmenit konec deka");
		printf("\n");
		printf("12:dobavit nachalo deka");
		printf("\n");
		printf("13:print struckture");
		printf("\n");
		printf("14:end rabotu");
		printf("\n");
		printf("15:end");
		printf("\n");
		scanf_s("%d", &i);
		switch (i)
		{
		case 1:
			system("cls");
			if (fa == 0)
			{
				printf("Nachato");
				fa = 1;
			}
			else
			{
				printf("ushe nachato");
				printf("\n");
				break;
			}
			if (flll == 1)
			{
				listing* head = NULL;
				flll = 0;
			}
			head = NULL;
			printf("\n");
			fl = 1; fll = 0;
			break;
		case 2:
			head = freedom(head);
			system("cls");
			flag = 1;
			head = NULL;
			break;
		case 3:
			cot = cots(head);
			system("cls");
			hf = lonelines(head, cot);
			printf("\n");
			if (hf == 0)
			{
				sucktion(head, flag, end);
				printf("\n");
				break;
			}
			else
			{
				break;
			}
		case 4:
			if (flag == 1)
			{
				system("cls");
				printf("no spisok");
				printf("\n");
				break;
			}
			system("cls");
			i = 0;
			while (*(head->word + i + 1) != NULL)
			{
				printf("%d", *(head->word + i));
				printf(" ");
				i++;
			}
			printf("\n");
			sucktion(head, flag, end);
			printf("\n");
			break;
		case 5:
			if (flag == 1)
			{
				system("cls");
				printf("no spisok");
				printf("\n");
				break;
			}
			system("cls");
			i = 0;
			while (*(end->word + i + 1) != NULL)
			{
				printf("%d", *(end->word + i));
				printf(" ");
				i++;
			}
			printf("\n");
			sucktion(head, flag, end);
			printf("\n");
			break;
		case 6:
			if (flag == 1)
			{
				system("cls");
				printf("no spisok");
				printf("\n");
				break;
			}
			system("cls");
			i = 0;
			head = headslave(head);
			printf("\n");
			if ((head != NULL) && (end != NULL))
			{
				sucktion(head, flag, end);
			}
			else
			{
				flag = 1;
				head = NULL;
				end = NULL;
			}
			printf("\n");
			break;
		case 7:
			if (flag == 1)
			{
				system("cls");
				printf("no spisok");
				printf("\n");
				break;
			}
			system("cls");
			i = 0;
			end = endslave(end);
			printf("\n");
			if ((head != NULL) && (end != NULL))
			{
				sucktion(head, flag, end);
			}
			else
			{
				flag = 1;
				head = NULL;
				end = NULL;
			}
			printf("\n");
			break;
		case 8:
			if (flag == 1)
			{
				system("cls");
				printf("no spisok");
				printf("\n");
				break;
			}
			system("cls");
			i = 0;
			head = takehead(head);
			printf("\n");
			if ((head != NULL) && (end != NULL))
			{
				sucktion(head, flag, end);
			}
			else
			{
				flag = 1;
				head = NULL;
				end = NULL;
			}
			printf("\n");
			break;
		case 9:
			if (flag == 1)
			{
				system("cls");
				printf("no spisok");
				printf("\n");
				break;
			}
			system("cls");
			i = 0;
			end = takeend(end);
			printf("\n");
			if ((head != NULL) && (end != NULL))
			{
				sucktion(head, flag, end);
			}
			else
			{
				flag = 1;
				head = NULL;
				end = NULL;
			}
			printf("\n");
			break;
		case 10:
			if (flag == 1)
			{
				system("cls");
				printf("no spisok");
				printf("\n");
				break;
			}
			system("cls");
			change2(head);
			printf("\n");
			sucktion(head, flag, end);
			printf("\n");
			break;
		case 11:
			if (flag == 1)
			{
				system("cls");
				printf("no spisok");
				printf("\n");
				break;
			}
			system("cls");
			change2(end);
			printf("\n");
			sucktion(head, flag, end);
			printf("\n");
			break;
		case 12:
			if (fl == 0)
			{
				system("cls");
				printf("No spisok");
				printf("\n");
				break;
			}
			if (head == NULL)
			{
				head = back_here(head);
				end = head;
				fl = 1;
				boy = head;
				listing* buff = head;
				flag = 0;
				system("cls");
				bb = head;
				sucktion(head, flag, end);
				printf("\n");
				break;
			}
			else
			{
				system("cls");
				end = pull_up2(head);
				listing* bufff = end;
				while (bufff->prev != NULL)
				{
					bufff = bufff->prev;
					head = bufff;
				}
				printf("\n");
				sucktion(head, flag, end);
				printf("\n");
			}
			break;
		case 13:
			if (flag == 1)
			{
				system("cls");
				printf("no spisok");
				printf("\n");
				break;
			}
			system("cls");
			sucktion(head, flag, end);
			printf("\n");
			break;
		case 14:
			head = freedom(head);
			system("cls");
			flag = 1;
			head = NULL;
			system("cls");
			free(head);
			fl = 0;
			fll = 1;
			flll = 1;
			fa = 0;
			printf("rabota zakonchena");
			printf("\n");
			break;
		case 15:
			if (fll != 1)
			{
				system("cls");
				printf("rabota not ended");
				printf("\n");
				break;
			}
			else
			{
				ii = 0;
				break;
			}
		default:
			system("cls");
			printf("nevernoe znachenie");
			printf("\n");

		}


	}
	head = freedom(head);
	system("cls");
	flag = 1;
	head = NULL;
}


void main()
{
	menu();
}