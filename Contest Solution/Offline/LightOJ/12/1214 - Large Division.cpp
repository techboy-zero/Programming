#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char num[1000];
    long long div,total,len;
    int t,i,digit;

    scanf("%d",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%s %lld",&num,&div);

        div=llabs(div);

        len=strlen(num);

        int j;

        if (num[0]=='-')
            j=1;
        else
            j=0;

        total=0;

        for (; j<len; j++)
        {
            digit=num[j]-'0';

            total=total*10+digit;

            total=total%div;
        }

        if (total==0)
            printf("Case %d: divisible\n",i);
        else
            printf("Case %d: not divisible\n",i);
    }

    return 0;
}
