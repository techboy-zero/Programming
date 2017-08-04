#include <stdio.h>

int main()
{
    int n,i,j;
    long long int t,total,x;
    char ch[10];

    scanf("%lld", &t);

    for (i=1; i<=t; i++)
    {
        printf("Case %d:\n",i);
        total=0;
        scanf("%d", &n);

        for (j=1; j<=n; j++)
        {
            scanf("%s",ch);

            if (strcmp(ch,"donate")==0)
            {
                scanf("%lld", &x);
                total+=x;
            }
            else if (strcmp(ch,"report")==0)
                printf("%lld\n",total);
        }
    }

    return 0;
}
