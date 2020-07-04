using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zadanie1
{
    public class IntStream
    {
        public int liczba;

        public IntStream()
        {
            liczba = 0;
        }

        virtual public int next()
        {
            if(eos())
            {
                Console.WriteLine("Przekroczony zakres!\n");
                return liczba;
            }
            else
            {   
                return liczba++;
            }
        }
        virtual public bool eos()
        {
            if (Int64.MaxValue < liczba)
            {
                return true;
            }
            else return false;
        }

        virtual public void reset()
        {
            liczba = 0;
        }

    }

    public class PrimeStream: IntStream
    {
        public PrimeStream()
        {
            liczba = 1;
        }

        private bool CzyPierwsza(int x)
        {
            for(int i=2;i*i<=x;i++)
            {
                if (x % i == 0) return false;
            }
            return true;
        }

        public override int next()
        {
            if (eos())
            {
                Console.WriteLine("Przekroczony zakres!");
            }
            else liczba++;

            while(CzyPierwsza(liczba) == false)
            {
                if(eos())
                {
                    Console.WriteLine("Przekroczony zakres!");
                    break;
                }
                else
                {
                    liczba++;
                }
            }
            return liczba;

        }

        public override void reset()
        {
            liczba = 1;
        }

    }

    public class RandomStream : IntStream
    {
        private Random liczba_losowa;
        public RandomStream()   
        {
            liczba_losowa = new Random();
        }

        public override int next()
        {
            return liczba_losowa.Next();
        }

        public override bool eos()
        {
            return false;
        }
    }

    public class RandomWordStream
    {
        PrimeStream liczba_pierwsza;
        RandomStream liczba_losowa;

        public RandomWordStream()
        {
            liczba_pierwsza = new PrimeStream();
            liczba_losowa = new RandomStream();
        }
        
        private char RandomChar()
        {
            int znak = liczba_losowa.next() % 26;
            return (char)('a' + znak);
        }

        public string next()
        {
            int prime_number = liczba_pierwsza.next();

            string nastepny_napis = "";

            for(int i=0;i<prime_number;i++)
            {
                nastepny_napis+=RandomChar();
            }
            return nastepny_napis;
        }

    }


    class Program
    {
        static void Main(string[] args)
        {
            IntStream liczba = new IntStream();
            PrimeStream liczba_pierwsza = new PrimeStream();
            RandomStream losowa_liczba = new RandomStream();
            RandomWordStream losowy_napis = new RandomWordStream();

            int ilosc_stringow = 8;


            for(int i=0;i<ilosc_stringow;i++)
            {
                Console.WriteLine("{0}  Liczba znakow: {1}",losowy_napis.next(), liczba_pierwsza.next());
            }


        }
    }
}
