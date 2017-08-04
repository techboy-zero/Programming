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
#define MOD 100000007

using namespace std;

struct cycle {
    int x,y,cost;
}e[2010];

int n,m,cost[1010];
vector <int> edges[1010],order;
bool visit[1010];

void Init () {
    memset(cost,0,sizeof(cost));
    memset(visit,false,sizeof(visit));
    order.clear();
}

void dfs (int u) {
    visit[u]=true;
    order.push_back(u);

    int sz=edges[u].size();
    for (int i = 0; i < sz; i++) {
        int v = edges[u][i];
        if (!visit[v]) dfs(v);
    }
}

void Bellman_Ford () {
    Init();

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++)
            if (cost[e[j].y] > cost[e[j].x] + e[j].cost) {
                cost[e[j].y] = cost[e[j].x] + e[j].cost;
                if (i == n) {
                    if (!visit[ e[j].y ])
                        dfs(e[j].y);
                }
            }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>n>>m;

        for (int i = 0; i < m; i++) {
            cin>>e[i].y>>e[i].x>>e[i].cost;
            edges[e[i].x].push_back(e[i].y);
        }

        Bellman_Ford ();

        printf("Case %d:",kase);
        if (!order.size()) cout<<" impossible"<<endl;
        else {
            int sz=order.size();
            sort(order.begin(),order.end());

            for (int i = 0; i < sz; i++)
                cout<<" "<<order[i];
            cout<<endl;
        }

        for (int i = 0; i < n; i++)
            edges[i].clear();
    }

    return 0;
}
