using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    abstract class Funcion
    {
        public abstract double Calculate(double x);


        public virtual void DisplayResult(double x, double y)
        {
            Console.WriteLine($"Значение функции y=f({x}) равно {y}");

        }
    }
    class Ellipse : Funcion
    {
        private double a;
        private double b;
        public Ellipse(double a, double b)
        {
            this.a = a;
            this.b = b;
        }

        public override double Calculate(double x)
        {
            return Math.Sqrt(1 - Math.Pow(x / a, 2)) * b;
        }
        public double CalculateArea()
        {
            return Math.PI * a * b;
        }

        //public abstract void myFunction(){}
    }
    class Hyperbola : Funcion
    {
        private double a;
        private double b;

        public Hyperbola(double a, double b)
        {
            this.a = a;
            this.b = b;
        }

        public override double Calculate(double x)
        {
            return Math.Sqrt(Math.Pow(x / a, 2) - 1) * b;
        }
    }

    class Program
    {
        static void Main(String[] args)
        {
            Ellipse ellipse = new Ellipse(2, 3);
            Hyperbola hyperbola = new Hyperbola(2, 3);
            double number;
            string input = Console.ReadLine();
            if (double.TryParse(input, out number))
            {
                Console.WriteLine("Введено число: " + number);
                double x1 = number;
                double y1 = ellipse.Calculate(x1);
                double x2 = 1.1;
                double y2 = ellipse.Calculate(x2);

                ellipse.DisplayResult(x1, y1);
                ellipse.DisplayResult(x2, y2);

                Funcion funcion = ellipse;
                double x3 = 0.4;
                double y3 = funcion.Calculate(x3);
                funcion.DisplayResult(x3, y3);

            }
            else
            {
                Console.WriteLine("Ошибка! Введено не число.");
            }
            
        }



    }
}