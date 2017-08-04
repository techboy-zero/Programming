#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int t,i;
    double a,b,c,d,h,base,area,e;

    scanf("%d",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);

        if (b==d)
        {
            base=fabs(a-c)/2;

            h=sqrt(b*b-base*base);

            area=0.5*h*(c+a);
        }
        else
        {
            base=fabs(c-a);
            e=(b*b-d*d-base*base)/(2.0*base);

            h=sqrt(d*d-e*e);

            area=0.5*h*(c+a);
        }

        printf("Case %d: %lf\n",i,area);
    }

    return 0;
}
