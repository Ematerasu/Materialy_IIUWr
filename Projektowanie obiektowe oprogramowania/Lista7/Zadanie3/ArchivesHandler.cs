using System;
using System.Collections.Generic;
using System.Text;

namespace Zadanie3
{
    class ArchivesHandler : Handler
    {
        private List<string> archives = new List<string>();

        public override bool ProcessRequest(string msg)
        {
            archives.Add(msg);
            Console.WriteLine("Wiadomosc dodana do archiwum. Treść: " + msg.Substring(0, 10) + "...");
            return true;
        }
    }
}
