


#include "Functions.h"	



float MaxElement(int N, int M, float** Arr, float max) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (max <= Arr[i][j]) {
				max = Arr[i][j];
			}
		}
	}
	return max;
}

float** AddMatrixInBrr(int N, int M, float** Arr, float** Brr, float max) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Arr[i][j] > 0) {
				Brr[i][j] = max;
			}
			else {
				Brr[i][j] = Arr[i][j];
			}
		}
	}
	return Brr;
}


void removeMatrixs(int N, float** Arr, float** Brr) {
	for (int i = 0; i < N; i++) {
		delete[] Arr[i];
		delete[] Brr[i];
	}
	delete[]Arr;
	delete[]Brr;
}






