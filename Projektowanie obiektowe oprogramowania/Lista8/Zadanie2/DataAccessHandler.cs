using System;
using System.Collections.Generic;
using System.Text;

namespace Zadanie2
{
    public abstract class DataAccessHandler
    {
        public abstract void ConnectData();
        public abstract void DownloadData();
        public abstract void ProcessData();
        public abstract void CloseConnect();

        public void Execute()
        {
            ConnectData();
            DownloadData();
            ProcessData();
            CloseConnect();
        }
    }
}
