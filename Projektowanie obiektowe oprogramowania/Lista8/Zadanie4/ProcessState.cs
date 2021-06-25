using System;
using System.Collections.Generic;
using System.Text;

namespace Zadanie4
{
    class ProcessState : State
    {
        public override void Handle()
        {
            Console.WriteLine("Wprowadz kwote ktora chcesz wyplacic");
            string input = Console.ReadLine();
            Console.WriteLine("Wyplacam " + input + "zl");

            this.context.state = new PrintState() { context = context, money = input };
        }
    }
}
