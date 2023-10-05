
#include <stdio.h> 
#include <locale.h> 
using namespace std;

int keyboard();
int output();
int menu();
int newLine();
int search();


struct list
{
    int x;
    char name_cat[100];
    char colour[100];//цвет
    int price;//цена
    int age;//возраст
    char gender[100];
} cat_home[100];


int main()
{
    menu();
    return(0);
}

int menu()
{
    setlocale(LC_ALL, "RUS");
    printf("\n");
    printf("1. Вводить данные с клавиатуры\n");
    printf("2. Выводить данные на экран\n");
    printf("3. Добавление одной новой строки\n");
    printf("4. Поиск по конкретной строчке\n");
    printf("5. Выход\n");
    printf("\n");
    printf("Введите то, что вас интересует\n");
    int a;
    scanf_s("%d", &a);
    switch (a)
    {
    case (1): keyboard();
        break;
    case (2): output();
        break;
    case (3): newLine();
        break;
    case (4): search();
        break;
    case (5): 
        break;
    }
    return(0);
}

int keyboard()
{
    int S;
    printf("Введите кол-во строк\n");
    int q;
    scanf_s("%d", &q);
    int x=0;

    for (int i = 1; i <= q; i++) {
        printf("Введите имя кота\n");
        scanf_s("%s", &cat_home[i].name_cat, 20);

        printf("Введите цвет кота\n");
        scanf_s("%s", &cat_home[i].colour, 20);

        printf("Введите цену коту\n");
        scanf_s("%d", &cat_home[i].price);

        printf("Введите возраст кота\n");
        scanf_s("%d", &cat_home[i].age);

        printf("Введите пол кота\n");
        scanf_s("%s", &cat_home[i].gender, 20);

        x++;
        cat_home->x = x;
    }
    printf("Введите 1, чтобы продолжить\n");
    scanf_s("%d", &S);

    if (S == 1)
    {
        menu();
    }
    return(0);
}

int output() //функция для цифры 2 
{
    int S;
    int count = 1;
    for (int i = 1; i <= cat_home->x; i++)
    {

        printf("%d.",count);
        
        printf("%s\t", cat_home[i].name_cat);
        printf("%s\t", cat_home[i].colour);
        printf("%d\t", cat_home[i].price);
        printf("%d\t", cat_home[i].age);
        printf("%s\t", cat_home[i].gender);
        printf("\n");
        count++;
    }

    printf("Введите 1, чтобы вернуться в меню!\n");
    scanf_s("%d", &S);
    if (S == 1)
    {
        menu();
    }
    return(0);
}

int newLine() //фунцкия для цифры 3 
{
    int F;

    int w;
    w = cat_home->x + 1;
    printf("Введите имя кота\n");
    scanf_s("%s", &cat_home[w].name_cat, 20);
    printf("Введите цвет кота\n");
    scanf_s("%s", &cat_home[w].colour, 20);
    printf("Введите цену коту\n");
    scanf_s("%d", &cat_home[w].price);
    printf("Введите возраст кота\n");
    scanf_s("%d", &cat_home[w].age);
    printf("Введите пол кота\n");
    scanf_s("%s", &cat_home[w].gender,20);

    int count = cat_home->x+1;
    for (int i = 1; i <= count; i++)
    {

        printf("%d", i);
        printf(".");
        printf("%s\t", cat_home[i].name_cat);
        printf("%s\t", cat_home[i].colour);
        printf("%d\t", cat_home[i].price);
        printf("%d\t", cat_home[i].age);
        printf("%s\t", cat_home[i].gender);
        printf("\n");
    }
    printf("Вернуться к выбору возможностей - 0\n");
    scanf_s("%d", &F);

    if (F == 0)
    {
        menu();
    }
    return(0);
}

int search() //функция для цифры 4 
{
    int s;
    int p;
    printf("Какая строчка вас интересует?\n");
    scanf_s("%d", &p);
    for (int i = 1; i < 30; i++)
    {
        if (p == i)
        {
            int number = 1;
            printf("%d", number);
            printf(".");
            printf("%s\t", cat_home[i].name_cat);
            printf("%s\t", cat_home[i].colour);
            printf("%d\t", cat_home[i].price);
            printf("%d\t", cat_home[i].age);
            printf("%s\t", cat_home[i].gender);
            printf("\n");
            number++;
        }
    }
    printf("Вернуться к выбору возможностей - 0\n");
    scanf_s("%d", &s);
    if (s == 0)
    {
        menu();
    }
    return(0);
}

