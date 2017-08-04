#include <stdio.h>
#include <math.h>

int main()
{
    int t,i,j,count;
    long long w,n,m;

    scanf("%d",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%lld",&w);

        count=0;
        n=w;

        if (n%2==1)
        {
            printf("Case %d: Impossible\n",i);
        }
        else
        {
            for (j=1; ; j++)
            {
                if (n%2==0)
                {
                    count++;
                    n=n/2;
                }

                if (n%2==1)
                {
                    m=pow(2,count);
                    printf("Case %d: %lld %lld\n",i,n,m);
                    break;
                }
            }
        }
    }

    return 0;
}
