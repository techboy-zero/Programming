#include <stdio.h>
#include <string.h>

int main()
{
    long long t,i,j,n,a,b,c,volume[110],min,max,min_in,max_in;
    char name[101][25];

    scanf("%lld",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%lld",&n);

        for (j=0; j<n; j++)
        {
            scanf("%s %lld %lld %lld",&name[j],&a,&b,&c);

            volume[j]=(a*b*c);
        }

        min=volume[0];
        max=volume[0];
        max_in=0;
        min_in=0;

        for (j=1; j<n; j++)
        {
            if (volume[j]>max)
            {
                max=volume[j];
                max_in=j;
            }
            if (volume[j]<min)
            {
                min=volume[j];
                min_in=j;
            }
        }

        if (min==max)
            printf("Case %lld: no thief\n",i);
        else
            printf("Case %lld: %s took chocolate from %s\n",i,name[max_in],name[min_in]);
    }

    return 0;
}
