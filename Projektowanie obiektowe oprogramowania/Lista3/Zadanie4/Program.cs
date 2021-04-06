using System;

//Nalezy stworzyc interfejs/klase abstrakcyjna np. Polygon, wtedy klasy rectangle i square będą dziedziczyć z Polygon metodę Area(). LSP zostanie zachowane.

namespace Zadanie4
{

    public abstract class Polygon
    {
        public abstract int Area();
    }

    public class Rectangle : Polygon
    {
        public int Height { get; set; }
        public int Width { get; set; }

        public override int Area()
        {
            return Height * Width;
        }
    }

    public class Square : Polygon
    {
        public int Side { get; set; }
        public override int Area()
        {
            return Side * Side;
        }
    }

    public class AreaCalculator
    {
        public int CalculateArea(Polygon p)
        {
            return p.Area();
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            int w = 4, h = 5;
            Rectangle rect = new Rectangle() { Width = w, Height = h };
            AreaCalculator calc = new AreaCalculator();
            Console.WriteLine("prostokat o wymiarach {0} na {1} ma pole {2}", w, h, calc.CalculateArea(rect));
            Square squa = new Square() { Side = w };
            Console.WriteLine("kwadrat o wymiarach {0} na {1} ma pole {2}", w, w, calc.CalculateArea(squa));
        }
    }
}
