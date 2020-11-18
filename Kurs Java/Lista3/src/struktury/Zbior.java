package struktury;

public abstract class Zbior {

    public abstract Para Szukaj(String k) throws Exception;

    public abstract void Wstaw(Para p) throws Exception;

    public abstract void Usun(String k);

    public abstract double Czytaj(String k) throws Exception;

    public abstract void Ustaw(Para p) throws Exception;

    public abstract void Czysc();

    public abstract int Ile();

}
