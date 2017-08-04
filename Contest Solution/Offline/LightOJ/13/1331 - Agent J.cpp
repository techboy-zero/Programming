#include <stdio.h>
#include <math.h>
int main()
{
    int t,kase=1;
    double r1,r2,r3,res,pei,a,b,c,s,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf %lf",&r1,&r2,&r3);

        a=r1+r2;

        b=r2+r3;

        c=r1+r3;

        s=(a+b+c)/2.0;

        res = sqrt(s*(s-a)*(s-b)*(s-c));

        pei=acos((a*a+c*c-b*b)/2/a/c);

        x=r1*r1*180.0;

        res-=(x*pei)/360.0;

        pei=acos((b*b+c*c-a*a)/2/b/c);

        x=r3*r3*180.0;

        res-=(x*pei)/360.0;

        pei=acos((a*a+b*b-c*c)/2/a/b);

        x=r2*r2*180.0;

        res-=(x*pei)/360.0;

        printf("Case %d: %.11lf\n",kase++,res);

    }
    return 0;
}
