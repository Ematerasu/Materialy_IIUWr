using System;
using System.Collections.Generic;
using System.Text;

namespace Zadanie4
{
    class WaitState : State
    {
        public override void Handle()
        {
            Console.WriteLine("Wprowadz karte (psst napisz karta)");
            string input;
            while(!(input = Console.ReadLine()).Equals("karta"))
            {
                Console.WriteLine("Blad wczytywania karty");
                Console.WriteLine("Sprobuj jeszcze raz");
            }

            this.context.state = new ValidationState() { context = context };
        }
    }
}
