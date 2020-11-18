package test;
import struktury.*;

public class Main {

    public final static void main(String args[]) {
        Para test_para = new Para("test", 1.0);
        System.out.println("Testowa para: " + test_para);

        try {
            ZbiorNaTablicy test_zbior = new ZbiorNaTablicy(5);
            System.out.println("Tablica zwykla: ");
            test_zbior.Wstaw(new Para("test1", 1.0));
            test_zbior.Wstaw(new Para("test2", 2.0));
            test_zbior.Wstaw(new Para("test3", 3.0));
            System.out.println("Stan tablicy przed usunieciem: ");
            test_zbior.PrintArray();

            System.out.print("\n");

            test_zbior.Usun("test2");
            System.out.println("Stan tablicy po usunieciu: ");
            test_zbior.PrintArray();

            System.out.print("\n");
        
            System.out.println("Szukanie pary o kluczu test3: " + test_zbior.Szukaj("test3"));

            System.out.print("\n");

            test_zbior.Ustaw(new Para("test4", 4.0));
            System.out.println("Stan tablicy po dodaniu jednej pary: ");
            test_zbior.PrintArray();

            System.out.print("\n");
        
            System.out.println("Ilosc elementow: " + test_zbior.Ile());
            test_zbior.Usun("test3");
            System.out.println("Ilosc elementow po usunieciu jednej pary: " + test_zbior.Ile());

            
        }
        catch(Exception e) {
            e.printStackTrace();
        }
        
        System.out.print("\n");
        System.out.print("\n");
        System.out.print("\n");

        try {
            ZbiorNaTablicyDynamicznej test_zbior2 = new ZbiorNaTablicyDynamicznej();
            System.out.println("Tablica dynamiczna: ");
            test_zbior2.Wstaw(new Para("test1", 1.0));
            test_zbior2.Wstaw(new Para("test2", 2.0));
            test_zbior2.Wstaw(new Para("test3", 3.0));
            System.out.println("Stan tablicy: ");
            test_zbior2.PrintArray();

            test_zbior2.Usun("test2");
            System.out.println("Stan tablicy po usunieciu: ");
            test_zbior2.PrintArray();

            System.out.print("\n");
        
            System.out.println("Szukanie pary o kluczu test3: " + test_zbior2.Szukaj("test3"));

            System.out.print("\n");

            test_zbior2.Ustaw(new Para("test4", 4.0));
            System.out.println("Stan tablicy po dodaniu jednej pary: ");
            test_zbior2.PrintArray();

            System.out.print("\n");
        
            System.out.println("Ilosc elementow: " + test_zbior2.Ile());
            test_zbior2.Usun("test3");
            System.out.println("Stan tablicy po usunieciu jednej pary: ");
            test_zbior2.PrintArray();
            System.out.println("Ilosc elementow po usunieciu tej pary: " + test_zbior2.Ile());

        }
        catch(Exception e) {
            e.printStackTrace();
        }
        

        
    }
}