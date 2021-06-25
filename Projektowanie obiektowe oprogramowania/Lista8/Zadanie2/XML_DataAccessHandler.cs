using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace Zadanie2
{
    class XML_DataAccessHandler : DataAccessHandler
    {
        private XmlTextReader reader;
        public override void ConnectData()
        {
            reader = new XmlTextReader("../../../randomXMLFile.xml"); //Losowy plik xml z generatora;
        }
        public override void DownloadData()
        {

        }
        public override void ProcessData()
        {
            int max = 0;
            string name = "";
            while (reader.Read())
            {
                if(reader.NodeType == XmlNodeType.Element)
                {
                    if (reader.Name.Length > max)
                    {
                        max = reader.Name.Length;
                        name = reader.Name;
                    }
                }
            }

            Console.WriteLine(max +" " + name);
        }
        public override void CloseConnect()
        {
            reader.Close();
        }
    }
}
