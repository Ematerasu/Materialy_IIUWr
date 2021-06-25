using System;
using System.Collections.Generic;
using System.Reflection;

/*
 * Wykonane w parze z Kacper Kingsford
 *  
 */

namespace DI
{
    public class SimpleContainer
    {

        private interface ICreator
        {
            object Create();
        }

        private class SingletonCreator : ICreator
        {
            object instance;
            ConstructorInfo constructor;

            public SingletonCreator(ConstructorInfo constructor)
            {
                this.constructor = constructor;
            }

            public object Create()
            {
                if (instance == null)
                {
                    instance = constructor.Invoke(new object[] { });
                }
                return instance;
            }
        }

        private class NonSingletonCreator : ICreator
        {
            ConstructorInfo constructor;

            public NonSingletonCreator(ConstructorInfo constructor)
            {
                this.constructor = constructor;
            }

            public object Create()
            {
                return constructor.Invoke(new object[] { });
            }
        }

        //Lista 10
        private class InstanceCreator : ICreator
        {
            object instance;

            public InstanceCreator(object instance)
            {
                this.instance = instance;
            }

            public object Create()
            {
                return instance;
            }
        }
        //

        private Dictionary<Type, ICreator> creators;

        public SimpleContainer()
        {
            creators = new Dictionary<Type, ICreator>();
        }

        public void RegisterType<T>(bool singleton) where T : class
        {
            if (singleton)
            {
                creators[typeof(T)] = new SingletonCreator(typeof(T).GetConstructor(new Type[] { }));
            }
            else
            {
                creators[typeof(T)] = new NonSingletonCreator(typeof(T).GetConstructor(new Type[] { }));
            }
        }
        public void RegisterType<From, To>(bool singleton) where To : From
        {
            if (singleton)
            {
                creators[typeof(From)] = new SingletonCreator(typeof(To).GetConstructor(new Type[] { }));
            }
            else
            {
                creators[typeof(From)] = new NonSingletonCreator(typeof(To).GetConstructor(new Type[] { }));
            }
        }

        //Lista 10
        public void RegisterInstance<T>(T instance) where T : class
        {
            creators[typeof(T)] = new InstanceCreator(instance);
        }
        //
        public T Resolve<T>() where T : class
        {
            var creatorType = typeof(T);
            ICreator creator;

            if (!creators.TryGetValue(creatorType, out creator))
            {
                // Uwaga 1
                if (creatorType.IsAbstract || creatorType.IsInterface)
                {
                    Console.WriteLine("Not registered " + (creatorType.IsAbstract ? "abstract" : "interface") + " " + creatorType.ToString());
                    throw new InvalidOperationException();
                }

                //Uwaga 2
                RegisterType<T>(false);
                return Resolve<T>();

            }

            return (T)creator.Create();
        }
    }
    class Program
    {
        static void Main(string[] args)
        {

        }
    }
}
