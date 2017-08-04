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

vector <int>  nodes[20001];
int color[20001],black,white,mx;

void dfs(int u,int col)
{
    if (col)    white++;
    else        black++;

    color[u]=col;
    int len=nodes[u].size();

    for (int i=0; i<len; i++)
        if (color[nodes[u][i]]==-1)
            dfs(nodes[u][i],(col+1)%2);
}

int main()
{
    int t;

    scanf("%d",&t);

    for (int i=1; i<=t; i++)
    {
        int n,node1,node2,hi=0;

        scanf("%d",&n);

        for (int j=0; j<n; j++)
        {
            scanf("%d %d",&node1,&node2);

            nodes[node1].push_back(node2);      nodes[node2].push_back(node1);

            color[node1]=color[node2]=-1;

            if (node1>hi)   hi=node1;
            if (node2>hi)   hi=node2;
        }

        mx=0;

        for (int j=1; j<=hi; j++)
        {
            if (color[j]==-1)
            {
                black=white=0;
                dfs(j,0);

                mx+=(black>white?black:white);
            }
        }

        printf("Case %d: %d\n",i,mx);

        for (int j=1; j<=hi; j++)
            nodes[j].clear();
    }

    return 0;
}
