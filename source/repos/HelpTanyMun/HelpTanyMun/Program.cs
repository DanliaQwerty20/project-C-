using System;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            // заданные значения
            double x = 1.7;
            double E = 0.001;

            // начальные значения
            double sum = 1;
            double term = x;
            int n = 1;

            // цикл для вычисления суммы
            while (Math.Abs(term) >= E)
            {
                sum += term;
                n++;
                term *= x * x / (2 * n - 1) / (2 * n);
            }
            //будешь должна очень много
            // вывод результатов
            Console.WriteLine("Результат");
            Console.WriteLine("Значение суммы: " + sum);
            Console.WriteLine("Число членов ряда: " + n);
            Console.ReadLine();
        }
    }
}