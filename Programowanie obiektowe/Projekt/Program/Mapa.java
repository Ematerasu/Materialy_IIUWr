
import java.util.Random;

public class Mapa {

    private Random rnd = new Random();
    private int[][] Map = new int[5][5]; //Typy komnat 1-Przeciwnik, 2-Zagadka, 3-Artefakt, 4-Pulapka, 5-Nic, 6-Slepa uliczka, >6 zamkniete, trzeba klucza
    private int pozycja_skarbu_i, pozycja_skarbu_j;
    private int i, j;
//W tym przypadku mapa jest bardzo prosta, system kluczy itp. nie jest skomplikowany wiec postanowilem poprostu uzyc oznaczenia pokoi poprzez liczby;
// Jednak gdybym zdecydowal sie bardziej rozwinac gre na bardziej rozbudowana mape to na pewno trzeba by bylo zrobic to w inny sposob, np. pokoje jako klasy;

    public Mapa()
    {
        switch(rnd.nextInt()%1)
        {
            case 0: //Narazie tylko jedna mapa na potrzeby testowania, mozna oczywiscie dodawac kolejne
                Map[0][0] = 6;
                Map[0][1] = 9;
                Map[0][2] = 4;
                Map[0][3] = 6;
                Map[0][4] = 6;

                Map[1][0] = 6;
                Map[1][1] = 5;
                Map[1][2] = 5;
                Map[1][3] = 6;
                Map[1][4] = 6;

                Map[2][0] = 4;
                Map[2][1] = 2;
                Map[2][2] = 7;
                Map[2][3] = 5;
                Map[2][4] = 6;

                Map[3][0] = 6;
                Map[3][1] = 5;
                Map[3][2] = 2;
                Map[3][3] = 4;
                Map[3][4] = 6;

                Map[4][0] = 6;
                Map[4][1] = 5;
                Map[4][2] = 5;
                Map[4][3] = 5;
                Map[4][4] = 6;
                i = 4;
                j = 2;
                pozycja_skarbu_i = 0;
                pozycja_skarbu_j = 1;
                break;


        }
    }

    public int get_i()
    {
        return i;
    }

    public int get_j()
    {
        return j;
    }

    public void Ruch_prawo()
    {
        j+=1;
    }

    public void Ruch_lewo()
    {
        j-=1;
    }
    public void Ruch_przod()
    {
        i-=1;
    }
    public void Ruch_tyl()
    {
        i+=1;
    }

    public int get_room()
    {
        return Map[i][j];
    }

    public int get_room(int x, int y)
    {
        if(x>=0 && x<=4 && y>=0 && y<=4)
        {
            return Map[x][y];
        }
        else return 0;
    }

    public int get_pozycjaskarbu_i()
    {
        return pozycja_skarbu_i;
    }

    public int get_pozycja_skarbu_j()
    {
        return pozycja_skarbu_j;
    }

    public void open_room()
    {
        Map[i][j]-=6;
    }

    public void after_event()
    {
        Map[i][j] = 5;
    }

    public void MozliweDrogi()
    {
        if(i != 4 && i != 0 && j!= 0 && j!=4)
        {
            System.out.println("Mozliwy ruch:");
            System.out.println("1.Naprzod");
            System.out.println("2.W lewo");
            System.out.println("3.W prawo");
            System.out.println("4.Do tylu");
        }
        else if(i != 0 && j!= 0 && j!=4)
        {
            System.out.println("Mozliwy ruch:");
            System.out.println("1.Naprzod");
            System.out.println("2.W lewo");
            System.out.println("3.W prawo");
        }
        else if(i != 4 && j!= 0 && j!=4)
        {
            System.out.println("Mozliwy ruch:");
            System.out.println("2.W lewo");
            System.out.println("3.W prawo");
            System.out.println("4.Do tylu");
        }
        else if(i != 4 && i != 0 && j!=4)
        {
            System.out.println("Mozliwy ruch:");
            System.out.println("1.Naprzod");
            System.out.println("3.W prawo");
            System.out.println("4.Do tylu");
        }
        else if(i != 4 && i != 0 && j!= 0)
        {
            System.out.println("Mozliwy ruch:");
            System.out.println("1.Naprzod");
            System.out.println("2.W lewo");
            System.out.println("4.Do tylu");
        }
        else if(i != 4 && j!= 0)
        {
            System.out.println("Mozliwy ruch:");
            System.out.println("2.W lewo");
            System.out.println("4.Do tylu");
        }
        else if(i != 4 && j!=4)
        {
            System.out.println("Mozliwy ruch:");
            System.out.println("3.W prawo");
            System.out.println("4.Do tylu");
        }
        else if(i != 0 && j!=4)
        {
            System.out.println("Mozliwy ruch:");
            System.out.println("1.Naprzod");
            System.out.println("3.W prawo");
        }
        else if(i != 0 && j!=0)
        {
            System.out.println("Mozliwy ruch:");
            System.out.println("1.Naprzod");
            System.out.println("2.W lewo");
        }

    }
}
