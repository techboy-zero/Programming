#include <stdio.h>
#include <string.h>

int monthcheck(char m[20])
{
    char month[12][20]=
    {
        "January","February","March","April","May","June","July","August","September",
        "October","November","December"
    };
    int i;

    for (i=0; i<12; i++)
    {
        if (strcmp(m,month[i])==0)
            return i+1;
    }
}

int main()
{
    int t,i,j,k,d1,d2,m1,m2;
    long long int y1,y2,lyear;
    char m[2][20];

    scanf("%d",&t);

    for (i=1; i<=t; i++)
    {
        lyear=0;

        scanf("%s %d, %lld",&m[0],&d1,&y1);
        scanf("%s %d, %lld",&m[1],&d2,&y2);

        m1=monthcheck(m[0]);
        m2=monthcheck(m[1]);

        lyear=((y2/4)-(y2/100)+(y2/400))-((y1/4)-(y1/100)+(y1/400));

        if (y1%4==0 && m1<=2)
        {
            if (y1%100==0)
            {
                if (y1%400==0)
                    lyear++;
            }
            else
                lyear++;
        }

        if (y2%4==0 && m2<2)
        {
            if (y2%100==0)
            {
                if (y2%400==0)
                    lyear--;
            }
            else lyear--;
        }
        if (y2%4==0 && (m2==2 && d2<29))
        {
            if(y2%100==0)
            {
                if(y2%400==0) lyear--;
            }
            else lyear--;
        }

        printf("Case %d: %lld\n",i,lyear);
    }

    return 0;
}
