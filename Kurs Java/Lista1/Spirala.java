/*
    Dominik Budzki 314625
    Kurs Java Lista 1 Zadanie 1
*/

public class Spirala {

    //Zamiast wszystkie funkcje opisywac jako statyczne moznaby użyc Singletona. Przy tym malym programie uznalem ze przejrzysciej bedzie uzyc statycznych funkcji.

    //Jedna funkcja ktora wypelnia mi spiralnie tę macierz
    static void spiralFill(int n, int arr[][]) { 
        int val = 0; 
        int begin = n*n;
        int m = n; //macierz arr jest n*n ale zeby utworzyc spirale musze kontrolowac oba wymiary osobno wiec kopiuje n do m
  
        int k = 0, l = 0; //Do chodzenia po macierzy

        //Rozdzielam n parzyste i n nieparzyste poniewaz maja po przeciwnych stronach najwyzsza wartosc, dla n parzystego 1 oczywiscie nie bedzie w srodku bo nie ma jak
        if(n%2 == 0) {
            while (k < m && l < n) { 
                //wpisujemy liczby do pierwszego rzedu
                for (int i = l; i < n; ++i) { 
                    arr[k][i] = begin-val++; 
                } 
                k++;
                //"usuwamy" pierwszy rzad"
                
    
                //wpisujemy liczby do ostatniej kolumny 
                for (int i = k; i < m; ++i) { 
                    arr[i][n - 1] = begin-val++; 
                } 
                n--;
                 //"usuwamy" ostatnia kolumne
                
      
                //wpisujemy liczby do ostatniego rzedu
                //Sprawdzamy w if'ie czy ostatni rzad nie jest jednoczesnie pierwszym
                if (k < m) {
                    for (int i = n - 1; i >= l; --i) { 
                        arr[m - 1][i] = begin-val++; 
                    } 
                    m--; 
                    //"usuwamy" ten ostatni rzad
                }
    
                //wpisujemy liczby do pierwszej kolumny
                //Sprawdzamy w if'ie czy ostatnia kolumna nie jest jednoczesnie pierwsza
                if (l < n) { 
                    for (int i = m - 1; i >= k; --i) {
                        arr[i][l] = begin-val++; 
                    } 
                    l++;
                    //"usuwamy" pierwsza kolumne
                } 
            } 

        }
        else {
            while (k < m && l < n) { 
                //wpisujemy liczby do ostatniego rzedu
                for (int i = n - 1; i >= l; --i) { 
                    arr[m - 1][i] = begin-val++; 
                } 
                m--; 
                //"usuwamy" ten ostatni rzad
    
                //wpisujemy liczby do pierwszej kolumny 
                for (int i = m - 1; i >= k; --i) {
                    arr[i][l] = begin-val++; 
                } 
                l++;
                //"usuwamy" pierwsza kolumne
      
                //wpisujemy liczby do pierwszego rzedu
                //Sprawdzamy w if'ie czy ostatni rzad nie jest jednoczesnie pierwszym
                if (k < m) {
                    for (int i = l; i < n; ++i) { 
                        arr[k][i] = begin-val++; 
                    } 
                    k++;
                    //"usuwamy" pierwszy rzad"
                }
    
                //wpisujemy liczby do ostatniej kolumny
                //Sprawdzamy w if'ie czy ostatnia kolumna nie jest jednoczesnie pierwsza
                if (l < n) { 
                    for (int i = k; i < m; ++i) { 
                        arr[i][n - 1] = begin-val++; 
                    } 
                    n--;
                     //"usuwamy" ostatnia kolumne
                } 
            } 
        }
        
    }
    //Zwykla funkcja sprawdzajaca pierwszosc liczby
    public static boolean IsPrime(int n)
    {
        if(n <= 1) return false;
        else{
            for(int i = 2; i <= Math.sqrt(n);i++){
                if(n % i == 0) return false;
            }
            return true;
        }
    }

    //Dwie nastepne funkcje tworza juz obraz finalny
    public static void MakeItUlamSpiral(int[][] arr, int n)
    {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                if(!IsPrime(arr[i][j])) arr[i][j] = 0;
            }
        }
    }

    public static void PrintArray(int[][] arr, int n){
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(arr[i][j] == 0) System.out.print(" ");
                else System.out.print("* ");
            }
            System.out.print("\n");
        }

    }

    public static void main(String args[]) {

        int n = Integer.valueOf(args[0]);

        if(n > 200 || n < 2) {
            throw new IllegalArgumentException("parametr spoza zakresu 2...200");
        }

        int[][] tab = new int[n][n];

        spiralFill(n, tab);
        MakeItUlamSpiral(tab, n);
        PrintArray(tab, n);
    }
}