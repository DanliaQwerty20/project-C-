using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Runtime.ConstrainedExecution;
using System.Text;
using System.Threading.Tasks;

namespace LabaFirstCS
{
    public class Movie
    {
        public String MovieName ;
        public String Genre { get; set; }

        

        public String FFF
        {
            get
            {
                return MovieName;
            }
            set
            {
                MovieName = value;
            }
        }
        
  
        public Movie(String movieName, String genre)
        {
            this.MovieName = movieName;
            this.Genre = genre;
        }

        public override string ToString()
        {
            return this.MovieName + " - " + this.Genre;
        }
    }
    public class Class1
    {

        static void mmm()
        {
            Console.WriteLine("Задание #1");
            Console.WriteLine("Введите длину массива");
            int len = Convert.ToInt32(Console.ReadLine());
            int[] a = new int[len];

            for (int i = 0; i < len; i++)
            {
                a[i] = Convert.ToInt32(Console.ReadLine());
            }
            
            for (int i = 0; i < len; i++)
            {
                if (a[i] > 0)
                {
                    a[i] = 0;
                }
            }
            for(int i = 0; i < len; i++)
            {
                Console.WriteLine(a[i]);
            }
            
        }
        static void mmm3()
        {
            List<Movie> movies = new List<Movie>();

            

            movies.Add(new Movie("ЯЯЯ", "комедия"));
            movies.Add(new Movie("ЙЙЙ", "ужастик"));
            movies.Add(new Movie("ААА", "триллер"));
            movies.Add(new Movie("ФФФ", "комедия"));

            movies.ForEach(x => Console.WriteLine(x.ToString()));
            Console.WriteLine("\n\n");
            List<Movie> list = movies.FindAll(x => x.Genre == "комедия");
         
            list.ForEach(x => Console.WriteLine(x.ToString()));

            list.RemoveAll(x => x.Genre == "триллер");// вызываем гетер жанра
            list.Remove(new Movie("ААА", "триллер"));
            
        }
        static void mmm2()
        {

            int[,] nums2 = new int[5, 4];
            Random random = new Random();
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    nums2[i, j] = random.Next(-10, 10);
                }

            }
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    Console.Write(nums2[i, j] + " ");
                }
                Console.Write("\n");
            }
            
            int min = nums2[0,0];
            int mini = 0;
            int minj = 0;
            for (int i = 0; i < 5; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    if (min > nums2[i, j])
                    {
                        min = nums2[i, j];
                        mini = i;
                        minj = j;
                    }
                } 
            }
            for (int i = mini; i < 5; i++)
            {
                for (int j = minj; j < 4; j++)
                {    
                    nums2[i, j] = 0;
                    
                }
            }
            bool flag = false;
            for (int i = mini; i < 5; i++)
            {
                for (int j = minj; j < 4; j++)
                {

                    if (nums2[i, j] == 0 && flag==false)
                    {
                        nums2[i, j] = min;
                        flag = true;
                    }

                }
            }
            Console.WriteLine("\n\n\n");
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    Console.Write(nums2[i, j] + " ");
                }
                Console.Write("\n");
            }
        }

        #region Main
        static void Main()
        {
            Console.WriteLine("Выберите номер задачи\n");
            int cheic = Convert.ToInt32(Console.ReadLine());
            
            if (cheic == 1)
            {
                mmm();
            }
            if (cheic == 2)
            {
                mmm2();
            }
            if (cheic == 3)
            {
                mmm3();
            }
        }
        #endregion


    }

}