#include <stdio.h>

int main()
{
    int t,one,i;
    unsigned int n,j;

    scanf("%d", &t);

    for (i=1; i<=t; i++)
    {
        scanf("%u", &n);
        one=0;

        for (j=1<<31; j>=1 ; j>>=1)
        {
            if (n & j)
                one++;
        }
        if (one%2==0)
            printf("Case %d: even\n",i);
        else
            printf("Case %d: odd\n",i);
    }

    return 0;
}
