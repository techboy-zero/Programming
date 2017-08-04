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
#define INF 999999999

using namespace std;

struct traffic{
    int a,b,cost;
}edges[40007];

int nodes,edge_total,node_cost[207],busy_cost[207];
bool negative_cycle[207];

void init(){
    fill(node_cost,node_cost+nodes+1,INF);
    memset(negative_cycle,false,sizeof(negative_cycle));
}

void Bellman_Ford(){
    init();
    node_cost[1]=0;

    for (int i=1; i<=nodes; i++){
        for (int j=0; j<edge_total; j++)
            if (node_cost[edges[j].a]<INF){
                int u=node_cost[edges[j].a], v=node_cost[edges[j].b];
                if (v>u+edges[j].cost){
                    v=u+edges[j].cost;
                    node_cost[edges[j].b]=v;
                    if (i==nodes) negative_cycle[edges[j].b]=true;
                }
            }
    }
}

bool check(int desti){
    if (negative_cycle[desti]) return false;
    if (desti>nodes)           return false;
    if (desti==1)              return false;
    if (node_cost[desti]==INF) return false;
    if (node_cost[desti]<3)    return false;
    if (!nodes)                return false;

    return true;
}

int main()
{
    #ifdef Local
    freopen("input.txt","r",stdin);
    #endif

    int t;
    cin>>t;

    for (int kase=1; kase<=t; kase++){
        cin>>nodes;
        for (int i=1; i<=nodes; i++)
            cin>>busy_cost[i];

        cin>>edge_total;
        for (int i=0; i<edge_total; i++){
            cin>>edges[i].a>>edges[i].b;

            int u=busy_cost[edges[i].b], v=busy_cost[edges[i].a];
            edges[i].cost=pow(u-v,3);
        }

        Bellman_Ford();
        int query;
        cin>>query;
        printf("Case %d:\n",kase);

        for (int i=0; i<query; i++){
            int desti;
            cin>>desti;

            if (check(desti)) cout<<node_cost[desti]<<endl;
            else              cout<<"?"<<endl;
        }
    }

    return 0;
}
