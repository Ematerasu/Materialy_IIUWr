using System;
using System.Collections.Generic;
using System.Text;

namespace Zadanie1
{
    class CopyFileCommand : ICommand
    {
        string from, to;
        private ReceiverImplementation receiver = new ReceiverImplementation();

        public CopyFileCommand(string from, string to)
        {
            this.from = from;
            this.to = to;
        }

        public void Execute()
        {
            receiver.CopyFile(from, to);
        }
    }
}
