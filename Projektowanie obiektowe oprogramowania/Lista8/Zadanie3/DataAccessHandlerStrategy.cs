using System;
using System.Collections.Generic;
using System.Text;

namespace Zadanie3
{
    public abstract class DataAccessHandlerStrategy
    {
        public abstract void ConnectData();
        public abstract void DownloadData();
        public abstract void ProcessData();
        public abstract void CloseConnect();
    }
}
