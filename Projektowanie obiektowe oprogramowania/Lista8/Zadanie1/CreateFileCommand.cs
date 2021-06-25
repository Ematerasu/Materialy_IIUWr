using System;
using System.Collections.Generic;
using System.Text;

namespace Zadanie1
{
    class CreateFileCommand : ICommand
    {
        string path;
        private ReceiverImplementation receiver = new ReceiverImplementation();

        public CreateFileCommand(string path)
        {
            this.path = path;
        }

        public void Execute()
        {
            receiver.CreateFile(path);
        }
    }
}
