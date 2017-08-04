#include <stdio.h>

int main()
{
    int t,a,b,c,i;

    scanf("%d", &t);

    for (i=1; i<=t; i++)
    {
        scanf("%d %d %d",&a,&b,&c);

        if (a==b && b==c)
            printf("Case %d: no\n",i);
        else
        {
            if ((a*a==b*b+c*c) || (b*b==c*c+a*a) || (c*c==a*a+b*b))
                printf("Case %d: yes\n",i);
            else
                printf("Case %d: no\n",i);
        }
    }

    return 0;
}
