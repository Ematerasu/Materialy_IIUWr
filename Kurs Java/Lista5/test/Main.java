package test;
import structures.*;
import java.util.*;

public class Main {
    public static final void main(String[] args) {

        OrderedList<Integer> test = new OrderedList<Integer>();
        System.out.println("Integery:");
        test.insert(Integer.valueOf(10));
        test.insert(Integer.valueOf(3));
        test.insert(Integer.valueOf(6));
        test.insert(Integer.valueOf(2));
        test.insert(Integer.valueOf(3));
        test.insert(Integer.valueOf(8));
        test.insert(Integer.valueOf(1));
        test.printList();
        System.out.println("\n");
        test.remove(Integer.valueOf(1));
        test.printList();

        System.out.println("\nWartosc minimalna: " + test.min());
        System.out.println("\nWartosc maksymalna: " + test.max());
        System.out.println("\nWartosc na pozycji 3: " + test.at(3));

        System.out.println("\nCzy jest na liscie 8?: " + test.search(8));
        System.out.println("\nCzy jest na liscie 9?: " + test.search(9));

        System.out.println("\nIndeks na ktorym jest 8: " + test.index(8));

        for(Integer i : test) {
            System.out.println(i);
        }
        System.out.println("\nString:");
        OrderedList<String> test2 = new OrderedList<String>();

        test2.insert("c");
        test2.insert("d");
        test2.insert("a");
        test2.insert("b");
        for(String i : test2) {
            System.out.println(i);
        }
        System.out.println("\nCalendar:");
        OrderedList<Calendar> test3 = new OrderedList<Calendar>();
        
        test3.insert(Calendar.getInstance(TimeZone.getTimeZone("GMT-8")));
        test3.insert(Calendar.getInstance(TimeZone.getTimeZone("GMT+5:30")));
        test3.insert(Calendar.getInstance(TimeZone.getTimeZone("UTC")));
        test3.insert(Calendar.getInstance(TimeZone.getTimeZone("PST")));
        
        for(Calendar i : test3) {
            System.out.println(i.getTime());
        }
    }
}

