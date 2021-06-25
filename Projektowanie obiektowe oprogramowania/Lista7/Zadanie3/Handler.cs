using System;
using System.Collections.Generic;
using System.Text;

namespace Zadanie3
{
    abstract class Handler
    {
        protected Handler next;

        public abstract bool ProcessRequest(string msg);

        public Handler SetNext(Handler h)
        {
            Handler lastHandler = this;

            while (lastHandler.next != null)
            {
                lastHandler = lastHandler.next;
            }

            lastHandler.next = h;
            return this;
        }

        public void Chain(string msg)
        {
            Handler archive = new ArchivesHandler();
            archive.ProcessRequest(msg);
            Handler curr = this;

            while(curr != null && !curr.ProcessRequest(msg))
            {
                curr = curr.next;
            }
        }
    }
}
