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

int n,m,value[101];
vector <int> nodes[101],node_cost[101];
priority_queue < pair<int,int> > q;

void setup(void)
{
    for (int i=1; i<=n; i++)
    {
        value[i]=999999999;
        nodes[i].clear();
        node_cost[i].clear();
    }
}

void dijkstra(void)
{
    value[1]=0;
    q.push( make_pair(0,1) );

    while (!q.empty())
    {
        int from=q.top().second, curr=-q.top().first, limit=nodes[from].size();
        q.pop();

        if (curr>value[from]) continue;

        for (int i=0; i<limit; i++)
        {
            int to=nodes[from][i], cost=node_cost[from][i];

            if (value[from]+cost<value[to])
            {
                value[to]=value[from]+cost;
                q.push(make_pair(-value[to],to));
            }
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);

    int t;
    cin>>t;

    for (int i=1; i<=t; i++)
    {
        cin>>n>>m;
        setup();

        for (int j=1; j<=m; j++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            nodes[u].push_back(v);
            nodes[v].push_back(u);
            node_cost[u].push_back(w);
            node_cost[v].push_back(w);
        }

        dijkstra();

        printf("Case %d: ",i);
        if (value[n]==999999999)
            printf("Impossible\n");
        else
            printf("%d\n",value[n]);

    }

    return 0;
}
