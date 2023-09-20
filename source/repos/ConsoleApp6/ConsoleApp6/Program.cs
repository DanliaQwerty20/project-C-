using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

class Program
{
    static void Main(string[] args)
    {
        int X = 1;
        int T = 1;
        int m = 5; //10
        int n = 80; //250
        double p = (double)(3 * 7 + 1) / (7 + 2);
        double h = (double)X / m;
        double t = (double)T / n;
        double t2 = 0;
        double[,] U = new double[m + 1, n + 1];
        double[,] U2 = new double[m + 1, 2];
        U2[0, 0] = 0;
        U2[0, 0] = 0;
        U2[m - 1, 0] = 0;
        U2[m - 1, 1] = 1;
        int i = 0;
        int j = 0;
        for (i = 0; i < m + 1; i++)
        {
            for (j = 0; j < n + 1; j++)
            {
                if (i == 0 && j == 0)
                {
                    U[i, j] = 0;
                }
                if (i == 0 && j > 0)
                {
                    U[i, j] = 0;
                }
                if (i == m)
                {
                    U[i, j] = 0;
                }
                if (j == 0 && i > 0 && i < m)
                {
                    U[i, j] = p * Math.Sin(3.1415926535 * (i * h));
                }
            }
        }
        for (i = 1; i < m; i++)
        {
            for (j = 1; j < n + 1; j++)
            {
                double temp = 0;
                temp = (U[i - 1, j - 1] - 2 * U[i, j - 1] + U[i + 1, j - 1]) / (h * h);
                temp = temp * t;
                temp = temp + U[i, j - 1];
                U[i, j] = temp;
                if (j * t == 0.2)
                {
                    U2[i, 0] = temp;
                    U2[i, 1] = i * h;
                }
            }
        }
        for (i = 0; i < m + 1; i++)
        {
            Console.Write("({1},{0})", U2[i, 0].ToString("0.#####################################"), U2[i,
           1]);
            if (i != m)
            {
                Console.Write(",");
            }
        }
    }
}
