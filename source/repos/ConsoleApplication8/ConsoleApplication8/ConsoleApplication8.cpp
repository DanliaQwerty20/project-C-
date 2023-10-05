#include <iostream>
#include <windows.h>
#define kv(x) x*x
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	double E1 = 0.15, E2 = 0.2, M = 10, xk1 = 0, xk2 = 0.5, E = 0.2;
	double a, b, c;
	int s = 0;
	double gradfxk, gradfx1, gradfx2, gradfx11, gradfx12;
	cout << "Задайте функцию:\nf(x) = a*x1^2+b*x1*x2+c*x2^2\na = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	int ff = 1, f = 1;
	double t = 0.5, xk11, xk12, fxk1, fxk;
	int k = 0;
	printf("====== k = %d ======\n", k);
	while (f)
	{
		printf("x = (%0.2f; %0.2f)\n", xk1, xk2);
		printf("Градиент f(x) = (%0.2f*x1 + %0.2f*x2; %0.2f*x2 + %0.2f*x1)\n", a*2 , b, c*2, b);
		gradfx1 = 6 * xk1 + 0.1 * xk2;
		gradfx2 = 0.1*xk1 + 12*xk2;
	

		//gradfx1 = 2 * xk1 * a + b * xk2; //Производная по х1 от f(x) = a*x1^2 + b*x1*x2 + c*x2^2
		//gradfx2 = 2 * c * xk2 + b * xk1; //Производная по х2 от f(x) = a*x1^2 + b*x1*x2 + c*x2^2
		printf("Градиент f(x) = (%0.2f; %0.2f)\n", gradfx1, gradfx2);
		gradfxk = sqrt(kv(gradfx1) + kv(gradfx2));
		printf("Градиент f(x) = %0.2f\n", gradfxk);
		printf("Сравниваем градиент f(x) и Е1\n");
		if (gradfxk < E1)
		{
			printf("Градиент меньше Е1\n");
			printf("\nx* = (%0.2f; %0.2f)\nf(x) = %0.2f\nk = %d\n", xk1, xk2, fxk, k);
			return 0;
		}
		else
		{
			printf("Градиент больше равен Е1\n");
			printf("Сравниваем k и М; k = %d, M = 10\n", k);
			if (k >= M)
			{
				printf("k больше равно М\n");
				printf("\nx* = (%0.2f; %0.2f)\nf(x) = %0.2f\nk = %d\n", xk1, xk2, fxk, k);
				return 0;
			}
			else
			{
				printf("k меньше равно М\nЗадаём t = %0.2f\n", t);
				ff = 1;
				while (ff)
				{
					printf("Вычисляем x(k+1)\n");
					xk11 = xk1 - t * gradfx1;
					xk12 = xk2 - t * gradfx2;
					printf("x(k+1) = (%0.2f; %0.2f)\n", xk11, xk12);
					fxk = a * kv(xk1) + b * xk1 * xk2 + c * kv(xk2);
					fxk1 = a * kv(xk11) + b * xk11 * xk12 + c * kv(xk12);
					printf("Вычисляем f(xk) и f(x(k+1))\nf(xk) = %0.2f, f(x(k+1)) = %0.2f\n", fxk, fxk1);
					printf("Сравниваем f(xk) и f(x(k+1))\n");
					if (fxk1 <= fxk)
					{
						printf("f(x(k+1)) <= f(x)\n");
						printf("Cравниваем (||x1-x0|| и E2) и (|f(x(k+1))|)  и E2)");
						double x1x0 = sqrt(kv((xk11 - xk1)) + kv((xk12 - xk2)));
						if (((x1x0 < E2) && ((abs(fxk1 - fxk)) < E2)))
						{
							s++;
							if (s == 2)
							{
								printf("\nx* = (%f; %f)\nf(x) = %0.2f\nk = %d\n", xk11, xk12, fxk1, k + 1);
								return 0;
							}
							else
							{
								printf("(|| x1 - x0 || >= E2) или (| f(x(k + 1)) | ) >= E2)\n");
								k++;
								printf("Увеличиваем k на 1\n--- k = %d ---\nxk = x(k+1)\n", k);
								xk1 = xk11;
								xk2 = xk12;
								ff = 0;
							}
						}
						else
						{
							s = 0;
							printf("(|| x1 - x0 || >= E2) или (| f(x(k + 1)) | ) >= E2)\n");
							k++;
							printf("Увеличиваем k на 1\n--- k = %d ---\n xk = x(k+1)\n", k);
							xk1 = xk11;
							xk2 = xk12;
							ff = 0;
						}
					}
					else
					{
						printf("f(x(k+1)) > f(x)\n");
						t /= 2;
					}
				}
			}
		}
	}
}