//2.1) дана строка символов. нужно ввести её, используя функцию calloc(). Память захватывавть
// под некоторое фиксированное количество элементов (от 2 до 5). Если памяти не хватает, то
// добавить её, используя функцию realloc()
/*

#include <stdio.h>
#include <malloc.h>
#include <windows.h>
int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);//кодировка для русского языка
    int i, n = 0, j = 1;
    char* stroka = NULL;
    stroka = (char*)calloc(j, sizeof(char));//выделяем память массива для 1 элемента для типа char
    printf("Введите строку:\n");
    for (i = 0; (*(stroka + i) = getchar()) != '\n'; i++)//
    {
        stroka = (char*)realloc(stroka, (1 + (i + 1)) * sizeof(char));
    }
    if (stroka == NULL)
    {
        free(stroka);
        return(0);
    }
    while (*stroka != '\0')
    {
        if (*stroka != ' ')
        {
            while ((*stroka != ' ') && (*stroka != '\0'))
            {
                stroka++;
            }
            n++;
        }
        else
        {
            stroka++;
        }
    }
    printf_s("Количество слов в строке = %d", n);
}
*/