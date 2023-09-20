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
        printf_s("Память не выделена. Завершение программы...\n");
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
        printf("%c ", list->symbol);    //выводить символ, находящийся в каждом элементе
        list = list->next;                //передвигаем указатель на последующий элемент
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
            printf("Рабочий указатель указывает на конец списка!\n");
        }
        else
        {
            printf("Рабочий указатель указывает НЕ на конец списка!\n");
        }
    }
    else
    {
        printf("Это нельзя сделать, так как список пуст.\n");
    }
}

struct list* pointer_next(struct list* core, struct list* current)
{
    if (core->symbol != NULL)
    {
        if (current->next != NULL)
        {                    //если текущий указатель стоит не в конце списка
            current = current->next;                     //сдвигаем его вправо
        }
        else
        {
            printf("Это нельзя сделать, так как рабочий указатель стоит на конце списка.\n");
        }
    }
    else
    {
        printf("Это нельзя сделать, так как список пуст.\n");
    }
    return (current);
}

void print_next(struct list* core, struct list* current)
{
    if (core->symbol != NULL && current->next != NULL)
    {
        printf("Значение элемента после рабочего указателя - %c\n", current->next->symbol); //выводим значение элемента после рабочего указателя
    }
    else
    {
        if (core->symbol == NULL)
        {
            printf("Это нельзя сделать, так как список пуст.\n");
        }
        else
        {
            printf("Это нельзя сделать, так как рабочий указатель стоит в конце списка.\n"); //иначе уведомляем пользователя о том, что указатель в конце списка
        }
    }
}

void cut_after(struct list* core, struct list* current)
{
    char cutted;
    if (core->symbol != NULL)
    {
        if (current->next != NULL)
        {                                                              //если указатель не в конце списка
            cutted = current->next->symbol;                                                      //сохраняем значение следующего элемента
            deletecurrentelement(core, current->next);                                                   //удаляем его
            printf("Элемент списка, следующий после рабочего указателя, удалён.\n");
            printf("Вырезан следующий элемент списка - %c\n", cutted);
        }
        else
        {
            printf("Это нельзя сделать, так как рабочий указатель находится на конце списка.\n");
        }
    }
    else
    {
        printf("Это нельзя сделать, так как список пуст.\n");
    }
}
void changeelem(struct list* current, char c)
{
    current->next->symbol = c;
}

int menu(struct list* core)   //функция menu принимает на вход указатель на список
{
    struct list* tmp = core;
    struct list* current = NULL;                    //создам указатель на начало списка
    int comm = 0;                                 //команда пользователя
    system("cls");
    printf("Выберите, что должна сделать программа:\n\n");
    while (comm != 20)
    {
        if (core->symbol == NULL)
        {
            printf("(1) - Добавить первый элемент;\n\n");
        }
        printf("(2) - Очистить список;\n\n");
        printf("(3) - Проверка пустоты списка;\n\n");
        printf("(4) - Установить указатель на начало списка;\n\n");
        printf("(5) - Проверить находится ли указатель в конце списка;\n\n");
        printf("(6) - Переместить рабочий указатель вправо;\n\n");
        printf("(7) - Вывести значение элемента списка после рабочего указателя;\n\n");
        printf("(8) - Удалить элемент списка после рабочего указателя;\n\n");
        printf("(9) - Взять значение элемента списка после рабочего указателя;\n\n");
        printf("(10) - Изменить значение элемента списка после рабочего указателя;\n\n");
        printf("(11) - Добавить элемент списка после рабочего указателя;\n\n");
        printf("(12) - Завершение работы со списком;\n\n");

        scanf_s("%d", &comm);
        struct list* s = core;                                      //этот указатель понадобится при визуальном отображении указателя на текущий элемент
        system("cls");
        if (comm < 1 || comm > 12) printf("Пожалуйста, введите корректный пункт меню:\n");
        if (comm == 1)
        {
            current = core;                                         //текущий указатель смотрит на новое начало списка
            char c = NULL;                                         //создаём символ
            printf("Введите первый элемент списка:\n");
            c = getchar();
            current->symbol = c;
            tmp = core;
        }
        if (comm == 2)
        {
            if (core->symbol != NULL)
            {
                deletelist(core);
                core = initiate(NULL);                             //и создаём новый пустой список
                current = core;                              //текущий указатель смотрит на новое начало списка
                printf("Список очищен!\n");
            }
            else
            {
                printf("Список и так пуст!\n");
            }
        }
        if (comm == 3)
        {
            if (core->symbol == NULL)
            {
                printf("Список пуст!\n\n");
            }
            else
            {
                printf("Список не пуст!\n\n");
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
                printf("Сначала введите первый элемент списка!\n");
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
                    printf("Это нельзя сделать, так как список пуст.\n");
                }

                else

                    if (current->next == NULL)
                    {
                        printf("Это нельзя сделать, так как рабочий указатель находится на конце списка.\n");
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
                    printf("Введите измененное значение элемента ПОСЛЕ рабочего указателя:\n");
                    c = getchar();
                    c = getchar();
                    changeelem(current, c);
                }
                else
                {
                    if (core->symbol == NULL)
                    {
                        printf("Это нельзя сделать, так как список пуст.\n");
                    }
                    else
                    {
                        printf("Это нельзя сделать, так как рабочий указатель стоит в конце списка.\n"); //иначе уведомляем пользователя о том, что указатель в конце списка
                    }
                }
            }
            else
            {
                printf("Сначала введите первый элемент списка!\n");
            }
        }
        if (comm == 11)
        {
            if (core->symbol != NULL)
            {
                char c;
                printf("Введите элемент, который нужно добавить ПОСЛЕ рабочего указателя:\n");
                c = getchar();
                c = getchar();
                addelement(current, c);
            }
            else
            {
                printf("Сначала введите первый элемент списка!\n");
            }
        }
        if (comm == 12)
        {
            deletelist(core);
            return(2);
        }
        if (core->symbol != NULL)
        {
            printf("Список:");
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
    printf("Проведем организацию списка\n");
    printf("Введите 1, чтобы организовать список или введите 0, чтобы выйти из програмы:\n");
    while (c != 0)
    {
        scanf_s("%d", &c);
        if (c == 1)
        {
            core = initiate(NULL);
            c = menu(core);
            printf("Спасибо за работу\n");
            printf("Введите 1, чтобы организовать новый список или введите 0, чтобы выйти из програмы:\n");
        }
        else if (c != 1 && c != 0)
        {
            system("cls");
            printf("Пожалуйста, введите корректный пункт меню.\n");
            printf("Введите 1, чтобы организовать список или введите 0, чтобы выйти из програмы:\n");
        }
    }
    printf("До скорой встречи...\n");
}