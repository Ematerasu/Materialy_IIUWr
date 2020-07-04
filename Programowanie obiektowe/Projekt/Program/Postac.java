
//Strategy
public interface Postac {
    void Perk(Mapa map); //umiejetnosc specjalna bohatera, dla kazdej postaci inna
    boolean IsAlive();
    int get_Sila();
    int get_Zrecznosc();
    int get_Uzycia();
    void set_Alive(boolean val);
    void set_Sila(int val);
    void set_Zrecznosc(int val);
    void Add_Key(int val);
    boolean Has_Key(int val);
}
