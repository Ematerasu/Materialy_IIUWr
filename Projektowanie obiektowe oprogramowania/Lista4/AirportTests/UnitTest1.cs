using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using Zadanie3;

namespace AirportTests
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void AcquireWorking()
        {
            AirPort a = new AirPort();
            Plane p = a.AcquirePlane();
            Assert.IsNotNull(p);
        }

        [TestMethod]
        public void CapacityWorking()
        {
            AirPort a = new AirPort();
            List<Plane> planes = new List<Plane>();
            for(int i = 0; i < 10; i++)
            {
                planes.Add(a.AcquirePlane());
            }

            for (int i = 0; i < 10; i++)
            {
                Assert.IsNotNull(planes[i]);
            }

            Assert.ThrowsException<ArgumentException>(() =>
            {
                Plane temp = a.AcquirePlane();
            });

        }

        [TestMethod]
        public void ReleaseWorking()
        {
            AirPort a = new AirPort();
            Plane p = a.AcquirePlane();
            Assert.IsNotNull(p);

            Assert.ThrowsException<ArgumentException>(() =>
            {
                a.ReleaseReusable(new Plane());
            });
        }



    }
}
