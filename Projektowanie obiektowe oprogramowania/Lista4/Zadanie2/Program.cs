using System;
using System.Collections.Generic;

namespace Zadanie2
{
    public interface IShape
    {

    }

    public class Square : IShape
    { 
        public int a { get; set; }
    }
    public class Rectangle : IShape
    {
        public int a { get; set; }
        public int b { get; set; }
    }

    public interface IShapeFactoryWorker
    {
        bool Parameter(string name, params object[] parameters);
        IShape CreateShape(params object[] parameters);
    }

    public class SquareFactoryWorker : IShapeFactoryWorker
    {
        public bool Parameter(string name, params object[] parameters)
        {
            return name.Equals("Square") && parameters.Length == 1;
        }
        public IShape CreateShape(params object[] parameters)
        {
            IShape s = new Square() { a = (int)parameters[0] };
            return s;
        }
    }

    public class RectangleFactoryWorker : IShapeFactoryWorker
    {
        public bool Parameter(string name, params object[] parameters)
        {
            return name.Equals("Rectangle") && parameters.Length == 2;
        }
        public IShape CreateShape(params object[] parameters)
        {
            IShape s = new Rectangle() { a = (int)parameters[0], b = (int)parameters[1] };
            return s;
        }
    }

    public class ShapeFactory
    {
        private List<IShapeFactoryWorker> workers;

        public ShapeFactory()
        {
            workers = new List<IShapeFactoryWorker>();
        }
        public void RegisterWorker(IShapeFactoryWorker worker)
        {
            workers.Add(worker);
        }

        public IShape CreateShape(string ShapeName, params object[] parameters)
        {
            foreach(IShapeFactoryWorker w in workers)
            {
                if(w.Parameter(ShapeName, parameters))
                {
                    return w.CreateShape(parameters);
                }
            }
            return null;
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
