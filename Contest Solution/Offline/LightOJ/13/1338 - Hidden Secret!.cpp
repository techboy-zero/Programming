#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int t,i,k,m,letter1,letter2,count1[30],count2[30],index;
    char name1[150],name2[150];
    char alpha[]=
    {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    scanf("%d",&t);
    getchar();

    for (i=1; i<=t; i++)
    {
        gets(name1);
        gets(name2);

        letter1=0;
        letter2=0;

        for (k=0; k<26; k++)
            count1[k]=0;                //these arrays will be used later to keep the record of numbers of letters
        for (k=0; k<26; k++)
            count2[k]=0;

        for (k=0; k<strlen(name1); k++)
        {
            if (name1[k]!=' ')
                letter1++;              //here we will count total letter numbers of first string
        }

        for (k=0; k<strlen(name2); k++)
        {
            if (name2[k]!=' ')
                letter2++;              //here we will count total letter numbers of second string
        }

        if (letter1!=letter2)
            printf("Case %d: No\n",i);
        else
        {
            for (k=0; k<strlen(name1); k++)
                name1[k]=toupper(name1[k]);     //changing all letters to upper case

            for (k=0; k<strlen(name2); k++)
                name2[k]=toupper(name2[k]);

            for (k=0; k<strlen(name1); k++)
            {
                if (name1[k]==' ')
                    continue;

                index=(int) name1[k]-65;        //getting the integer value of the character and substituting 65

                count1[index]++;                //increasing the number to keep record of recurrance of a letter
            }

            for (k=0; k<strlen(name2); k++)
            {
                if (name2[k]==' ')
                    continue;

                index=(int) name2[k]-65;

                count2[index]++;
            }

            for (k=0; k<26; k++)
            {
                if (count1[k]!=count2[k])
                {
                    printf("Case %d: No\n",i);
                    break;
                }
            }

            if (k==26)
                printf("Case %d: Yes\n",i);
        }
    }

    return 0;
}
