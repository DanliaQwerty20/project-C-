#include <stdio.h>
//
//решение через символьную строку.
int main() {
	char str[100];//обычный массив,с которым будем работать
	char ch = 'a';
	printf("Please enter string: ");
	if (gets(str, 100)) {//вводим строку
		char last_space = 0;
		int size = strlen(str);//тут находим последний пробел
		int count1 = 0;
		for (int i = size - 1; i > 0; i--) {
			if (str[i] == 'a') {
				count1++;
			}
			if (str[i] == ' ') {
				printf("%d", count1);
				break;
			}
		}
	}
	return 0;
}