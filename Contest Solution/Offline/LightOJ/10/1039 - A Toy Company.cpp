#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

#define sqr(x) (x*x)
#define cube(x) (x*x*x)

using namespace std;

int t,n;
char space[4], start[4], desti[4], first[51][27], sec[51][27], third[51][27];

map <string,int> words;
map <string,bool> check;
queue <string>  toy;

void forbidden_gen(void)
{
    words[desti]=-2;    //marking the destination

    for (int i=0; i<n; i++)
    {
        int len1=strlen(first[i]), len2=strlen(sec[i]), len3=strlen(third[i]);

        for (int j=0; j<len1; j++)
            for (int k=0; k<len2; k++)
                for (int l=0; l<len3; l++)
                {
                    char str[4];
                    str[0]=first[i][j];
                    str[1]=sec[i][k];
                    str[2]=third[i][l];
                    str[3]='\0';

                    words[str]=-1;
                }
    }
}

void bfs(void)
{
    if (words[start] == -1)   return;

    toy.push(start);
    words[start]=0;
    check[start]=true;

    if ( !strcmp( start, desti) )   return;

    while (!toy.empty())
    {
        string temp1 = toy.front(), temp2;
        toy.pop();

        for (int i = 0; i < 3; i++)
        {
            temp2 = temp1;
            temp2[i]++;
            if (temp2[i] > 'z') temp2[i] = 'a';

            if (words[temp2] != -1 && !check[temp2])
            {
                toy.push(temp2);
                words[temp2] = words[temp1] + 1;
                check[temp2]=true;

                if (desti == temp2)   return;
            }

            temp2 = temp1;
            temp2[i]--;
            if (temp2[i] < 'a') temp2[i] = 'z';

            if (words[temp2] != -1 && !check[temp2])
            {
                toy.push(temp2);
                words[temp2] = words[temp1] + 1;
                check[temp2]=true;

                if (desti == temp2)   return;
            }
        }
    }

    if (words[desti] == -2)   words[desti] = -1;
}

void clean(void)
{
    words.clear();
    check.clear();

    while (!toy.empty())
        toy.pop();
}

int main()
{
    cin>>t;
    getchar();

    for (int i=1; i<=t; i++)
    {
        gets(space);
        cin>>start>>desti;

        cin>>n;
        for (int j=0; j<n; j++)
            cin>>first[j]>>sec[j]>>third[j];

        forbidden_gen();

        bfs();

        if (words[desti]==-2)   words[desti]=-1;

        printf("Case %d: %d\n",i,words[desti]);

        clean();
    }

    return 0;
}
