#include <stdio.h>
#include <string.h>

int main()
{
    char num1[50],num2;
    int t,i,j,len,count;
    long long num3,num4;

    scanf("%d",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%s %c",num1,&num2);

        getchar();

        num3=atoi(num1);

        len=strlen(num1);

        for (j=0; j<len; j++)
            num1[j]=num2;

        num1[j]='\0';

        num4=atoi(num1);

        num2=(num2-'0');

        for (count=len; ; count++)
        {
            if (num4%num3!=0)
                num4=(num4%num3)*10+num2;
            else
                break;
        }

        printf("Case %d: %d\n",i,count);
    }

    return 0;
}
