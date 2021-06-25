using System;
using System.Collections;
using System.Runtime.InteropServices;

namespace Zadanie4
{

    public class ComparerAdapter : IComparer
    {
        Func<int, int, int> comparer;

        public ComparerAdapter(Func<int, int, int> comparer)
        {
            this.comparer = comparer;
        }

        public int Compare(object a, object b) { return comparer((int)a, (int)b); }
    }
    class Program
    {
        /* this is the Comparison<int> to be converted */
        static int IntComparer(int x, int y)
        {
            return x.CompareTo(y);
        }

        static void Main(string[] args)
        {
            ArrayList a = new ArrayList() { 1, 5, 3, 3, 2, 4, 3 };

            /* the ArrayList's Sort method accepts ONLY an IComparer */
            ComparerAdapter cmp = new ComparerAdapter(IntComparer);
            a.Sort(cmp);

            foreach (var x in a) Console.WriteLine(x);
        }
    }
}
