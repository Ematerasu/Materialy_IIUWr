package com.company;

public class MergeSort implements Runnable {

    int begin, end;
    int[] Tab;

    public MergeSort(int arr[], int begin, int end)
    {
        this.Tab = arr;
        this.begin = begin;
        this.end = end;
    }

    private void merge()
    {
        int s = (begin + end) / 2;

        int n1 = s - begin + 1;
        int n2 = end - s;

        int L[] = new int [n1];
        int R[] = new int [n2];

        for (int i=0; i<n1; ++i)
            L[i] = Tab[begin + i];
        for (int j=0; j<n2; ++j)
            R[j] = Tab[s + 1 + j];

        int i = 0, j = 0;
        int k = begin;

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                Tab[k] = L[i];
                i++;
            }
            else
            {
                Tab[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            Tab[k] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            Tab[k] = R[j];
            j++;
            k++;
        }
    }

    public void run()
    {
        if (begin < end)
        {
            int s = (begin+end)/2;

            MergeSort lewy = new MergeSort(Tab, begin, s);
            MergeSort prawy = new MergeSort(Tab, s+1, end);

            Thread watek_lewy = new Thread(lewy);
            Thread watek_prawy = new Thread(prawy);



            try
            {
                watek_lewy.start();
                watek_lewy.join();
            }
            catch(InterruptedException e)
            {
                e.printStackTrace();
            }

            try
            {
                watek_prawy.start();
                watek_prawy.join();
            }
            catch(InterruptedException e)
            {
                e.printStackTrace();
            }

            merge();
        }
    }


}
