using System;
using System.Collections.Generic;
using System.Text;

namespace Zadanie4
{
    class PrintState : State
    {
        public string money;

        public override void Handle()
        {
            Console.WriteLine("POTWIERDZENIE");
            Console.WriteLine("Wyplacono " + money + "zl");

            this.context.state = new ReleaseCardState() { context = context };
        }
    }
}
