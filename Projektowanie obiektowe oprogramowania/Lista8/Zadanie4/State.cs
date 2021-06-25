using System;
using System.Collections.Generic;
using System.Text;

namespace Zadanie4
{
    public abstract class State
    {
        public Context context;
        public abstract void Handle();
    }
}
