using System;

namespace Zadanie3
{

    //Wersja z listy
    public class OldTaxCalculator
    {
        public Decimal CalculateTax(Decimal Price)
        {
            return Price * new Decimal(0.22);
        }
    }
    public class Item
    {
        public Decimal Price;
        public string Name;
        public Item(double Price, string Name)
        {
            this.Price = new Decimal(Price);
            this.Name = Name;
        }
    }

    public class CashRegister
    {
        public OldTaxCalculator taxCalc = new OldTaxCalculator();

        public Decimal CalculatePrice(Item[] items)
        {
            Decimal price = 0;
            foreach(Item item in items)
            {
                price += item.Price + taxCalc.CalculateTax(item.Price);
            }
            return price;
        }

        public void PrintBill(Item[] items)
        {
            foreach(var item in items)
            {
                Console.WriteLine("towar {0} : cena {1} + podatek {2}", item.Name, item.Price, taxCalc.CalculateTax(item.Price));
            }
        }
    }
    //Poprawiona wersja


    //Dodaje możliwość obliczenia podatku podając konkretną wartość procentową podatku, dwie metody o tej samej nazwie ale rozróżniające ilość parametrów.
    //Ewentualnie klient może narzucić nową wartość podatku podczas wywołania konstruktora.
    public class NewTaxCalculator
    {
        private Decimal taxRate = new Decimal(0.22);

        public NewTaxCalculator() { }

        public NewTaxCalculator(double newTaxRate)
        {
            taxRate = new Decimal(newTaxRate);
        }

        public Decimal CalculateTax(Decimal Price)
        {
            return Price * this.taxRate;
        }

        public Decimal CalculateTax(Decimal Price, double taxRate)
        {
            return Price * new Decimal(taxRate);
        }
    }

    //Tworzę interfejs sortowan, by wygodnie móc korzystać z dwóch rodzajów, alfabetyczne sortowanie i sortowanie wg. ceny
    public interface SortItems
    {
        Item[] ItemsSort(Item[] items);
    }

    public class AlphabeticalSort : SortItems
    {
        public Item[] ItemsSort(Item[] items)
        {
            for (int i = 0; i < items.Length - 1; i++)
            {
                for (int j = i + 1; j > 0; j--)
                {
                    if (String.Compare(items[j - 1].Name, items[j].Name) > 0)
                    {
                        Item temp = items[j - 1];
                        items[j - 1] = items[j];
                        items[j] = temp;
                    }
                }
            }
            return items;
        }
    }

    public class PriceSort : SortItems
    {
        public Item[] ItemsSort(Item[] items)
        {
            for (int i = 0; i < items.Length - 1; i++)
            {
                for (int j = i + 1; j > 0; j--)
                {
                    if (items[j - 1].Price > items[j].Price)
                    {
                        Item temp = items[j - 1];
                        items[j - 1] = items[j];
                        items[j] = temp;
                    }
                }
            }
            return items;
        }
    }

    public class NewCashRegister
    {
        public NewTaxCalculator taxCalc = new NewTaxCalculator(0.22);

        public Decimal CalculatePrice(Item[] items)
        {
            Decimal price = 0;
            foreach (Item item in items)
            {
                price += item.Price + taxCalc.CalculateTax(item.Price);
            }
            return price;
        }

        public void PrintBill(Item[] items)
        {
            foreach (var item in items)
            {
                Console.WriteLine("towar {0} : cena {1} + podatek {2}", item.Name, item.Price, taxCalc.CalculateTax(item.Price));
            }
        }

        public void PrintBill(Item[] items, SortItems sort)
        {
            Item[] sortedItems = sort.ItemsSort(items);

            foreach (var item in sortedItems)
            {
                Console.WriteLine("towar {0} : cena {1} + podatek {2}", item.Name, item.Price, taxCalc.CalculateTax(item.Price));
            }
        }
    }



    class Program
    {
        static void Main(string[] args)
        {
            Item[] lista = new Item[]
            {
                new Item(2.0, "Woda"),
                new Item(4.5, "Papryka"),
                new Item(1.2, "Guma"),
                new Item(6.0, "Chipsy")
            };

            CashRegister oldCash = new CashRegister();

            Console.WriteLine("\nDo zapłaty: " + oldCash.CalculatePrice(lista));
            oldCash.PrintBill(lista);

            NewCashRegister newCash = new NewCashRegister();
            Console.WriteLine("\nDo zapłaty z podatkiem 22%: " + newCash.CalculatePrice(lista));
            Console.WriteLine("\nParagon:");
            newCash.PrintBill(lista);
            newCash.taxCalc = new NewTaxCalculator(0.18);
            Console.WriteLine("\nDo zapłaty z podatkiem 18%: " + newCash.CalculatePrice(lista));
            Console.WriteLine("\nParagon:");
            newCash.PrintBill(lista);
            Console.WriteLine("\nParagon alfabetycznie:");
            newCash.PrintBill(lista, new AlphabeticalSort());
            Console.WriteLine("\nParagon wg. cen:");
            newCash.PrintBill(lista, new PriceSort());


        }
    }
}
