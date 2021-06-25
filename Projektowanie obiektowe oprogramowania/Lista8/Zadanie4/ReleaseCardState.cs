using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace Zadanie4
{
    class ReleaseCardState : State
    {
        public override void Handle()
        {
            Console.WriteLine("Wydawanie karty...");
            Thread.Sleep(1000);
            Console.WriteLine("Wydawanie karty...");
            Thread.Sleep(1000);
            Console.WriteLine("Karta wydana");

            this.context.state = new EndState() { context = context };
        }
    }
}
