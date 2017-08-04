#include <stdio.h>
#include <math.h>

int main()
{
    long long t,n,i,j,count,sum;

    scanf("%lld",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%lld",&n);

        count=1;
        sum=1;

        while (n%2==0)
        {
            n=n/2;
            count++;
        }

        sum=sum*count;

        for (j=3; j*j<=n; j+=2)
        {
            count=1;

            while (n%j==0)
            {
                n=n/j;
                count++;
            }

            sum=sum*count;
        }

        if (n>1)
            sum=sum*2;

        printf("Case %lld: %lld\n",i,--sum);
    }

    return 0;
}
