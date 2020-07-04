package com.company;

import java.io.IOException;
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.io.ObjectInputStream;
import java.io.FileInputStream;

public class Main {

    private static final String path = "test.txt";

    public static void main(String[] args)
    {
        PrimeNumbers test = new PrimeNumbers();
        test.next();
        test.next();
        test.next();
        test.ShowAll();
        System.out.println("Zapisuje do pliku test.txt");
        try
        {
            FileOutputStream file = new FileOutputStream(path);
            ObjectOutputStream out = new ObjectOutputStream(file);

            out.writeObject(test);

            out.close();
            file.close();

            System.out.println("Object has been serialized");

        }

        catch(IOException ex)
        {
            System.out.println("IOException is caught");
        }
        System.out.println("\n\n");
        test.next();
        test.next();
        test.next();
        test.ShowAll();
        System.out.println("\n\n");
        System.out.println("Wczytuje z pliku test.txt");

        PrimeNumbers test2 = new PrimeNumbers();
        try
        {
            // Reading the object from a file
            FileInputStream file = new FileInputStream(path);
            ObjectInputStream in = new ObjectInputStream(file);

            // Method for deserialization of object
            test2 = (PrimeNumbers)in.readObject();

            in.close();
            file.close();

            System.out.println("Object has been deserialized ");
        }

        catch(IOException ex)
        {
            System.out.println("IOException is caught");
        }

        catch(ClassNotFoundException ex)
        {
            System.out.println("ClassNotFoundException is caught");
        }
        System.out.println("Kolekcja wczytana z dysku: ");
        test2.ShowAll();
    }
}
