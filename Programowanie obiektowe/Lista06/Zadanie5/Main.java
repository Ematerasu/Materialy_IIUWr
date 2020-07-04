package com.company;

public class Main {

    public static void main(String[] args)
    {
        int[] test = {6, 12, -135, -1, 75, 867, 13, 34, 7, 6, 53, 6536, 0, 1, 2};

        MergeSort sort = new MergeSort(test, 0, test.length - 1);
        Thread watek  = new Thread(sort);

        try
        {
            watek.start();
            watek.join();
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }

        for (int i = 0; i < test.length; i++)
        {
            System.out.println(test[i]);
        }

    }
}
