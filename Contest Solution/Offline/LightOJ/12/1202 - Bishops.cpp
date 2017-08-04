#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    long long t,i,r1,c1,r2,c2;

    scanf("%lld",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%lld %lld %lld %lld",&r1,&c1,&r2,&c2);

        if (abs(r2-r1)==abs(c2-c1))
            printf("Case %lld: 1\n",i);
        else if ((r1+c1)%2!=(r2+c2)%2)
            printf("Case %lld: impossible\n",i);
        else
            printf("Case %lld: 2\n",i);
    }

    return 0;
}
