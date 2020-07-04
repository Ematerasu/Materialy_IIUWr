using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zadanie2
{
    class ListaLeniwa
    {
        public int rozmiar_listy;
        List<int> Lista;
        Random losowa_liczba;

        public ListaLeniwa()
        {
            rozmiar_listy = 0;
            Lista = new List<int>();
            losowa_liczba = new Random();
        }
        virtual public int element (int i)
        {
            if(i>rozmiar_listy)
            {
                int dopelnienie = i - rozmiar_listy;
                Zwiekszanie_listy(dopelnienie);
                rozmiar_listy = i;
            }

            return Lista[i - 1];
        }

        public void Zwiekszanie_listy(int ilosc)
        {
            while(ilosc>0)
            {
                Lista.Add(losowa_liczba.Next(int.MinValue, int.MaxValue));
                ilosc--;
            }
        }

        virtual public int size()
        {
            return rozmiar_listy;
        }
    }

    class Pierwsze : ListaLeniwa
    {
        int liczba;
        List<int> lista_pierwszych;

        public Pierwsze()
        {
            lista_pierwszych = new List<int>();
            liczba = 1;
        }

        private bool CzyPierwsza(int liczba)
        {
            for(int i=2;i*i<liczba;i++)
            { 
                if(liczba%i==0)
                {
                    return false;
                }
            }
            return true;
        }

        override public int element(int i)
        {
            if(i > rozmiar_listy)
            {
                int dopelnienie = i - rozmiar_listy;
                Zwiekszanie_listy_pierwszych(dopelnienie);
                rozmiar_listy = i;
            }
            return lista_pierwszych[i - 1];
        }

        void Zwiekszanie_listy_pierwszych(int ilosc)
        {
            while (ilosc > 0)
            {
                if(CzyPierwsza(liczba))
                {
                    lista_pierwszych.Add(liczba);
                    ilosc--;
                }
                liczba++;
            }
        }

        public override int size()
        {
            return rozmiar_listy;
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            Pierwsze test = new Pierwsze();

            Console.WriteLine("Rozmiar listy: {0}\n", test.size());
            Console.WriteLine("Element o indeksie 3: {0}", test.element(3));
            Console.WriteLine("Rozmiar listy: {0}\n", test.size());
            Console.WriteLine("Element o indeksie 40: {0}", test.element(40));
            Console.WriteLine("Rozmiar listy: {0}\n",test.size());
            Console.WriteLine("Element o indeksie 38: {0}", test.element(38));
            Console.WriteLine("Rozmiar listy: {0}\n", test.size());
            Console.WriteLine("Element o indeksie 3: {0}",test.element(3));
            Console.WriteLine("Rozmiar listy: {0}\n", test.size());
            Console.WriteLine("Element o indeksie 51: {0}", test.element(51));
            Console.WriteLine("Rozmiar listy: {0}\n", test.size());


        }
    }
}
