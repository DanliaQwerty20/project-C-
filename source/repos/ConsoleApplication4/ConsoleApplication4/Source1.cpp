#include <stdio.h>
//
//������� ����� ���������� ������.
int main() {
	char str[100];//������� ������,� ������� ����� ��������
	char ch = 'a';
	printf("Please enter string: ");
	if (gets(str, 100)) {//������ ������
		char last_space = 0;
		int size = strlen(str);//��� ������� ��������� ������
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