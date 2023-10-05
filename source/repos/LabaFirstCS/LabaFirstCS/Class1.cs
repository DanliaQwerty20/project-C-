using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LabaFirstCS
{
    class Class1
    {

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
            int[,] nums2 = new int[8,3];
            Random random= new Random();    
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    nums2[i,j] = random.Next(-10,10);
                }

            }
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    Console.Write(nums2[i,j]+" ");
                }
                Console.Write("\n");
            }
            double[] a = new double[8];
            for (int i = 0; i < 8; i++)
            {
                double temp;
                temp = (nums2[i,0] + nums2[i, 1] + nums2[i, 1] + nums2[i, 2]) / 3;
                a[i] = temp;
            }
            for (int i = 0; i < 8; i++)
            {
                Console.WriteLine(a[i]);
            }
        }

        void main()
        {
            int cheic = Convert.ToInt32(Console.ReadLine());
            if (cheic == 1)
            {
                mmm();
            }
            if (cheic == 2)
            {
                mmm2();
            }
        }
    }
}
