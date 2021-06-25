using System;
using System.Collections.Generic;
using System.Text;

namespace Zadanie3
{
    class ShopHandler : Handler
    {
        private List<string> skrzynkaSklepu = new List<string>();
        public override bool ProcessRequest(string msg)
        {
            if (msg.StartsWith("Zamówienie"))
            {
                skrzynkaSklepu.Add(msg);
                Console.WriteLine("Zamówienie dotarło do działu handlowego");
                return true;
            }
            return false;
        }
    }
}
