public class Prosta {
    public double a, b, c; //Te zmienne mialy byc finalne ale jednoczesnie potem mialem napisac metode ktora przesunie prosta czyli zmodyfikuje te zmienne. Dlatego te pola nie sa u mnie finalne

    public Prosta(double a, double b, double c) {
        this.a = a/b;
        this.b = 1;
        this.c = c/b;
    }

    public void przesun(Wektor v) {
        this.a += v.dx;
        this.c += v.dy;
    }

    public static boolean czyRownolegle(Prosta p, Prosta q) {
        if(p.a == q.a) return true;
        else return false;
    }

    public static boolean czyProstopadle(Prosta p, Prosta q) {
        if(p.a * q.a == -1) return true;
        else return false;
    }

    public static Punkt punktPrzeciecia(Prosta p, Prosta q) {
        if(czyRownolegle(p, q)) {
            System.out.println("Te proste sa rownolegle");
            return null;
        }

        return new Punkt((q.c - p.c)/(p.a - q.a), p.a*(q.c - p.c)/(p.a - q.a) + p.c);
    }


}