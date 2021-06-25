using System;
using System.Collections.Generic;
using System.Text;

namespace Zadanie4
{
    public class Context
    {
        public State state;
        
        public Context(State beginstate)
        {
            this.state = beginstate;
            this.state.context = this;
        }

        public void Execute()
        {
            this.state.Handle();
        }
    }
}
