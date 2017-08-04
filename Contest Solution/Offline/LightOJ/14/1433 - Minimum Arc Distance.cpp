#include <stdio.h>
#include <math.h>

int main()
{
    int t,i,j,x[3],y[3];
    double a,b,o,theta,radius,arc;

    scanf("%d",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%d %d %d %d %d %d",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2]);

        o=sqrt(pow(x[1]-x[2],2)+pow(y[1]-y[2],2));
        a=sqrt(pow(x[0]-x[2],2)+pow(y[0]-y[2],2));
        b=sqrt(pow(x[0]-x[1],2)+pow(y[0]-y[1],2));

        theta=acos((a*a+b*b-o*o)/(2*a*b));

        radius=a;

        arc=theta*radius;

        printf("Case %d: %.8lf\n",i,arc);
    }

    return 0;
}
