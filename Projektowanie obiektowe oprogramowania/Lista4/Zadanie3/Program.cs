using System;
using System.Collections.Generic;

namespace Zadanie3
{

    public class Plane
    {
        public void ResetPlane()
        {
            //tutaj powiedzmy po użyciu samolotu chcielibyśmy go przygotować do nastepnęgo lotu tzn. posprzątać w środku, zatankować itd.
        }
    }

    public class AirPort
    {
        private int capacity;
        private List<Plane> available = new List<Plane>();
        private List<Plane> released = new List<Plane>();

        public AirPort()
        {
            this.capacity = 10; //Zalozmy ze lotnisko ma limit 10 samolotow

        }

        public Plane AcquirePlane()
        {
            //Pierwsza kropka z zadania
            if(released.Count >= capacity)
            {
                throw new ArgumentException();
            }

            if (available.Count == 0)
            {
                available.Add(new Plane());
            }

            Plane p = available[0];
            available.Remove(p);
            released.Add(p);
            return p;
        }

        public void ReleaseReusable(Plane p)
        {
            if (!released.Contains(p))
            {
                throw new ArgumentException();
            }

            released.Remove(p);
            p.ResetPlane(); //Druga kropka z zadania
            available.Add(p);
        }
    }

    
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }
    }
}
