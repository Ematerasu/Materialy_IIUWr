using System;
using System.Collections.Generic;
using System.Text;

namespace Zadanie1
{
    class DownloadFTPCommand : ICommand
    {
        string address;
        private ReceiverImplementation receiver = new ReceiverImplementation();

        public DownloadFTPCommand(string address)
        {
            this.address = address;
        }

        public void Execute()
        {
            receiver.DownloadFileFTP(address);
        }
    }
}
