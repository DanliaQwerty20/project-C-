#include <conio.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
//Туристы: имя, страна, возвраст, номер телефона

struct tablichka
{
    char name[20];
    char country[20];
    int age;
    char number[20];
} x[10];

int  i, f, k;
FILE* file;
char b[200];



int get_1(const char* msg)
{
    char b[200];
    int y;

    fgets(b, sizeof(b), stdin);

    while (sscanf_s(b, "%d", &y) != 1)
    {

        fgets(b, sizeof(b), stdin);
        if (sscanf_s(b, "%d", &y) != 1)
            printf("Incorrect, Try again : ");

    }
    return y;
}

void add()
{
    int  i, f, k;
    char b[200];
    system("cls");

    for (i = 1; i <= 10; i++)
    {
        if (x[i].age == 0)
        {

            printf("Enter which country the tourist from \n");
            scanf_s("%s", x[i].country, 20);
            printf("%s\n", x[i].country);

            printf("Enter tourist name \n");
            scanf_s("%s", x[i].name, 20);
            printf("%s\n", x[i].name);

            printf("Enter tourist age \n");
            x[i].age = get_1(b);
            printf("%d\n", x[i].age);

            printf("Enter tourist phone number \n");
            scanf_s("%s", x[i].number, 20);
            printf("%s\n", x[i].number);

            printf("If you want to add another line, press 1, if not - 0\n");
            scanf_s("%d", &f);
            if (f == 0)
            {
                return;
            }
        }
    };

}

void vvod_1()
{
    int  i, f, k;
    char b[200];
    k = 1;
    system("cls");
    for (i = 1; i <= 1; i++)
    {

        printf("Enter which country the tourist from \n");
        scanf_s("%s", x[k].country, 20);
        printf("%s\n", x[k].country);

        printf("Enter tourist name \n");
        scanf_s("%s", x[k].name, 20);
        printf("%s\n", x[k].name);

        printf("Enter tourist age \n");
        x[k].age = get_1(b);
        printf("%d\n", x[k].age);

        printf("Enter tourist phone number \n");
        scanf_s("%s", x[k].number, 20);
        printf("%s\n", x[k].number);

        printf("If you want to add another line, press 1, if not - 0\n");
        scanf_s("%d", &f);
        if (f == 1 and k <= 10)
        {
            i--;
            k++;
        }

    }
}

void vvod_2()
{
    int i = 1;
    fopen_s(&file, "text221.txt", "rt+");

    if (file != NULL)
    {
        while (!feof(file))
        {
            fscanf_s(file, "%s", x[i].name, 20);
            fscanf_s(file, "%s", x[i].country, 20);
            fscanf_s(file, "%d", &x[i].age);
            fscanf_s(file, "%s", x[i].number, 20);
            i++;
        }
    }
    else
        printf("File opening error");

    fclose(file);
    return;
}

void vvod()
{
    int _vvod;
    printf("Enter data from the console - 1, from the file - 2\n");
    _vvod = get_1(b);
    switch (_vvod)
    {
    case 1:
        vvod_1();
        break;
    case 2:
        vvod_2();
        break;
    default:
        printf("You have selected the wrong menu item\nTry again : ");
        vvod();
        break;

    }

}

void vivod_1()
{
    int i, q;
    system("cls");
    for (q = 1; q <= 10; q++)
    {
        if (x[q].age != 0)
        {
            printf("%d ", q);
            printf("%s ", x[q].name);
            printf("%s ", x[q].country);
            printf("%d ", x[q].age);
            printf("%s \n", x[q].number);
            printf("\n");
        }
        else
            q = 11;
    }

}

void vivod_2()
{
    int q;
    fopen_s(&file, "text221.txt", "wt+");

    if (file != NULL)
    {
        for (q = 1; q <= 10; q++)
        {
            if (x[q].age != 0)
            {
                fprintf(file, "%s", x[q].name);
                fprintf(file, "%s", x[q].country);
                fprintf(file, "%d", x[q].age);
                fprintf(file, "%s", x[q].number);
            }
            else
                q = 11;
        }
    }

    fclose(file);
    return;
}

void vivod()
{
    int _vivod;
    printf("Choose where to output the table, to the console - 1, to the file - 2\n");
    _vivod = get_1(b);
    switch (_vivod)
    {
    case 1:
        vivod_1();
        break;
    case 2:
        vivod_2();
        break;
    default:
        printf("You have selected the wrong menu item\nTry again : ");
        vivod();
        break;
    }
}

void poisk()
{
    int n, m;
    char b[20];
    system("cls");
    printf("Select a column to search: ");
    scanf_s("%d", &n);
    switch (n)
    {
    case 1:
        printf("Enter the name you want to search: ");
        scanf_s("%s", b, 20);
        for (i = 1; i <= 10; i++)
        {
            if (strcmp(x[i].name, b) == 0)
            {
                printf("%d ", i);
                printf("%s ", x[i].name);
                printf("%s ", x[i].country);
                printf("%d ", x[i].age);
                printf("%s \n", x[i].number);
                printf("\n");
            }
        };
        break;
    case 2:
        printf("Enter the country you want to search: ");
        scanf_s("%s", b, 20);
        for (i = 1; i <= 10; i++)
        {
            if (strcmp(x[i].country, b) == 0)
            {
                printf("%d ", i);
                printf("%s ", x[i].name);
                printf("%s ", x[i].country);
                printf("%d ", x[i].age);
                printf("%s \n", x[i].number);
                printf("\n");
            }
        };

        break;
    case 4:
        printf("Enter the age you want to search: ");
        scanf_s("%s", b, 20);
        for (i = 1; i <= 10; i++)
        {
            if (strcmp(x[i].country, b) == 0)
            {
                printf("%d ", i);
                printf("%s ", x[i].name);
                printf("%s ", x[i].country);
                printf("%d ", x[i].age);
                printf("%s \n", x[i].number);
                printf("\n");
            }
        };
        break;
    case 3:
        printf("Enter the number you want to search: ");
        m = get_1(b);
        for (i = 1; i <= 10; i++)
        {
            if (x[i].age == m)
            {
                printf("%d ", i);
                printf("%s ", x[i].name);
                printf("%s ", x[i].country);
                printf("%d ", x[i].age);
                printf("%s \n", x[i].number);
                printf("\n");
            }
        };
        break;
    default:
        printf("You have selected the wrong menu item\n" "Try again :\n");
        n = get_1(b);
        while (n != 1)
        {
            printf("You have selected the wrong menu item\n" "Try again :\n");
            n = get_1(b);
        }
        if (n == 1)
            poisk();
        break;

    }

}

void udoli()
{
    int n, m;
    char b[20];
    system("cls");

    printf("Select the column you want to delete : ");
    scanf_s("%d", &n);
    switch (n)
    {
    case 1:
        printf("Enter a name to delete : ");
        scanf_s("%s", b, 20);
        for (i = 1; i <= 10; i++)
        {
            if (strcmp(x[i].name, b) == 0)
            {
                memset(x[i].name, 0, sizeof(x[i].name));
                memset(x[i].country, 0, sizeof(x[i].country));
                x[i].age = 0;
                memset(x[i].number, 0, sizeof(x[i].number));
            }
        };
        break;
    case 2:
        printf("Enter a country to delete : ");
        scanf_s("%s", b, 20);
        for (i = 1; i <= 10; i++)
        {
            if (strcmp(x[i].country, b) == 0)
            {
                memset(x[i].name, 0, sizeof(x[i].name));
                memset(x[i].country, 0, sizeof(x[i].country));
                x[i].age = 0;
                memset(x[i].number, 0, sizeof(x[i].number));
            }
        };

        break;
    case 3:
        printf("Enter an age to delete : ");
        m = get_1(b);
        for (i = 1; i <= 10; i++)
        {
            if (x[i].age == m)
            {
                memset(x[i].name, 0, sizeof(x[i].name));
                memset(x[i].country, 0, sizeof(x[i].country));
                x[i].age = 0;
                memset(x[i].number, 0, sizeof(x[i].number));
            }
        };

        break;
    case 4:
        printf("Enter a number to delete : ");
        scanf_s("%s", b, 20);
        for (i = 1; i <= 10; i++)
        {
            if (strcmp(x[i].number, b) == 0)
            {
                memset(x[i].name, 0, sizeof(x[i].name));
                memset(x[i].country, 0, sizeof(x[i].country));
                x[i].age = 0;
                memset(x[i].number, 0, sizeof(x[i].number));
            }
        };

        break;
    }
}

void sort()
{
    int n, m;
    char b[20];
    system("cls");

    printf("Select the column you want to delete : ");
    scanf_s("%d", &n);
    switch (n)
    {
    case 1:
        printf("Enter the name you want to search : ");
        scanf_s("%s", b, 20);
        for (i = 1; i <= 10; i++)
        {
            if (strcmp(x[i].name, b) == 0)
            {
                printf("%d ", i);
                printf("%s ", x[i].name);
                printf("%s ", x[i].country);
                printf("%d ", x[i].age);
                printf("%s \n", x[i].number);
                printf("\n");
            }
        };
        for (i = 1; i <= 10; i++)
        {
            if (strcmp(x[i].name, b) != 0)
            {
                printf("%d ", i);
                printf("%s ", x[i].name);
                printf("%s ", x[i].country);
                printf("%d ", x[i].age);
                printf("%s \n", x[i].number);
                printf("\n");
            }
        };
        break;
    case 2:
        printf("Enter the country you want to search : ");
        scanf_s("%s", b, 20);
        for (i = 1; i <= 10; i++)
        {
            if (strcmp(x[i].country, b) == 0)
            {
                printf("%d ", i);
                printf("%s ", x[i].name);
                printf("%s ", x[i].country);
                printf("%d ", x[i].age);
                printf("%s \n", x[i].number);
                printf("\n");
            }
        };
        for (i = 1; i <= 10; i++)
        {
            if (strcmp(x[i].country, b) != 0)
            {
                printf("%d ", i);
                printf("%s ", x[i].name);
                printf("%s ", x[i].country);
                printf("%d ", x[i].age);
                printf("%s \n", x[i].number);
                printf("\n");
            }
        };
        break;
    case 3:
        printf("Enter the number you want to search: ");
        m = get_1(b);
        for (i = 1; i <= 10; i++)
        {
            if (x[i].age == m)
            {
                printf("%d ", i);
                printf("%s ", x[i].name);
                printf("%s ", x[i].country);
                printf("%d ", x[i].age);
                printf("%s \n", x[i].number);
                printf("\n");
            }
        };
        for (i = 1; i <= 10; i++)
        {
            if (x[i].age != m)
            {
                printf("%d ", i);
                printf("%s ", x[i].name);
                printf("%s ", x[i].country);
                printf("%d ", x[i].age);
                printf("%s \n", x[i].number);
                printf("\n");
            }
        };
        break;
    case 4:
        printf("Enter the number you want to search : ");
        scanf_s("%s", b, 20);
        for (i = 1; i <= 10; i++)
        {
            if (strcmp(x[i].number, b) == 0)
            {
                printf("%d ", i);
                printf("%s ", x[i].name);
                printf("%s ", x[i].country);
                printf("%d ", x[i].age);
                printf("%s \n", x[i].number);
                printf("\n");
            }
        };
        for (i = 1; i <= 10; i++)
        {
            if (strcmp(x[i].number, b) != 0)
            {
                printf("%d ", i);
                printf("%s ", x[i].name);
                printf("%s ", x[i].country);
                printf("%d ", x[i].age);
                printf("%s \n", x[i].number);
                printf("\n");
            }
        };
        break;


    }
}

void print_menu()
{
    system("cls");
    printf("What do you want to do?\n");
    printf("1. Add table\n");
    printf("2. Output table on display\n");
    printf("3. Add new line\n");
    printf("4. Search by column\n");
    printf("5. Delete \n");
    printf("6. Sort by column\n");
    printf("7. Exit\n");
}

int main()
{
    int variant, i, n;
    char b[200];

    print_menu();

    scanf_s("%d", &variant);

    switch (variant)
    {
    case 1:
        vvod();
        printf("Press 1 to exit the menu \n");
        scanf_s("%d", &n);
        if (n == 1)
            main();
        break;
    case 2:
        vivod();
        printf("Press 1 to exit the menu \n");
        scanf_s("%d", &n);
        if (n == 1)
            main();

        break;
    case 3:
        add();
        printf("Press 1 to exit the menu \n");
        scanf_s("%d", &n);
        if (n == 1)
            main();

        break;
    case 4:
        poisk();
        printf("Press 1 to exit the menu \n");
        scanf_s("%d", &n);
        if (n == 1)
            main();

        break;
    case 5:
        udoli();
        printf("Press 1 to exit the menu \n");
        scanf_s("%d", &n);
        if (n == 1)
            main();

        break;
    case 6:
        break;
    case 7:
        return 0;
    default:
        printf("You have selected the wrong menu item\nPress 1 to exit the menu\n");
        n = get_1(b);
        while (n != 1)
        {
            printf("You have selected the wrong menu item\nPress 1 to exit the menu  \n");
            n = get_1(b);
        }
        if (n == 1)
            main();
        else
            return(0);
        break;
    }
}