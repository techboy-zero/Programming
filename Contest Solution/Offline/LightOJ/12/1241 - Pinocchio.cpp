#include <stdio.h>

int main()
{
    int t,i,j,n,count,size[60],diff;

    scanf("%d",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%d",&n);

        count=0;

        size[0]=2;

        for (j=1; j<=n; j++)
            scanf("%d",&size[j]);

        for (j=1; j<=n; j++)
        {
            diff=size[j]-size[j-1];

            count+=(diff/5);

            if ((diff%5)>0)
                count++;
        }

        printf("Case %d: %d\n",i,count);
    }

    return 0;
}
