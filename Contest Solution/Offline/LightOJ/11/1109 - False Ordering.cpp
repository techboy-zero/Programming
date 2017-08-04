#include <stdio.h>
#include <math.h>

int main()
{
    int t,order1[1001],order2[1001],i,j,count,index,num,temp;      //using 1001 indexes for array.it will help us use from 1-1000 instead of 0-999.

    for (i=0; i<=1000; i++)
        order1[i]=i;            //first array will be used to store the numbers

    order2[0]=0;
    order2[1]=1;

    for (i=2; i<=1000; i++)
    {
        count=0;

        for(j=1; j<=sqrt(i); j++)        //process of counting divisors number
        {
            if (j*j==i)                     //special check for root of the number
                count++;
            else if (i%j==0)
                count+=2;
        }

        order2[i]=count;            //second array will be used to store their divisor numbers
    }

    for (i=2; i<1000; i++)
    {
        index=i;

        for (j=i+1; j<=1000; j++)
        {
            if (order2[j]<order2[index])            //if the second number's divisor is greater than the previous then index will be renewed
                index=j;
            else if (order2[j]==order2[index])
            {
                if (order1[j]>order1[index])        //in case of same number of divisors the bigger number will get preference
                    index=j;
            }
        }

        temp=order2[index];             //here we will exchange the divisors
        order2[index]=order2[i];
        order2[i]=temp;


        temp=order1[index];             //here we will exchange the number
        order1[index]=order1[i];
        order1[i]=temp;
    }

    scanf("%d",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%d",&num);

        printf("Case %d: %d\n",i,order1[num]);
    }

    return 0;
}
