import java.util.Arrays;
import java.util.Random;

class MergeSort implements Runnable {
    protected int arr[];
    protected int l, r;
    public static int[] temp;
    //private static int M = 10;
    //private static int threadUsed = 0;

    MergeSort(int arr[], int l, int r) {
        this.arr = arr;
        
        this.l = l;
        this.r = r;
    }

    private void merge(int l, int m, int r) {
        for (int i = l; i <= r; i++) {
            MergeSort.temp[i] = arr[i];
        }
        int i = l, j = m+1;
        int index = l;
        while (i < m+1 && j <= r) {
            if (MergeSort.temp[i] <= MergeSort.temp[j]) {
                arr[index] = MergeSort.temp[i];
                i += 1;
            } else {
                arr[index] = MergeSort.temp[j];
                j += 1;
            }
            index += 1;
        }
        while (i < m+1) {
            arr[index] = MergeSort.temp[i];
            index += 1;
            i += 1;
        }
        while (j <= r) {
            arr[index] = MergeSort.temp[j];
            index += 1;
            j += 1;
        }
    }

    public void sort(int l, int r) {
        if (l < r) {
            int m = (l + r) / 2;
            sort(l, m);
            sort(m + 1, r);
            merge(l, m, r);
        }
    }

    /*private synchronized void increaseThreadCount(){
        MergeSort.threadUsed += 2;
    }

    private synchronized void decreaseThreadCount(){
        MergeSort.threadUsed -= 2;
    }*/

    @Override
    public void run() {
        if (this.l < this.r /*&& MergeSort.threadUsed+2 <= MergeSort.M*/) {
            int m = (this.l + this.r) / 2;
            MergeSort left = new MergeSort(arr, this.l, m);
            MergeSort right = new MergeSort(arr, m + 1, this.r);
            Thread t1 = new Thread(left);
            Thread t2 = new Thread(right);
            //this.increaseThreadCount();
            t1.start();
            t2.start();
            try {
                t1.join();
                t2.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            //this.decreaseThreadCount();
            this.merge(this.l, m, this.r);
        }
        else{
            sort(this.l, this.r);
        }
    }
}
public class RookieMergeSort {

    public static boolean isSorted(int[] arr){
        for (int i = 1; i < arr.length; i++) {
            if(arr[i-1] > arr[i]){
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        Random rd = new Random();
        int[] arr = new int[1000];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = rd.nextInt(5000000);
        }
        long startTime = System.currentTimeMillis();
        MergeSort.temp = new int[arr.length];
        MergeSort w = new MergeSort(arr, 0, arr.length-1);

        Thread t = new Thread(w);

        t.start();
        try {
            t.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        long endTime = System.currentTimeMillis();
        System.out.println("That took " + (endTime - startTime) + " milliseconds");

        System.out.println(isSorted(arr));
    }
}