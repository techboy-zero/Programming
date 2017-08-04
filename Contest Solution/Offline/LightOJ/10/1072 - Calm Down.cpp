#include <stdio.h>
#include <math.h>

int main()
{
    int t,n,i;
    double R,r;
    double pi=2*acos(0.0);

    scanf("%d", &t);

    for (i=1; i<=t; i++)
    {
        scanf("%lf %d", &R, &n);

        r=(R*sin(pi/n))/(sin(pi/n)+1);

        printf("Case %d: %.10lf\n",i,r);
    }

    return 0;
}
