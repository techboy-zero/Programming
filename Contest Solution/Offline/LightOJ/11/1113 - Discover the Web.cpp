#include <stdio.h>
#include <string.h>

int main()
{
    int t,i,j,lpage;
    char str1[10],str2[100][60];

    strcpy(str2[0],"http://www.lightoj.com/");

    scanf("%d", &t);

    for (i=1; i<=t; i++)
    {
        printf("Case %d:\n",i);

        j=0;
        lpage=0;

        do
        {
            scanf("%s",&str1);

            if (strcmp(str1,"VISIT")==0)
            {
                scanf("%s",&str2[++j]);

                lpage=j;

                printf("%s\n",str2[j]);
            }
            else if (strcmp(str1,"FORWARD")==0)
            {
                if (j==lpage)
                    printf("Ignored\n");
                else
                    printf("%s\n",str2[++j]);
            }
            else if (strcmp(str1,"BACK")==0)
            {
                if (j==0)
                    printf("Ignored\n");
                else
                    printf("%s\n",str2[--j]);
            }


        }
        while(strcmp(str1,"QUIT")!=0);
    }

    return 0;
}
