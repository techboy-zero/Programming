#include <stdio.h>

int main()
{
    int t,i,j,n,p,q,egg[31],weight,count;

    scanf("%d",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%d %d %d",&n,&p,&q);

        for (j=0; j<n; j++)
            scanf("%d",&egg[j]);

        weight=0;
        count=0;

        for (j=0; j<n; j++)
        {
            weight+=egg[j];
            count++;

            if (count==p)
            {
                if (weight>q)
                    count--;

                break;
            }
            else if (weight==q)
                break;
            else if (weight>q)
            {
                count--;
                break;
            }
        }

        printf("Case %d: %d\n",i,count);
    }

    return 0;
}
