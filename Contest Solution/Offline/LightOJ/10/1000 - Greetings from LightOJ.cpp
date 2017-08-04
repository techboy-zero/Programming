#include <stdio.h>

int main()
{
    int a,b,T,i,x[125];

    scanf("%d",&T);

    if (T<=125)
    {
        for (i=0; i<T; i++)
        {
            scanf("%d %d",&a,&b);

            x[i]=a+b;
        }

        for (i=0; i<T; i++)
        {
            printf("Case %d: %d\n",i+1,x[i]);
        }
    }
    else
        printf("WRONG INPUT!\n\n");

    return 0;
}
