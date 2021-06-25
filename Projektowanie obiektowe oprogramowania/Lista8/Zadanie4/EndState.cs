using System;
using System.Collections.Generic;
using System.Text;

namespace Zadanie4
{
    class EndState : State
    {
        public override void Handle()
        {
            Console.WriteLine("Dziekuje za skorzystanie z mojego bankomatu :)");
            this.context.state = null;
        }
    }
}
