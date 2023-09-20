#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <malloc.h>
typedef struct dequ//объявление структуры "дек"
{
	char* mass;//массив слов
	int size;//размер 
	struct dequ* next_el;//указатель на следующий элемент
	struct dequ* pred_el;//указатель на предыдущий элемент
} dec;

int vybor();//прототип функции
char* input_per_word();//прототип функции
int ckeck_word(char* word);//прототип функции
int isSpaces(char* word);//прототип функции
int isEmpty(dec* Decq_Start);//прототип функции
void clearDec(dec** Decq_Start, dec** Decq_Ending);//прототип функции
void showLeft(dec* Decq_Start);//прототип функции
void showRight(dec* Decq_Ending);//прототип функции
void delRight(dec** Decq_Start, dec** Decq_Ending);//прототип функции
void delLeft(dec** Decq_Start, dec** Decq_Ending);//прототип функции
void Take_Left(dec** Decq_Start, dec** Decq_Ending);//прототип функции
void Take_Right(dec** Decq_Start, dec** Decq_Ending);//прототип функции
void change_Left(dec** Decq_Start, dec** Decq_Ending);//прототип функции
void change_Right(dec** Decq_Start, dec** Decq_Ending);//прототип функции
void addLeft(dec** Decq_Start, dec** Decq_Ending);//прототип функции
void addRight(dec** Decq_Start, dec** Decq_Ending);//прототип функции
void printDec(dec* Decq_Start);//прототип функции
void glavnoeMenu(dec** Decq_Start, dec** Decq_Ending);//прототип функции
void zakonchitRaboty(dec** Decq_Start, dec** Decq_Ending);//прототип функции
void menuDeca(dec** Decq_Start, dec** Decq_Ending);//прототип функции
int dec_Size_elem = 0;//текущее количество слов
int limit_on_input = 5;//лимит слов

int main()
{
	setlocale(LC_ALL, "ru");
	dec* Decq_Start = NULL;//указатель на первый элемент дека обнулен
	dec* Decq_Ending = NULL;//указатель на последний элемент  дека обнулен
	glavnoeMenu(&Decq_Start, &Decq_Ending);
	return 0;
}

void glavnoeMenu(dec** Decq_Start, dec** Decq_Ending)//функция, запускающая побочное(первое) меню
{
	int v;
	while (1)//бесконечный цикл
	{
		printf("1. Начать работу\n");
		printf("2. Закончить\n");
		v = vybor();//функция, запоминающая выбор пользователя
		switch (v)
		{
		case 1:
			menuDeca(Decq_Start, Decq_Ending);//функция, запускающая основное меню
			break;
		case 2:
			printf("Работа окончена\n");
			exit(0);//выход из программы
			break;
		default:
			printf("Нет такого пункта\n");
			break;
		}
	}
}
void menuDeca(dec** Decq_Start, dec** Decq_Ending)//функция основного меню
{
	int v = 0;
	while (1)
	{
		printf("Вывод: \n");
		if (*Decq_Start != NULL)//если первый элемент дека не нуль
			printDec(*Decq_Start);//функция вывода дека
		printf("\n1. Сделать дек пустым\n");
		printf("2. Проверка пустоты дека\n");
		printf("3. Показать начало дека\n");
		printf("4. Показать конец дека\n");
		printf("5. Удалить начало дека\n");
		printf("6. Удалить конец дека\n");
		printf("7. Взять в начале\n");
		printf("8. Взять в конце\n");
		printf("9. Поменять в начале\n");
		printf("10. Поменять в конце\n");
		printf("11. Добавить в начало дека\n");
		printf("12. Добавить в конец дека\n");
		printf("13. Распечатать структуру дека\n");
		printf("14. закончить работу\n");
		v = vybor();
		switch (v)
		{
		case 1:
			clearDec(Decq_Start, Decq_Ending);//функция очистки дека
			break;

		case 2:
			if (!isEmpty(*Decq_Start))//функция проверки дека на пустоту
				printf("Пуст!\n");
			else
				printf("Не пуст!\n");
			break;

		case 3:
			showLeft(*Decq_Start);//функция вывода первого элемента
			break;

		case 4:
			showRight(*Decq_Ending);//функция вывода последнего элемента
			break;

		case 5:
			delLeft(Decq_Start, Decq_Ending);//функция удаления первого элемента
			break;

		case 6:
			delRight(Decq_Start, Decq_Ending);//функция удаления последнего элемента
			break;

		case 7:
			Take_Left(Decq_Start, Decq_Ending);//функция взятия начального элемента
			break;
		case 8:
			Take_Right(Decq_Start, Decq_Ending);//функция взятия последнего элемента
			break;
		case 9:
			change_Left(Decq_Start, Decq_Ending);//функция, изменяющая первый элемент
			break;

		case 10:
			change_Right(Decq_Start, Decq_Ending);////функция, изменяющая первый элемент
			break;

		case 11:
			addLeft(Decq_Start, Decq_Ending);//функция, добавляющая элемент в начало дека
			break;

		case 12:
			addRight(Decq_Start, Decq_Ending);//функция, добавляющая элемент в конец дека
			break;

		case 13:
			printDec(*Decq_Start);//вывод дека
			break;

		case 14:
			zakonchitRaboty(Decq_Start, Decq_Ending);//конец программы
			break;

		default:
			printf("Такой пункт в меню отсутствует\n");
			break;
		}
	}
}
void printDec(dec* Decq_Start)//вывод дека
{
	if (Decq_Start == NULL)//если первый элемент равен нулю, то дек пуст
	{
		printf("Дек пуст!\n");
		return;
	}

	dec* wek = Decq_Start;//в переменную wek помещается первый элемент
	printf("_");
	while (wek != NULL)//пока wek не равен нулю
	{

		printf("%s", wek->mass);//вывод элемета

		if (wek->next_el != NULL)//если следующий элемент не нуль
		{
			printf("_");
		}
		wek = wek->next_el;//wek равен следующему элементу 
	}
	printf("_\n");
}
int vybor()
{
	printf("Сделайте ввод: ");

	char str[100];
	scanf_s("%s", str, 100);

	int length = strlen(str);//определяется длинна строки 
	if (length > 2)//если динна больше 2
		return 0;//вернуть 0

	for (int i = 0; i < length; i++)// пока счетчик i не будет равен lenght. После каждого прохода for, i увеличивается на 1
	{
		if (isdigit(str[i]) == 0)//isdigit возвращает 0 если буква
			return 0;//вернуть 0
	}

	return atoi(str);//atoi конвертирует строку в int
}
void clearDec(dec** Decq_Start, dec** Decq_Ending)
{
	if (*Decq_Start == NULL)//проверка, пустой ли дек, если первый элемент равен нулю, то пуст
	{
		printf("Дек пуст!\n");
		return;
	}

	while (*Decq_Start != NULL)//пока первый элемент не равен нулю
		delLeft(Decq_Start, Decq_Ending);//функция delLeft удаляет первый элемент

}
char* input_per_word()//ввод слова
{
	char* word = (char*)malloc(1024);//динамическое выделение памяти под слово
	if (word == NULL)//проверка, есть ли память под слово, если нет, то выходим
	{
		printf("%s", "Нет памяти\n");
		exit(1);//завершение программы с ошибкой
	}
	getc(stdin);//
	do
	{
		printf("%s", "Введите: ");//ввод слова
		scanf_s("%s", word, 1024);
	} while (isSpaces(word) || !ckeck_word(word));//проверка, есть ли пробелы или числа в слове
	if (word == NULL)//проверка, есть ли память под слово, если нет, то выходим
	{
		printf("%s", "Нет памяти\n");
		exit(1);
	}
	return word;
}

int isEmpty(dec* Decq_Start)//проверка, пуст ли дек
{
	if (Decq_Start == NULL)//если первый элемент пуст
		return 0;
	return 1;
}
void addLeft(dec** Decq_Start, dec** Decq_Ending)//добавление слова в начало 
{
	if (dec_Size_elem == limit_on_input)//проверка, превышен ли размер дека
	{
		printf("Превышен размер Дека!\n");
		return;
	}

	dec* tmp = (dec*)malloc(sizeof(dec));//динамическое выделение памяти для временной переменной tmp
	if (tmp == NULL)//проверка, выделилась ли память
	{
		printf("Нет памяти!\n");
		exit(1);
	}
	tmp->mass = NULL;//обнуление переменной mass
	tmp->mass = input_per_word();//в масс заполняется результат функции input_per_word
	if (tmp->mass == NULL)//проверка, правильно ли введено слово
	{
		printf("Неверный ввод\n");
		free(tmp);//освобождение памяти под переменную tmp
		return;
	}

	dec_Size_elem++;//увеличение счетчика количества слов в деке
	if (*Decq_Start == NULL)//если указатель на первый элемент дека равен нулю
	{
		tmp->next_el = NULL;//следующий элемент равен нулю
		tmp->pred_el = NULL;//предыдущий элемент равен нулю
		(*Decq_Ending) = tmp;//последний элемент равен tmp
	}
	else
	{
		(*Decq_Start)->pred_el = tmp;//предыдущему элементу начала присваивается tmp 
		tmp->next_el = *Decq_Start;//значение следующего элемента равно начальному
		tmp->pred_el = NULL;//предыдущий элемент равен нулю
	}
	(*Decq_Start) = tmp;//начальный элемент равен tmp
}
void addRight(dec** Decq_Start, dec** Decq_Ending)//добавление слова в конец 
{
	if (dec_Size_elem == limit_on_input)//проверка, превышен ли размер дека
	{
		printf("Превышен размер Дека!\n");
		return;
	}
	dec* tmp = (dec*)malloc(sizeof(dec));//динамическое выделение памяти
	if (tmp == NULL)
	{
		printf("Нет памяти!\n");
		exit(1);
	}
	tmp->mass = NULL;
	tmp->mass = input_per_word();
	if (tmp->mass == NULL)
	{
		printf("Неверный ввод\n");
		free(tmp);
		return;
	}

	dec_Size_elem++;
	if (*Decq_Start == NULL)//если указатель на первый элемент равен нулю
	{
		tmp->next_el = NULL;//следующий элемент равен нулю
		tmp->pred_el = NULL;//предыдущий элемент равен нулю
		(*Decq_Start) = tmp;//начальное значение равно tmp

	}
	else
	{
		(*Decq_Ending)->next_el = tmp;//следующий после конца элемент равен tmp
		tmp->pred_el = (*Decq_Ending);//значение предыдущего элемента равно конечному
		tmp->next_el = NULL;//следующий элемент равен нулю
	}

	(*Decq_Ending) = tmp;//конечное значение равно tmp
}
void Take_Left(dec** Decq_Start, dec** Decq_Ending)//взять первый элемент
{
	if (*Decq_Start == NULL)//проверка, пуст ли дек
	{
		printf("Дек пуст!\n");
		return;
	}

	showLeft(*Decq_Start);//вывести первый элемет
	delLeft(Decq_Start, Decq_Ending);//удалить первый элемет
}
void Take_Right(dec** Decq_Start, dec** Decq_Ending)//взять последний элемент
{
	if (*Decq_Start == NULL)//проверка, пуст ли дек
	{
		printf("Дек пуст!\n");
		return;
	}

	showRight(*Decq_Start);//вывести последний элемент
	delRight(Decq_Start, Decq_Ending);//удалить последний элемент 
}
void showLeft(dec* Decq_Start)//вывод первого элемета 
{
	if (Decq_Start == NULL)//проверка, пуст ли дек
	{
		printf("Дек пуст!\n");
		return;
	}

	printf("%s", Decq_Start->mass);//вывод первого элемента из mass

	printf("\n");//переход на следующую строку в окне вывода
}
void showRight(dec* Decq_Ending)//вывод последнего элемента
{
	if (Decq_Ending == NULL)//проверка, пуст ли дек
	{
		printf("Дек пуст!\n");
		return;
	}

	printf("%s", Decq_Ending->mass);//вывод последнего элемента из mass

	printf("\n");//переход на следующую строку в окне вывода
}
void change_Left(dec** Decq_Start, dec** Decq_Ending)//изменить первый элемет 
{
	if (*Decq_Start == NULL)//проверка, пуст ли дек
	{
		printf("Дек пуст!\n");
		return;
	}
	else//если дек нем пуст
	{
		(*Decq_Start)->mass = input_per_word();//в первый элемент mass попадает результат функции input_per_word
	}

}
int ckeck_word(char* word)//проверка вводимого слова
{
	int length = strlen(word);//в переменную lenght лежит значение кол-ва символов в слове 
	for (int i = 0; i < length; i++)//пока счетчик i не будет равен lenght
	{
		if (('a' <= word[i] && word[i] <= 'z') || ('A' <= word[i] && word[i] <= 'Z'))//если в слове присутствуют буквы
			continue;//продолжить 
		else
			return 0;//вернуть 0

	}
	return 1;//вернуть 1
}
void change_Right(dec** Decq_Start, dec** Decq_Ending)//изменить последний элемент
{
	if (*Decq_Ending == NULL)//проверка, пуст ли дек
	{
		printf("Дек пуст!\n");
		return;
	}
	else//если не пуст то
	{
		(*Decq_Ending)->mass = input_per_word();//в последний элемент mass попадает результат функции input_per_word
	}

}
int isSpaces(char* word)
{
	int length = strlen(word);
	for (int i = 0; i < length; i++)
	{
		if (word[i] == '\0' || word[i] == '\n')//если в слове найдено нулевой символ или новая строка
			break;//завершение оператора if
		if (word[i] == ' ')//если найден пробел
			return 1;
	}
	return 0;
}
void delRight(dec** Decq_Start, dec** Decq_Ending)//удалить справа
{
	if (*Decq_Ending == NULL)//проверка, пуст ли дек
	{
		printf("Дек пуст!\n");
		return;
	}

	dec* wek = *Decq_Ending;//в wek лежит указатель на последний элемент 
	if ((*Decq_Ending)->pred_el == NULL)//если предыдущий от конца элемент дека равен нулю
	{
		(*Decq_Ending) = (*Decq_Start) = NULL;//начальный и конечный элементы дека равны нулю
	}
	else
	{
		(*Decq_Ending) = (*Decq_Ending)->pred_el;//в указатель поледнего элемента попадает предыдущий элемент
		(*Decq_Ending)->next_el = NULL;//следующее от нового последнего элемента дека значение удаляется
	}

	free(wek->mass);//освобождение памяти 
	free(wek);
	dec_Size_elem--;//кол-во элементов уменьшенно на 1
}
void delLeft(dec** Decq_Start, dec** Decq_Ending)//удалить первое слово
{
	if (*Decq_Start == NULL)//проверка, пуст ли дек
	{
		printf("Дек пуст!\n");
		return;
	}

	dec* wek = *Decq_Start;
	if ((*Decq_Start)->next_el == NULL)//первый элемент равен нулю?
	{
		(*Decq_Start) = NULL;
		(*Decq_Ending) = NULL;
	}
	else
	{
		(*Decq_Start) = (*Decq_Start)->next_el;//следующий после начального элемент становится начальный
		(*Decq_Start)->pred_el = NULL;//старый первый элементь удаляется
	}
	free(wek->mass);
	free(wek);
	dec_Size_elem--;
}
void zakonchitRaboty(dec** Decq_Start, dec** Decq_Ending)//окончание работы 
{
	clearDec(Decq_Start, Decq_Ending);//очистка дека
	printf("Работа окончена\n");
	exit(0);//выход из программы
};
