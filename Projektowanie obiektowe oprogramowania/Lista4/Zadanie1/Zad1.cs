using System;
using System.Threading;
namespace Zadanie1
{
    // a)
    public class Singleton
    {
        private static Singleton instance;

        private Singleton()
        {
            //cos
        }

        public static Singleton getInstance()
        {
            if(instance == null)
            {
                instance = new Singleton();
            }

            return instance;
        }
    }

    // b)
    public class SingletonThread
    {
        private static ThreadLocal<SingletonThread> instances = new ThreadLocal<SingletonThread>();
        private SingletonThread()
        {
            //cos
        }

        public static SingletonThread getInstance()
        {
            if (!instances.IsValueCreated)
            {
                instances.Value = new SingletonThread();
            }

            return instances.Value;
        }
    }

    // c)
    public class SingletonFiveSeconds
    {
        private static SingletonFiveSeconds instance;
        private static DateTime timer;
        private SingletonFiveSeconds()
        {
            // cos
        }

        public static SingletonFiveSeconds getInstance()
        {
            if(instance == null)
            {
                instance = new SingletonFiveSeconds();
                timer = DateTime.Now;
            }
            else if((DateTime.Now - timer).Seconds > 5)
            {
                instance = new SingletonFiveSeconds();
                timer = DateTime.Now;
            }
            return instance;
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
