using OxyPlot;
using OxyPlot.Axes;
using OxyPlot.Series;
using OxyPlot.Utilities;
using System.Windows.Forms;
using System;
using OxyPlot;
using OxyPlot.Series;
using OxyPlot.Axes;

namespace lab01
{
    class program
    {
        static int Input()
        {
            int num;
            while (true)
            {
                var input = Console.ReadLine();
                if (int.TryParse(input, out num))
                {
                    break;
                }
                else
                {
                    Console.WriteLine("Некорректный ввод!\nВведите число ещё раз:");
                }
            }
            return num;
        }
        class LeastSquares
        {
            double SummX = 0, SummXpow2 = 0, SummXpow3 = 0, SummXpow4 = 0, SummY = 0, SummXY = 0, SummXpow2Y = 0;
            double[,] dots;
            int n = 10;

            public object Controls { get; private set; }

            public LeastSquares()
            {
                dots = new double[2, 10] { { 3.244F, 3.802F, 3.001F, 3.720F, 3.803F, 3.270F, 3.409F, 3.307F, 3.856F, 3.917F }, { 4.399, 6.635F, 3.534F, 6.468F, 6.881F, 4.462F, 5.115F, 4.519F, 7.198F, 7.691F } };
                calcCoef();
            }
            void calcCoef()
            {
                int i = 0;
                while (i < n)
                {
                    SummX += dots[0, i];
                    SummXpow2 += dots[0, i] * dots[0, i];
                    SummXpow3 += dots[0, i] * dots[0, i] * dots[0, i];
                    SummXpow4 += dots[0, i] * dots[0, i] * dots[0, i] * dots[0, i];
                    SummY += dots[1, i];
                    SummXY += dots[0, i] * dots[1, i];
                    SummXpow2Y += dots[0, i] * dots[0, i] * dots[1, i];
                    i++;
                }
                Console.WriteLine("SummX = " + SummX);
                Console.WriteLine("SummX^2 = " + SummXpow2);
                Console.WriteLine("SummX^3 = " + SummXpow3);
                Console.WriteLine("SummX^4 = " + SummXpow4);
                Console.WriteLine("SummY = " + SummY);
                Console.WriteLine("SummXY = " + SummXY);
                Console.WriteLine("SummX^2Y = " + SummXpow2Y);
            }
            public void GaussLinear()
            {
                int RowAm = 2;
                Console.WriteLine();
                Console.Write("размерность матрицы: " + RowAm);
                double[,] MatrixCoef = new double[RowAm, RowAm];
                double[] FreeCoef = new double[RowAm];
                double Multi1, Multi2;
                double[] Result = new double[RowAm];
                Console.WriteLine();
                Console.WriteLine();
                Console.WriteLine("A[0][0] = " + SummXpow2);
                MatrixCoef[0, 0] = SummXpow2;
                Console.WriteLine("A[0][1] = " + SummX);
                MatrixCoef[0, 1] = SummX;
                Console.WriteLine("B[0] = " + SummXY);
                FreeCoef[0] = SummXY;

                Console.WriteLine("A[1][0] = " + SummX);
                MatrixCoef[1, 0] = SummX;
                Console.WriteLine("A[1][1] = " + n);
                MatrixCoef[1, 1] = n;
                Console.WriteLine("B[1] = " + SummY);
                FreeCoef[1] = SummY;
                Console.WriteLine("Начальный вид матрицы:");
                Console.WriteLine();

                int MatrixRow = MatrixCoef.GetLength(0);
                int MatrixCol = MatrixCoef.GetLength(1);
                for (int i = 0; i < MatrixRow; i++)
                {
                    for (int j = 0; j < MatrixCol; j++)
                    {
                        Console.Write(MatrixCoef[i, j] + "\t");
                    }
                    Console.WriteLine();
                }
                Console.WriteLine();
                Console.WriteLine("Свободные члены матрицы:");
                Console.WriteLine();
                for (int i = 0; i < RowAm; i++)
                {
                    Console.WriteLine($"B[{i + 1}] = {FreeCoef[i]}");
                }
                Console.WriteLine();
                for (int k = 0; k < RowAm; k++)
                {
                    for (int j = k + 1; j < RowAm; j++)
                    {
                        Multi1 = MatrixCoef[j, k] / MatrixCoef[k, k];
                        for (int i = k; i < RowAm; i++)
                        {
                            MatrixCoef[j, i] = MatrixCoef[j, i] - Multi1 * MatrixCoef[k, i];
                        }
                        FreeCoef[j] = FreeCoef[j] - Multi1 * FreeCoef[k];
                    }
                }
                for (int k = RowAm - 1; k >= 0; k--)
                {
                    Multi1 = 0;
                    for (int j = k; j < RowAm; j++)
                    {
                        Multi2 = MatrixCoef[k, j] * Result[j];
                        Multi1 += Multi2;
                    }
                    Result[k] = (FreeCoef[k] - Multi1) / MatrixCoef[k, k];
                }
                Console.WriteLine("Конечный вид матрицы:");
                Console.WriteLine();
                for (int i = 0; i < MatrixRow; i++)
                {
                    for (int j = 0; j < MatrixCol; j++)
                    {
                        Console.Write(MatrixCoef[i, j] + "\t");
                    }
                    Console.WriteLine();
                }
                Console.WriteLine();
                Console.WriteLine("Корни матрицы:");
                Console.WriteLine();
                for (int i = 0; i < RowAm; i++)
                {
                    Console.WriteLine($"X[{i + 1}] = {Result[i]}");
                }
                Console.WriteLine();
                Console.WriteLine("Программа завершила решение.");
            }
            public void GaussQuadratic()
            {
                int RowAm = 3;
                Console.WriteLine();
                Console.Write("размерность матрицы: " + RowAm);
                double[,] MatrixCoef = new double[RowAm, RowAm];
                double[] FreeCoef = new double[RowAm];
                double Multi1, Multi2;
                double[] Result = new double[RowAm];
                Console.WriteLine();
                Console.WriteLine("A[0][0] = " + SummXpow2);
                MatrixCoef[0, 0] = SummXpow2;
                Console.WriteLine("A[0][1] = " + SummX);
                MatrixCoef[0, 1] = SummX;
                Console.WriteLine("A[0][2] = " + n);
                MatrixCoef[0, 2] = n;
                Console.WriteLine("B[0] = " + SummY);
                FreeCoef[0] = SummY;

                Console.WriteLine("A[1][0] = " + SummXpow3);
                MatrixCoef[1, 0] = SummXpow3;
                Console.WriteLine("A[1][1] = " + SummXpow2);
                MatrixCoef[1, 1] = SummXpow2;
                Console.WriteLine("A[1][2] = " + SummX);
                MatrixCoef[1, 2] = SummX;
                Console.WriteLine("B[1] = " + SummXY);
                FreeCoef[1] = SummXY;

                Console.WriteLine("A[2][0] = " + SummXpow3);
                MatrixCoef[2, 0] = SummXpow4;
                Console.WriteLine("A[2][1] = " + SummXpow2);
                MatrixCoef[2, 1] = SummXpow3;
                Console.WriteLine("A[2][2] = " + SummX);
                MatrixCoef[2, 2] = SummXpow2;
                Console.WriteLine("B[2] = " + SummXpow2Y);
                FreeCoef[2] = SummXpow2Y;

                Console.WriteLine("Начальный вид матрицы:");
                Console.WriteLine();
                int MatrixRow = MatrixCoef.GetLength(0);
                int MatrixCol = MatrixCoef.GetLength(1);
                for (int i = 0; i < MatrixRow; i++)
                {
                    for (int j = 0; j < MatrixCol; j++)
                    {
                        Console.Write(MatrixCoef[i, j] + "\t");
                    }
                    Console.WriteLine();
                }
                Console.WriteLine();
                Console.WriteLine("Свободные члены матрицы:");
                Console.WriteLine();
                for (int i = 0; i < RowAm; i++)
                {
                    Console.WriteLine($"B[{i + 1}] = {FreeCoef[i]}");
                }
                Console.WriteLine();
                for (int k = 0; k < RowAm; k++)
                {
                    for (int j = k + 1; j < RowAm; j++)
                    {
                        Multi1 = MatrixCoef[j, k] / MatrixCoef[k, k];
                        for (int i = k; i < RowAm; i++)
                        {
                            MatrixCoef[j, i] = MatrixCoef[j, i] - Multi1 * MatrixCoef[k, i];
                        }
                        FreeCoef[j] = FreeCoef[j] - Multi1 * FreeCoef[k];
                    }
                }
                for (int k = RowAm - 1; k >= 0; k--)
                {
                    Multi1 = 0;
                    for (int j = k; j < RowAm; j++)
                    {
                        Multi2 = MatrixCoef[k, j] * Result[j];
                        Multi1 += Multi2;
                    }
                    Result[k] = (FreeCoef[k] - Multi1) / MatrixCoef[k, k];
                }
                Console.WriteLine("Конечный вид матрицы:");
                Console.WriteLine();
                for (int i = 0; i < MatrixRow; i++)
                {
                    for (int j = 0; j < MatrixCol; j++)
                    {
                        Console.Write(MatrixCoef[i, j] + "\t");
                    }
                    Console.WriteLine();
                }
                Console.WriteLine();
                Console.WriteLine("Корни матрицы:");
                Console.WriteLine();
                for (int i = 0; i < RowAm; i++)
                {
                    Console.WriteLine($"X[{i + 1}] = {Result[i]}");
                }
                Console.WriteLine();
                Console.WriteLine("Программа завершила решение.");
            }
            public void PlotFunction()
            {
                // создаем новый график
                var plotModel = new PlotModel { Title = "График F(t)" };
                double[,] dots;
                // создаем ось X
                var axisX = new LinearAxis { Position = AxisPosition.Bottom, Title = "t" };
                plotModel.Axes.Add(axisX);

                // создаем ось Y
                var axisY = new LinearAxis { Position = AxisPosition.Left, Title = "F(t)" };
                plotModel.Axes.Add(axisY);

                // создаем новый ряд данных для графика
                var series = new LineSeries();
                series.Color = OxyColors.SkyBlue;
                dots = new double[2, 10] { { 3.244F, 3.802F, 3.001F, 3.720F, 3.803F, 3.270F, 3.409F, 3.307F, 3.856F, 3.917F }, { 4.399, 6.635F, 3.534F, 6.468F, 6.881F, 4.462F, 5.115F, 4.519F, 7.198F, 7.691F } };


                // добавляем точки графика
                for (int i = 0; i < 8; i++)
                {
                    double x = dots[0, i];
                    double y = dots[1, i];
                    series.Points.Add(new DataPoint(x, 4.44852800 * x - 10.02600 * y));
                }

                // добавляем ряд данных на график
                plotModel.Series.Add(series);

                // создаем вид графика, используя элемент управления PlotView
                var plotView = new PlotController();


                plotView.Model = plotModel;

                // добавляем элемент управления PlotView на форму
                Controls.Add(plotView);
            }
        }

        static void Main()
        {
            LeastSquares Task = new LeastSquares();
            int comm = 0;
            bool flag = true;
            while (flag)
            {
                Console.WriteLine("\nЧто будем делать ?");
                Console.WriteLine("1)Решать СЛАУ для линейной аппроксимирующей функции;");
                Console.WriteLine("2)Решать СЛАУ для квадратичной аппроксимирующей функции;");
                Console.WriteLine("3)Ничего;");
                comm = Input();
                switch (comm)
                {
                    case 1:
                        {
                            Task.GaussLinear();
                            break;
                        }
                    case 2:
                        {
                            Task.GaussQuadratic();
                            break;
                        }
                    case 3:
                        {
                            flag = false;
                            break;
                        }
                    default:
                        {
                            break;
                        }
                }
            }
        }
    }
}

