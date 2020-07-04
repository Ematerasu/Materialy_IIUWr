using System;
using System.Collections;               
using System.Collections.Generic;

namespace Zadanie1
{
    interface Numbers
    {
        int next();
        bool eos();
        void reset();
    }


    public class IntStream : Numbers
    {
        public int liczba;

        public IntStream()
        {
            liczba = 0;
        }

        public int next()
        {
            if (eos())
            {
                Console.WriteLine("Przekroczony zakres!\n");
                return liczba;
            }
            else
            {
                return liczba++;
            }
        }
        public bool eos()
        {
            if (int.MaxValue < liczba)
            {
                return true;
            }
            else return false;
        }

        public void reset()
        {
            liczba = 0;
        }

    }

    class PrimeStream : Numbers, IEnumerable
    {
        public int liczba;
        List<int> Liczby_pierwsze;
        int indeks;

        public PrimeStream()
        {
            liczba = 1;
            Liczby_pierwsze = new List<int>();
            indeks = 0;
        }

        private bool CzyPierwsza(int x)
        {
            if (x < 2) return false;
            for (int i = 2; i * i <= x; i++)
            {
                if (x % i == 0) return false;
            }
            return true;
        }

        public int next()
        {
            if (eos())
            {
                Console.WriteLine("Przekroczony zakres!");
            }
            else liczba++;

            while (CzyPierwsza(liczba) == false)
            {
                if (eos())
                {
                    Console.WriteLine("Przekroczony zakres!");
                    break;
                }
                else
                {
                    liczba++;
                }
            }
            Liczby_pierwsze.Add(liczba);
            indeks++;
            return liczba;

        }

        public bool eos()
        {
            if (int.MaxValue < liczba)
            {
                return true;
            }
            else return false;
        }

        public void reset()
        {
            liczba = 1;
            Liczby_pierwsze.Clear();
            indeks=0;
        }

        public int this[int index]
        {
            get
            {
                return Liczby_pierwsze[index];
            }

            set
            {
                Liczby_pierwsze[index] = value;
            }
        }

        public override string ToString()
        {
            if (indeks > 0) return Liczby_pierwsze[indeks].ToString();
            else return null;
        }

        public int Length()
        {
            return Liczby_pierwsze.Count;
        }

        public IEnumerator GetEnumerator()
        {
            return new PrimeStreamEnumerator(Liczby_pierwsze);
        }

        private IEnumerator GetEnumerator1()
        {
            return this.GetEnumerator();
        }
        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator1();
        }
    }

    public class PrimeStreamEnumerator : IEnumerator
    {
        public int pozycja;
        List<int> Liczby;

        public PrimeStreamEnumerator(List<int> orig)
        {
            Liczby = orig;
            pozycja = -1;
        }

        public int Current
        {
            get
            {
                return Liczby[pozycja];
            }
        }

        public bool MoveNext()
        {
            pozycja++;
            if (pozycja < Liczby.Count) return true;
            else return false;
        }

        public void Reset()
        {
            pozycja = -1;
        }

        object IEnumerator.Current
        {
            get
            {
                return Liczby[pozycja];
            }
        }
        
    }

    class Program
    {

        static void Main(string[] args)
        {
            PrimeStream Pierwsz = new PrimeStream();


            for(int i = 0;i<20;i++)
                Console.WriteLine(Pierwsz.next());

            int temp = Pierwsz[0];



            Console.WriteLine(temp);
               

            Console.WriteLine("\nTest indeksowania:");
            Console.WriteLine("Pierwsz[0] = " + Pierwsz[0].ToString());
            Console.WriteLine("Pierwsz[10] = " + Pierwsz[10]);
            Console.WriteLine("Pierwsz[19] = " + Pierwsz[18]);
            Console.WriteLine("Pierwsz[20] = " + Pierwsz[19]);
           
            foreach(int p in Pierwsz)
            {
                Console.WriteLine(p);
            }
            Console.WriteLine(Pierwsz.Length());


        }
    }
}
