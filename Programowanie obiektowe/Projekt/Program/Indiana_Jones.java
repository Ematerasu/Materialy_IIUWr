
import java.util.ArrayList;
import java.lang.Math;

public class Indiana_Jones implements Postac {

    private int Sila;
    private int Zrecznosc;
    private boolean Alive;
    private int Uzycia_umiejetnosc;
    private ArrayList<Integer> klucze = new ArrayList<Integer>();

    public Indiana_Jones()
    {
        Sila = 10;
        Zrecznosc = 5;
        Alive = true;
        Uzycia_umiejetnosc = 2;
    }

    public void Perk(Mapa map) //proste sprawdzenie w ktorym kierunku znajduje sie skarb
    {
        if(Uzycia_umiejetnosc > 0)
        {
            int x, y;
            x = map.get_i() - map.get_pozycjaskarbu_i();
            y = map.get_j() - map.get_pozycja_skarbu_j();

            if(x>0 && x>Math.abs(y))
            {
                System.out.println("Skarb jest przed toba!");
            }
            else if(Math.abs(y)>x && y>0)
            {
                System.out.println("Skarb jest na lewo!");
            }
            else if(x<0 && Math.abs(x)>y)
            {
                System.out.println("Skarb jest za toba!");
            }
            else if(Math.abs(y)>x && y<0)
            {
                System.out.println("Skarb jest na prawo!");
            }
            Uzycia_umiejetnosc-=1;
        }
    }

    public int get_Uzycia()
    {
        return this.Uzycia_umiejetnosc;
    }

    public int get_Sila()
    {
        return this.Sila;
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
