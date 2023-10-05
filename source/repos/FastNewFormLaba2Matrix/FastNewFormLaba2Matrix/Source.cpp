#include <iostream>
#include "Funtions.h"
using namespace std;



void main() {
	setlocale(LC_ALL, "rus");


	int N, M;
	//ввод размера матицы
	cout << "Ввод N:\n";
	cin >> N;
	cout << "Ввод M:\n";
	cin >> M;


	float** Arr = new float* [N];//первая матрица
	float** Brr = new float* [N];//конечная матрица
	for (int i = 0; i < N; i++) {
		Arr[i] = new float[M];
		Brr[i] = new float[M];
	}
	//задаем Arr
	bool flag;
	cout << "Сгенирировать матрицу-1,ЗАписать матрицу-0\n";
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
	max = MaxElement(N, M, Arr, max);//нахождение макса
	Brr = AddMatrixInBrr(N, M, Arr, Brr, max);//заполнение Brr

	//Вывод Brr
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << Brr[i][j] << " ";
		}
		cout << endl;
	}
	removeMatrixs(N, Arr, Brr);

}