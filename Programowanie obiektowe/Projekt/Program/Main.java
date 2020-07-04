
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//Za wszelkie czerstwe dialogi przepraszam, to nie jest moja specjalnosc :(

public class Main {

    public static void main(String[] args) throws IOException, InterruptedException //sleep
    {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in)); //wczytywanie z konsoli
            String temp = new String("");
            String wybor = new String("n"); //domyslnie na "n", czekamy az gracz wybierze postac

            System.out.println("Witaj w 'A Maze Ing'");
            Thread.sleep(2000);
            System.out.println("Przed rozpoczeciem rozgrywki prosze wybierz postac");
            System.out.println("Do wyboru masz dwie znane postacie:");
            System.out.print("\n");
            while (wybor.equals("n")) {
                System.out.println("1.Lara Croft");
                System.out.println("2.Indiana Jones");
                System.out.println("Wpisz odpowiedni numer by wyswietlic opis");
                System.out.print(">");
                temp = reader.readLine();
                System.out.print("\n");
                if (temp.equals("1")) {
                    System.out.println("Znana Pani archeolog");
                    System.out.println("Kobieca intuicja pozwala jej przeskanowac pobliskie pomieszczenia w poszukiwaniu pulapek");
                    System.out.println("Czy wybierasz Lare Croft? (y/n)");
                    System.out.print(">");
                    wybor = reader.readLine();
                } else if (temp.equals("2")) {
                    System.out.println("Popularny poszukiwacz przygod z lassem u boku.");
                    System.out.println("Jego doswiadczenie pozwala mu sie domyslec w ktorym kierunku znajduje sie artefakt");
                    System.out.println("Czy wybierasz Indiane Jonesa? (y/n)");
                    System.out.print(">");
                    wybor = reader.readLine();
                }
                System.out.print("\n");
            }

            Postac Hero;
            //strategy tutaj
            if (temp.equals("1")) {
                Hero = new Lara_Croft();
            }
            else {
                Hero = new Indiana_Jones();
            }

            Mapa map = new Mapa();              //generowanie losowej mapy

            System.out.println("Trafiasz do starozytnych podziemi");
            Thread.sleep(2000);
            System.out.println("Wygladaja jak labirynt...");
            Thread.sleep(2000);
            System.out.println("Jakies slady butow...Ktos tu jest");
            Thread.sleep(2000);
            System.out.println("Cos tu musi sie znajdowac.");
            Thread.sleep(2000);

            while (Hero.IsAlive() && map.get_room() != 3) {    //gra trwa dopoki Bohater zyje, ew. event znalezienia skarbu konczy gre
                map.MozliweDrogi();
                if(Hero.get_Uzycia()>0) {
                    System.out.println("5. Uzyj umiejetnosci (" + Hero.get_Uzycia() + ")");
                }
                System.out.print(">");
                temp = reader.readLine();
                switch (temp) {
                    case "1":
                        map.Ruch_przod();
                        break;
                    case "2":
                        map.Ruch_lewo();
                        break;
                    case "3":
                        map.Ruch_prawo();
                        break;
                    case "4":
                        map.Ruch_tyl();
                        break;
                    case "5":
                        Hero.Perk(map);
                        break;
                    default:
                        System.out.print("\n");
                        break;
                }

                if (map.get_room() == 6) {
                    System.out.println("Slepa uliczka, zwrot w tyl!");
                    switch (temp) {
                        case "1":
                            map.Ruch_tyl();
                            break;
                        case "2":
                            map.Ruch_prawo();
                            break;
                        case "3":
                            map.Ruch_lewo();
                            break;
                        case "4":
                            map.Ruch_przod();
                            break;
                        default:
                            System.out.print("\n");
                            break;
                    }
                } else {
                    if (temp != "5") { //Jezeli nie trafilismy do pokoju typu 6 i gracz nie uzyl umiejetnosci
                        if (map.get_room() > 6) //sprawdzamy czy zamkniete czy nie
                        {
                            if(Hero.Has_Key(map.get_room()))
                            {
                                System.out.println("Hmm.. zamkniete, moze moj klucz otworzy te drzwi");
                                System.out.println("Moze ten klucz bedzie pasowac...");
                                Thread.sleep(1000);
                                System.out.println("Pasuje jak ulal.");
                                Thread.sleep(1000);
                                map.open_room();
                                Event e = new Event(map.get_room(), Hero);
                            }
                            else
                            {
                                System.out.println("Zamkniete...Tu musi byc gdzies klucz do tych drzwi");
                                switch (temp) {
                                    case "1":
                                        map.Ruch_tyl();
                                        break;
                                    case "2":
                                        map.Ruch_prawo();
                                         break;
                                    case "3":
                                        map.Ruch_lewo();
                                        break;
                                    case "4":
                                        map.Ruch_przod();
                                        break;
                                    default:
                                        System.out.print("\n");
                                        break;
                                }
                            }
                        }
                        else
                        {
                            if(temp != "5")
                            {
                                Event e = new Event(map.get_room(), Hero);
                            }
                        }

                        if(map.get_room()!=3 && map.get_room()!=9) map.after_event();
                        else
                        {
                            Thread.sleep(3000);
                            System.out.println("To chyba na tyle tutaj, trzeba juz isc...");
                            Thread.sleep(2000);

                            break;
                        }
                        Thread.sleep(1000);
                    }
                    System.out.println("\n");
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
        Thread.sleep(1000);
        System.out.println("THE END");
    }
}
