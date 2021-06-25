using System;
using System.Collections.Generic;
using System.Text;

namespace Zadanie3
{
    class MarketingHandler : Handler
    {
        private List<string> skrzynkaMarketingu = new List<string>();
        public override bool ProcessRequest(string msg)
        {
            skrzynkaMarketingu.Add(msg);
            Console.WriteLine("Wiadomość trafiła do działu marketingu");
            return true;
        }
    }
}
