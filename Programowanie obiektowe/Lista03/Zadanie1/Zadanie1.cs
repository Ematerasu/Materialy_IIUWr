using System;

namespace Zadanie11
{
    class Element<T>
    {
        public T value;
        public Element<T> next;
        public Element<T> previous; //first.previous wskazuje na koniec listy

        public Element(T val)
        {
            value = val;
            next = null;
            previous = null;
        }

    }

    class Lista<T>
    {
        Element<T> first;

        public Lista()
        {
            first = null;
        }

        public bool isEmpty()
        {
            if (first == null)
                return true;
            else return false;
        }

        public void AddBegin(T val)
        {
            Element<T> new_one = new Element<T>(val);

            if(isEmpty())
            {
                first = new_one;
            }
            else if(first.next == null)
            {
                new_one.next = first;
                new_one.previous = first;
                first.previous = new_one;
                first = new_one;
            }
            else
            {
                new_one.next = first;
                new_one.previous = first.previous;
                first.previous = new_one;
                first = new_one;
            }
            Console.WriteLine("Dodano na poczatek listy element o wartosci: " + val);

        }

        public void AddEnd(T val)
        {
            Element<T> new_one = new Element<T>(val);

            if (isEmpty())
            {
                first = new_one;
            }
            else if (first.next == null)
            {
                first.next = new_one;
                first.previous = new_one;
                new_one.previous = first;
            }
            else
            {
                new_one.previous = first.previous; //ostatni element staje sie przedostatnim
                first.previous.next = new_one;  
                first.previous = new_one;   //new_one staje sie ostatnim
            }
            Console.WriteLine("Dodano na koniec listy element o wartosci: " + val);
        }

        public T DeleteBegin()
        {
            if(isEmpty())
            {
                throw new ArgumentException("Pusta lista, nie ma elementu który mozna usunac!");
            }
            else if(first.next == null)
            {
                T val = first.value;
                first = null;
                return val;
            }
            else
            {
                T val = first.value;
                first.next.previous = first.previous;   //drugi element dostaje wskaznik na ostatni
                first = first.next; //drugi element staje sie pierwszym
                return val;
            }
        }

        public T DeleteEnd()
        {
            if (isEmpty())
            {
                throw new ArgumentException("Pusta lista, nie ma elementu który mozna usunac!");
            }
            else if (first.next == null)
            {
                T val = first.value;
                first = null;
                return val;
            }
            else
            {
                T val = first.previous.value;
                first.previous.previous.next = null;    //usuwam element nastepny po przedostatnim, czyli ostatni
                first.previous = first.previous.previous;          //przedostatni staje sie ostatnim        
                return val;
            }
        }

        public void ShowList()
        {
            Element<T> temp;
            temp = first;
            Console.WriteLine("Zawartosc listy: ");

            while(temp != null)
            {
                Console.WriteLine(temp.value);
                temp = temp.next;
            }
        }

    }

    
    class Program
    {
        static void Main(string[] args)
        {
            Lista<int> list = new Lista<int>();

            list.AddBegin(5);
            list.AddBegin(4);
            list.AddEnd(6);
            list.AddBegin(3);
            Console.WriteLine("Usunieto element z konca listy o wartosci: " + list.DeleteEnd());
            list.AddBegin(2);
            list.AddBegin(151);
            Console.WriteLine("Usunieto element z poczatku listy o wartosci: " + list.DeleteBegin());
            list.ShowList();

        }
    }
}
