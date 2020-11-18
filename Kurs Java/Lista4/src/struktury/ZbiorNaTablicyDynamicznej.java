package struktury;

public class ZbiorNaTablicyDynamicznej extends ZbiorNaTablicy {

    Para[] zbior;
    
    public ZbiorNaTablicyDynamicznej() {
        zbior = new Para[2];
    }
    
    public void Wstaw(Para p) {

        int pozycja = 0;
        for(int i = 0; zbior[i] != null && i < zbior.length; i++) {
            if(zbior[i].klucz == p.klucz) throw new IllegalArgumentException("Taka para juz jest w tablicy");
            pozycja = i+1;
        }

        if(pozycja<zbior.length-1) {
            zbior[pozycja] = p;
            return;
        }

        Para[] bufor = new Para[2*zbior.length];
        System.arraycopy(zbior, 0, bufor, 0, pozycja+1);
        zbior = new Para[2*zbior.length];
        zbior = bufor;

        zbior[pozycja] = p;
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
            zbior[i] = zbior[i+1];                                        //pozycja jest ustawiona na koniec zbioru
        }

        if(pozycja < zbior.length/4) {
            Para[] bufor = new Para[zbior.length/2];
            System.arraycopy(zbior, 0, bufor, 0, pozycja+1);
            zbior = bufor;
        }
    }

    public void Ustaw(Para p) {
        int pozycja = 0;
        for(int i = 0; zbior[i] != null && i < zbior.length; i++) {
            if(zbior[i].klucz == p.klucz) {
                zbior[i] = p;
                return;
            }
            pozycja = i;
        }

        if(pozycja<zbior.length-1) {
            zbior[pozycja+1] = p;
            return;
        }

        Para[] bufor = new Para[2*zbior.length];
        System.arraycopy(zbior, 0, bufor, 0, pozycja+1);
        zbior = bufor;

        zbior[pozycja+1] = p;
    }

    public void PrintArray() {
        for(int i = 0; zbior[i] != null && i < zbior.length; i++) {
            System.out.println(zbior[i]);
        }
    }

    public int Ile() {
        int x=0;
        for(int i = 0; zbior[i] != null && i < zbior.length; i++) {
            x++;
        }
        return x;
    }

    public void Czysc() {
        int rozmiar = zbior.length;
        
        zbior = new Para[rozmiar];
    }

    public double Czytaj(String k) {
        for(int i = 0; i < zbior.length; i++) {
            if(zbior[i].klucz == k) return zbior[i].get_wartosc();
        }

        throw new IllegalArgumentException("Nie ma pary o takim kluczu");
    }

    public Para Szukaj(String k) {

        for(int i = 0; zbior[i] != null && i < zbior.length; i++) {
            if(zbior[i].klucz == k) return zbior[i];
        }

        throw new IllegalArgumentException("Nie ma pary o takim kluczu");
    }


}
