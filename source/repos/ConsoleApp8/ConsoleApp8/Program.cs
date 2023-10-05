using System;
using System.Text;

class Program
{
    static void Main(string[] args)
    {
        MyClass obj1 = new MyClass(1, 2);
        MyClass obj2 = new MyClass(3, 4);
        MyClass result = obj1 + obj2;
        Console.WriteLine($"Результат: {result.IntProperty1}, {result.IntProperty2}");

        Console.ReadKey();
    }
}