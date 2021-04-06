using System;

/*
 * 1. Creator
 * 2. Information expert
 * 3. Polymorphism
 * 4. Low coupling
 * 5. High cohesion
 */

    //Low coupling w całym programie, sprzężenie ograniczone do minimum, PolygonCreator wywołuje konstruktor klas dziedzicących z klasy Polygon, ale to wszystko.
namespace Zadanie1
{
    public abstract class Polygon
    {
        public abstract double CalculateArea();
    }

    //Information expert - Square, Triangle i Polygon mają informacje potrzebne do policzenia ich pól więc one wykonują te obliczenia
    //Polymorphism - Kazda klasa liczy pole w inny sposób więc każda klasa nadpisuje metode z klasy abstrakcyjnej i wykonuje swoje działanie.
    public class Square : Polygon
    {
        private double a;

        public Square(double a)
        {
            this.a = a;
        }

        public override double CalculateArea()
        {
            return a * a;
        }
    }

    public class Triangle : Polygon
    {
        private double a;

        public Triangle(double a)
        {
            this.a = a;
        }

        public override double CalculateArea()
        {
            return Math.Sqrt(3)*a*a/4;
        }
    }

    public class Pentagon : Polygon
    {
        private double a;

        public Pentagon(double a)
        {
            this.a = a;
        }

        public override double CalculateArea()
        {
            return Math.Sqrt(25+10*Math.Sqrt(5)) * a * a / 4;
        }
    }


    class PolygonCreator //Creator, tworzy instancje klasy Polygon, High cohesion - jak nazwa wskazuje PolygonCreator tworzy obiekty Polygon: jasny cel, zrozumiałe, łatwe w utrzymaniu
    {
        public Polygon CreatePolygon(string type, double a)
        {
            if(type.ToUpper() == "SQUARE")
            {
                return new Square(a);
            }
            else if(type.ToUpper() == "TRIANGLE")
            {
                return new Triangle(a);
            }
            else if (type.ToUpper() == "PENTAGON")
            {
                return new Pentagon(a);
            }

            return null;
        }
    }
        


    class Program
    {
        static void Main(string[] args)
        {
            PolygonCreator p = new PolygonCreator();
            Polygon test = p.CreatePolygon("Square", 3);
            Console.WriteLine(test.CalculateArea());
        }
    }
}
