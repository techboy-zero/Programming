#include <stdio.h>

int main()
{
    int t,i;
    long long int m,n,d,zero,nine,num1,num2;

    scanf("%d",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%lld %lld",&m,&n);

        zero=0;
        nine=0;

        if (m==0)
            zero++;

        for (d=10; (n/d)!=0; d*=10)
        {
            zero+=(n/d);
            zero-=((m-1)/d);

            nine+=(9*(d/100));

            if (d>=100)
            {
                num1=n/d;

                if (num1>0)
                {
                    zero+=(num1-1)*nine;

                    if (n%d>=nine)
                        zero+=nine;
                    else
                        zero+=(n%d);
                }

                num2=(m-1)/d;

                if (num2>0)
                {
                    zero-=(num2-1)*nine;

                    if ((m-1)%d>=nine)
                        zero-=nine;
                    else
                        zero-=((m-1)%d);
                }
            }
        }

        printf("Case %d: %lld\n",i,zero);
    }

    return 0;
}
