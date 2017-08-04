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

struct roads {
    int x,y,cost;
}road_list[100010];

int par[10010],sz[10010];

int find_parent(int x) {
    if (par[x]==x) return x;
    return par[x]=find_parent(par[x]);
}

bool is_united(int x,int y) {
    return find_parent(x)==find_parent(y);
}

bool comp(roads a,roads b) {
    return a.cost<b.cost;
}

void make_united(int x,int y) {
    int u=find_parent(x), v=find_parent(y);
    if (sz[u]<sz[v]) swap(u,v);
    par[v]=u;
    sz[u]+=sz[v];
}

void set_parent(int n) {
    for (int i=1; i<=n; i++) {
        par[i]=i;
        sz[i]=1;
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);

    for (int kase=1; kase<=t; kase++) {
        int n,m,air_cost;
        scanf("%d %d %d",&n,&m,&air_cost);
        set_parent(n);

        for (int i=0; i<m; i++)
            scanf("%d %d %d",&road_list[i].x,&road_list[i].y,&road_list[i].cost);
        sort(road_list,road_list+m,comp);
        int counter=n;
        long long total=0;
        for (int i=0; i<m && road_list[i].cost<air_cost; i++)
            if (!is_united(road_list[i].x,road_list[i].y)) {
                counter--;
                total+=road_list[i].cost;
                make_united(road_list[i].x,road_list[i].y);
            }
        total+=counter*air_cost;

        printf("Case %d: %lld %d\n",kase,total,counter);
    }

    return 0;
}
