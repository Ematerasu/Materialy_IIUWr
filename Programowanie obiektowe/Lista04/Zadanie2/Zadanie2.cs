using System;
using System.Collections;
using System.Collections.Generic;

namespace Zadanie2
{
    class PrimeCollection: IEnumerable<int>, IEnumerator<int>
    {
        int liczba;

        public PrimeCollection()
        {
            liczba = 2;
        }
        private bool IsPrime(int licz)
        {
            if (licz < 2) return false;
            for(int i = 2;i<licz;i++)
            {
                if (licz % i == 0) return false;
            }
            return true;
        }

        public int Current
        {
            get
            {
                return liczba;
            }
        }

        public IEnumerator<int> GetEnumerator()
        {
            return this;
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return this;
        }

        object IEnumerator.Current
        {
            get
            {
                return liczba;
            }
        }
        public bool MoveNext()
        {
            liczba++;
            while (!IsPrime(liczba)) liczba++;
            return liczba < int.MaxValue;
        }

        public void Dispose() //Bez tej funkcji nie kompilowalo sie mimo ze jej nie potrzebuje, zostawilem ja tak jak jest bo nie rozumialem jej dzialania czytajac o niej w internecie
        {
        }

        public void Reset()
        {
            liczba = 2;
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            PrimeCollection pc = new PrimeCollection();

            foreach (int p in pc) Console.WriteLine(p);

        }

    }
}
