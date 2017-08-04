#include <stdio.h>
#include <string.h>

int main()
{
    int t,i,j,k,n,m,d,x,y,z;
    int a[100000],b[100000];
    char ch;

    scanf("%d",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%d %d",&n,&m);

        for (j=0; j<n; j++)
            scanf("%d",&a[j]);

        for (k=1; k<=m; k++)
        {
            getchar();
            scanf("%c",&ch);

            if (ch=='S')
            {
                scanf("%d",&d);

                for (j=0; j<n; j++)
                    a[j]=a[j]+d;
            }
            else if (ch=='M')
            {
                scanf("%d",&d);

                for (j=0; j<n; j++)
                    a[j]=a[j]*d;
            }
            else if (ch=='D')
            {
                scanf("%d",&d);

                for (j=0; j<n; j++)
                    a[j]=a[j]/d;
            }
            else if (ch=='R')
            {
                x=n-1;

                for (j=0; j<n; j++)
                {
                    b[j]=a[x];
                    x--;
                }

                for (j=0; j<n; j++)
                    a[j]=b[j];
            }
            else if (ch=='P')
            {
                scanf("%d %d",&y,&z);

                b[0]=a[y];
                a[y]=a[z];
                a[z]=b[0];
            }
        }

        printf("Case %d:\n",i);

        for (j=0; j<n; j++)
        {
            printf("%d",a[j]);

            if (j<(n-1))
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
