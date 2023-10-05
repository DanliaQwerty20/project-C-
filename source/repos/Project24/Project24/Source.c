#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>

//Определение конца блока
short End_Range(FILE* f) {
	int tmp;
	tmp = fgetc(f);
	tmp = fgetc(f);
	//Возвращаемся на 2 позиции назад
	if (tmp != '\'') fseek(f, -2, 1);
	else fseek(f, 1, 1);
	return tmp == '\'' ? 1 : 0;
}

//Сортировки естественным слиянием
void NaturalMergingSort() {
	int s1, s2, a1 = 0, a2 = 0, mark = 0;
	FILE* f, * f1, * f2;
	s1 = s2 = 1;
	//Пока в обоих файлах серия не равна нулю
	while (s1 > 0 && s2 > 0) {
		mark = 1;
		s1 = 0;
		s2 = 0;
		f = fopen("Enter.txt", "r");
		f1 = fopen("nmsort_1", "w");
		f2 = fopen("nmsort_2", "w");
		//Первое число записываем в f1
		fscanf_s(f, "%d", &a1);
		if (!feof(f)) {
			fprintf(f1, "%d ", a1);
		}
		//Второе число сравниваем с первым и выбираем файл для записи
		//В случае, если будет найдена упорядоченная последовательность, серия увеличится, а время сортировки уменьшится
		if (!feof(f)) fscanf_s(f, "%d", &a2);
		while (!feof(f)) {
			if (a2 < a1) {
				switch (mark) {
				case 1: {fprintf(f1, "' "); mark = 2; s1++; break; }
				case 2: {fprintf(f2, "' "); mark = 1; s2++; break; }
				}
			}
			//Смена файлов
			if (mark == 1) { fprintf(f1, "%d ", a2); s1++; }
			else { fprintf(f2, "%d ", a2); s2++; }
			//Теперь будем сравнивать следующий элемент
			a1 = a2;
			fscanf_s(f, "%d", &a2);
		}
		//Последнее действие после полного прочтения файла, деление серий
		if (s2 > 0 && mark == 2) { fprintf(f2, "'"); }
		if (s1 > 0 && mark == 1) { fprintf(f1, "'"); }
		fclose(f2);
		fclose(f1);
		fclose(f);

		//Сортировка и запись в файл f
		f = fopen("Enter.txt", "w");
		f1 = fopen("nmsort_1", "r");
		f2 = fopen("nmsort_2", "r");
		if (!feof(f1)) fscanf_s(f1, "%d", &a1);
		if (!feof(f2)) fscanf_s(f2, "%d", &a2);
		short file1, file2;
		//Пока оба файла не закончились
		while (!feof(f1) && !feof(f2)) {
			//В каждом файле ещё есть серии
			file1 = file2 = 0;
			while (!file1 && !file2) {
				if (a1 <= a2) {
					fprintf(f, "%d ", a1);
					//Определяем конец блока
					file1 = End_Range(f1);
					fscanf_s(f1, "%d", &a1);
				}
				else {
					fprintf(f, "%d ", a2);
					//Определяем конец блока
					file2 = End_Range(f2);
					fscanf_s(f2, "%d", &a2);
				}
			}
			//Если закончился второй файл
			while (!file1) {
				fprintf(f, "%d ", a1);
				file1 = End_Range(f1);
				fscanf_s(f1, "%d", &a1);
			}
			//Если закончился первый файл
			while (!file2) {
				fprintf(f, "%d ", a2);
				file2 = End_Range(f2);
				fscanf_s(f2, "%d", &a2);
			}
		}
		//Возвращаем значения
		file1 = file2 = 0;
		//Записываем оставшиеся значения в файлах
		while (!file1 && !feof(f1)) {
			fprintf(f, "%d ", a1);
			file1 = End_Range(f1);
			fscanf_s(f1, "%d", &a1);
		}
		while (!file2 && !feof(f2)) {
			fprintf(f, "%d ", a2);
			file2 = End_Range(f2);
			fscanf_s(f2, "%d", &a2);
		}
		fclose(f2);
		fclose(f1);
		fclose(f);
	}
	remove("nmsort_1");
	remove("nmsort_2");
}

//Двухфазная сортировка прямым слиянием
void SimpleMergingSort() {
	int a1 = 0, a2 = 0, series = 0, i = 0, j = 0, symCount = 0, tmp = 0;
	FILE* f, * f1, * f2;
	symCount = 0;
	f = fopen("Enter.txt", "r");

	if (f == NULL)
		printf("\nИсходный файл не может быть прочитан...");
	else {
		//Считаем количество чисел в файле
		while (!feof(f)) {
			fscanf_s(f, "%d", &a1);
			symCount++;
		}
		fclose(f);
	}
	series = 1;
	//Пока серия не совпадёт с количеством симоволов (ну или будет больше)
	while (series < symCount) {
		f = fopen("Enter.txt", "r");
		f1 = fopen("smsort_1.txt", "w");
		f2 = fopen("smsort_2.txt", "w");
		//Записываем первый символ
		if (!feof(f)) fscanf_s(f, "%d", &a1);
		//Записываем значения в файлы сериями, чередую их между собой
		while (!feof(f)) {
			for (i = 0; i < series && !feof(f); i++) {
				fprintf(f1, "%d ", a1);
				fscanf_s(f, "%d", &a1);
			}
			for (j = 0; j < series && !feof(f); j++) {
				fprintf(f2, "%d ", a1);
				fscanf_s(f, "%d", &a1);
			}
		}
		fclose(f2);
		fclose(f1);
		fclose(f);

		//Сортировка и запись в файл f
		f = fopen("Enter.txt", "w");
		f1 = fopen("smsort_1.txt", "r");
		f2 = fopen("smsort_2.txt", "r");
		if (!feof(f1)) fscanf_s(f1, "%d", &a1);
		if (!feof(f2)) fscanf_s(f2, "%d", &a2);
		while (!feof(f1) && !feof(f2)) {
			i = 0;
			j = 0;
			while (i < series && j < series && !feof(f1) && !feof(f2)) {
				if (a1 < a2) {
					fprintf(f, "%d ", a1);
					fscanf_s(f1, "%d", &a1);
					i++;
				}
				else {
					fprintf(f, "%d ", a2);
					fscanf_s(f2, "%d", &a2);
					j++;
				}
			}
			while (i < series && !feof(f1)) {
				fprintf(f, "%d ", a1);
				fscanf_s(f1, "%d", &a1);
				i++;
			}
			while (j < series && !feof(f2)) {
				fprintf(f, "%d ", a2);
				fscanf_s(f2, "%d", &a2);
				j++;
			}
		}
		while (!feof(f1)) {
			fprintf(f, "%d ", a1);
			fscanf_s(f1, "%d", &a1);
		}
		while (!feof(f2)) {
			fprintf(f, "%d ", a2);
			fscanf_s(f2, "%d", &a2);
		}
		fclose(f2);
		fclose(f1);
		fclose(f);
		series *= 2;
	}
	remove("smsort_1.txt");
	remove("smsort_2.txt");
}

int main()
{
	setlocale(LC_ALL, "RUS");
	char arr[20] = "Enter.txt";
	int size = 20, choice = 0;
	FILE* f;

	do {
		// Вводить данные с пробелом на конце!
		f = fopen("Enter.txt", "r");

		printf("Исходный массив: ");
		while (fgets(arr, size, f) != NULL) {
			printf("%s", arr);
		}
		printf("\n");

		fclose(f);

		printf("1. Сортировка методом слияния\n");
		printf("2. Выход\n\n");
		printf("> ");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			system("cls");

			SimpleMergingSort();
			printf("\n\n\tМассив отсортирован\n");
			printf("\n\n");

			f = fopen("Enter.txt", "r");

			printf("Результат: ");
			while (fgets(arr, size, f) != NULL) {
				printf("%s", arr);
			}
			printf("\n");

			fclose(f);

			system("pause");

			system("cls");
			break;
		case 4:
			system("cls");

			NaturalMergingSort();
			printf("\n\n\tМассив отсортирован\n");
			printf("\n\n");

			f = fopen("Enter.txt", "r");

			printf("Результат: ");
			while (fgets(arr, size, f) != NULL) {
				printf("%s", arr);
			}
			printf("\n");

			fclose(f);

			system("pause");

			system("cls");
			break;
		case 2:
			system("cls");
			exit(0);
			break;
		default:
			system("cls");
			printf("\nВведите значение от 1 до 3!\n\n");
			break;
		}
	} while (choice != 3);
}