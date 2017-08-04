#include <stdio.h>
#include <math.h>

int main()
{
    int t,i;
    long long int s,root,side1,side2,square,x,y;
    double check;

    scanf("%d",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%lld",&s);

        root=sqrt(s);       //this is for getting integer value
        check=sqrt(s);      //this is for getting float value

        if ((root*1.0)==check)
        {
            side1=pow(root,2);
            side2=side1-2*(root-1);
        }
        else
        {
            root+=1;
            side1=pow(root,2);
            side2=side1-2*(root-1);
        }

        if (side1%2==0)
        {
            if ((side1-s)<root)
            {
                x=root;
                y=(side1-s)+1;
            }
            else
            {
                x=(s-side2)+1;
                y=root;
            }
        }
        else
        {
            if ((side1-s)<root)
            {
                x=(side1-s)+1;
                y=root;
            }
            else
            {
                x=root;
                y=(s-side2)+1;
            }
        }

        printf("Case %d: %lld %lld\n",i,x,y);
    }

    return 0;
}
