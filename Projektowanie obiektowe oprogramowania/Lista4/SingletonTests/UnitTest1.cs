using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Threading;
using Zadanie1;

namespace SingletonTests
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            Singleton s1, s2;

            s1 = Singleton.getInstance();
            s2 = Singleton.getInstance();

            Assert.AreSame(s1, s2);
            Assert.IsNotNull(s1);
        }

        [TestMethod]
        public void TestMethod2()
        {
            SingletonThread s1, s2;
            s1 = null;
            s2 = null;
            Thread t1, t2;

            t1 = new Thread(() =>
            {
                s1 = SingletonThread.getInstance();
            });

            t2 = new Thread(() =>
            {
                s2 = SingletonThread.getInstance();
            });

            t1.Start();
            t2.Start();
            t1.Join();
            t2.Join();

            Assert.AreNotSame(s1, s2);
            Assert.IsNotNull(s1);
            Assert.IsNotNull(s2);
        }

        [TestMethod]
        public void TestMethod3()
        {
            SingletonFiveSeconds s1, s2, s3;
            s1 = SingletonFiveSeconds.getInstance();
            s2 = SingletonFiveSeconds.getInstance();
            Thread.Sleep(6000);
            s3 = SingletonFiveSeconds.getInstance();

            Assert.AreNotSame(s1, s3);
            Assert.AreSame(s1, s2);
        }

    }
}
