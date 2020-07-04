
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Random;

public class Event {
    private BufferedReader reader  = new BufferedReader(new InputStreamReader(System.in));
    private String temp = new String("");
    private Random rng = new Random();
    public Event(int Typ, Postac Hero) throws IOException //konstruktor ktory wywola odpowiedni event
    {
        switch (Typ) {
            case 1:
                Event_1(Hero);
                break;
            case 2:
                Event_2(Hero);
                break;
            case 3:
                Event_3();
                break;
            case 4:
                Event_4(Hero);
                break;
            case 5:
                System.out.println("Tutaj spokojnie...");
                break;
        }

    }

    public void Event_1(Postac Hero) throws IOException
    {
        try {
            Przeciwnicy Foe = new Zlodziej_zpistoletem();
            System.out.println("Napotykasz zlodzieja");
            Thread.sleep(2000);
            System.out.println("*W myslach* Czego tu szuka?");
            Thread.sleep(2000);
            System.out.println("Jest odwrocony tylem, dostrzegasz w jego kieszeni kajdanki");
            System.out.println("Moglbys sie zakrasc i zapiac mu je na nadgarstkach");
            Thread.sleep(2000);
            System.out.println("Jezeli wolisz rozwiazanie silowe moglbys sprobowac go ogluszyc");
            Thread.sleep(3000);
            System.out.println("Ktora opcje wybierasz? (1/2)");
            System.out.print(">");
            temp = reader.readLine();

            if (temp.equals("1")) {
                if (Hero.get_Zrecznosc() < Foe.get_Zrecznosc()) {
                    System.out.println("Nie byles wystarczajaco zreczny.");
                    Foe.Atak();
                    System.out.println("YOU DIED");
                    Hero.set_Alive(false);
                } else {
                    System.out.println("Udalo ci sie zrecznie zakrasc");
                    System.out.println("Szybkim ruchem ukradles kajdanki i zalozyles mu na rece");
                    System.out.println("Mozesz isc dalej");
                }
            } else if (temp.equals("2")) {
                if (Hero.get_Sila() < Foe.get_Sila()) {
                    System.out.println("Nie byles wystarczajaco silny.");
                    Foe.Atak();
                    System.out.println("YOU DIED");
                    Hero.set_Alive(false);
                } else {
                    System.out.println("Udalo ci sie skutecznie go znokautowac");
                    System.out.println("Zlodziej lezy nieprzytomny, troche minie zanim wstanie");
                    System.out.println("Mozesz isc dalej");
                }
            }
        }
        catch(IOException e)
        {
            System.out.println("Error");
        }
        catch(InterruptedException e)
        {
            System.out.println("Error");
        }
    }

    public void Event_2(Postac Hero) throws IOException
    {
        try {
            System.out.println("Znajdujesz skrzynie z zamkiem na kod");
            Thread.sleep(2000);
            if (rng.nextInt() % 2 == 1) {
                System.out.println("Obok jest napis: Rok premiery PlayStation 4");
                System.out.print(">");
                while (!reader.readLine().equals("2013")) {
                    System.out.println("Nie dziala...");
                    System.out.print(">");
                }

                System.out.println("Mam! W srodku jest klucz, ciekawe do ktorych drzwi");
                Hero.Add_Key(rng.nextInt(2) == 1 ? Hero.Has_Key(7) ? 9 : 7 : Hero.Has_Key(9) ? 7 : 9); //Zapobieganie sytuacji w ktorej dostajemy dwa razy ten sam klucz

            } else {
                System.out.println("Obok jest napis: Rok premiery PlayStation 5");
                System.out.print(">");
                while (!reader.readLine().equals("2020")) {
                    System.out.println("Nie dziala...");
                    System.out.print(">");
                }

                System.out.println("Mam! W srodku jest klucz, ciekawe do ktorych drzwi");
                Hero.Add_Key(rng.nextInt(2) == 1 ? Hero.Has_Key(7) ? 9 : 7 : Hero.Has_Key(9) ? 7 : 9);
            }
        }
        catch(IOException e)
        {
            System.out.println("Error");
        }
        catch(InterruptedException e)
        {
            System.out.println("Error");
        }
    }

    public void Event_3() throws IOException
    {
        try {
            System.out.println("Trafiasz do duzej sali");
            Thread.sleep(1000);
            System.out.println("Na samym srodku znajduje sie duzy piedestal");
            Thread.sleep(1000);
            System.out.println("Lezy na nim jakis przedmiot...");
            Thread.sleep(2000);
            System.out.println("...");
            Thread.sleep(2000);
            switch(rng.nextInt(3))
            {
                case 0:
                    System.out.print("Starozytny mongolski luk!\n");
                    break;
                case 1:
                    System.out.print("Korona azteckiego krola!\n");
                    break;
                case 2:
                    System.out.print("Miecz Krola Artura!\n");
                    break;
            }
            Thread.sleep(1000);
            System.out.println("To niesamowite! To tego musial szukac ten czlowiek.");
        }
        catch(InterruptedException e)
        {
            System.out.println("Error");
        }
    }

    public void Event_4(Postac Hero) throws IOException
    {
        try {
            System.out.println("Hmm, pusto...");
            Thread.sleep(3000);
            switch (rng.nextInt(3)) {
                case 0:
                    System.out.println("Z sufitu spada blok najezony kolcami!");
                    System.out.println("1.Unik w lewo");
                    System.out.println("2.Unik w prawo");
                    System.out.println("3.Unik w dol");
                    System.out.print(">");
                    if (reader.readLine().equals("3")) {
                        System.out.println("Za pozno...");
                        System.out.println("YOU DIED");
                        Hero.set_Alive(false);
                    } else {
                        System.out.println("uff...");
                    }
                    break;
                case 1:
                    System.out.println("Podloga sie zapada!");
                    System.out.println("1.Skocz do drzwi wejsciowych");
                    System.out.println("2.Skocz w prawo");
                    System.out.println("3.Skocz do przodu");
                    System.out.print(">");
                    if (reader.readLine().equals("1")) {
                        System.out.println("W ostatniej chwili...");
                    } else {
                        System.out.println("Zly wybor...");
                        System.out.println("YOU DIED");
                        Hero.set_Alive(false);
                    }
                    break;
                case 2:
                    System.out.println("Hmm, na scianie znajduja sie 3 obrazy...");
                    Thread.sleep(1000);
                    System.out.println("1.Pierwszy z nich opisuje Bitwe pod Grundwaldem,");
                    Thread.sleep(1000);
                    System.out.println("2.Srodkowy chyba Hold Pruski");
                    Thread.sleep(1000);
                    System.out.println("3.Ostatni wyglada jakby opisywal Rozbicie Dzielnicowe");
                    Thread.sleep(1000);
                    System.out.println("Pod obrazami sa przyciski, chyba musze je wcisnac w chronologicznej kolejnosci");
                    Thread.sleep(1000);
                    System.out.println("hm...");
                    System.out.print(">");
                    if (reader.readLine().equals("3")) {
                        Thread.sleep(1000);
                        System.out.println("Chyba dziala...");
                        System.out.print(">");
                        if (reader.readLine().equals("1")) {
                            Thread.sleep(1000);
                            System.out.println("Ok, zyje");
                            System.out.print(">");
                            if (reader.readLine().equals("2")) {
                                Thread.sleep(1000);
                                System.out.println("Wszystko sie zgadza");
                                Thread.sleep(1000);
                                System.out.println("O prosze, cos wypadlo z obrazu");
                                Thread.sleep(1000);
                                System.out.println("*Znaleziono miksture wzmocnienia*");
                                Hero.set_Sila(Hero.get_Sila() + 5);
                                Hero.set_Zrecznosc(Hero.get_Zrecznosc() + 5);
                                Thread.sleep(1000);
                                System.out.println("Po wypiciu jej czuje sie lepiej!");
                            }
                        } else {
                            System.out.println("Ze sciany wychodza kolce...");
                            Thread.sleep(1000);
                            System.out.println("YOU DIED");
                            Hero.set_Alive(false);
                        }
                    } else {
                        System.out.println("Ze sciany wychodza kolce...");
                        Thread.sleep(1000);
                        System.out.println("YOU DIED");
                        Hero.set_Alive(false);
                    }

                    break;
            }
        }
        catch(IOException e)
        {
            System.out.println("Error");
        }
        catch(InterruptedException e)
        {
            System.out.println("Error");
        }
    }
}
