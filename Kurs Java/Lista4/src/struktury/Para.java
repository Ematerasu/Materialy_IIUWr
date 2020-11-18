package struktury;

public class Para {
    public final String klucz;
    private double wartosc;

    private boolean containsUpperCaseLetters(String word) {

        for(int i = 0; i < word.length(); i++) {
            if(word.charAt(i) > 64 && word.charAt(i) < 91) return true;
        }
        return false;
    }

    public Para(String k, double v) {
        if(k == null || k == "" || containsUpperCaseLetters(k)) throw new IllegalArgumentException("Zly klucz");
        this.klucz = k;
        this.wartosc = v;
    }

    public double get_wartosc() {return wartosc;}

    public void set_wartosc(double v) {this.wartosc = v;}

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Para)) return false;

        return this.klucz == ((Para) obj).klucz;
    }

    @Override
    public String toString() {
        return "("+klucz+", "+wartosc+")";
    }
}
