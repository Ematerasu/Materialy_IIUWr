using System;
using System.Collections.Generic;
using System.Text;

namespace Zadanie3
{
    class CEOHandler : Handler
    {
        private List<string> skrzynkaPrezesa = new List<string>();
        public override bool ProcessRequest(string msg)
        {
            if (msg.StartsWith("Pochwała"))
            {
                skrzynkaPrezesa.Add(msg);
                Console.WriteLine("Wiadomość pochwalna trafiła do Prezesa");
                return true;
            }
            return false;
        }
    }
}
