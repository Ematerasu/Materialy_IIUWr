using System;
using System.Collections.Generic;
using System.Text;

namespace Zadanie3
{
    class LawDepHandler : Handler
    {
        private List<string> skrzynkaPrawna = new List<string>();
        public override bool ProcessRequest(string msg)
        {
            if (msg.StartsWith("Skarga"))
            {
                skrzynkaPrawna.Add(msg);
                Console.WriteLine("Skarga trafiła do działu prawnego");
                return true;
            }
            return false;
        }
    }
}
