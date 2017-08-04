#include <stdio.h>  //code accepted

int main()
{
    int t,i,n;

    scanf("%d",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%d",&n);

        if (n<10)
            printf("0 %d\n",n);
        else
            printf("10 %d\n",(n-10));
    }

    return 0;
}
