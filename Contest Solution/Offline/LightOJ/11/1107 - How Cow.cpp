#include <stdio.h>

int main()
{
    int t,m,x1,y1,x2,y2,x,y,i,j;

    scanf("%d", &t);

    for (i=1; i<=t; i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

        scanf("%d", &m);

        printf("Case %d:\n",i);

        for(j=1; j<=m; j++)
        {
            scanf("%d %d", &x,&y);

            if (x>x1 && x<x2 && y>y1 && y<y2)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}
