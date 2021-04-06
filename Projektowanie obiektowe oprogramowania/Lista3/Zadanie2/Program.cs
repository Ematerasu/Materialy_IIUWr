using System;

namespace Zadanie2
{
    //Zad2   
    public class ReportPrinter
    {
        public string data { get; set; }
        public string GetData()
        {
            return data;
        }

        public void FormatDocument()
        {
            data = "format";
        }
        public void PrintReport()
        {
            Console.WriteLine("Drukowanie " + data + "...");
        }
    }
    /*
        Dokonując testu odpowiedzialności SRP:
        ReportPrinter "printuje report" - tak
        ReportPrinter zwraca dane ? Nie za bardzo
        ReportPrinter formatuje dokument ? Rowniez nie bardzo.
        Propozycja zmiany: Stworzenie klas do trzymania danych oraz formatowania dokumentu, zajmujące się tymi metodami które nie pasuja do klasy ReportPrinter.
    */

    //Zmiany
    public class ReportPrinterBetter
    {
        public void PrintReport(Report r)
        {
            Console.WriteLine("Drukowanie " + r.data + "...");
        }
    }

    public class Report
    {
        public string data { get; set; }
    }

    public class DocumentFormatter
    {
        public void FormatDocument(Report doc)
        {
            doc.data = "format";
        }
    }

    //W tym przypadku każda metoda trafiła do osobnej klasy ale nie zawsze tak musi być, widzieliśmy to na wykładzie gdzie z klasy Samochód która miała 7 metod,
    // 4 z nich poszły do innych klas ale 3 zostały.


    //Zad7

    public interface IReport
    {
        public string GetData();
        public void SetData(string s);
    }

    public class ExampleReport : IReport
    {
        private string data;
        public string GetData()
        {
            return data;
        }
        public void SetData(string s)
        {
            data = s;
        }
    }

    public interface IDocumentFormatter
    {
        public void FormatDocument(IReport report);
    }

    public class ExampleFormatter : IDocumentFormatter
    {
        public void FormatDocument(IReport report)
        {
            report.SetData("Formatted");
        }
    }

    public interface IReportPrinter
    {
        public void print(IReport report);
    }

    public class ExamplePrinter : IReportPrinter
    {
        public void print(IReport report)
        {
            Console.WriteLine("Drukowanie {0}...", report.GetData());
        }
    }
    public class ReportComposer
    {
        private IDocumentFormatter formatter;
        private IReport report;
        private IReportPrinter printer;

        public ReportComposer(IDocumentFormatter f, IReport r, IReportPrinter rp)
        {
            formatter = f;
            report = r;
            printer = rp;
        }

        public void Format()
        {
            formatter.FormatDocument(report);
        }

        public void Print()
        {
            printer.print(report);
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            ReportPrinter test1 = new ReportPrinter();
            test1.data = "Przykład";
            test1.PrintReport();
            test1.FormatDocument();

            Report test2 = new Report();
            ReportPrinterBetter printer = new ReportPrinterBetter();
            DocumentFormatter format = new DocumentFormatter();
            test2.data = "Drugi przykład";
            format.FormatDocument(test2);
            printer.PrintReport(test2);

        }
    }
}
