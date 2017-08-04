#include <stdio.h>
#include <math.h>

int main()
{
    double r,pi=2*acos(0),space;
    int T,i;

    scanf("%d", &T);

    for(i=1; i<=T; i++)
    {
        scanf("%lf",&r);
        space=(r*r*4)-(pi*r*r);
        printf("Case %d: %.2lf\n",i,space);
    }

    return 0;
}
