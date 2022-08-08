# include <stdio.h>

void warshall(int **boolMartix, int n)
{
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                boolMartix[i][j] |= boolMartix[i][k] & boolMartix[k][j];
}