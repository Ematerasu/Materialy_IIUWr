using System;

namespace Zadanie3
{
    class Program
    {
        static void Main(string[] args)
        {
            Handler handler = new CEOHandler().SetNext(new LawDepHandler()).SetNext(new ShopHandler()).SetNext(new MarketingHandler());

            handler.Chain("Pochwała za obsługe");
            handler.Chain("Mam problem z...");
            handler.Chain("Zamówienie na komputer...");
            handler.Chain("Skarga na dział....");
        }
    }
}
