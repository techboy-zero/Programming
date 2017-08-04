#include <stdio.h>
#include <string.h>

int main()
{
    int t,i,j,pleft,pright,push,n,m,x,y,kase=0;
    int a[250];
    char s[20];

    scanf("%d", &t);

    for (i=1; i<=t; i++)
    {
        scanf("%d %d",&n,&m);

        push=0;
        pleft=100;
        pright=101;

        printf("Case %d:\n",++kase);

        for (j=1; j<=m; j++)
        {
            scanf("%s",&s);

            if (strcmp(s,"pushLeft")==0)
            {
                scanf("%d",&x);

                if (push==n)
                    printf("The queue is full\n");
                else
                {
                    a[pleft--]=x;

                    push++;

                    printf("Pushed in left: %d\n",x);
                }
            }
            else if (strcmp(s,"pushRight")==0)
            {
                scanf("%d",&x);

                if (push==n)
                    printf("The queue is full\n");
                else
                {
                    a[pright++]=x;

                    push++;

                    printf("Pushed in right: %d\n",x);
                }
            }
            else if (strcmp(s,"popLeft")==0)
            {
                if (push==0)
                    printf("The queue is empty\n");
                else
                {
                    printf("Popped from left: %d\n",a[++pleft]);

                    push--;
                }
            }
            else if (strcmp(s,"popRight")==0)
            {
                if (push==0)
                    printf("The queue is empty\n");
                else
                {
                    printf("Popped from right: %d\n",a[--pright]);

                    push--;
                }
            }
        }
    }

    return 0;
}
