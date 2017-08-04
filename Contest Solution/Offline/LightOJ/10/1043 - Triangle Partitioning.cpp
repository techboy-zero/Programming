#include <stdio.h>
#include <math.h>

int main()
{
    int t,i;
    double ab,bc,ca,ad,ratio1,ratio2;

    scanf("%d",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%lf %lf %lf %lf",&ab,&bc,&ca,&ratio1);

        ratio2=(1.00+ratio1)/ratio1;

        ad=ab/sqrt(ratio2);

        printf("Case %d: %.10lf\n",i,ad);
    }

    return 0;
}
