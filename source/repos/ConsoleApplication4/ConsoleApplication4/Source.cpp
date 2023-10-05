#include <stdio.h>
//массив символов
int main()
{
	char str[10];
	printf("Vvedite string:\n");

	scanf_s("%9c", str);
	int i = 0;
	int count = 0;
	while (str[i] != NULL) {
		if (str[i] == 'a') {
			count++;
		}
		if (str[i] == ' ') {
			count = 0;
		}
		i++;
	}
	printf("%d", count);
}