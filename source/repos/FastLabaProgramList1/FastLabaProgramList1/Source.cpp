#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include <locale.h>
struct list
{
    char symbol;
    struct list* next;
};

struct list* initiate(char c){
    struct list* list;
    list = (struct list*)malloc(sizeof(struct list));
    if (list == NULL)
    {
        printf_s("������ �� ��������. ���������� ���������\n");
        return(0);
    }
    list->symbol = c;
    list->next = NULL;
    return(list);
}

struct list* addelement(struct list* current, char c)
{
    struct list* temp, * p;
    temp = initiate(c);
    p = current->next;
    current->next = temp;
    temp->next = p;
    return(temp);
}

void printlist(struct list* list)
{
    while (list != NULL)
    {
        printf("%c ", list->symbol);    //�������� ������, ����������� � ������ ��������
        list = list->next;                //����������� ��������� �� ����������� �������
    }
}

struct list* deletecurrentelement(struct list* core, struct list* deleted)
{
    struct list* previous = core;
    while (previous->next != deleted)
    {
        previous = previous->next;
    }
    previous->next = deleted->next;
    free(deleted);
    return(previous);
}

void deletelist(struct list* core)
{
    struct list* tmp = core;
    struct list* aft = NULL;
    while (tmp != NULL)
    {
        aft = tmp->next;
        free(tmp);
        tmp = aft;
    }
    core = NULL;
}

struct list* point_begin(struct list* core, struct list* current)
{
    current = core;
    return(current);
}

void checking_end(struct list* core, struct list* current)
{
    if (core->symbol != NULL)
    {
        if (current->next == NULL)
        {
            printf("������� ��������� ��������� �� ����� ������!\n");
        }
        else
        {
            printf("������� ��������� ��������� �� �� ����� ������!\n");
        }
    }
    else
    {
        printf("��� ������ �������, ��� ��� ������ ����.\n");
    }
}

struct list* pointer_next(struct list* core, struct list* current)
{
    if (core->symbol != NULL)
    {
        if (current->next != NULL)
        {                    //���� ������� ��������� ����� �� � ����� ������
            current = current->next;                     //�������� ��� ������
        }
        else
        {
            printf("��� ������ �������, ��� ��� ������� ��������� ����� �� ����� ������.\n");
        }
    }
    else
    {
        printf("��� ������ �������, ��� ��� ������ ����.\n");
    }
    return (current);
}

void print_next(struct list* core, struct list* current)
{
    if (core->symbol != NULL && current->next != NULL)
    {

        printf("�������� �������� ����� �������� ��������� - %c\n", current->next->symbol); //������� �������� �������� ����� �������� ���������
        printf("%c",current->next->symbol);
    }
    else
    {
        if (core->symbol == NULL)
        {
            printf("��� ������ �������, ��� ��� ������ ����.\n");
        }
        else
        {
            printf("��� ������ �������, ��� ��� ������� ��������� ����� � ����� ������.\n"); //����� ���������� ������������ � ���, ��� ��������� � ����� ������
        }
    }
}

void cut_after(struct list* core, struct list* current)
{
    char cutted;
    if (core->symbol != NULL)
    {
        if (current->next != NULL)
        {                                                              //���� ��������� �� � ����� ������
            cutted = current->next->symbol;                                                      //��������� �������� ���������� ��������
            deletecurrentelement(core, current->next);                                                   //������� ���
            printf("������� ������, ��������� ����� �������� ���������, �����.\n");
            printf("������� ��������� ������� ������ - %c\n", cutted);
        }
        else
        {
            printf("��� ������ �������, ��� ��� ������� ��������� ��������� �� ����� ������.\n");
        }
    }
    else
    {
        printf("��� ������ �������, ��� ��� ������ ����.\n");
    }
}
void changeelem(struct list* current, char c)
{
    current->next->symbol = c;
}

int menu(struct list* core)   //������� menu ��������� �� ���� ��������� �� ������
{
    struct list* tmp = core;
    struct list* current = NULL;                    //������ ��������� �� ������ ������
    int number = 0;                                 //������� ������������
    system("cls");

    while (number != 20)
    {
        if (core->symbol == NULL)
        {
            printf("1.�������� ������ �������;\n");
        }
        printf("2.�������� ������;\n");
        printf("3.�������� ������� ������;\n");
        printf("4.���������� ��������� �� ������ ������;\n");
        printf("5.��������� ��������� �� ��������� � ����� ������;\n");
        printf("6.����������� ������� ��������� ������;\n");
        printf("7.������� �������� �������� ������ ����� �������� ���������;\n");
        printf("8.������� ������� ������ ����� �������� ���������;\n");
        printf("9.����� �������� �������� ������ ����� �������� ���������;\n");
        printf("10.�������� �������� �������� ������ ����� �������� ���������;\n");
        printf("11.�������� ������� ������ ����� �������� ���������;\n");
        printf("12.���������� ������ �� �������;\n");
        scanf_s("%d", &number);
        
        system("cls");
        if (number == 1)
        {
            current = core;    //������� ��������� ������� �� ����� ������ ������
            char c = NULL;     //������ ������
            printf("������� ������ ������� ������:\n");
            c = getchar();
            current->symbol = c;
            tmp = core;
        }
        if (number == 2)
        {
            if (core->symbol != NULL)
            {
                deletelist(core);
                core = initiate(NULL);//� ������ ����� ������ ������
                current = core;//������� ��������� ������� �� ����� ������ ������
                printf("������ ������!\n");
            }
            else {
                printf("������ ������!\n");
            }
        }
        if (number == 3)
        {
            if (core->symbol == NULL)
            {
                printf("������ ����!\n\n");
            }
            else
            {
                printf("������ �� ����!\n\n");
            }
        }
        if (number == 4)
        {
            if (core->symbol != NULL)
            {
                current = point_begin(core, current);
            }
            else
            {
                printf("������� ������� ������ ������� ������!\n");
            }
        }
        if (number == 5)
        {
            checking_end(core, current);
        }
        if (number == 6)
        {
            current = pointer_next(core, current);
        }
        if (number == 7)
        {
            print_next(core, current);
        }
        if (number == 8)
        {
            if (core->symbol != NULL && current->next != NULL)
            {
                deletecurrentelement(core, current->next);
            }
            else
            {
                if (core->symbol == NULL)
                {
                    printf("��� ������ �������, ��� ��� ������ ����.\n");
                }

                else

                    if (current->next == NULL)
                    {
                        printf("��� ������ �������, ��� ��� ������� ��������� ��������� �� ����� ������.\n");
                    }
            }
        }
        if (number == 9)
        {
            cut_after(core, current);
        }
        if (number == 10)
        {
            if (core->symbol != NULL)
            {
                if (core->symbol != NULL && current->next != NULL)
                {
                    char c;
                    printf("������� ���������� �������� �������� ����� �������� ���������:\n");
                    c = getchar();
                    c = getchar();
                    changeelem(current, c);
                }
                else
                {
                    if (core->symbol == NULL)
                    {
                        printf("��� ������ �������, ��� ��� ������ ����.\n");
                    }
                    else
                    {
                        printf("��� ������ �������, ��� ��� ������� ��������� ����� � ����� ������.\n"); //����� ���������� ������������ � ���, ��� ��������� � ����� ������
                    }
                }
            }
            else
            {
                printf("������� ������� ������ ������� ������!\n");
            }
        }
        if (number == 11)
        {
            if (core->symbol != NULL)
            {
                char c;
                printf("������� �������, ������� ����� �������� ����� �������� ���������:\n");
                c = getchar();
                c = getchar();
                addelement(current, c);
            }
            else
            {
                printf("������� ������� ������ ������� ������!\n");
            }
        }
        if (number == 12)
        {
            deletelist(core);
            return(2);
        }
        if (core->symbol != NULL)
        {
            printf("������:");
            printlist(core);
            printf("\n       ");
            while (tmp != current)
            {
                printf("  ");
                tmp = tmp->next;
            }
            printf("*");
            printf("\n");
            tmp = core;
        }
    }
}

int main(){
    setlocale(LC_ALL, "rus");
    struct list* core;
    int c = 2;
    printf("������� 1, ����� ������ ������:\n");
    while (c != 0){
        scanf_s("%d", &c);
        if (c == 1){
            core = initiate(NULL);
            c = menu(core);
            printf("������� 1, ����� ������������ ����� ������ ��� ������ ����� ��� ������ �� ���������\n");
        }
        else {
            printf("��������� ������\n");
        }
    }
}