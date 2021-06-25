using System;
using System.Collections.Generic;
using System.Text;

namespace Zadanie1
{
    class ReceiverImplementation
    {
        public void DownloadFileFTP(string from)
        {
            Console.WriteLine("Downloading FTP from " + from);
        }

        public void DownloadFileHTTP(string from)
        {
            Console.WriteLine("Downloading HTTP from " + from);
        }
        public void CreateFile(string path)
        {
            Console.WriteLine("Creating file in " + path);
        }
        public void CopyFile(string from, string to)
        {
            Console.WriteLine("Copying file from " + from + " to " + to);
        }
    }
}
