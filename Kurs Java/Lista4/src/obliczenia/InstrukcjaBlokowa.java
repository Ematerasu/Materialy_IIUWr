package obliczenia;

import java.util.ArrayList;

public class InstrukcjaBlokowa extends Instrukcja {
    public ArrayList<Instrukcja> instrukcje = new ArrayList<Instrukcja>();

    public InstrukcjaBlokowa(Instrukcja... ins) {
        for(Instrukcja i : ins) {
            if(i == null) {
                throw new NullPointerException("Instrukcja jest rowna null");
            }
            instrukcje.add(i);
        }
    }

    @Override
    public void wykonaj() {
        for(Instrukcja i : instrukcje) {
            i.wykonaj();
        }
    }

    @Override
    public String toString() {
        String output = "{\n";
        for(Instrukcja i : instrukcje) {
            output += "\t"+i.toString();
        }

        return output+"}\n";
    }
}
