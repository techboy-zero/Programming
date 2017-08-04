#include<stdio.h>
long long a[10020];

int main()
{
    int n,i,j,k,t,l,temp;
    long long total;
    scanf("%d", &t);
    for(i=1;i<=t;i++)
    {
        k=0;
        scanf("%lld %lld %lld %lld %lld %lld %d",&a[k],&a[k+1],&a[k+2],&a[k+3],&a[k+4],&a[k+5],&n);
        if(n<=5)
        {
            printf("Case %d: %lld",i,a[n]%10000007);
        }
        else
        {
            for(j=6;j<=n;j++)
            {
                total=0;
                for(l=j-6;l<=j-1;l++)
                {
                    total=(total%10000007+a[l]%10000007)%10000007;
                }
                a[j]=total;
            }
            printf("Case %d: %lld",i,a[n]);
        }
        printf("\n");
    }

    return 0;
}
