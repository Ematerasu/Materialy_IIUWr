using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace Zadanie1
{
    class Invoker
    {
        private int queueLimit = 10;
        private Queue<ICommand> q = new Queue<ICommand>();
        private const int generatorSleepTime = 1000;
        private const int dispatcherSleepTime = 2000;

        private void Generator()
        {
            ICommand c;

            while (true)
            {
                Random randNum = new Random();
                switch (randNum.Next(4))
                {
                    case 0:
                        c = new DownloadFTPCommand("(Adres FTP)");
                        break;
                    case 1:
                        c = new DownloadHTTPCommand("(Adres HTTP)");
                        break;
                    case 2:
                        c = new CreateFileCommand("(C//...)");
                        break;
                    default:
                        c = new CopyFileCommand("(C//...)", "(D//...)");
                        break;
                }

                lock(this){

                    while (q.Count > queueLimit)
                    {
                        Monitor.Wait(this, 1000);
                    }
                    q.Enqueue(c);
                }

                Thread.Sleep(generatorSleepTime);
            }
        }

        private void Dispatcher()
        {
            while (true)
            {
                ICommand c;
                lock (this)
                {
                    while (q.Count == 0)
                    {
                        Monitor.Wait(this, 1000);
                    }
                    c = q.Dequeue();
                }
                c.Execute();
                Thread.Sleep(dispatcherSleepTime);
            }
        }

        public void Run()
        {
            Thread generator = new Thread(new ThreadStart(Generator));
            Thread dispatcher1 = new Thread(new ThreadStart(Dispatcher));
            Thread dispatcher2 = new Thread(new ThreadStart(Dispatcher));

            try
            {
                generator.Start();
                dispatcher1.Start();
                dispatcher2.Start();

                generator.Join();
                dispatcher2.Join();
                dispatcher1.Join();
            }
            catch(ThreadInterruptedException e)
            {
                Console.WriteLine(e);
                Environment.Exit(1);
            }

        }
    }
}
