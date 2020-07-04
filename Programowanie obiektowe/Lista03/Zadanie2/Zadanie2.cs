using System;


namespace Zadanie2_1
{
    class Slownik<K,V> where K : IComparable //potrzebny do porownywania kluczy
    {
        K klucz;
        V wartosc;
        Slownik<K, V> elem;

        public void Add(K key, V value)
        {
            if(elem == null)
            {
                elem = new Slownik<K, V>();
                elem.klucz = key;
                elem.wartosc = value;
                Console.WriteLine("Dodano obiekt o kluczu " + key + " z wartoscia " + value);
                return;
            }
            else
            {
                if(key.CompareTo(elem.klucz) == 0)
                {
                    Console.WriteLine("Obiekt o takim kluczu znajduje sie juz w slowniku!");
                    return;
                }
                elem.Add(key, value);
            }
        }

        public void Delete(K key)
        { 
            if(elem != null)
            {
                if (key.CompareTo(elem.klucz) == 0)
                {
                    Console.WriteLine("Usunieto element o kluczu " + elem.klucz);
                    elem = elem.elem;
                    return;
                }
                
                elem.Delete(key);
            }
            else
            {
                Console.WriteLine("Obiekt o takim kluczu nie znajduje sie w slowniku");
            }
        
        }

        public void Search(K key)
        {
            if (elem != null)
            {
                if (key.CompareTo(elem.klucz) == 0)
                {
                    Console.WriteLine("Znaleziono element o kluczu " + elem.klucz + ", jego wartosc: " + elem.wartosc);
                    return;
                }

                elem.Search(key);
            }
            else
            {
                Console.WriteLine("Obiekt o takim kluczu nie znajduje sie w slowniku");
            }


        }

        public void Show()
        {
            if(elem != null)
            {
                Console.WriteLine("Obiekt o kluczu: " + elem.klucz + " ma wartosc " + elem.wartosc);
                elem.Show();
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Slownik<int, string> Dict = new Slownik<int, string>();

            Dict.Add(1, "Budzki");
            Console.WriteLine("Zawartosc slownika: ");
            Dict.Show();
            Dict.Delete(1);
            Dict.Add(2, "Dominik");
            Dict.Add(4, "II Uwr");
            Dict.Add(9, "abcd");
            Console.WriteLine("Zawartosc slownika: ");
            Dict.Show();
            Dict.Add(3, "Programowanie_obiektowe");
            Dict.Search(3);
        }
    }
}
