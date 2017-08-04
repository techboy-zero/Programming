
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int primefactor[110][110],factorial[110][110];

void factorization(void)
{
    int i,num;

    for (i=2; i<=100; i++)
    {
        num=i;

        for (int j=2; j*j<=num; j++)
        {
            while (num%j==0)
            {
                primefactor[i][j]++;
                num/=j;
            }
        }

        if (num>1)
            primefactor[i][num]++;
    }
}

void factorial_prime(void)
{
    for (int i=2; i<=100; i++)
    {
        for (int j=2; j<=i; j++)
            factorial[i][j]=factorial[i-1][j]+primefactor[i][j];
    }
}

int main()
{
    factorization();
    factorial_prime();

    int t,num;
    bool star;

    scanf("%d",&t);

    for (int i=1; i<=t; i++)
    {
        scanf("%d",&num);
        star=false;

        printf("Case %d: %d =",i,num);

        for (int j=2; j<=num; j++)
        {
            if (factorial[num][j]>0)
            {
                if (star==true)
                    printf(" *");

                printf(" %d (%d)",j,factorial[num][j]);
            }

            star=true;
        }

        printf("\n");
    }

    return 0;
}
