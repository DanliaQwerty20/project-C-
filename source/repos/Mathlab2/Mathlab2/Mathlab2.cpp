#include <GL/glut.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <iostream>
const int n = 5; // number of cubic polynomials
const float a = -2.5;
const float b = 2.5;
const float h = (b - a) / n;
using namespace std;
void fillFunction(float*& X, float*& Y)
{
	float a = 0;
	for (size_t i = 0; i < n + 1; i++)
	{
		X[i] = a;
		a = a + 0.5;
		Y[i] = (0.8889) * cos(1.4 * X[i]);

	}
}
void fillMatrix(float**& matrix, unsigned int& N, float* Y)
{
	N = n - 1;
	const unsigned int _N = n - 1;
	matrix = new float* [N];
	for (size_t i = 0; i < N; i++)
		matrix[i] = new float[N + 1];
	for (size_t i = 0; i < N; i++)
		for (size_t j = 0; j < N; j++)
			matrix[i][j] = 0;
	for (size_t i = 0; i < N; i++)
	{
		if (i == 0)
		{
			matrix[i][i] = 4;
			matrix[i][i + 1] = 1;
		}
		else if (i == N - 1)
		{
			matrix[i][i - 1] = 1;
			matrix[i][i] = 4;
		}
		else
		{
			matrix[i][i - 1] = 1;
			matrix[i][i] = 4;
			matrix[i][i + 1] = 1;
		}
	}
	for (size_t i = 0; i < N; i++)
		
	{
		if (i == 0)
			matrix[i][N] = 3.0 / (h * h*4) * (Y[i + 2] - 2 * Y[i + 1]);
		else if (i == N - 1)
			matrix[i][N] = 3.0 / (h * h*4) * (Y[i] - 2 * Y[i + 1]);
		else
			matrix[i][N] = 3.0 / (h * h*4) * (Y[i + 2] + Y[i] - 2 * Y[i + 1]);
	}
}
float* Solve(float** matrix, unsigned int N)
{
	float* P = new float[N];
	float* Q = new float[N];
	float* X = new float[N + 1];
	float a, b, c, d;
	for (size_t i = 0; i < N; i++)
	{
		a = matrix[i][i - 1];
		b = matrix[i][i];
		c = matrix[i][i + 1];
		d = matrix[i][N];
		if (i == 0)
		{
			P[i] = -c / b;
			Q[i] = d / b;
		}
		else if (i == N - 1)
		{
			P[i] = 0;
			Q[i] = (d - a * Q[i - 1]) / (b + a * P[i - 1]);
		}
		else
		{
			P[i] = -c / (b + a * P[i - 1]);
			Q[i] = (d - a * Q[i - 1]) / (b + a * P[i - 1]);
		}
	}
	X[N - 1] = Q[N - 1];
	for (int i = N - 2; i > -1; i--)
		X[i] = P[i] * X[i + 1] + Q[i];
	for (int i = N; i > 0; i--)
		X[i] = X[i - 1];
	X[0] = 0;
	return X;
}
void fillCoefficients(float* X, float* Y, float*& A, float*& B, float*& C, float*& D)
{
	for (size_t i = 0; i < n - 1; i++)
	{
		A[i] = Y[i];
		D[i] = (C[i + 1] - C[i]) / (3 * h);
		B[i] = (Y[i + 1] - Y[i]) / h - (C[i + 1] + 2 * C[i]) * h / 3;
	}
	A[n - 1] = Y[n - 1];
	B[n - 1] = (Y[n] - Y[n - 1]) / h - 2 * C[n - 1] * h / 3;
	D[n - 1] = -C[n - 1] / (3 * h);
}

float function(float x, float x0, float A, float B, float C, float D)
{
	return A + B * (x - x0) + C * (x - x0) * (x - x0) + D * (x - x0) * (x - x0) * (x
		- x0);
}
// Window size
int width = 1024;
int height = 1024;
void Draw()
{
	float** Matrix;
	float* X = new float[n];
	float* Y = new float[n];
	float* A = new float[n];
	float* B = new float[n];
	float* C = new float[n];
	float* D = new float[n];
	unsigned int N;
	fillFunction(X, Y);
	fillMatrix(Matrix, N, Y);
	C = Solve(Matrix, N);
	fillCoefficients(X, Y, A, B, C, D);
	// clear (has to be done at the beginning)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	int Kx = 0; //-width / 4;
	int Ky = 0; //-height / 4;
	float kx = width / 6.0, ky = height / 6.0;
	// Draw X axis
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-width / 2.0f, 0.0f + Ky);
	glVertex2f(width / 2.0f, 0.0f + Ky);
	glEnd();
	// Draw Y axis
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.0f + Kx, -height / 2.0f);
	glVertex2f(0.0f + Kx, height / 2.0f);
	glEnd();
	// Draw original function ( (0.8889) * cos(1.4 * 1);)
	float H = 0.05;
	for (float i = a; i < b; i += H)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 1.0f);

		glVertex2f(i*kx+Kx,0.8889*cos(1.4*(-i*i))*ky);



		glEnd();
	}
	
		// Draw polinoms
		for (size_t i = 0; i < n; i++)
		{
			for (float x = a + i * h; x < a + i * h + h; x += H)
			{
				float X = x - (a + i * h);
				glBegin(GL_LINES);
				glColor3f(1.0f, 0.0f, 0.0f);
				glVertex2f(x * kx + Kx, function(x, a + i * h, A[i], B[i], C[i], D[i]) * ky
					+ Ky);
				glVertex2f((x + H) * kx + Kx, function(x + H, a + i * h, A[i], B[i],
					C[i], D[i]) * ky + Ky);
				glEnd();
			}
		}
	glutSwapBuffers();
}
void Enable2D(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-width / 2.0f, width / 2.0f, -height / 2.0f, height / 2.0f, 0.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
// Program entry point
int main(int argc, char** argv)
{
	// Initialize opengl (via glut)
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("Graph");
	glutDisplayFunc(Draw);
	// setup scene to 2d mode and set draw color to white
	Enable2D(width, height);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Start the whole thing
	glutMainLoop();
	return 0;
}