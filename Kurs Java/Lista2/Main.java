/*
Kurs Java Lista 2
Dominik Budzki 314625
*/
class Main {

    public static void main(String[] args) {
        Punkt test = new Punkt(1,0);
        System.out.println(test.get_x()+", " +test.get_y());
        Punkt test2 = new Punkt(2,0);
        Punkt test3 = new Punkt(0,3);
        Odcinek test4 = new Odcinek(test, test2);
        Odcinek test5 = new Odcinek(test2, test3);
        Odcinek test6 = new Odcinek(test, test3);
        System.out.println(test4);
        System.out.println(test5);
        System.out.println(test6);
        Trojkat trojkat_test = new Trojkat(test, test2, test3);
        System.out.println(trojkat_test.toString());
    }

}