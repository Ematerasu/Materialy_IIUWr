using System;
using System.Collections.Generic;
using System.Text;

namespace Zadanie1
{
    class DownloadHTTPCommand : ICommand
    {
        string address;
        private ReceiverImplementation receiver = new ReceiverImplementation();

        public DownloadHTTPCommand(string address)
        {
            this.address = address;
        }

        public void Execute()
        {
            receiver.DownloadFileHTTP(address);
        }
    }
}
