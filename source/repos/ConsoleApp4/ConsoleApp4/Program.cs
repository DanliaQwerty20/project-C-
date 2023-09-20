// Абстрактный базовый класс Norm
abstract class Norm
{
    // Абстрактный метод вычисления нормы
    public abstract double CalculateNorm();

    // Виртуальный метод вычисления модуля
    public virtual double CalculateModule()
    {
        return Math.Abs(CalculateNorm());
    }
}


// Производный класс Complex
class Complex : Norm
{
    public double real { get; set; } // Действительная часть
    public double imaginary { get; set; } // Мнимая часть

    public Complex(double real, double imaginary)
    {
        this.real = real;
        this.imaginary = imaginary;
    }

    // Реализация метода вычисления нормы (квадрата модуля)
    public override double CalculateNorm()
    {
        return Math.Pow(real, 2) + Math.Pow(imaginary, 2);
    }

    // Переопределение метода вычисления модуля
    public override double CalculateModule()
    {
        return Math.Sqrt(CalculateNorm());
    }
}

// Производный класс Vector
class Vector : Norm
{
    public double x1, y1, x2, y2;

    public Vector(double x1, double y1, double x2, double y2)
    {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }

    // Реализация метода вычисления нормы (максимальное из абсолютных значений координат)
    public override double CalculateNorm()
    {
        double maxX = Math.Max(Math.Abs(x1), Math.Abs(x2));
        double maxY = Math.Max(Math.Abs(y1), Math.Abs(y2));
        return Math.Max(maxX, maxY);
    }

    // Переопределение метода вычисления модуля
    public override double CalculateModule()
    {
        return Math.Sqrt(Math.Pow(x2 - x1, 2) + Math.Pow(y2 - y1, 2));
    }
    
}

class Program
{

        static void Main(string[] args)
        {
            // Создаем объекты классов Complex и Vector
            Complex complex = new Complex(2, 3);
            Vector vector = new Vector(1, 2, 3, 4);
     
            // Вызываем методы CalculateNorm() и CalculateModule() для объекта complex
            double norm1 = complex.CalculateNorm();
            double module1 = complex.CalculateModule();
            Console.WriteLine($"Для комплексного числа z = {complex.real} + {complex.imaginary}i:");
            Console.WriteLine($"Норма (квадрат модуля) равна {norm1}");
            Console.WriteLine($"Модуль (корень из суммы квадратов действительной и мнимой частей) равен {module1}");

            // Вызываем методы CalculateNorm() и CalculateModule() для объекта vector
            double norm2 = vector.CalculateNorm();
            double module2 = vector.CalculateModule();
            Console.WriteLine($"Для вектора ({vector.x1}, {vector.y1})-({vector.x2}, {vector.y2}):");
     
        
            
    }

    
     
    abstract class MyClass1{
        public virtual double myFunction()
        {
            return 0.1;
        }
    }
    abstract class MyClass2:MyClass1{
        private virtual void myFunction(){
            int a;
        }
    }

    abstract class MyClass3:MyClass2{



    }


     
     
}
