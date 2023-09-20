#include <iostream>
#include "Funtions.h"
using namespace std;



void main() {
	setlocale(LC_ALL, "rus");


	int N, M;
	//���� ������� ������
	cout << "���� N:\n";
	cin >> N;
	cout << "���� M:\n";
	cin >> M;


	float** Arr = new float* [N];//������ �������
	float** Brr = new float* [N];//�������� �������
	for (int i = 0; i < N; i++) {
		Arr[i] = new float[M];
		Brr[i] = new float[M];
	}
	//������ Arr
	bool flag;
	cout << "������������� �������-1,�������� �������-0\n";
	cin >> flag;
	if (!flag) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> Arr[i][j];
			}
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				Arr[i][j] = rand() % 20-10;
			}
		}
	}

	float max = Arr[0][0];
	max = MaxElement(N, M, Arr, max);//���������� �����
	Brr = AddMatrixInBrr(N, M, Arr, Brr, max);//���������� Brr

	//����� Brr
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << Brr[i][j] << " ";
		}
		cout << endl;
	}
	removeMatrixs(N, Arr, Brr);

}