#include <stdio.h>
#include <math.h>

double digit[1000000];
double base[1000];

int main()
{
    int t,i;
    long long x,y,j;
    double count;

    digit[0]=log(1.0);

    for (j=1; j<1000000; j++)
        digit[j]=digit[j-1]+log((double) (j+1));
    for (j=1; j<1000; j++)
        base[j]=log((double )(j+1));

    scanf("%d",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%lld %lld",&x,&y);

        if (x==0)
            count=1.0;
        else
            count=digit[x-1]/base[y-1];

        printf("Case %d: %lld\n",i,(long long) ceil(count));
    }

    return 0;
}
