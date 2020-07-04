package com.company;

//Szeregowy->kapral->sierzant->porucznik
//1->3->6->18 jezeli wszystkie stopnie po kolei numerowac

public class Main {

    public static void main(String[] args)
    {
	    StopnieWojskowe test = new StopnieWojskowe();

	    test.Dodaj(new Szeregowy());
	    test.Dodaj(new Sierzant());
	    test.Dodaj(new Porucznik());
	    test.Dodaj(new Kapral());

	    test.Wypisz();

	    test.Dodaj(new Sierzant());
	    System.out.println("\n");
	    System.out.println(test.Pobierz());
		System.out.println("\n");

	    test.Dodaj(new Porucznik());
	    test.Wypisz();
		System.out.println(test.zbior_rang.get(0).get_stopien());
    }
}
