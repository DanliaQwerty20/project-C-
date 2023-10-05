#include <iostream>
#include <iomanip>
#include <cmath>
#include <numbers>
#define PI 3.14159265
using namespace std;

double Sn(int N)
{
    return N * sin(2 * PI / N) / 2;
}

double Area(int i, int j, int k, int N)
{
    return abs(sin(2 * PI * (j - i) / N) + sin(2 * PI * (k - j) / N) + sin(2 * PI * (i - k) / N)) / 2;
}


int main()
{
    for (int k = 1; k < 21; ++k)
    {
        int N = (1 << k) * 9 - 6;
        double s = 0;
        int L = 1;
        for (int i = k - 1; i >= 0; --i)
        {
            int count = 3 * (1 << i);
            s += count * Area(0, L, 2 * L, N);
            L = L * 2 + 2;
        }
        s += Area(0, L, 2 * L, N);
        s = s / Sn(N);
        
        cout << N << "   " << setprecision(15) << 1.0 - s << endl;
    }
}