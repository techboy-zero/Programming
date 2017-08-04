#include <stdio.h>

int main()
{
    int t,x,y,i;

    scanf("%d", &t);

    for (i=1; i<=t; i++)
    {
        scanf("%d %d",&x,&y);

        if (y>x)
            printf("Case %d: %d\n",i,9+10+(y-x)*4+x*4);
        else if (x>y)
            printf("Case %d: %d\n",i,9+10+(x-y)*4+x*4);
        else
            printf("Case %d: %d\n",i,9+10+x*4);
    }

    return 0;
}
