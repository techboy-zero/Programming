#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    int t,i;

    scanf("%d",&t);

    for (i=1; i<=t; i++)
    {
        int n;

        scanf("%d",&n);

        char bin[34];
        int k=0;

        for (int j=1<<30; j>=1; j>>=1)
        {
            if (j & n)
                bin[k++]='1';
            else
                bin[k++]='0';
        }

        bin[k]='\0';

        next_permutation(bin,bin+31);

        int total=0;

        for (int j=0; j<31; j++)
        {
            total+=(bin[j]-'0')*pow(2,31-j-1);
        }

        printf("Case %d: %d\n",i,total);
    }

    return 0;
}
