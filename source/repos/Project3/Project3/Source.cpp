#include <stdio.h>
#include <malloc.h>
#include <windows.h>

struct list
{
    char symbol;
    struct list* next;
};

struct list* initiate(char c)
{
    struct list* list;
    list = (struct list*)malloc(sizeof(struct list));
    if (list == NULL)
    {
        printf_s("������ �� ��������. ���������� ���������...\n");
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
    int comm = 0;                                 //������� ������������
    system("cls");
    printf("��������, ��� ������ ������� ���������:\n\n");
    while (comm != 20)
    {
        if (core->symbol == NULL)
        {
            printf("(1) - �������� ������ �������;\n\n");
        }
        printf("(2) - �������� ������;\n\n");
        printf("(3) - �������� ������� ������;\n\n");
        printf("(4) - ���������� ��������� �� ������ ������;\n\n");
        printf("(5) - ��������� ��������� �� ��������� � ����� ������;\n\n");
        printf("(6) - ����������� ������� ��������� ������;\n\n");
        printf("(7) - ������� �������� �������� ������ ����� �������� ���������;\n\n");
        printf("(8) - ������� ������� ������ ����� �������� ���������;\n\n");
        printf("(9) - ����� �������� �������� ������ ����� �������� ���������;\n\n");
        printf("(10) - �������� �������� �������� ������ ����� �������� ���������;\n\n");
        printf("(11) - �������� ������� ������ ����� �������� ���������;\n\n");
        printf("(12) - ���������� ������ �� �������;\n\n");

        scanf_s("%d", &comm);
        struct list* s = core;                                      //���� ��������� ����������� ��� ���������� ����������� ��������� �� ������� �������
        system("cls");
        if (comm < 1 || comm > 12) printf("����������, ������� ���������� ����� ����:\n");
        if (comm == 1)
        {
            current = core;                                         //������� ��������� ������� �� ����� ������ ������
            char c = NULL;                                         //������ ������
            printf("������� ������ ������� ������:\n");
            c = getchar();
            current->symbol = c;
            tmp = core;
        }
        if (comm == 2)
        {
            if (core->symbol != NULL)
            {
                deletelist(core);
                core = initiate(NULL);                             //� ������ ����� ������ ������
                current = core;                              //������� ��������� ������� �� ����� ������ ������
                printf("������ ������!\n");
            }
            else
            {
                printf("������ � ��� ����!\n");
            }
        }
        if (comm == 3)
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
        if (comm == 4)
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
        if (comm == 5)
        {
            checking_end(core, current);
        }
        if (comm == 6)
        {
            current = pointer_next(core, current);
        }
        if (comm == 7)
        {
            print_next(core, current);
        }
        if (comm == 8)
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
        if (comm == 9)
        {
            cut_after(core, current);
        }
        if (comm == 10)
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
        if (comm == 11)
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
        if (comm == 12)
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
            printf("^");
            printf("\n");
            tmp = core;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    struct list* core;
    int c = 2;
    printf("�������� ����������� ������\n");
    printf("������� 1, ����� ������������ ������ ��� ������� 0, ����� ����� �� ��������:\n");
    while (c != 0)
    {
        scanf_s("%d", &c);
        if (c == 1)
        {
            core = initiate(NULL);
            c = menu(core);
            printf("������� �� ������\n");
            printf("������� 1, ����� ������������ ����� ������ ��� ������� 0, ����� ����� �� ��������:\n");
        }
        else if (c != 1 && c != 0)
        {
            system("cls");
            printf("����������, ������� ���������� ����� ����.\n");
            printf("������� 1, ����� ������������ ������ ��� ������� 0, ����� ����� �� ��������:\n");
        }
    }
    printf("�� ������ �������...\n");
}