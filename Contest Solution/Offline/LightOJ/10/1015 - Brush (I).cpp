#include <stdio.h>

int main()
{
    int t,n,i,j,total,x[1000];

    scanf("%d",&t);

    for (i=1; i<=t; i++)
    {
        total=0;
        scanf("%d",&n);

        for(j=0; j<n; j++)
        {
            scanf("%d",&x[j]);

            if (x[j]>0)
                total+=x[j];
        }

        printf("Case %d: %d\n",i,total);
    }

    return 0;
}
