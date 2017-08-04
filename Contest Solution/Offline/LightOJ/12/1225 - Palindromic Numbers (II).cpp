#include <stdio.h>
#include <string.h>

int main()
{
    int t,i,j,x;
    char n[1000000];

    scanf("%d",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%s",&n);

        x=strlen(n);

        for (j=0; ; j++)
        {
            --x;

            if (j>x)
            {
                printf("Case %d: Yes\n",i);
                break;
            }
            else if (n[j]!=n[x])
            {
                printf("Case %d: No\n",i);
                break;
            }
        }
    }

    return 0;
}
