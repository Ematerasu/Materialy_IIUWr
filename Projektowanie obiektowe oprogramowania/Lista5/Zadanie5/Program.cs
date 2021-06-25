using System;
using System.Collections.Generic;

namespace Zadanie5
{
    //Jezeli dobrze rozumiem to tak naprawde zostalo to w teorii zrobione na wykladzie, takze zrobie to w taki sam sposob
    public class Person
    {

    }
    //Wersja pierwsza
    public abstract class PersonRegistry
    {
        protected PersonNotifier notifier;

        public PersonRegistry(PersonNotifier notifier)
        {
            this.notifier = notifier;
        }
        public abstract IEnumerable<Person> GetPersons();

        public void Notify()
        {
            this.notifier.Notify(this.GetPersons());
        }
    }

    public class XMLPersonRegistry : PersonRegistry
    {
        public XMLPersonRegistry(PersonNotifier notifier) : base(notifier)
        {
            this.notifier = notifier;
        }

        public override IEnumerable<Person> GetPersons()
        {
            throw new NotImplementedException();
        }
    }

    public class SQLPersonRegistry : PersonRegistry
    {
        public SQLPersonRegistry(PersonNotifier notifier) : base(notifier)
        {
            this.notifier = notifier;
        }

        public override IEnumerable<Person> GetPersons()
        {
            throw new NotImplementedException();
        }
    }

    public abstract class PersonNotifier
    {
        public abstract void Notify(IEnumerable<Person> persons);
    }

    public class MailPersonNotifier : PersonNotifier
    {
        public override void Notify(IEnumerable<Person> persons)
        {
            foreach(Person p in persons)
            {
                //Wyslij maila do p
            }
        }
    }

    public class SMSPersonNotifier : PersonNotifier
    {
        public override void Notify(IEnumerable<Person> persons)
        {
            foreach (Person p in persons)
            {
                //Wyslij sms do p
            }
        }
    }


    // Wersja druga, analogiczna
    public abstract class PersonRegistry2
    {
        public PersonRegister register;
        public PersonRegistry2(PersonRegister register)
        {
            this.register = register;
        }
        public IEnumerable<Person> GetPersons()
        {
            return this.register.GetPersons();
        }

        public abstract void Notify();
    }

    public class MailPersonNotify : PersonRegistry2
    {
        public MailPersonNotify(PersonRegister register) : base(register)
        {
            this.register = register;
        }

        public override void Notify()
        {
            IEnumerable<Person> persons = this.GetPersons();

            foreach (Person p in persons)
            {
                //Wyslij mail do p
            }
        }
    }

    public class SMSPersonNotify : PersonRegistry2
    {
        public SMSPersonNotify(PersonRegister register) : base(register)
        {
            this.register = register;
        }

        public override void Notify()
        {
            IEnumerable<Person> persons = this.GetPersons();

            foreach (Person p in persons)
            {
                //Wyslij sms do p
            }
        }
    }

    public abstract class PersonRegister
    {
        public abstract IEnumerable<Person> GetPersons();
    }

    public class XMLPersonRegister : PersonRegister
    {
        public override IEnumerable<Person> GetPersons()
        {

            return null; //Tu zamiast null oczywiscie musimy zwrocic liste uzyskana z pliku xml
        }
    }

    public class SQLPersonRegister : PersonRegister
    {
        public override IEnumerable<Person> GetPersons()
        {
            return null; //Podobnie jak wyzej tylko liste z bazy danych oczywiscie
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }
    }
}
