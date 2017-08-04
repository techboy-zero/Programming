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

int n,m,cost[510],start;
vector <int> nodes[510],nodes_cost[510];
priority_queue < pair<int,int> > q;

void dijkstra()
{
    cost[start]=0;
    q.push( make_pair(0,start) );

    while (!q.empty())
    {
        int from=q.top().second, curr= -q.top().first, limit=nodes[from].size();
        q.pop();

        if (curr>cost[from]) continue;

        for (int i=0; i<limit; i++)
        {
            int to=nodes[from][i], value=nodes_cost[from][i];
            if (value<cost[from]) value=cost[from];
            if (value<cost[to])
            {
                cost[to]=value;
                q.push( make_pair(-value,to) );
            }
        }
    }
}

void set_values(void)
{
    for (int i=0; i<n; i++)
    {
        cost[i]=999999999;
        nodes[i].clear();
        nodes_cost[i].clear();
    }
}

int main()
{
    //freopen("input.txt","r",stdin);

    int t;
    scanf("%d",&t);

    for (int i=1; i<=t; i++)
    {
        cin>>n>>m;
        set_values();

        int u,v,c;

        for (int j=0; j<m; j++)
        {
            cin>>u>>v>>c;
            nodes[u].push_back(v);
            nodes[v].push_back(u);
            nodes_cost[u].push_back(c);
            nodes_cost[v].push_back(c);
        }
        scanf("%d",&start);
        dijkstra();

        printf("Case %d:\n",i);

        for (int j=0; j<n; j++)
            if (cost[j]==999999999)
                printf("Impossible\n");
            else
                printf("%d\n",cost[j]);
    }

    return 0;
}
