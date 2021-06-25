using System;
using System.IO;
using System.Net.Mail;

namespace Zadanie1
{
    class SmtpFacade
    {
        
        public void Send(string From, string To, string Subject, string Body, Stream Attachment, string AttachmentMimeType)
        {
            //Aby wyslac wiadomosc, string "host" nalezy zastapic prawdziwym hostem
            SmtpClient client = new SmtpClient("host");
            MailMessage msg = new MailMessage(new MailAddress(From), new MailAddress(To));
            msg.Subject = Subject;
            msg.Body = Body;
            msg.Attachments.Add(new Attachment(Attachment, AttachmentMimeType));
            client.Send(msg);

            msg.Dispose();
            Console.WriteLine("Message sent");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            SmtpFacade mailman = new SmtpFacade();
            //mailman.Send(...);
        }
    }
}
