using NUnit.Framework;
using DI;
using System;

namespace DITests
{
    public class Tests
    {
        [SetUp]
        public void Setup()
        {
        }
        public interface IFoo
        {

        }
        public class Foo : IFoo
        {

        }

        public class Bar : IFoo
        {

        }

        public abstract class AbstractQux
        {

        }

        public class Qux : AbstractQux
        {

        }


        [Test]
        public void TestOfSingleton()
        {
            SimpleContainer c = new SimpleContainer();
            c.RegisterType<Foo>(true);
            Foo f1 = c.Resolve<Foo>();
            Foo f2 = c.Resolve<Foo>();
            Assert.AreEqual(f1, f2);
        }

        [Test]
        public void TestDifferentInstance()
        {
            SimpleContainer c = new SimpleContainer();
            c.RegisterType<IFoo, Foo>(false);
            IFoo f = c.Resolve<IFoo>();
            // f ma typ Foo
            c.RegisterType<IFoo, Bar>(false);
            IFoo g = c.Resolve<IFoo>();
            // g ma typ Bar
            Assert.IsInstanceOf(typeof(Foo), f);
            Assert.IsInstanceOf(typeof(Bar), g);
        }

        [Test]
        public void TestException()
        {
            SimpleContainer c = new SimpleContainer();
            Assert.Throws<InvalidOperationException>(
                () => c.Resolve<IFoo>()
            );
            
        }

        [Test]
        public void TestNotRegistered()
        {
            SimpleContainer c = new SimpleContainer();
            IFoo g = c.Resolve<Bar>();
         
            Assert.IsInstanceOf(typeof(Bar), g);
        }
        
        [Test]
        public void TestSameTypeDiffInstance()
        {
            SimpleContainer c = new SimpleContainer();
            c.RegisterType<Foo>(false);
            Foo f1 = c.Resolve<Foo>();
            Foo f2 = c.Resolve<Foo>();
            Assert.AreNotEqual(f1, f2);
        }

        [Test] // Lista 10
        public void TestRegisterInstance()
        {
            SimpleContainer c = new SimpleContainer();
            IFoo foo1 = new Foo();
            c.RegisterInstance<IFoo>(foo1);
            IFoo foo2 = c.Resolve<IFoo>();
            Assert.AreEqual(foo1, foo2);
        }
    }
}