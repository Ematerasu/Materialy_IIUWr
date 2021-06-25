using System;
using System.Collections.Generic;
using System.Text;
using Zadanie3;

namespace Zadanie2
{
    public abstract class DataAccessHandler
    {
        DataAccessHandlerStrategy strategy;

        public DataAccessHandler(DataAccessHandlerStrategy strategy)
        {
            this.strategy = strategy;
        }
        public void Execute()
        {
            strategy.ConnectData();
            strategy.DownloadData();
            strategy.ProcessData();
            strategy.CloseConnect();
        }
    }
}
