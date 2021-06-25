using System;
using Zadanie2;
namespace Zadanie3
{
    class ShapeFactoryProxyProtect
    {
        private ShapeFactory sf;
        private int open = 8;
        private int closed = 22;

        public ShapeFactoryProxyProtect()
        {
            sf = new ShapeFactory();
        }

        public void RegisterWorker(IShapeFactoryWorker worker)
        {
            DateTime t = DateTime.Now;
            if (t.Hour > open && t.Hour < closed)
                sf.RegisterWorker(worker);
            else throw new UnauthorizedAccessException("Factory is closed!");
        }

        public IShape CreateShape(string ShapeName, params object[] parameters)
        {
            DateTime t = DateTime.Now;
            if (t.Hour > open && t.Hour < closed)
                return sf.CreateShape(ShapeName, parameters);
            else throw new UnauthorizedAccessException("Factory is closed!");
        }

    }

    //Zalozmy ze dostep do klasy posiada tylko osoba z uprawnieniami conajmniej administratora
    public abstract class User
    {
        private string position;
        public string getPosition();
    }
    class ShapeFactoryProxyLogging
    {
        private ShapeFactory sf;

        //Zalozmy ze tu jest program sprawdzajacy czy dana pozycja w firmie ma pozwolenie na uzywanie tego obiektu,
        //nie jest chyba wymagane w tym zadaniu wiec zostawie to tak jako tylko pomoc
        private bool DoesHavePermission(String s)
        {
            return true;
        }

        public ShapeFactoryProxyLogging(User u)
        {
            if(DoesHavePermission(u.getPosition()))
                sf = new ShapeFactory();
            else throw new UnauthorizedAccessException("Access denied! You dont have permission!");
        }

        public void RegisterWorker(IShapeFactoryWorker worker)
        {
            DateTime t = DateTime.Now;
            sf.RegisterWorker(worker);
        }

        public IShape CreateShape(string ShapeName, params object[] parameters)
        {
            DateTime t = DateTime.Now;
            return sf.CreateShape(ShapeName, parameters);
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
