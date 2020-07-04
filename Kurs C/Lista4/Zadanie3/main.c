#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int Obrazek[n][n];
    int c;
    int zapisx, zapisy;
    int dl;
    int dlmax=0;
    int sprawdz;

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c=getchar();
            while(c==32) c=getchar();

            if(c=='1' || c=='0')
            {
                Obrazek[i][j]=c-48;
            }
        }
    }

    for(int i=0;i<8;i++)
    {
        dl=1;
        if(Obrazek[0][i]==1)
        {
            zapisx=0;
            zapisy=i;
            {
                if(zapisy>0)
                {
                    if(Obrazek[zapisx][zapisy-1]==0)
                    {
                        zapisy--;
                        dl++;
                        sprawdz=zapisx;
                        if(zapisy>0)
                        {
                            if(Obrazek[zapisx][zapisy-1]==1)
                            {
                                zapisy--;
                                dl++;
                                sprawdz=zapisx;
                            }
                            else if(zapisx<7)
                            {
                                if(Obrazek[zapisx+1][zapisy]==1)
                                {
                                    zapisx++;
                                    dl++;
                                    sprawdz=1
                                }
                            }
                        }
                        else if(zapisx<7)
                        {
                            if(Obrazek[zapisx+1][zapisy]==1)
                            {
                                zapisx++;
                                dl++;
                            }
                        }
                    }
                }
                if(zapisy<7)
                {
                    if(Obrazek[zapisx][zapisy+1]==0)
                    {
                        if(sprawdz==zapisx) break;
                        zapisy++;
                        dl++;
                        if(zapisy<7)
                        {
                            if(Obrazek[zapisx][zapisy+1]==1)
                            {
                                zapisy++;
                                dl++;
                            }
                            else if(zapisx<7)
                            {
                                if(Obrazek[zapisx+1][zapisy]==1)
                                {
                                    zapisx++;
                                    dl++;
                                }
                            }
                        }
                        else if(zapisx<7)
                        {
                            if(Obrazek[zapisx+1][zapisy]==1)
                            {
                                zapisx++;
                                dl++;
                            }
                        }
                    }

                }
                if(zapisx<7)
                {
                    if(Obrazek[zapisx+1][zapisy]==0)
                    {
                        zapisx++;
                        dl++;
                        if(zapisy<7)
                        {
                            if(Obrazek[zapisx][zapisy+1]==1)
                            {
                                zapisy++;
                                dl++;
                                sprawdz=zapisx;
                            }
                        }

                        if(zapisy>0)
                        {
                            if(Obrazek[zapisx][zapisy-1]==1)
                            {
                                if(sprawdz==zapisx) break;
                                zapisy--;
                                dl++;
                            }
                        }
                    }
                    if(zapisx<7)
                    {
                        if(Obrazek[zapisx+1][zapisy]==1)
                        {
                            zapisx++;
                            dl++;
                        }
                    }
                }
            }
        }
        if(dl>dlmax) dlmax=dl;
    }
    printf("\n%d", dlmax);

    return 0;
}
