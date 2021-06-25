using System;
using System.Collections.Generic;
using System.Text;

namespace Zadanie4
{
    class ValidationState : State
    {
        public override void Handle()
        {
            Console.WriteLine("Wprowadz PIN (...psst 1234)");
            string input;
            while (!(input = Console.ReadLine()).Equals("1234"))
            {
                Console.WriteLine("PIN niepoprawny");
                Console.WriteLine("Sprobuj jeszcze raz");
            }

            this.context.state = new ProcessState() { context = context };
        }
    }
}
