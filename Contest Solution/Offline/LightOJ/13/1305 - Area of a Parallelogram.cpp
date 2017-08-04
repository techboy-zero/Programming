#include <stdio.h>
#include <math.h>

int main()
{
    int t,i;
    double a,b,ab,bc,ca,s,area,x[4],y[4];;

    scanf("%d",&t);

    for(i=1; i<=t; i++)
    {
        scanf("%lf %lf %lf %lf %lf %lf",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2]);

        x[3]=x[0]+x[2]-x[1];
        y[3]=y[0]+y[2]-y[1];

        ab=sqrt(pow(x[0]-x[1],2)+pow(y[0]-y[1],2));
        bc=sqrt(pow(x[1]-x[2],2)+pow(y[1]-y[2],2));
        ca=sqrt(pow(x[2]-x[0],2)+pow(y[2]-y[0],2));

        s=(ab+bc+ca)/2.0;

        area=2*sqrt(s*(s-ab)*(s-bc)*(s-ca));

        printf("Case %d: %.0lf %.0lf %.0lf\n",i,x[3],y[3],area);
    }

    return 0;
}
