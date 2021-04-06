using Microsoft.VisualStudio.TestTools.UnitTesting;
using Zadanie2;

namespace ShapeFactoryTests
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            ShapeFactory f = new ShapeFactory();
            f.RegisterWorker(new SquareFactoryWorker());
            IShape s1 = f.CreateShape("Square", 5);
            IShape s2 = f.CreateShape("Square", 5, 4);

            Assert.IsNotNull(s1);
            Assert.IsNull(s2);
        }

        [TestMethod]
        public void TestMethod2()
        {
            ShapeFactory f = new ShapeFactory();
            f.RegisterWorker(new SquareFactoryWorker());
            f.RegisterWorker(new RectangleFactoryWorker());
            IShape s1 = f.CreateShape("Square", 5);
            IShape s2 = f.CreateShape("Rectangle", 5, 5);

            Assert.IsNotNull(s1);
            Assert.IsNotNull(s2);
            Assert.AreNotSame(s1, s2);
        }


    }
}
