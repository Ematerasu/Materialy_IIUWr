#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, num_blocks;
    int w, h;
    int num_tests;

    scanf("%d %d %d", &m, &n, &num_blocks);

    char plansza[m][n];
    int p[num_tests][num_blocks];

    for(int i=0;i<num_blocks;i++)
    {
        scanf("%d %d", &w, &h);
        char block[num_blocks][h][w];
        char x;
        for(int j=0;j<h;j++)
        {
            for(int k=0;k<w;k++)
            {
                scanf("%c", &x);
                block[i][j][k]=x;
            }
        }
    }
    scanf("%d", &num_tests);

    for(int j=0;j<num_tests;j++)
    {
        for(int i=0;i<num_blocks;i++)
        {
            scanf("%d", &p[j][i];
        }
    }

    for(int i=0;i<num_tests;i++)
    {
        for(int j=0;j<num_blocks;j++)
        {
            block[p[num_tests][num_blocks]][]
        }

    }



    return 0;
}
