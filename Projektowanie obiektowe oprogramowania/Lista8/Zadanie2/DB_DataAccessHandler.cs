using System;
using System.Collections.Generic;
using System.Data.Common;
using System.Text;
using System.Data.SqlClient;
using System.Linq;

/*
 *  Tu troche namieszało mi się z bibliotekami które działają na bazach danych,
 *  więc zrobiłem to tak "abstrakcyjnie", jak wyobrażam sobie taką implementację
 *  
 */

namespace Zadanie2
{
    class DB_DataAccessHandler : DataAccessHandler
    {
        private SqlConnection connection;
        private List<int> nums = new List<int>();

        public override void ConnectData()
        {
            connection = new SqlConnection("Database = ...");
            connection.Open();
        }

        public override void CloseConnect()
        {
            connection.Dispose();
        }

        public override void DownloadData()
        {
            int temp;
            while (temp = connection.getRow().getNumber())
            {
                nums.Add(temp);
            }
        }

        public override void ProcessData()
        {
            int suma = 0;

            foreach(int num in nums)
            {
                suma += num;
            }

            Console.WriteLine(suma);
        }
    }
}
