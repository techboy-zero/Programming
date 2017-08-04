#include <stdio.h>
#include <math.h>

int main()
{
    int t,i;
    double h1,h2,r1,r2,r3,d2,d3,p,volume;
    double pi=2*acos(0.0);

    scanf("%d", &t);

    for (i=1; i<=t; i++)
    {
        scanf("%lf %lf %lf %lf",&r1,&r2,&h1,&p);

        h2=(h1*r2)/(r1-r2);

        r3=(r2*(h2+p))/h2;

        d2=2*r2;
        d3=2*r3;

        volume = (pi*p*(d2*d2+d2*d3+d3*d3))/12;

        printf("Case %d: %.9lf\n",i,volume);
    }

    return 0;
}
