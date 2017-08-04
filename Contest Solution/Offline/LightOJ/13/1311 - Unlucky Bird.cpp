#include <stdio.h>

int main()
{
    double v1,v2,v3,a1,a2,s1,s2,t1,t2,d1,d2;
    int t,i;

    scanf("%d",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%lf %lf %lf %lf %lf",&v1,&v2,&v3,&a1,&a2);   //v for velocity,a for acceleration of train

        s1=(v1*v1)/(2.0*a1);        //distance travelled by first train before stopping
        s2=(v2*v2)/(2.0*a2);        //distance travelled by second train before stopping

        d1=s1+s2;                   //distance when two drivers saw each other

        t1=(v1/a1);                 //time needed by first train to stop
        t2=(v2/a2);                 //time needed by second train to stop

        if (t1==t2)
            d2=t1*v3;               //we can use t2 too.both are same
        else if(t1>t2)
            d2=t1*v3;
        else
            d2=t2*v3;

        printf("Case %d: %0.8lf %0.8lf\n",i,d1,d2);
    }

    return 0;
}
