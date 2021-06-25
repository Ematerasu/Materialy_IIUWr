using System;

namespace Zadanie4
{
    class Program
    {
        static void Main(string[] args)
        {
            Context Bankomat = new Context(new WaitState());
            while(Bankomat.state != null)
            {
                Bankomat.Execute();
            }
        }
    }
}
