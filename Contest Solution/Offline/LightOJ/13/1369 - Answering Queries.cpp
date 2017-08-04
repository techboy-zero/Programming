#include <stdio.h>

long long f(long long int a[],long long int n)
{
    long long sum = 0,i;

    for(i=0; i<n; i++)
    {
        sum+=(n-2*i-1)*a[i];
    }

    return sum;
}

int main()
{
    int t,i;
    long long int sum,j,k,n,q,x,v,num,a[100500];

    scanf("%d",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%lld %lld",&n,&q);

        for (j=0; j<n; j++)
        {
            scanf("%lld",&a[j]);
        }

        sum=f(a,n);

        printf("Case %d:\n",i);

        for (k=1; k<=q; k++)
        {
            scanf("%lld",&num);

            if (num==0)
            {
                scanf("%lld %lld",&x,&v);

                sum+=(n-2*x-1)*(v-a[x]);

                a[x]=v;
            }

            else if (num==1)
                printf("%lld\n",sum);
        }
    }

    return 0;
}
