// See https://aka.ms/new-console-template for more information

using System;

main();
void mmm()
{
    int len = Convert.ToInt32(Console.ReadLine());
    int[] a = new int[len];

    for (int i = 0; i < len; i++)
    {
        a[i] = Convert.ToInt32(Console.ReadLine());
    }
    int otr = 0;
    for (int i = 0; i < len; i++)
    {
        if (a[i] < 0)
        {
            otr++;
        }
    }
    Console.WriteLine(otr);
}


void mmm2()
{
    Random random= new Random();
    int[,] array = new int[8, 3];
    int[,] nums2 = new int[8,3];
    for (int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            array[i, j] = (random.Next(-10,10));
        }
        
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Console.WriteLine(array[i, j]);
        }
        Console.WriteLine("\n");

    }
    double[] a = new double[8];
    for (int i = 0; i < 8; i++)
    {
        double temp;
        temp =( array[i,0] + array[i, 1] + array[i, 1] + array[i, 2]) / 3; 
        a[i]= temp;
    }
    for(int i = 0; i < 8; i++)
    {
        Console.WriteLine(a[i]);
    }
}

void main()
{
    int cheic= Convert.ToInt32(Console.ReadLine());
    if (cheic == 1)
    {
        mmm();
    }
    if (cheic == 2)
    {
        mmm2();
    }

}