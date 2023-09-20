#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <time.h>
#include "Funtions.h"


using namespace std;
//прототипы
float MaxElement(int N, int M, float** Arr, float max);
float** AddMatrixInBrr(int N, int M, float** Arr, float** Brr, float max);
void removeMatrixs(int N, float** Arr, float** Brr);