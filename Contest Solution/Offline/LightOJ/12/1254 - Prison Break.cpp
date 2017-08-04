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

int n,m,query,fuel_price[107],cost[107][107],desti_cost;

vector < pair<int,int> > tanks[107];
priority_queue < pair<int,pair<int,int> > > pq;

void init(int capa) {
    for (int i=0; i<n; i++)
        for (int j=0; j<=capa; j++)
            cost[i][j]=INF;
}

void Dijkstra(int start,int desti,int capacity) {
    init(capacity);
    cost[start][0]=0;
    desti_cost=INF;

    pq.push(make_pair(0,make_pair(0,start)));

    while(!pq.empty()) {
        int from=pq.top().second.second, curr=-pq.top().first, limit=tanks[from].size(), reserve=pq.top().second.first;
        pq.pop();

        if (from==desti){
            desti_cost=curr;
            break;
        }

        if (reserve+1<=capacity && cost[from][reserve+1]>cost[from][reserve]+fuel_price[from])
        {
            cost[from][reserve+1]=cost[from][reserve]+fuel_price[from];
            pq.push(make_pair(-cost[from][reserve+1],make_pair(reserve+1,from)));
        }

        for (int i=0; i<limit; i++) {
            int to=tanks[from][i].first, dist=tanks[from][i].second;

            if (dist>reserve) continue;

            if (cost[to][reserve-dist]>cost[from][reserve])
            {
                cost[to][reserve-dist]=cost[from][reserve];
                pq.push(make_pair(-cost[to][reserve-dist],make_pair(reserve-dist,to)));
            }
        }
    }

    while(!pq.empty())
        pq.pop();
}

int main() {
    #ifdef Local
    freopen("input.txt","r",stdin);
    #endif
    int t;
    scanf("%d",&t);

    for (int kase=1; kase<=t; kase++) {
        scanf("%d %d",&n,&m);

        for (int i=0; i<n; i++)
            scanf("%d",&fuel_price[i]);

        for (int i=0; i<m; i++) {
            int node1,node2,cost;
            scanf("%d %d %d",&node1,&node2,&cost);

            tanks[node1].push_back(make_pair(node2,cost));
            tanks[node2].push_back(make_pair(node1,cost));
        }

        printf("Case %d:\n",kase);
        scanf("%d",&query);

        for (int i=0; i<query; i++) {
            int start,desti,capacity;

            scanf("%d %d %d",&capacity,&start,&desti);
            Dijkstra(start,desti,capacity);

            if (desti_cost==INF) printf("impossible\n");
            else                 printf("%d\n",desti_cost);
        }

        for (int i=0; i<n; i++)
            tanks[i].clear();
    }

    return 0;
}
