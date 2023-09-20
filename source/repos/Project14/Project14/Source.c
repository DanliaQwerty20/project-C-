#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>

//����������� ����� �����
short End_Range(FILE* f) {
	int tmp;
	tmp = fgetc(f);
	tmp = fgetc(f);
	//������������ �� 2 ������� �����
	if (tmp != '\'') fseek(f, -2, 1);
	else fseek(f, 1, 1);
	return tmp == '\'' ? 1 : 0;
}

//���������� ������������ ��������
void NaturalMergingSort() {
	int s1, s2, a1 = 0, a2 = 0, mark = 0;
	FILE* f, * f1, * f2;
	s1 = s2 = 1;
	//���� � ����� ������ ����� �� ����� ����
	while (s1 > 0 && s2 > 0) {
		mark = 1;
		s1 = 0;
		s2 = 0;
		f = fopen("Enter.txt", "r");
		f1 = fopen("nmsort_1", "w");
		f2 = fopen("nmsort_2", "w");
		//������ ����� ���������� � f1
		fscanf_s(f, "%d", &a1);
		if (!feof(f)) {
			fprintf(f1, "%d ", a1);
		}
		//������ ����� ���������� � ������ � �������� ���� ��� ������
		//� ������, ���� ����� ������� ������������� ������������������, ����� ����������, � ����� ���������� ����������
		if (!feof(f)) fscanf_s(f, "%d", &a2);
		while (!feof(f)) {
			if (a2 < a1) {
				switch (mark) {
				case 1: {fprintf(f1, "' "); mark = 2; s1++; break; }
				case 2: {fprintf(f2, "' "); mark = 1; s2++; break; }
				}
			}
			//����� ������
			if (mark == 1) { fprintf(f1, "%d ", a2); s1++; }
			else { fprintf(f2, "%d ", a2); s2++; }
			//������ ����� ���������� ��������� �������
			a1 = a2;
			fscanf_s(f, "%d", &a2);
		}
		//��������� �������� ����� ������� ��������� �����, ������� �����
		if (s2 > 0 && mark == 2) { fprintf(f2, "'"); }
		if (s1 > 0 && mark == 1) { fprintf(f1, "'"); }
		fclose(f2);
		fclose(f1);
		fclose(f);

		//���������� � ������ � ���� f
		f = fopen("Enter.txt", "w");
		f1 = fopen("nmsort_1", "r");
		f2 = fopen("nmsort_2", "r");
		if (!feof(f1)) fscanf_s(f1, "%d", &a1);
		if (!feof(f2)) fscanf_s(f2, "%d", &a2);
		short file1, file2;
		//���� ��� ����� �� �����������
		while (!feof(f1) && !feof(f2)) {
			//� ������ ����� ��� ���� �����
			file1 = file2 = 0;
			while (!file1 && !file2) {
				if (a1 <= a2) {
					fprintf(f, "%d ", a1);
					//���������� ����� �����
					file1 = End_Range(f1);
					fscanf_s(f1, "%d", &a1);
				}
				else {
					fprintf(f, "%d ", a2);
					//���������� ����� �����
					file2 = End_Range(f2);
					fscanf_s(f2, "%d", &a2);
				}
			}
			//���� ���������� ������ ����
			while (!file1) {
				fprintf(f, "%d ", a1);
				file1 = End_Range(f1);
				fscanf_s(f1, "%d", &a1);
			}
			//���� ���������� ������ ����
			while (!file2) {
				fprintf(f, "%d ", a2);
				file2 = End_Range(f2);
				fscanf_s(f2, "%d", &a2);
			}
		}
		//���������� ��������
		file1 = file2 = 0;
		//���������� ���������� �������� � ������
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

//���������� ���������� ������ ��������
void SimpleMergingSort() {
	int a1 = 0, a2 = 0, series = 0, i = 0, j = 0, symCount = 0, tmp = 0;
	FILE* f, * f1, * f2;
	symCount = 0;
	f = fopen("Enter.txt", "r");

	if (f == NULL)
		printf("\n�������� ���� �� ����� ���� ��������...");
	else {
		//������� ���������� ����� � �����
		while (!feof(f)) {
			fscanf_s(f, "%d", &a1);
			symCount++;
		}
		fclose(f);
	}
	series = 1;
	//���� ����� �� ������� � ����������� ��������� (�� ��� ����� ������)
	while (series < symCount) {
		f = fopen("Enter.txt", "r");
		f1 = fopen("smsort_1.txt", "w");
		f2 = fopen("smsort_2.txt", "w");
		//���������� ������ ������
		if (!feof(f)) fscanf_s(f, "%d", &a1);
		//���������� �������� � ����� �������, ������� �� ����� �����
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

		//���������� � ������ � ���� f
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
		// ������� ������ � �������� �� �����!
		f = fopen("Enter.txt", "r");

		printf("�������� ������: ");
		while (fgets(arr, size, f) != NULL) {
			printf("%s", arr);
		}
		printf("\n");

		fclose(f);

		printf("1. ���������� ������� �������\n");
		printf("2. ���������� ������������ ��������\n");
		printf("3. �����\n\n");
		printf("> ");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			system("cls");

			SimpleMergingSort();
			printf("\n\n\t������ ������������\n");
			printf("\n\n");

			f = fopen("Enter.txt", "r");

			printf("���������: ");
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

			NaturalMergingSort();
			printf("\n\n\t������ ������������\n");
			printf("\n\n");

			f = fopen("Enter.txt", "r");

			printf("���������: ");
			while (fgets(arr, size, f) != NULL) {
				printf("%s", arr);
			}
			printf("\n");

			fclose(f);

			system("pause");

			system("cls");
			break;
		case 3:
			system("cls");
			exit(0);
			break;
		default:
			system("cls");
			printf("\n������� �������� �� 1 �� 3!\n\n");
			break;
		}
	} while (choice != 3);
}