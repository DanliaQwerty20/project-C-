
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
    char colour[100];//����
    int price;//����
    int age;//�������
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
    printf("1. ������� ������ � ����������\n");
    printf("2. �������� ������ �� �����\n");
    printf("3. ���������� ����� ����� ������\n");
    printf("4. ����� �� ���������� �������\n");
    printf("5. �����\n");
    printf("\n");
    printf("������� ��, ��� ��� ����������\n");
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
    printf("������� ���-�� �����\n");
    int q;
    scanf_s("%d", &q);
    int x=0;

    for (int i = 1; i <= q; i++) {
        printf("������� ��� ����\n");
        scanf_s("%s", &cat_home[i].name_cat, 20);

        printf("������� ���� ����\n");
        scanf_s("%s", &cat_home[i].colour, 20);

        printf("������� ���� ����\n");
        scanf_s("%d", &cat_home[i].price);

        printf("������� ������� ����\n");
        scanf_s("%d", &cat_home[i].age);

        printf("������� ��� ����\n");
        scanf_s("%s", &cat_home[i].gender, 20);

        x++;
        cat_home->x = x;
    }
    printf("������� 1, ����� ����������\n");
    scanf_s("%d", &S);

    if (S == 1)
    {
        menu();
    }
    return(0);
}

int output() //������� ��� ����� 2 
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

    printf("������� 1, ����� ��������� � ����!\n");
    scanf_s("%d", &S);
    if (S == 1)
    {
        menu();
    }
    return(0);
}

int newLine() //������� ��� ����� 3 
{
    int F;

    int w;
    w = cat_home->x + 1;
    printf("������� ��� ����\n");
    scanf_s("%s", &cat_home[w].name_cat, 20);
    printf("������� ���� ����\n");
    scanf_s("%s", &cat_home[w].colour, 20);
    printf("������� ���� ����\n");
    scanf_s("%d", &cat_home[w].price);
    printf("������� ������� ����\n");
    scanf_s("%d", &cat_home[w].age);
    printf("������� ��� ����\n");
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
    printf("��������� � ������ ������������ - 0\n");
    scanf_s("%d", &F);

    if (F == 0)
    {
        menu();
    }
    return(0);
}

int search() //������� ��� ����� 4 
{
    int s;
    int p;
    printf("����� ������� ��� ����������?\n");
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
    printf("��������� � ������ ������������ - 0\n");
    scanf_s("%d", &s);
    if (s == 0)
    {
        menu();
    }
    return(0);
}

