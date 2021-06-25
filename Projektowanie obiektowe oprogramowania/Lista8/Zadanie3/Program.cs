using System;

namespace Zadanie3
{
    class Program
    {
        static void Main(string[] args)
        {
            DataAccessHandler xmlHandler = new XML_DataAccessHandler();
            xmlHandler.Execute();
        }
    }
}
