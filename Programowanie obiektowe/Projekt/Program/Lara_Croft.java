
import java.util.ArrayList;
import java.util.Vector;

public class Lara_Croft implements Postac {

    private int Sila;
    private int Zrecznosc;
    private boolean Alive;
    private int Uzycia_umiejetnosc;
    private ArrayList<Integer> klucze = new ArrayList<Integer>();

    public Lara_Croft()
    {
        Sila = 5;
        Zrecznosc = 10;
        Alive = true;
        Uzycia_umiejetnosc = 2;
    }

    public void Perk(Mapa map) //prosta implementacja sprawdzania pokoi wokoło
    {
        boolean jest = false;

        if(Uzycia_umiejetnosc > 0)
        {
                if(map.get_room(map.get_i()-1, map.get_j()) == 4)
                {
                    System.out.println("Pulapka w pokoju za toba!");
                    jest = true;
                }

                if(map.get_room(map.get_i()+1, map.get_j()) == 4)
                {
                    System.out.println("Pulapka w pokoju przed toba!");
                    jest = true;
                }

                if(map.get_room(map.get_i(), map.get_j()-1) == 4)
                {
                    System.out.println("Pulapka w pokoju na lewo!");
                    jest = true;
                }

                if(map.get_room(map.get_i(), map.get_j()+1) == 4)
                {
                    System.out.println("Pulapka w pokoju na prawo!");
                    jest = true;
                }

                if(!jest)
                {
                    System.out.println("Czysto!\n");
                }
       }
        Uzycia_umiejetnosc-=1;
    }

    public int get_Sila()
    {
        return this.Sila;
    }

    public int get_Uzycia()
    {
        return this.Uzycia_umiejetnosc;
    }

    public int get_Zrecznosc()
    {
        return this.Zrecznosc;
    }

    public boolean IsAlive()
    {
        return this.Alive;
    }

    public void set_Alive(boolean val)
    {
        Alive = val;
    }

    public void set_Sila(int val)
    {
        Sila = val;
    }

    public void set_Zrecznosc(int val)
    {
        Zrecznosc = val;
    }

    public void Add_Key(int val)
    {
        klucze.add(val);
    }

    public boolean Has_Key(int Typ)
    {
        return klucze.contains(Typ);
    }

}
