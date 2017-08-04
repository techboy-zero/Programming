#include <stdio.h>
#include <string.h>

int main()
{
    int t,i,k,same;
    char bin1[4][10],bin2[4][10];
    unsigned int a,b,c,d,j;

    scanf("%d",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%u.%u.%u.%u",&a,&b,&c,&d);
        getchar();

        for(k = 0; k < 4; k++)
        {
            scanf("%[01]s", bin1[k]);
            getchar();
        }

        k=0;
        same=0;

        for (j=1<<7; k<=7; j>>=1)
        {
            if (j & a)
                bin2[0][k]='1';
            else
                bin2[0][k]='0';

            if (j & b)
                bin2[1][k]='1';
            else
                bin2[1][k]='0';

            if (j & c)
                bin2[2][k]='1';
            else
                bin2[2][k]='0';

            if (j & d)
                bin2[3][k]='1';
            else
                bin2[3][k]='0';

            k++;
        }

        for (j=0; j<4; j++)
        {
            bin2[j][k]='\0';
        }

        for (j=0; j<4; j++)
        {
            if (strcmp(bin1[j],bin2[j])==0)
                same++;
        }

        if (same==4)
            printf("Case %d: Yes\n",i);
        else
            printf("Case %d: No\n",i);

    }

    return 0;
}
