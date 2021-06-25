using System;
using System.IO;

namespace Zadanie1
{
    public interface ILogger
    {
        public void Log(string Message);
    }

    public class FileLogger : ILogger
    {
        private string path;
        public FileLogger(string path)
        {
            this.path = path;
        }

        public void Log(string Message)
        {
            File.WriteAllTextAsync(path, Message);
        }
    }

    public class ConsoleLogger : ILogger
    {
        public void Log(string Message)
        {
            Console.WriteLine(Message);
        }
    }

    public class NullLogger : ILogger
    {
        public void Log(string Message)
        {
            //null
        }
    }
    public enum LogType { None, Console, File}

    public class LoggerFactory
    {
        private static LoggerFactory S;
        public ILogger GetLogger(LogType LogType, string Parameters = null)
        {
            switch (LogType)
            {
                case LogType.Console:
                    return new ConsoleLogger();
                case LogType.File:
                    return new FileLogger(Parameters);
                default:
                    return new NullLogger();
            }
        }

        public static LoggerFactory Instance()
        {
            if(S == null){
                S = new LoggerFactory();
            }
            return S;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            ILogger logger1 = LoggerFactory.Instance().GetLogger(LogType.File, "Test.txt"); //   bin/Debug/netcoreapp3.1
            logger1.Log("foo bar");
            ILogger logger2 = LoggerFactory.Instance().GetLogger(LogType.None);
            logger2.Log("qux");
            ILogger logger3 = LoggerFactory.Instance().GetLogger(LogType.Console);
            logger3.Log("lalala");
        }
    }
}
