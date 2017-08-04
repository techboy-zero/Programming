#include <stdio.h>

int main()
{
    int t,i,j,three;
    long int a,b,d;

    scanf("%d", &t);

    for (i=1; i<=t; i++)
    {
        three=0;
        scanf("%ld %ld",&a,&b);

        d=b-a;

        if (a%3==1 && b%3==1)
            three=d-(d/3);
        else if ((a%3==2 && b%3==2) || (a%3==0 && b%3==0))
            three=(2*d/3)+1;
        else if (a%3==1 && b%3==2)
            three=(2*(d-1)/3)+1;
        else if ((a%3==1 && b%3==0) || (a%3==2 && b%3==1))
            three=2*((d+1)/3);
        else if (a%3==2 && b%3==0)
            three=((d+2)/3)*2;
        else if (a%3==0 && b%3==1)
            three=d-((d-1)/3);
        else if (a%3==0 && b%3==2)
            three=((d+1)/3)*2;


        printf("Case %d: %d\n",i,three);
    }

    return 0;
}
