package struktury;

public class ZbiorNaTablicy extends Zbior {

    public Para[] zbior;

    public ZbiorNaTablicy(int n) {
        if(n < 2) throw new IllegalArgumentException("Rozmiar musi byc przynajmniej 2");

        zbior = new Para[n];
    }

    public ZbiorNaTablicy() {
        zbior = new Para[2];
    }

    public Para Szukaj(String k) {

        for(int i = 0; zbior[i] != null && i < zbior.length; i++) {
            if(zbior[i].klucz == k) return zbior[i];
        }

        throw new IllegalArgumentException("Nie ma pary o takim kluczu");
    }

    public void Wstaw(Para p) {

        for(int i = 0; i < zbior.length; i++) {
            if(zbior[i] != null && zbior[i].klucz == p.klucz) { 
                throw new IllegalArgumentException("Ta para juz jest w tablicy");
            }
            if(zbior[i] == null) {
                zbior[i] = p;
                return;
            }

        }

    }

    public void Usun(String k) {

        int pozycja = zbior.length-1;

        for(int i = 0; zbior[i] != null && i < zbior.length; i++) {
            if(zbior[i].klucz == k) {
                zbior[i] = null;
                pozycja = i;
                break;
            }
        }

        for(int i = pozycja; i < zbior.length-1; i++) { //przesuwamy elementy, zeby w srodku nie bylo zadnej dziury, jezeli wczesniej nie znajdziemy elementu do usuniecia to nie wejdziemy do tej petli bo
            zbior[i] = zbior[i+1];                      //pozycja jest ustawiona na koniec zbioru
        }
    }

    public double Czytaj(String k) {
        for(int i = 0; zbior[i] != null && i < zbior.length; i++) {
            if(zbior[i].klucz == k) return zbior[i].get_wartosc();
        }

        throw new IllegalArgumentException("Nie ma pary o takim kluczu");
    }

    public void Ustaw(Para p) {
        for(int i = 0;i < zbior.length; i++) {
            if(zbior[i] != null && zbior[i].klucz == p.klucz) {
                zbior[i] = p;
                return;
            }

            if(zbior[i] == null) {
                zbior[i] = p;
                return;
            }
        }
    }

    public void Czysc() {
        int rozmiar = zbior.length;
        
        zbior = new Para[rozmiar];
    }

    public int Ile() {
        int x=0;
        for(int i = 0; zbior[i] != null && i < zbior.length; i++) {
            x++;
        }
        return x;
    }

    public void PrintArray() {
        for(int i = 0; zbior[i] != null && i < zbior.length; i++) {
            System.out.println(zbior[i]);
        }
    }

}
