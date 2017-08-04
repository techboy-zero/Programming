#include <stdio.h>

int main()
{
    long long int t,n,m,i,j,total;

    scanf("%lld",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%lld %lld",&n,&m);

        total=(n/2)*m;

        printf("Case %lld: %lld\n",i,total);
    }
    return 0;
}
