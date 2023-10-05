
/*
 Создать консольное приложение, в котором объявить класс, 
содержащий в себе два целочисленных автоматически реализуемых 
свойства. Внутри класса переопределить оператор «+», который 
позволит складывать элементы данного класса между собой.
 */

class MyClass
{
    public int IntProperty1 { get; set; }
    public int IntProperty2 { get; set; }

    public MyClass(int int1, int int2)
    {
        IntProperty1 = int1;
        IntProperty2 = int2;
    }

    public static MyClass operator +(MyClass obj1, MyClass obj2)
    {
        return new MyClass(obj1.IntProperty1 + obj2.IntProperty1, obj1.IntProperty2 + obj2.IntProperty2);
    }
}
